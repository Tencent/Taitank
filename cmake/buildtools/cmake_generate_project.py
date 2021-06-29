import sys
import os
import os.path
import glob
import shutil
import xml.etree.ElementTree

def suffixExe():
    if sys.platform == 'win32':
        return '.exe'
    return ''

def makeCommand(platfrom):
    if platfrom == 'android':
        return 'ninja'
    return 'make'

def filterPreset(presetName):
    winPresetFilter = ['win']
    linuxPresetFilter = ['linux']
    if sys.platform == 'win32':        
        if any(presetName.find(elem) != -1 for elem in winPresetFilter):
            return True
    elif sys.platform == 'linux' or sys.platform == 'linux2':
        if any(presetName.find(elem) != -1 for elem in linuxPresetFilter):
            return True
    else:        
        if all(presetName.find(elem) == -1 for elem in winPresetFilter) and all(presetName.find(elem) == -1 for elem in linuxPresetFilter) :
            return True
    return False

def choosePreset():
    global input
    print('Preset parameter required, available presets:')
    presetfiles = []
    for file in glob.glob("buildtools/presets/*.xml"):
        presetfiles.append(file)

    counter = 0
    presetList = []
    for preset in presetfiles:
        if filterPreset(preset):
            presetXml = xml.etree.ElementTree.parse(preset).getroot()
            print('(' + str(counter) + ') ' + presetXml.get('name') + ' <--- ' + presetXml.get('comment'))
            presetList.append(presetXml.get('name'))
            counter = counter + 1            

    try: 
    	input = raw_input
    except NameError: 
    	pass    
    mode = int(input('Enter preset number: '))
    return presetList[mode]


class CMakeParser:
    presetName = ''
    targetPlatform = ''
    compiler = ''
    cmakeParameters = []

    def __init__(self, presetName):
        xmlPath = "buildtools/presets/"+presetName+".xml"
        if os.path.isfile(xmlPath):
            print('Using preset xml:' + xmlPath)
        else:
            print('Preset xml file:'+xmlPath+" not found")
            exit()

        # parse xml and get xml parameter
        presetNode = xml.etree.ElementTree.parse(xmlPath).getroot()
        self.presetName = presetNode.attrib['name']

        # parse target platform and compiler
        for platform in presetNode.findall('platform'):
            self.targetPlatform = platform.attrib['targetPlatform']
            self.compiler = platform.attrib['compiler']
            print('Target platform: ' + self.targetPlatform + ' using compiler: ' + self.compiler)

        # parse cmake parameters
        for cmakeParameter in presetNode.find('CMakeParameters'):
            if cmakeParameter.attrib['name'] == 'ANDROID_ABI':
                param = '-D' + cmakeParameter.attrib['name'] + '=\"' + cmakeParameter.attrib['value'] + '\"'
            else:    
                param = '-D' + cmakeParameter.attrib['name'] + '=' + cmakeParameter.attrib['value'] + ''
            self.cmakeParameters.append(param)
    pass

    def getCMakeParameters(self):
        outString = ''
        for cmakeParam in self.cmakeParameters:
            outString = outString + ' ' + cmakeParam
        return outString


    def getPlatformCMakeParameters(self):
        outString = ' '
        if self.compiler == 'v12':
            outString = outString + '-G \"Visual Studio 12 2013\"'
        elif self.compiler == 'vc14':
            outString = outString + '-G \"Visual Studio 14 2015\"'
        elif self.compiler == 'vc15':
            outString = outString + '-G \"Visual Studio 15 2017\"'
        elif self.compiler == 'vc16':
            outString = outString + '-G \"Visual Studio 16 2019\"'
        # elif self.compiler == 'xcode':
        #     outString = outString + '-G Xcode'
        elif self.targetPlatform == 'android':
            outString = outString + '-G \"Ninja\"'
        elif self.targetPlatform == 'linux':
            outString = outString + '-G \"Unix Makefiles\"'
        # elif self.targetPlatform == 'linuxAarch64':
        #     outString = outString + '-G \"Unix Makefiles\"'

        if self.targetPlatform == 'win32':
            outString = outString + ' -AWin32'
            outString = outString + ' -DTARGET_BUILD_PLATFORM=windows'
            outString = outString + ' -DPROJECT_OUTPUT_ARCH=x86'
            return outString
        elif self.targetPlatform == 'win64':
            outString = outString + ' -Ax64'
            outString = outString + ' -DTARGET_BUILD_PLATFORM=windows'
            outString = outString + ' -DPROJECT_OUTPUT_ARCH=x86'
            return outString
        elif self.targetPlatform == 'android':
            outString = outString + ' -DTARGET_BUILD_PLATFORM=android'
            # todo support mtt_shared stl
            # outString = outString + ' -DANDROID_STL=\"c++_static\"'
            if os.environ.get('PROJECT_ANDROID_NDK_PATH') is None:
                print('Please provide path to android NDK in variable PROJECT_ANDROID_NDK_PATH.')
                exit(-1)
            else:
                outString = outString + ' -DCMAKE_TOOLCHAIN_FILE=' + os.environ['PROJECT_ANDROID_NDK_PATH'] + '/build/cmake/android.toolchain.cmake'
                outString = outString + ' -DANDROID_NDK=' + os.environ['PROJECT_ANDROID_NDK_PATH']
            return outString
        elif self.targetPlatform == 'linux':
            outString = outString + ' -DTARGET_BUILD_PLATFORM=linux'
            if os.environ.get('PROJECT_CLANG_PATH') is not None:
                outString = outString + ' -DCMAKE_C_COMPILER=' + os.environ['PROJECT_CLANG_PATH'] + '/bin/clang'
                outString = outString + ' -DCMAKE_CXX_COMPILER=' + os.environ['PROJECT_CLANG_PATH'] + '/bin/clang++'
            else:
                outString = outString + ' -DCMAKE_C_COMPILER=clang'
                outString = outString + ' -DCMAKE_CXX_COMPILER=clang++'
            return outString
        elif self.targetPlatform == 'mac64':
            outString = outString + ' -DTARGET_BUILD_PLATFORM=mac'
            outString = outString + ' -DTARGET_ARCH=x86'
            return outString
        elif self.targetPlatform == 'ios64':
            outString = outString + ' -DTARGET_BUILD_PLATFORM=ios'
            outString = outString + ' -DCMAKE_TOOLCHAIN_FILE=\"' +  os.environ['PROJECT_CMAKE_MODULES_PATH'] + '/ios/ios.toolchain.cmake\"'
            return outString
        return ''

def getCommonParameters():
    outString = '--no-warn-unused-cli'
    # outString = outString + ' -DCMAKE_PREFIX_PATH=\"' + os.environ['PROJECT_ROOT_DIR'] + '\"'
    outString = outString + ' -DPROJECT_ROOT_DIR=\"' + os.environ['PROJECT_ROOT_DIR'] + '\"'
    return outString

def cleanupCompilerDir(compilerDirName):
    if os.path.exists(compilerDirName):
        if sys.platform == 'win32':
            os.system('rmdir /S /Q ' + compilerDirName)
        else:
            shutil.rmtree(compilerDirName, True)
    if os.path.exists(compilerDirName) == False:
        os.makedirs(compilerDirName)

def presetBuild(presetName):
    cmakeParser = CMakeParser(presetName)
    
    if os.environ.get('PROJECT_CMAKE_PATH') is not None:
        cmakeCommand = os.environ['PROJECT_CMAKE_PATH'] + '/bin/cmake' + suffixExe()
    else:
        cmakeCommand = 'cmake' + suffixExe()
    print('Cmake:' + cmakeCommand)

    # gather all cmake input parameters
    cmakeParams = cmakeParser.getPlatformCMakeParameters()
    cmakeParams = cmakeParams + ' ' + getCommonParameters()
    cmakeParams = cmakeParams + ' ' + cmakeParser.getCMakeParameters()
            
    configs = ['debug', 'release']
    for config in configs:
        # cleanup and create output directory
        outputDir = os.path.join('build', cmakeParser.presetName + '-' + config)
        cleanupCompilerDir(outputDir)

        # run the cmake script
        os.chdir(os.path.join(os.environ['PROJECT_BUILD_DIR'], outputDir))
        os.system(cmakeCommand + ' \"' + os.environ['PROJECT_BUILD_DIR'] + '/compiler/public' + '\"' + cmakeParams + ' -DCMAKE_BUILD_TYPE=' + config)

        # run make script
        if sys.platform != 'win32':
            command = makeCommand(cmakeParser.targetPlatform) + suffixExe()
            os.system(command)

        # return to build directory
        os.chdir(os.environ['PROJECT_BUILD_DIR'])



def main():
    if len(sys.argv) != 2:
        presetName = choosePreset()
        os.chdir(os.environ['PROJECT_BUILD_DIR'])
        if sys.platform == 'win32':
            os.system('generate.bat ' + presetName)
        else:
            os.system('./generate.sh ' + presetName)
    else:
        presetName = sys.argv[1]
        if filterPreset(presetName):
            presetBuild(presetName)
        else:
            print('Preset not supported on this build platform.')
main()
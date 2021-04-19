#!/bin/bash

TARGET_SYSTEM=""
BUILD_TYPE=""
TARGET_ARCH=""
PROJECT_DIR=`pwd`
MAKE_BUILD_TYPE="Release"
BUILD_DIR_BASE="build"

### todo get from env
#NDK_ROOT=/Users/chenli/Library/Android/sdk/ndk-bundle

show_help()
{
    echo "USAGE: ./build.sh -option [args]"
    echo "       -s [windows|android|ios|linux|macos]"
    echo "          setting target system"
    echo "          windows for Microsoft Windows system"
    echo "          android for Google Android system"
    echo "          ios for Apple iOS for iPhone"
    echo "          linux for Linux system"
    echo "          macos for Apple iOS for mac"
    echo "       -a [armeabi-v7a|arm64-v8a|i386|x86|x86_64|armv7|armv7s|arm64]"
    echo "          setting target arch"
    echo "          Notice:"
    echo "                Windows use [x86|x86_64]"
    echo "                Android use [armeabi-v7a|arm64-v8a|x86|x86_64]"
    echo "                iOS use [armv7|armv7s|arm64|i386|x86_64]"
    echo "                Linux use [x86_64]"
    echo "                macOS use [x86_64]"
    echo "       -t [debug|release]"
    echo "          setting build type"
    echo "       -h "
    echo "          with no args show help"
}

show_parameter()
{
    echo "SYNOPSIS "
    echo "       ./build.sh [ -s system ] [ -a architecture ] [ -t debug|release ]"
    echo "EXAMPLES "
    echo "       build taitank lib for linux and x86_64 architecture"
    echo "              ./build.sh -s linux -a x86_64"
    echo "       build taitank lib for android system and armeabi-v7a architecture"
    echo "              ./build.sh -s android -a armeabi-v7a"
    echo "       build taitank lib for ios system and armv7 architecture"
    echo "              ./build.sh -s ios -a armv7"
    echo "       build taitank debug lib for mac system and x86_64 architecture"
    echo "              ./build.sh -s macos -a x86_64 -t debug"
}

check_sys_arch()
{
    # if [ "$TARGET_SYSTEM" = "windows" ]; then
    #    if [ "$TARGET_ARCH" = "" -o "$TARGET_ARCH" = "" -o "$TARGET_ARCH" = "" ]; then
    #         return 0
    #    fi
    # fi

    if [ "$TARGET_SYSTEM" = "android" ]; then
        if [ "$TARGET_ARCH" = "armeabi-v7a" -o "$TARGET_ARCH" = "arm64-v8a" -o "$TARGET_ARCH" = "x86" -o "$TARGET_ARCH" = "x86_64" ]; then
            return 0
        fi
    fi

    if [ "$TARGET_SYSTEM" = "ios" ]; then
        if [ "$TARGET_ARCH" = "armv7" -o "$TARGET_ARCH" = "armv7s" -o "$TARGET_ARCH" = "arm64" -o "$TARGET_ARCH" = "i386" -o "$TARGET_ARCH" = "x86_64" ]; then
            return 0
        fi
    fi

    if [ "$TARGET_SYSTEM" = "linux" -o "$TARGET_SYSTEM" = "macos" ]; then
        if [ "$TARGET_ARCH" = "x86_64" ]; then
            return 0
        fi
    fi

    # if [ "$TARGET_SYSTEM" = "all platform" ]; then
    #     if [ "$TARGET_SYSTEM" = "" ]; then
    #         return 0
    #     fi
    # fi

    return 1
}

build_dir()
{
    BUILD_DIR=${PROJECT_DIR}/${BUILD_DIR_BASE}/$1/${BUILD_TYPE}/$2
}

clean_dir()
{
    if [ -d "$BUILD_DIR" ]; then
        rm -fr ${BUILD_DIR}/*
    else
        mkdir -p ${BUILD_DIR}
    fi
}

while getopts 's:a:t:h' opt;
do 
    case $opt in
        s)
            TARGET_SYSTEM=$OPTARG
            ;;
        t)
            BUILD_TYPE=$OPTARG
            ;;
        a)
            TARGET_ARCH=$OPTARG
            ;;
        h)
            show_help
            exit 1
            ;;
        \?)
            show_help
            exit 1
    esac
done

if [ "$BUILD_TYPE" = "" ]; then
    BUILD_TYPE="release"
fi
# if [ "$TARGET_SYSTEM" = "" ]; then
#     TARGET_SYSTEM="all platform"
# fi
# if [ "$TARGET_ARCH" = "" ]; then
#     TARGET_ARCH="all arch"
# fi

check_sys_arch
if [ $? = 1 ] ; then
    show_parameter
fi

echo "TARGET_SYSTEM:${TARGET_SYSTEM}"
echo "TARGET_ARCH:${TARGET_ARCH}"
echo "BUILD_TYPE:${BUILD_TYPE}"

### build 
if [ BUILD_TYPE = "debug" ]; then
    MAKE_BUILD_TYPE="Debug"
fi

### build for windows
# if [ "$TARGET_SYSTEM" = "windows" -o "$TARGET_SYSTEM" = "all platform" ]; then

# fi

### build for android
if [ "$TARGET_SYSTEM" = "android" ]; then

    if [ ! -n "$NDK_ROOT" ]; then
        echo "set environment variables NDK_ROOT"
        exit 1
    fi

    # 设置 ANDROID_NDK
    ANDROID_NDK=${NDK_ROOT}
    export ANDROID_NDK
    CMAKE_TOOLCHAIN_FILE="${NDK_ROOT}/build/cmake/android.toolchain.cmake"
    ANDROID_PLATFORM=android-14
    ANDROID_TOOLCHAIN=clang

    if [ "$TARGET_ARCH" = "armeabi-v7a" ]; then
        echo "build begin android system and armeabi-v7a arch"

        build_dir "android" "armeabi-v7a"
        echo "BUILD_DIR:${BUILD_DIR}"

        clean_dir
        cd ${BUILD_DIR}/

        ANDROID_ABI=armeabi-v7a
        #ANDROID_STL=c++_static

        echo "CMAKE_TOOLCHAIN_FILE:${CMAKE_TOOLCHAIN_FILE}"
        echo "ANDROID_NDK:${ANDROID_NDK}"
        echo "ANDROID_PLATFORM:${ANDROID_PLATFORM}"
        echo "ANDROID_TOOLCHAIN:${ANDROID_TOOLCHAIN}"
        echo "ANDROID_ABI:${ANDROID_ABI}"

        cmake ${PROJECT_DIR} \
            -DCMAKE_BUILD_TYPE=${MAKE_BUILD_TYPE} \
            -DCMAKE_TOOLCHAIN_FILE=${CMAKE_TOOLCHAIN_FILE} \
            -DANDROID_PLATFORM=${ANDROID_PLATFORM} \
            -DANDROID_ABI="${ANDROID_ABI}" \
            -DANDROID_TOOLCHAIN=${ANDROID_TOOLCHAIN} \
            -DUSE_ANDROID_LIB=ON
        make -j8
        echo "build done!"
    fi

    if [ "$TARGET_ARCH" = "arm64-v8a" ]; then
        echo "build begin android system and arm64-v8a arch"

        build_dir "android" "arm64-v8a"
        echo "BUILD_DIR:${BUILD_DIR}"
     
        # cd ${PROJECT_DIR}

        clean_dir
        cd ${BUILD_DIR}/
        
        ANDROID_ABI=arm64-v8a
        
        echo "CMAKE_TOOLCHAIN_FILE:${CMAKE_TOOLCHAIN_FILE}"
        echo "ANDROID_NDK:${ANDROID_NDK}"
        echo "ANDROID_PLATFORM:${ANDROID_PLATFORM}"
        echo "ANDROID_TOOLCHAIN:${ANDROID_TOOLCHAIN}"
        echo "ANDROID_ABI:${ANDROID_ABI}"

        cmake ${PROJECT_DIR} \
            -DCMAKE_BUILD_TYPE=${MAKE_BUILD_TYPE} \
            -DCMAKE_TOOLCHAIN_FILE=${CMAKE_TOOLCHAIN_FILE} \
            -DANDROID_PLATFORM=${ANDROID_PLATFORM} \
            -DANDROID_ABI="${ANDROID_ABI}" \
            -DANDROID_TOOLCHAIN=${ANDROID_TOOLCHAIN} \
            -DUSE_ANDROID_LIB=ON
        make -j8
        echo "build done!"
    fi

    if [ "$TARGET_ARCH" = "x86" ]; then
        echo "build begin android system and x86 arch"

        build_dir "android" "x86"
        echo "BUILD_DIR:${BUILD_DIR}"
     
        clean_dir
        cd ${BUILD_DIR}/

        ANDROID_ABI=x86

        echo "CMAKE_TOOLCHAIN_FILE:${CMAKE_TOOLCHAIN_FILE}"
        echo "ANDROID_NDK:${ANDROID_NDK}"
        echo "ANDROID_PLATFORM:${ANDROID_PLATFORM}"
        echo "ANDROID_TOOLCHAIN:${ANDROID_TOOLCHAIN}"
        echo "ANDROID_ABI:${ANDROID_ABI}"

        cmake ${PROJECT_DIR} \
            -DCMAKE_BUILD_TYPE=${MAKE_BUILD_TYPE} \
            -DCMAKE_TOOLCHAIN_FILE=${CMAKE_TOOLCHAIN_FILE} \
            -DANDROID_PLATFORM=${ANDROID_PLATFORM} \
            -DANDROID_ABI="${ANDROID_ABI}" \
            -DANDROID_TOOLCHAIN=${ANDROID_TOOLCHAIN} \
            -DUSE_ANDROID_LIB=ON
        make -j8
        echo "build done!"
    fi

    if [ "$TARGET_ARCH" = "x86_64" ]; then
        echo "build begin android system and x86_64 arch"

        build_dir "android" "x86_64"
        echo "BUILD_DIR:${BUILD_DIR}"
     
        clean_dir
        cd ${BUILD_DIR}/

        ANDROID_ABI=x86_64

        echo "CMAKE_TOOLCHAIN_FILE:${CMAKE_TOOLCHAIN_FILE}"
        echo "ANDROID_NDK:${ANDROID_NDK}"
        echo "ANDROID_PLATFORM:${ANDROID_PLATFORM}"
        echo "ANDROID_TOOLCHAIN:${ANDROID_TOOLCHAIN}"
        echo "ANDROID_ABI:${ANDROID_ABI}"

        cmake ${PROJECT_DIR} \
            -DCMAKE_BUILD_TYPE=${MAKE_BUILD_TYPE} \
            -DCMAKE_TOOLCHAIN_FILE=${CMAKE_TOOLCHAIN_FILE} \
            -DANDROID_PLATFORM=${ANDROID_PLATFORM} \
            -DANDROID_ABI="${ANDROID_ABI}" \
            -DANDROID_TOOLCHAIN=${ANDROID_TOOLCHAIN} \
            -DUSE_ANDROID_LIB=ON
        make -j8
        echo "build done!"
    fi
fi

### build for ios
if [ "$TARGET_SYSTEM" = "ios" ]; then

    CMAKE_TOOLCHAIN_FILE="${PROJECT_DIR}/toolchain/ios.toolchain.cmake"
    IOS_PLATFORM="OS"
    IOS_DEPLOYMENT_TARGET="9.0"


    if [ "$TARGET_ARCH" = "armv7" -o "$TARGET_ARCH" = "all arch" ]; then
        echo "build begin ios system and armv7 arch"

        build_dir "ios" "armv7"
        echo "BUILD_DIR:${BUILD_DIR}"

        clean_dir
        cd ${BUILD_DIR}/

        IOS_ARCH=armv7
        echo "CMAKE_TOOLCHAIN_FILE:${CMAKE_TOOLCHAIN_FILE}"
        echo "IOS_PLATFORM:${IOS_PLATFORM}"
        echo "IOS_ARCH:${IOS_ARCH}"
        echo "IOS_DEPLOYMENT_TARGET:${IOS_DEPLOYMENT_TARGET}"

        cmake ${PROJECT_DIR} \
            -DCMAKE_BUILD_TYPE=${MAKE_BUILD_TYPE} \
            -DCMAKE_TOOLCHAIN_FILE=${CMAKE_TOOLCHAIN_FILE} \
            -DIOS_PLATFORM=${IOS_PLATFORM} \
            -DIOS_ARCH=${IOS_ARCH} \
            -DIOS_DEPLOYMENT_TARGET=${IOS_DEPLOYMENT_TARGET} \
            -DENABLE_BITCODE=FALSE \
            -DENABLE_ARC=TRUE \
            -DENABLE_VISIBILITY=FALSE
        make -j8
        echo "build done!"
    fi

    if [ "$TARGET_ARCH" = "armv7s" -o "$TARGET_ARCH" = "all arch" ]; then
        echo "build begin ios system and armv7s arch"

        build_dir "ios" "armv7s"
        echo "BUILD_DIR:${BUILD_DIR}"

        clean_dir
        cd ${BUILD_DIR}/

        IOS_ARCH=armv7s
        echo "CMAKE_TOOLCHAIN_FILE:${CMAKE_TOOLCHAIN_FILE}"
        echo "IOS_PLATFORM:${IOS_PLATFORM}"
        echo "IOS_ARCH:${IOS_ARCH}"
        echo "IOS_DEPLOYMENT_TARGET:${IOS_DEPLOYMENT_TARGET}"

        cmake ${PROJECT_DIR} \
            -DCMAKE_BUILD_TYPE=${MAKE_BUILD_TYPE} \
            -DCMAKE_TOOLCHAIN_FILE=${CMAKE_TOOLCHAIN_FILE} \
            -DIOS_PLATFORM=${IOS_PLATFORM} \
            -DIOS_ARCH=${IOS_ARCH} \
            -DIOS_DEPLOYMENT_TARGET=${IOS_DEPLOYMENT_TARGET} \
            -DENABLE_BITCODE=FALSE \
            -DENABLE_ARC=TRUE \
            -DENABLE_VISIBILITY=FALSE
        make -j8
        echo "build done!"

    fi

    if [ "$TARGET_ARCH" = "arm64" -o "$TARGET_ARCH" = "all arch" ]; then
        echo "build begin ios system and arm64 arch"

        build_dir "ios" "arm64"
        echo "BUILD_DIR:${BUILD_DIR}"

        clean_dir
        cd ${BUILD_DIR}/

        IOS_ARCH=arm64
        echo "CMAKE_TOOLCHAIN_FILE:${CMAKE_TOOLCHAIN_FILE}"
        echo "IOS_PLATFORM:${IOS_PLATFORM}"
        echo "IOS_ARCH:${IOS_ARCH}"
        echo "IOS_DEPLOYMENT_TARGET:${IOS_DEPLOYMENT_TARGET}"

        cmake ${PROJECT_DIR} \
            -DCMAKE_BUILD_TYPE=${MAKE_BUILD_TYPE} \
            -DCMAKE_TOOLCHAIN_FILE=${CMAKE_TOOLCHAIN_FILE} \
            -DIOS_PLATFORM=${IOS_PLATFORM} \
            -DIOS_ARCH=${IOS_ARCH} \
            -DIOS_DEPLOYMENT_TARGET=${IOS_DEPLOYMENT_TARGET} \
            -DENABLE_BITCODE=FALSE \
            -DENABLE_ARC=TRUE \
            -DENABLE_VISIBILITY=FALSE
        make -j8
        echo "build done!"

    fi

    if [ "$TARGET_ARCH" = "i386" -o "$TARGET_ARCH" = "all arch" ]; then
        echo "build begin ios system and i386 arch"

        build_dir "ios" "i386"
        echo "BUILD_DIR:${BUILD_DIR}"

        clean_dir
        cd ${BUILD_DIR}/

        IOS_ARCH=i386
        IOS_PLATFORM="SIMULATOR"
        IOS_DEPLOYMENT_TARGET="10.0"

        echo "CMAKE_TOOLCHAIN_FILE:${CMAKE_TOOLCHAIN_FILE}"
        echo "IOS_PLATFORM:${IOS_PLATFORM}"
        echo "IOS_ARCH:${IOS_ARCH}"
        echo "IOS_DEPLOYMENT_TARGET:${IOS_DEPLOYMENT_TARGET}"

        cmake ${PROJECT_DIR} \
            -DCMAKE_BUILD_TYPE=${MAKE_BUILD_TYPE} \
            -DCMAKE_TOOLCHAIN_FILE=${CMAKE_TOOLCHAIN_FILE} \
            -DIOS_PLATFORM=${IOS_PLATFORM} \
            -DIOS_ARCH=${IOS_ARCH} \
            -DIOS_DEPLOYMENT_TARGET=${IOS_DEPLOYMENT_TARGET} \
            -DENABLE_BITCODE=FALSE \
            -DENABLE_ARC=TRUE \
            -DENABLE_VISIBILITY=FALSE
        make -j8
        echo "build done!"

    fi

    if [ "$TARGET_ARCH" = "x86_64" -o "$TARGET_ARCH" = "all arch" ]; then
        echo "build begin ios system and x86_64 arch"

        build_dir "ios" "x86_64"
        echo "BUILD_DIR:${BUILD_DIR}"

        clean_dir
        cd ${BUILD_DIR}/

        IOS_ARCH=x86_64
        IOS_PLATFORM="SIMULATOR64"
        IOS_DEPLOYMENT_TARGET="10.0"

        echo "CMAKE_TOOLCHAIN_FILE:${CMAKE_TOOLCHAIN_FILE}"
        echo "IOS_PLATFORM:${IOS_PLATFORM}"
        echo "IOS_ARCH:${IOS_ARCH}"
        echo "IOS_DEPLOYMENT_TARGET:${IOS_DEPLOYMENT_TARGET}"

        cmake ${PROJECT_DIR} \
            -DCMAKE_BUILD_TYPE=${MAKE_BUILD_TYPE} \
            -DCMAKE_TOOLCHAIN_FILE=${CMAKE_TOOLCHAIN_FILE} \
            -DIOS_PLATFORM=${IOS_PLATFORM} \
            -DIOS_ARCH=${IOS_ARCH} \
            -DIOS_DEPLOYMENT_TARGET=${IOS_DEPLOYMENT_TARGET} \
            -DENABLE_BITCODE=FALSE \
            -DENABLE_ARC=TRUE \
            -DENABLE_VISIBILITY=FALSE
        make -j8
        echo "build done!"
    fi
fi

### build for linux（todo)
if [ "$TARGET_SYSTEM" = "linux" ]; then
    if [ "$TARGET_ARCH" = "x86_64" ]; then
        echo "build begin linux system and x86_64 arch"

        build_dir "linux" "x86_64"
        echo "BUILD_DIR:${BUILD_DIR}"

        clean_dir
        cd ${BUILD_DIR}/

        cmake ${PROJECT_DIR} \
            -DCMAKE_BUILD_TYPE=${MAKE_BUILD_TYPE} \
            -DCMAKE_SYSTEM_NAME="Linux" \
            -DCMAKE_SYSTEM_PROCESSOR="x86_64"
            # -DTARGET_ARCH="x86_64"
        make -j1
        echo "build done!"
    fi
fi

### build for macos
if [ "$TARGET_SYSTEM" = "macos" ]; then
    if [ "$TARGET_ARCH" = "x86_64" ]; then
        echo "build begin macos system and x86_64 arch"

        build_dir "macos" "x86_64"
        echo "BUILD_DIR:${BUILD_DIR}"

        clean_dir
        cd ${BUILD_DIR}/
        cmake ${PROJECT_DIR} \
            -DCMAKE_BUILD_TYPE=${MAKE_BUILD_TYPE} \
            -DTARGET_ARCH="x86_64"
        make -j1

        echo "build done!"
    fi
fi

#!/bin/bash +x

export PROJECT_BUILD_DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"
export PROJECT_ROOT_DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )/.." && pwd )"
export PROJECT_CMAKE_MODULES_PATH="$( cd "$( dirname "${BASH_SOURCE[0]}" )/modules" && pwd )"
# export PROJECT_ANDROID_NDK_PATH="android ndk path"
# export PROJECT_CMAKE_PATH="cmake path"

# echo ${PROJECT_BUILD_DIR}
# echo ${PROJECT_ROOT_DIR}
# echo ${PROJECT_CMAKE_MODULES_PATH}

cd "$( dirname "${BASH_SOURCE[0]}" )"
python ./buildtools/cmake_generate_project.py $1
status=$?
if [ "$status" -ne "0" ]; then
echo "Error $status"
exit 1
fi
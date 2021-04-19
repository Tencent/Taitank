#! /bin/bash

clean_dir()
{
    if [ -d "$BUILD_DIR" ]; then
        rm -fr ${BUILD_DIR}/*
    else
        mkdir -p ${BUILD_DIR}
    fi  
}

PROJECT_DIR=`pwd`
BUILD_DIR=${PROJECT_DIR}/build/

echo "PROJECT_DIR:${PROJECT_DIR}"
echo "BUILD_DIR:${BUILD_DIR}"

# cd to build directory
clean_dir
cd $BUILD_DIR

# cmake
cmake ${PROJECT_DIR}

# make
make -j8

# run gtest
RUN_PATH="${BUILD_DIR}"/taitank_gtest
if [ -x "${RUN_PATH}" ];then
${RUN_PATH}
fi
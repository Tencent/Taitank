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

# Run emmake with the normal make to generate wasm object files.
emcmake cmake ..
emmake make

# cmake
cmake ${PROJECT_DIR}

# make
make -j8
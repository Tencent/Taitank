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
SOURCE_DIR=$(dirname "$PWD")/src

echo "PROJECT_DIR:${PROJECT_DIR}"
echo "BUILD_DIR:${BUILD_DIR}"
echo "SOURCE_DIR:${SOURCE_DIR}"

# cd to build directory
clean_dir
cd $BUILD_DIR

# cmake
cmake ${PROJECT_DIR} \
    -DSOURCE_DIR=${SOURCE_DIR}

# make
make -j8

# run benchmark
BENCH_MARK="${BUILD_DIR}"/taitank_benchmark
if [ -x "${BENCH_MARK}" ];then
    ${BENCH_MARK}
fi

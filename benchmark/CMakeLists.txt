cmake_minimum_required(VERSION 3.4.1)

project(BENCHMARK)

set(CMAKE_VERBOSE_MAKEFILE on)
message("SOURCE_DIR: ${SOURCE_DIR}")

add_compile_options(-fno-rtti)
add_compile_options(-fmessage-length=0)
add_compile_options(-fno-exceptions)
add_compile_options(-std=c++11)
add_compile_options(-O2)
add_compile_options(-g)
add_compile_options(-Wall)
add_compile_options(-c)

file(GLOB TAITANK_SROURCE_FILES ${SOURCE_DIR}/*.cc)
file(GLOB BENCH_MARK_FILES *.cc)

include_directories(
    ${SOURCE_DIR}
)

add_executable(taitank_benchmark ${TAITANK_SROURCE_FILES} ${BENCH_MARK_FILES})
# target_include_directories(taitank_benchmark PRIVATE ./ ../../engine)
target_link_libraries(taitank_benchmark pthread)

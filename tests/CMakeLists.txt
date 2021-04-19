cmake_minimum_required(VERSION 3.4.1)
set(CMAKE_VERBOSE_MAKEFILE on)

project(TAITANK_GTEST)

add_compile_options(
	-fno-rtti
	-std=c++11
	-Werror
	-fno-exceptions
	-Wno-format-truncation
	 )

file(GLOB TAITANK_SROURCE_FILES ../src/*.cc)
message( taitank source file list: "${TAITANK_SROURCE_FILES}")
file(GLOB GTEST_UNIT_FLIES ./*.cc) 
message( taitank gtest source file list: "${GTEST_UNIT_FLIES}")
file(GLOB GTEST_FILES ./gtest/*.cc) 
message( gtest source file list: "${GTEST_FILES}")


add_executable(taitank_gtest ${TAITANK_SROURCE_FILES} ${GTEST_UNIT_FLIES}  ${GTEST_FILES})
target_include_directories(taitank_gtest PRIVATE ./ ./gtest ../src)
target_link_libraries(taitank_gtest pthread)

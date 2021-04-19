cmake_minimum_required(VERSION 3.4.1)
set(CMAKE_VERBOSE_MAKEFILE on)

project(TAITANK_WASM)

set(CMAKE_C_STANDARD 11) # 根据你的C编译器支持情况进行修改
set(CMAKE_EXECUTABLE_SUFFIX ".html") # 编译生成.html


add_compile_options(
	-std=c++11
	-Werror
	-fno-exceptions
)

include_directories(../src/)

file(GLOB BINDING_FILES ./binding.cc)
file(GLOB TAITANK_FILES ../src/*.cc)

# target_include_directories(taitank_wasm PRIVATE ../src)

add_executable(taitank_wasm ${BINDING_FILES} ${TAITANK_FILES})
set_target_properties(taitank_wasm PROPERTIES LINK_FLAGS " --bind")
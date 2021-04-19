cmake_minimum_required(VERSION 3.4.1)

project(tatiank C CXX)

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE "Release")
endif(NOT CMAKE_BUILD_TYPE)

set(CMAKE_VERBOSE_MAKEFILE ON)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

add_compile_options(-fno-rtti -fno-threadsafe-statics)
add_compile_options(-fvisibility-inlines-hidden -fvisibility=hidden)
add_compile_options(-Werror -Wextra -Wall -Wno-unused-variable -Wno-unused-parameter -Wno-missing-field-initializers -Wno-unused-local-typedefs)
add_compile_options(--param=ssp-buffer-size=4)
add_compile_options(-fstack-protector)
add_compile_options(-fno-exceptions)
add_compile_options(-funwind-tables)
add_compile_options(-fno-strict-aliasing)
add_compile_options(-fPIC)
add_compile_options(-ffunction-sections -fdata-sections)
add_compile_options(-fno-short-enums)
# add_compile_options(-fomit-frame-pointer)
add_compile_options(-std=c++11)
add_compile_options(-pipe)
add_compile_options(-Os)
add_compile_options(-g)


file(GLOB  TAITANK_SROURCE_FILES ./src/*.cc)
message( taitank src file list: "${TAITANK_SROURCE_FILES}")

add_library(flexbox SHARED ${TAITANK_SROURCE_FILES})

if(USE_ANDROID_LIB)
	target_link_libraries(flexbox android log)
else()
	target_link_libraries(flexbox)
endif()



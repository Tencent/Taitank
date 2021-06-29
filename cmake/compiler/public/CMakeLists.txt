cmake_minimum_required(VERSION 3.6)

project(Taitank C CXX)

SET(CMAKE_VERBOSE_MAKEFILE ON)
SET(CMAKE_POSITION_INDEPENDENT_CODE ON)

MESSAGE("TAITANK ROOT ${PROJECT_ROOT_DIR}")

IF(NOT EXISTS ${PROJECT_ROOT_DIR})
	MESSAGE(FATAL_ERROR "PROJECT_ROOT_DIR environment variable wasn't set or was invalid.")
ENDIF()

MESSAGE("Taitank Build Platform: " ${TARGET_BUILD_PLATFORM})
MESSAGE("Using CXX Compiler: " ${CMAKE_CXX_COMPILER})
MESSAGE("Build type: " ${CMAKE_BUILD_TYPE})

ADD_COMPILE_OPTIONS(-Os)
ADD_COMPILE_OPTIONS(-std=c++11)

IF(NOT ${TARGET_BUILD_PLATFORM} STREQUAL "windows")
	ADD_COMPILE_OPTIONS(-Werror -Wextra -Wall -Wno-unused-variable -Wno-unused-parameter -Wno-missing-field-initializers)
	ADD_COMPILE_OPTIONS(-fno-rtti -fno-threadsafe-statics)
	ADD_COMPILE_OPTIONS(-fvisibility-inlines-hidden -fvisibility=hidden)
	ADD_COMPILE_OPTIONS(--param=ssp-buffer-size=4)
	ADD_COMPILE_OPTIONS(-fstack-protector)
	ADD_COMPILE_OPTIONS(-fno-exceptions)
	ADD_COMPILE_OPTIONS(-funwind-tables)
	ADD_COMPILE_OPTIONS(-fno-strict-aliasing)
	ADD_COMPILE_OPTIONS(-fPIC)
	ADD_COMPILE_OPTIONS(-ffunction-sections -fdata-sections)
	ADD_COMPILE_OPTIONS(-fno-short-enums)
	# add_compile_options(-fomit-frame-pointer)
	ADD_COMPILE_OPTIONS(-pipe)
	ADD_COMPILE_OPTIONS(-Os)
	ADD_COMPILE_OPTIONS(-g)
ENDIF()


FILE(GLOB  TAITANK_SROURCE_FILES ${PROJECT_ROOT_DIR}/src/*.cc)
MESSAGE("BUILD FILES: ${TAITANK_SROURCE_FILES}")

ADD_LIBRARY(flexbox SHARED ${TAITANK_SROURCE_FILES})

IF(${TARGET_BUILD_PLATFORM} STREQUAL "android" )
	TARGET_LINK_LIBRARIES(flexbox android log)
ELSE()
	TARGET_LINK_LIBRARIES(flexbox)
ENDIF()

cmake_minimum_required(VERSION 3.6)

project(Taitank C CXX)

SET(CMAKE_VERBOSE_MAKEFILE ON)
SET(CMAKE_POSITION_INDEPENDENT_CODE ON)

GET_FILENAME_COMPONENT(PROJECT_ROOT_DIR "${CMAKE_CURRENT_SOURCE_DIR}" REALPATH)
MESSAGE("TAITANK ROOT ${PROJECT_ROOT_DIR}")

IF(NOT EXISTS ${PROJECT_ROOT_DIR})
	MESSAGE(FATAL_ERROR "PROJECT_ROOT_DIR environment variable wasn't set or was invalid.")
ENDIF()

MESSAGE("Taitank Build Platform: " ${TARGET_BUILD_PLATFORM})
MESSAGE("Using CXX Compiler: " ${CMAKE_CXX_COMPILER})

ADD_COMPILE_OPTIONS(-std=c++11)

if("${CMAKE_SYSTEM_NAME}" NOT STREQUAL "Windows")
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
  ADD_COMPILE_OPTIONS(-pipe)
  ADD_COMPILE_OPTIONS(-Os)
  ADD_COMPILE_OPTIONS(-g)
endif()

FILE(GLOB  TAITANK_SROURCE_FILES src/*.cc)
MESSAGE("BUILD FILES: ${TAITANK_SROURCE_FILES}")

ADD_LIBRARY(taitank STATIC ${TAITANK_SROURCE_FILES})
TARGET_INCLUDE_DIRECTORIES(taitank PUBLIC src/)

IF(ANDROID)
	TARGET_LINK_LIBRARIES(taitank android log)
ELSE()
	TARGET_LINK_LIBRARIES(taitank)
ENDIF()

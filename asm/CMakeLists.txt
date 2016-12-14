cmake_minimum_required(VERSION 2.8)

project(helloasm)

#enable_language(ASM)
# CONFIGURE C/C++
#========================================================================
set (CMAKE_C_CXX_COMMON_FLAGS "-Wall -Wfloat-equal -Wundef -Wno-strict-aliasing -Wno-unused-function -Wno-unused-but-set-variable -Wno-unused-macros -Wno-unknown-pragmas")
set (CMAKE_C_FLAGS "-u MAIN__ -std=gnu99 ${CMAKE_C_CXX_COMMON_FLAGS}")
set (CMAKE_CXX_FLAGS "-u MAIN__ -std=gnu++11 ${CMAKE_C_CXX_COMMON_FLAGS}")

set(CMAKE_EXPORT_COMPILE_COMMANDS "ON")
set(CMAKE_GENERATOR "Unix Makefiles" CACHE INTERNAL "" FORCE)
set(CMAKE_EXTRA_GENERATOR "Sublime Text 2" CACHE INTERNAL "" FORCE)

add_executable(helloasm helloasm.c)


# Gen and cook lcmtypes
#========================================================================
#include(${PROJECT_SOURCE_DIR}/lcmdefs/PACKAGES.cmake)
#lcmtypes_build()

# INCLUDE COMMON LIBRARIES
#========================================================================
#include_directories(${PROJECT_SOURCE_DIR}/src/)


# INCLUDE PROJECT SUBDIRECTORY
#========================================================================
#add_subdirectory(src)

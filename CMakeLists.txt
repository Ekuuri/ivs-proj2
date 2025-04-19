cmake_minimum_required(VERSION 3.13)
project(epicCalculator)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_PREFIX_PATH "/home/ivs/Qt/6.8.2/gcc_64" ${CMAKE_PREFIX_PATH})

find_package(Qt6 COMPONENTS Core Gui Widgets)
if (Qt6_FOUND)
  message(STATUS "Found Qt6")
else()
  message(FATAL_ERROR "Cannot find Qt6, maybe try 'sudo apt install qtcreator qt6-base-dev'")
endif()

set(GOOGLETEST_VERSION 1.16.0)
set(GTEST_DIR "${CMAKE_SOURCE_DIR}/googletest")
include(CMakeDependentOption)
include(GNUInstallDirs)

option(BUILD_GMOCK "Builds the googlemock subproject" ON)
option(INSTALL_GTEST "Enable installation of googletest. (Projects embedding googletest may want to turn this OFF.)" ON)

file(GLOB DIR_CONTENT ${GTEST_DIR}/*)
if(NOT DIR_CONTENT)
  execute_process(
    COMMAND git submodule init
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
    RESULT_VARIABLE _git_init_result
    OUTPUT_VARIABLE _git_init_out
    ERROR_VARIABLE _git_init_err
  )
  execute_process(
    COMMAND git submodule update
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
    RESULT_VARIABLE _git_update_result
    OUTPUT_VARIABLE _git_update_out
    ERROR_VARIABLE _git_update_err
  )
endif()

if(BUILD_GMOCK)
  add_subdirectory(${GTEST_DIR}/googlemock googletest_build)
else()
  add_subdirectory(${GTEST_DIR}/googletest googletest_build)
endif()

include_directories(${GTEST_DIR}/googletest/include)

add_subdirectory(src)

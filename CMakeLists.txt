cmake_minimum_required(VERSION 3.13)
project(epicCalculator)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_PREFIX_PATH "/home/ivs/Qt/6.8.2/gcc_64" ${CMAKE_PREFIX_PATH})

find_package(Qt6 COMPONENTS Core Gui Widgets REQUIRED)

set(GOOGLETEST_VERSION 1.16.0)
set(GTEST_DIR "${CMAKE_SOURCE_DIR}/googletest")
include(CMakeDependentOption)
include(GNUInstallDirs)

option(BUILD_GMOCK "Builds the googlemock subproject" ON)
option(INSTALL_GTEST "Enable installation of googletest. (Projects embedding googletest may want to turn this OFF.)" ON)

if(BUILD_GMOCK)
  add_subdirectory(${GTEST_DIR}/googlemock googletest_build)
else()
  add_subdirectory(${GTEST_DIR}/googletest googletest_build)
endif()

include_directories(${GTEST_DIR}/googletest/include)

add_subdirectory(src)

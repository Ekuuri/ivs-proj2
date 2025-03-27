cmake_minimum_required(VERSION 3.13)
project(epicCalculator)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_PREFIX_PATH "/usr/lib/x86_64-linux-gnu/cmake/Qt5" ${CMAKE_PREFIX_PATH})

find_package(Qt5 COMPONENTS Core Gui Widgets REQUIRED)

set(GOOGLETEST_VERSION 1.16.0)
set(GTEST_DIR "${CMAKE_SOURCE_DIR}/third_party/googletest")
include(CMakeDependentOption)
include(GNUInstallDirs)

option(BUILD_GMOCK "Builds the googlemock subproject" ON)
option(INSTALL_GTEST "Enable installation of googletest. (Projects embedding googletest may want to turn this OFF.)" ON)
option(GTEST_HAS_ABSL "Use Abseil and RE2. Requires Abseil and RE2 to be separately added to the build." OFF)

if(GTEST_HAS_ABSL)
  if(NOT TARGET absl::base)
    find_package(absl REQUIRED)
  endif()
  if(NOT TARGET re2::re2)
    find_package(re2 REQUIRED)
  endif()
endif()

if(BUILD_GMOCK)
  add_subdirectory(${GTEST_DIR}/googlemock googletest_build)
else()
  add_subdirectory(${GTEST_DIR}/googletest googletest_build)
endif()

include_directories(${GTEST_DIR}/googletest/include)

add_subdirectory(src)
add_subdirectory(tests)
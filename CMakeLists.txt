cmake_minimum_required(VERSION 3.13)
project(epicCalculator)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#set(CMAKE_PREFIX_PATH "/home/ivs/Qt/6.8.2/gcc_64" ${CMAKE_PREFIX_PATH})

# ----------------------------------------------------------
# Qt6 configuration
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

# ----------------------------------------------------------
# GoogleTest submodule initialization
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
    
    set(INSTALL_GTEST OFF CACHE BOOL "Disable Googletest install" FORCE)
    if(BUILD_GMOCK)
    add_subdirectory(${GTEST_DIR}/googlemock googletest_build)
else()
  add_subdirectory(${GTEST_DIR}/googletest googletest_build)
endif()

include_directories(${GTEST_DIR}/googletest/include)

add_subdirectory(src)

# ----------------------------------------------------------
#Cpack configuration for Calculator and Profiling installer
#Informations about package
set(CPACK_PACKAGE_NAME "${PROJECT_NAME}")
set(CPACK_PACKAGE_CONTACT "xjedliv01@stud.fit.vut.cz")
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "Calculator and profiling installer")
set(CPACK_PACKAGE_VERSION "1.0.0")

#Generator set
set(CPACK_GENERATOR DEB)
#More packages
set(CPACK_DEB_COMPONENT_INSTALL ON)
set(CPACK_COMPONENTS_ALL EpicCalc stddev)

include(CPack)

# ----------------------------------------------------------
#Cpack configuration for Calculator installer
install(TARGETS epicCalculator
        RUNTIME DESTINATION /opt/${PROJECT_NAME}
        COMPONENT EpicCalc
)

install(FILES src/installer/${PROJECT_NAME}.desktop
        DESTINATION /usr/share/applications
        COMPONENT EpicCalc
)

install(FILES ${CMAKE_SOURCE_DIR}/LICENSE
        DESTINATION /usr/share/doc/${PROJECT_NAME}
        RENAME copyright
        COMPONENT EpicCalc
)

set(CPACK_DEBIAN_EpicCalc_PACKAGE_CONTROL_EXTRA
    "${CMAKE_CURRENT_SOURCE_DIR}/src/installer/postinst"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/installer/prerun"
)

#Icon
install(FILES ${CMAKE_SOURCE_DIR}/src/icon/epic_calculator.xpm
        DESTINATION /usr/share/pixmaps
        COMPONENT EpicCalc
)

#Dependencies
set(CPACK_DEBIAN_EpicCalc_PACKAGE_DEPENDS
  "libc6 (>= 2.34), libstdc++6 (>= 13), libqt6core6 (>= 6.2), libqt6gui6 (>= 6.2), libqt6widgets6 (>= 6.2)"
)

cpack_add_component(EpicCalc
  DISPLAY_NAME "Epic Calculator"
  DESCRIPTION  "Calculator installer"
)

# ----------------------------------------------------------
#Cpack configuration for Profiling installer
install(TARGETS stddev
        RUNTIME DESTINATION /opt/stddev
        COMPONENT stddev
)

install(FILES ${CMAKE_SOURCE_DIR}/LICENSE
        DESTINATION /usr/share/doc/${PROJECT_NAME}-stddev
        RENAME copyright
        COMPONENT stddev
)  

cpack_add_component(stddev
DISPLAY_NAME "Stddev profiling Tool"
DESCRIPTION  "Stddev profiling installer"
)



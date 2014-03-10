########################################################################
#
#       General section
#
########################################################################

# Set minimum cmake version
cmake_minimum_required(VERSION 2.6)

# Project name
project(EauVive)

# Set some directories
set(SOURCE_DIR "${CMAKE_SOURCE_DIR}/src")
set(BIN_DIR "${CMAKE_SOURCE_DIR}/bin")

# Enable debug symbols by default
if(CMAKE_BUILD_TYPE STREQUAL "")
    set(CMAKE_BUILD_TYPE Debug)
endif()

########################################################################
#
#       Sources section
#
########################################################################

# Set executable output
SET(EXECUTABLE_OUTPUT_PATH ${BIN_DIR})

# Set executable name
set(EXECUTABLE_NAME "eauVive")

# Get all source files
file(GLOB_RECURSE SOURCE_FILES "${SOURCE_DIR}/*")

# Add executable with all source files found
add_executable(${EXECUTABLE_NAME} ${SOURCE_FILES})

########################################################################
#
#       General config section
#
########################################################################

# If compiling under windows
if(WIN32)
    # Set conversion to windows
    set(CMAKE_GNUtoMS TRUE)
    
    # Set no install prefix
    set(CMAKE_INSTALL_PREFIX "")
endif()

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra")

########################################################################
#
#       Libraries section
#
########################################################################

# Set the cmake_module path
# set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules")

########################################################################
#
#       Finishing config section
#
########################################################################

# CPack packaging
include(InstallRequiredSystemLibraries)
include(CPack)

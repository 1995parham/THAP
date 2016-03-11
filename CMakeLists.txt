# In The Name Of God
# ========================================
# [] File Name : CMakeLists.txt
#
# [] Creation Date : 15-02-2016
#
# [] Created By : Parham Alvani (parham.alvani@gmail.com)
# =======================================
cmake_minimum_required(VERSION 2.6)
project(THAP)

# Use CPack for our packaging process :)))
set(CPACK_GENERATOR "DEB")
set(CPACK_DEBIAN_PACKAGE_DEPENDS "libsoup-2.4-1 (>= 2.50.0)")
set(CPACK_DEBIAN_PACKAGE_MAINTAINER "Parham Alvani <parham.alvani@gmail.com>")
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "The HTTP Analyzer Program")
set(CPACK_PACKAGE_DESCRIPTION "Simple HTTP request sender and analyze :)")
include(CPack)

# Set porject imformation
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/lib")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/lib")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin")

add_subdirectory(src)

# The version number
set(THAP_MAJOR_VERSION 1)
set(THAP_MINOR_VERSION 0)

# Configuration header file
configure_file(
	"${PROJECT_SOURCE_DIR}/config.h.in"
	"${PROJECT_BINARY_DIR}/config.h"
	)

# Add personal c flags
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -O0 -g -std=gnu11 ")
set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS} -DDEBUG")

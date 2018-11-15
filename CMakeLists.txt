#
# This file is part of Sage.
#
# Copyright (C) 2018  Hansel De La Cruz
#
# Sage is free software: you can redistribute it and/or modify
# it under the terms of the GNU Affero General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# Sage is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU Affero General Public License for more details.
#
# You should have received a copy of the GNU Affero General Public License
# along with Sage.  If not, see <http://www.gnu.org/licenses/>.
#

cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

project(sage VERSION 1.0.0 LANGUAGES CXX)

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif()
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

set(CMAKE_THREAD_PREFER_PTHREAD TRUE)
set(THREADS_PREFER_PTHREAD_FLAG TRUE)
find_package(Threads REQUIRED)

option (SAGE_TESTS "Build unit tests" OFF)
option (SAGE_PLAYGROUND "Build playground" ON)
option (SAGE_BUILD_STATIC "Also build static version of this library" OFF)

add_subdirectory(src)

if(SAGE_TESTS)
    enable_testing()
    add_subdirectory(tests)
endif()

if(SAGE_PLAYGROUND)
    add_subdirectory(playground)
endif()

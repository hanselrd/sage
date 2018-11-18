#[==[
  This file is part of Sage.

  Copyright (C) 2018  Hansel De La Cruz

  Sage is free software: you can redistribute it and/or modify
  it under the terms of the GNU Affero General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  Sage is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU Affero General Public License for more details.

  You should have received a copy of the GNU Affero General Public License
  along with Sage.  If not, see <http://www.gnu.org/licenses/>.
#]==]

cmake_minimum_required(VERSION 3.8 FATAL_ERROR)

project(sage VERSION 1.0.0 LANGUAGES CXX)

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif()

set(SAGE_ROOT_PROJECT OFF)
if(CMAKE_CURRENT_SOURCE_DIR STREQUAL CMAKE_SOURCE_DIR)
    set(SAGE_ROOT_PROJECT ON)
endif()

if(SAGE_ROOT_PROJECT)
    set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
    set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
endif()

option(SAGE_BUILD_SHARED_LIB "Build as a shared library" ON)
option(SAGE_BUILD_TESTS "Build tests" ON)
option(SAGE_BUILD_PLAYGROUND "Build playground" ON)

add_subdirectory(extlibs)
add_subdirectory(src)

if(SAGE_BUILD_TESTS)
    include(CTest)
    include(Catch)
    add_subdirectory(tests)
endif()

if(SAGE_BUILD_PLAYGROUND)
    add_subdirectory(playground)
endif()

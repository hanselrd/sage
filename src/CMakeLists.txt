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

project(${CMAKE_PROJECT_NAME})

set(sources
    test.cpp)

set(lua_api_sources
    )

set(unittest_sources
    )

set(libs
    Threads::Threads
    $<$<AND:$<CXX_COMPILER_ID:GNU>,$<VERSION_LESS:$<CXX_COMPILER_VERSION>,9.0>>:stdc++fs>
    )

add_library(${PROJECT_NAME} SHARED
    ${sources}
    ${lua_api_sources})

if(SAGE_BUILD_STATIC)
    add_library(${PROJECT_NAME}static STATIC
        ${sources}
        ${lua_api_sources})
endif()

target_include_directories(${PROJECT_NAME}
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/../include
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/../include/sage)

if(SAGE_BUILD_STATIC)
    target_include_directories(${PROJECT_NAME}static
        PUBLIC
            ${CMAKE_CURRENT_SOURCE_DIR}/../include
        PRIVATE
            ${CMAKE_CURRENT_SOURCE_DIR}/../include/sage)
endif()

target_compile_definitions(${PROJECT_NAME} PRIVATE
    SAGE_EXPORT)

if(SAGE_BUILD_STATIC)
    target_compile_definitions(${PROJECT_NAME}static PUBLIC
        SAGE_STATIC)
endif()

target_compile_options(${PROJECT_NAME} PRIVATE
    $<$<OR:$<CXX_COMPILER_ID:GNU>,$<CXX_COMPILER_ID:Clang>>:-Wall -Wextra -Werror -fvisibility=hidden -fvisibility-inlines-hidden>
    $<$<CXX_COMPILER_ID:MSVC>:/Wall /WX>)

if(SAGE_BUILD_STATIC)
    target_compile_options(${PROJECT_NAME}static PRIVATE
        $<$<OR:$<CXX_COMPILER_ID:GNU>,$<CXX_COMPILER_ID:Clang>>:-Wall -Wextra -Werror>
        $<$<CXX_COMPILER_ID:MSVC>:/Wall /WX>)
endif()

target_link_libraries(${PROJECT_NAME} PRIVATE
    ${libs})

if(SAGE_BUILD_STATIC)
    target_link_libraries(${PROJECT_NAME}static PRIVATE
        ${libs})
endif()

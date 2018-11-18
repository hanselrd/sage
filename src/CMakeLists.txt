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

set(CMAKE_THREAD_PREFER_PTHREAD TRUE)
set(THREADS_PREFER_PTHREAD_FLAG TRUE)
find_package(Threads REQUIRED)

set(sources
    log.cpp)

set(unittest_sources
    log.unittest.cpp)

if(SAGE_BUILD_SHARED_LIB)
    add_library(sage SHARED
        ${sources})
else()
    add_library(sage STATIC
        ${sources})
endif()

target_include_directories(sage
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../include>
        $<INSTALL_INTERFACE:include>
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR})

if(SAGE_BUILD_SHARED_LIB)
    target_compile_definitions(sage PRIVATE
        SAGE_EXPORT=1)
else()
    target_compile_definitions(sage PUBLIC
        SAGE_STATIC=1)
endif()

if(SAGE_BUILD_SHARED_LIB)
    target_compile_options(sage PRIVATE
        $<$<OR:$<CXX_COMPILER_ID:GNU>,$<CXX_COMPILER_ID:Clang>>:-Wall -Wextra -fvisibility=hidden -fvisibility-inlines-hidden>
        $<$<CXX_COMPILER_ID:MSVC>:/Wall>)
else()
    target_compile_options(sage PRIVATE
        $<$<OR:$<CXX_COMPILER_ID:GNU>,$<CXX_COMPILER_ID:Clang>>:-Wall -Wextra>
        $<$<CXX_COMPILER_ID:MSVC>:/Wall>)
endif()

target_compile_features(sage PRIVATE cxx_std_17)

target_link_libraries(sage
    PUBLIC
        Threads::Threads
        $<$<AND:$<CXX_COMPILER_ID:GNU>,$<VERSION_LESS:$<CXX_COMPILER_VERSION>,9.0>>:stdc++fs>
        spdlog::spdlog
    PRIVATE
        )

if(SAGE_BUILD_TESTS)
    add_executable(sage-test
        ${unittest_sources}
        ../tests/main.cpp)

    target_compile_options(sage-test PRIVATE
        $<$<OR:$<CXX_COMPILER_ID:GNU>,$<CXX_COMPILER_ID:Clang>>:-Wall -Wextra>
        $<$<CXX_COMPILER_ID:MSVC>:/Wall>)

    target_compile_features(sage-test PRIVATE cxx_std_17)

    target_link_libraries(sage-test PRIVATE
        sage
        Catch2::Catch2)

    catch_discover_tests(sage-test
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR})
endif()

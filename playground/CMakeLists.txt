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

project(playground)

set(sources)

set(libs
    ${CMAKE_PROJECT_NAME})

add_executable(${PROJECT_NAME}
    ${sources}
    main.cpp)

target_compile_options(${PROJECT_NAME} PRIVATE
    $<$<OR:$<CXX_COMPILER_ID:GNU>,$<CXX_COMPILER_ID:Clang>>:-Wall -Wextra -Werror>
    $<$<CXX_COMPILER_ID:MSVC>:/Wall /WX>)

target_link_libraries(${PROJECT_NAME}
    ${libs})

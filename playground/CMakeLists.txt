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

add_executable(sage-playground
    main.cpp)

target_compile_options(sage-playground PRIVATE
    $<$<OR:$<CXX_COMPILER_ID:GNU>,$<CXX_COMPILER_ID:Clang>>:-Wall -Wextra>
    $<$<CXX_COMPILER_ID:MSVC>:/Wall>)

target_compile_features(sage-playground PRIVATE cxx_std_17)

target_link_libraries(sage-playground PRIVATE
    sage)

/**
 *  This file is part of Sage.
 *
 *  Copyright (C) 2018  Hansel De La Cruz
 *
 *  Sage is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU Affero General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  Sage is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU Affero General Public License for more details.
 *
 *  You should have received a copy of the GNU Affero General Public License
 *  along with Sage.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef SAGE_CORE_MACROS_HPP
#define SAGE_CORE_MACROS_HPP

#include "log.hpp"

#define STRINGIFY(x) #x

#ifndef NDEBUG
#    define EXPECT_TRUE(condition)                                                                 \
        [&] {                                                                                      \
            if (!(condition)) {                                                                    \
                LOG_INTERNAL_WARN("Expected `" #condition "' to be true");                         \
            }                                                                                      \
            return condition;                                                                      \
        }()

#    define EXPECT_FALSE(condition)                                                                \
        [&] {                                                                                      \
            if (condition) {                                                                       \
                LOG_INTERNAL_WARN("Expected `" #condition "' to be false");                        \
            }                                                                                      \
            return condition;                                                                      \
        }()
#else
#    define EXPECT_TRUE(condition) (condition)
#    define EXPECT_FALSE(condition) (condition)
#endif

#ifndef NDEBUG
#    define UNUSED_ARG(arg)                                                                        \
        [&] {                                                                                      \
            LOG_INTERNAL_WARN("Unused argument `" #arg "'");                                       \
            (void)arg;                                                                             \
        }()
#else
#    define UNUSED_ARG(arg) ((void)arg)
#endif

#endif

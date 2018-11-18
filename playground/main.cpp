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

#include <sage/sage.hpp>

auto main(int argc, char *argv[]) -> int {
    sg::log::init();
    UNUSED_ARG(argc);
    UNUSED_ARG(argv);
    LOG_INTERNAL_TRACE("trace");
    LOG_INTERNAL_DEBUG("debug");
    LOG_INTERNAL_INFO("info");
    LOG_INTERNAL_WARN("warn");
    LOG_INTERNAL_ERROR("error");
    LOG_INTERNAL_CRITICAL("critical");

    LOG_TRACE("trace");
    LOG_DEBUG("debug");
    LOG_INFO("info");
    LOG_WARN("warn");
    LOG_ERROR("error");
    LOG_CRITICAL("critical");
    return 0;
}

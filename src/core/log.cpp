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

#include "core/log.hpp"
#include <iostream>
#include <memory>
#include <spdlog/sinks/stdout_color_sinks.h>

namespace sg {
namespace log {
namespace {
auto internal_logger = std::shared_ptr<spdlog::logger>{};
auto external_logger = std::shared_ptr<spdlog::logger>{};
} // namespace

auto init() -> void {
    try {
        internal_logger = spdlog::stdout_color_mt("sage");
        internal_logger->set_level(spdlog::level::trace);

        external_logger = spdlog::stdout_color_mt("app");
        external_logger->set_level(spdlog::level::trace);
    } catch (const spdlog::spdlog_ex &ex) {
        std::cerr << "Log initialization failed: " << ex.what() << std::endl;
    }
}

auto get_internal_logger() -> std::shared_ptr<spdlog::logger> & {
    return internal_logger;
}

auto get_external_logger() -> std::shared_ptr<spdlog::logger> & {
    return external_logger;
}
} // namespace log
} // namespace sg

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

#ifndef SAGE_CORE_LOG_HPP
#define SAGE_CORE_LOG_HPP

#include "config.hpp"
#include <memory>
#include <spdlog/spdlog.h>

namespace sg {
namespace log {
SAGE_API auto init() -> void;
SAGE_API auto get_internal_logger() -> std::shared_ptr<spdlog::logger> &;
SAGE_API auto get_external_logger() -> std::shared_ptr<spdlog::logger> &;
} // namespace log
} // namespace sg

#define LOG_INTERNAL_TRACE sg::log::get_internal_logger()->trace
#define LOG_INTERNAL_DEBUG sg::log::get_internal_logger()->debug
#define LOG_INTERNAL_INFO sg::log::get_internal_logger()->info
#define LOG_INTERNAL_WARN sg::log::get_internal_logger()->warn
#define LOG_INTERNAL_ERROR sg::log::get_internal_logger()->error
#define LOG_INTERNAL_CRITICAL sg::log::get_internal_logger()->critical

#define LOG_TRACE sg::log::get_external_logger()->trace
#define LOG_DEBUG sg::log::get_external_logger()->debug
#define LOG_INFO sg::log::get_external_logger()->info
#define LOG_WARN sg::log::get_external_logger()->warn
#define LOG_ERROR sg::log::get_external_logger()->error
#define LOG_CRITICAL sg::log::get_external_logger()->critical

#endif

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

#ifndef SAGE_CORE_CONFIG_HPP
#define SAGE_CORE_CONFIG_HPP

#if !defined(SAGE_STATIC)
#    if defined(_WIN32) || defined(__CYGWIN__)
#        define SAGE_API_IMPORT __declspec(dllimport)
#        define SAGE_API_EXPORT __declspec(dllexport)
#    else
#        if __GNUC__ >= 4
#            define SAGE_API_IMPORT __attribute__((visibility("default")))
#            define SAGE_API_EXPORT __attribute__((visibility("default")))
#        else
#            define SAGE_API_IMPORT
#            define SAGE_API_EXPORT
#        endif
#    endif
#    if defined(SAGE_EXPORT)
#        define SAGE_API SAGE_API_EXPORT
#    else
#        define SAGE_API SAGE_API_IMPORT
#    endif
#else
#    define SAGE_API_IMPORT
#    define SAGE_API_EXPORT
#    define SAGE_API
#endif

#endif

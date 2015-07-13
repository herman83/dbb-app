// Copyright (c) 2015 Jonas Schnelli
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef LIBDBB_UTIL_H
#define LIBDBB_UTIL_H

#include <stdint.h>
#include <string>

#if defined(HAVE_CONFIG_H)
#include "config/dbb_cli-config.h"
#endif

#define DEBUG_SHOW_CATEGRORY 1

#ifdef ENABLE_DEBUG
#define DebugOut(category,format,args...) \
		if (DEBUG_SHOW_CATEGRORY) {\
			printf("%s: ", category); \
		}\
		printf(format, ## args);			
#else
#define DebugOut(category,format,args...)
#endif
				
#define PrintConsole(format,args...) printf(format, ## args);
				
//sanitize a string and clean out things which could generate harm over a RPC/JSON/Console output
std::string SanitizeString(const std::string& str);

#endif // LIBDBB_UTIL_H
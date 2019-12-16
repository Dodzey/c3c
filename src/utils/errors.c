// Copyright (c) 2019 Christoffer Lerno. All rights reserved.
// Use of this source code is governed by the GNU LGPLv3.0 license
// a copy of which can be found in the LICENSE file.

#include "errors.h"
#include <stdarg.h>

void evprintf(const char *format, va_list list)
{
	vfprintf(stderr, format, list);
}

void eprintf(const char *format, ...)
{
	va_list arglist;
	va_start(arglist, format);
	vfprintf(stderr, format, arglist);
	va_end(arglist);
}

void __attribute__((noreturn)) error_exit(const char *format, ...)
{
	va_list arglist;
	va_start(arglist, format);
	vfprintf(stderr, format, arglist);
	fprintf(stderr, "\n");
	va_end(arglist);
	exit(EXIT_FAILURE);
}


/* See LICENSE file for copyright and license details. */
#ifndef UTIL_H
#define UTIL_H

#include <stdint.h>
#include <stdio.h>

#undef LEN
#define LEN(x) (sizeof(x) / sizeof(*(x)))

intmax_t getline(char **, size_t *, FILE *);

#endif /* UTIL_H */

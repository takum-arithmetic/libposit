/* See LICENSE file for copyright and license details. */
#include <errno.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "../posit.h"

#include "util.h"

intmax_t
getline(char **lineptr, size_t *n, FILE *fp)
{
	size_t pos;
	int c;

	if (lineptr == NULL || fp == NULL || n == NULL) {
		errno = EINVAL;
		return -1;
	}

	if ((c = getc(fp)) == EOF) {
		return -1;
	}

	if (*lineptr == NULL) {
		if ((*lineptr = malloc(BUFSIZ)) == NULL) {
			return -1;
		}
		*n = BUFSIZ;
	}

	pos = 0;
	while (c != EOF) {
		if (pos + 1 >= *n) {
			size_t new_size;
			char *new_ptr;

			if ((new_size = *n + (*n >> 2)) < BUFSIZ) {
				new_size = BUFSIZ;
			}
			if ((new_ptr = realloc(*lineptr, new_size)) == NULL) {
				return -1;
			}
			*n = new_size;
			*lineptr = new_ptr;
		}

		((unsigned char *)(*lineptr))[pos++] = c;
		if (c == '\n') {
			break;
		} else {
			c = getc(fp);
		}
	}

	(*lineptr)[pos] = '\0';

	return pos;
}

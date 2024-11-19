/* See LICENSE file for copyright and license details. */
#ifndef UTIL_H
#define UTIL_H

#include "../posit.h"

#include <stddef.h>
#include <stdint.h>

#undef MIN
#define MIN(x, y) ((x) < (y) ? (x) : (y))
#undef MAX
#define MAX(x, y) ((x) > (y) ? (x) : (y))
#undef LEN
#define LEN(x) (sizeof(x) / sizeof(*(x)))

#define LB_E 1.4426950408889634073599246810018921374266L
#define LG_E 0.4342944819032518276511289189166050822944L
#define PI   3.1415926535897932384626433832795028841972L

enum posit_type {
	POSIT8,
	POSIT16,
	POSIT32,
	POSIT64,
	POSIT_LOG8,
	POSIT_LOG16,
	POSIT_LOG32,
	POSIT_LOG64,
};

struct posit_type_parameters {
	const char *name;
	size_t n;
	int64_t nar;
	int64_t positive_minimum;
	int64_t positive_maximum;
	uint64_t count;
	long double (*int64_posit_to_extended_float)(int64_t);
	int64_t (*int64_posit_from_extended_float)(long double);
};

enum unit_test_block_type {
	UNIT_TEST_BLOCK_TYPE_ROUNDTRIP,         /* roundtrip conversion */
	UNIT_TEST_BLOCK_TYPE_POSIT_INT64_POSIT, /* (posit, int) → posit */
	UNIT_TEST_BLOCK_TYPE_POSIT_POSIT,       /* posit → posit */
	UNIT_TEST_BLOCK_TYPE_POSIT_POSIT_POSIT, /* (posit, posit) → posit */
	UNIT_TEST_BLOCK_TYPE_POSIT_UINT8,       /* posit → posit */
};

struct unit_test_block {
	enum unit_test_block_type type;
	const char *function_name;

	union {
		struct {
			posit8 (*posit8_function)(posit8);
			posit16 (*posit16_function)(posit16);
			posit32 (*posit32_function)(posit32);
			posit64 (*posit64_function)(posit64);
			posit_log8 (*posit_log8_function)(posit_log8);
			posit_log16 (*posit_log16_function)(posit_log16);
			posit_log32 (*posit_log32_function)(posit_log32);
			posit_log64 (*posit_log64_function)(posit_log64);
		} roundtrip;

		struct {
			long double (*reference_function)(long double, int64_t);
			posit8 (*posit8_function)(posit8, int64_t);
			posit16 (*posit16_function)(posit16, int64_t);
			posit32 (*posit32_function)(posit32, int64_t);
			posit64 (*posit64_function)(posit64, int64_t);
			posit_log8 (*posit_log8_function)(posit_log8, int64_t);
			posit_log16 (*posit_log16_function)(posit_log16,
			                                    int64_t);
			posit_log32 (*posit_log32_function)(posit_log32,
			                                    int64_t);
			posit_log64 (*posit_log64_function)(posit_log64,
			                                    int64_t);
			const int64_t *integer_test_cases;
			size_t integer_test_case_count;
		} posit_int64_posit;

		struct {
			long double (*reference_function)(long double);
			posit8 (*posit8_function)(posit8);
			posit16 (*posit16_function)(posit16);
			posit32 (*posit32_function)(posit32);
			posit64 (*posit64_function)(posit64);
			posit_log8 (*posit_log8_function)(posit_log8);
			posit_log16 (*posit_log16_function)(posit_log16);
			posit_log32 (*posit_log32_function)(posit_log32);
			posit_log64 (*posit_log64_function)(posit_log64);
		} posit_posit;

		struct {
			long double (*reference_function)(long double,
			                                  long double);
			posit8 (*posit8_function)(posit8, posit8);
			posit16 (*posit16_function)(posit16, posit16);
			posit32 (*posit32_function)(posit32, posit32);
			posit64 (*posit64_function)(posit64, posit64);
			posit_log8 (*posit_log8_function)(posit_log8,
			                                  posit_log8);
			posit_log16 (*posit_log16_function)(posit_log16,
			                                    posit_log16);
			posit_log32 (*posit_log32_function)(posit_log32,
			                                    posit_log32);
			posit_log64 (*posit_log64_function)(posit_log64,
			                                    posit_log64);
		} posit_posit_posit;

		struct {
			uint8_t (*reference_function)(long double,
			                              enum posit_type);
			uint8_t (*posit8_function)(posit8);
			uint8_t (*posit16_function)(posit16);
			uint8_t (*posit32_function)(posit32);
			uint8_t (*posit64_function)(posit64);
			uint8_t (*posit_log8_function)(posit_log8);
			uint8_t (*posit_log16_function)(posit_log16);
			uint8_t (*posit_log32_function)(posit_log32);
			uint8_t (*posit_log64_function)(posit_log64);
		} posit_uint8;
	} data;
};

/* type punning unions */
union util_posit8_union {
	int8_t value;
	uint8_t bits;
};

union util_posit16_union {
	int16_t value;
	uint16_t bits;
};

union util_posit32_union {
	int32_t value;
	uint32_t bits;
};

union util_posit64_union {
	int64_t value;
	uint64_t bits;
};

extern char *argv0;
extern const struct posit_type_parameters posit_type_parameters[];

int next_sample(int64_t *, enum unit_test_block_type, enum posit_type);
int run_unit_test_block(const struct unit_test_block *);

#endif

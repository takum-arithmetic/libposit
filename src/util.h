/* See LICENSE file for copyright and license details. */
#ifndef UTIL_H
#define UTIL_H

#include "../posit.h"

#define LB_E 1.4426950408889634073599246810018921374266L
#define LG_E 0.4342944819032518276511289189166050822944L
#define PI   3.1415926535897932384626433832795028841972L

#undef MIN
#define MIN(x, y) ((x) < (y) ? (x) : (y))
#undef MAX
#define MAX(x, y) ((x) > (y) ? (x) : (y))
#undef LEN
#define LEN(x) (sizeof(x) / sizeof(*(x)))

/*
 * Even though just in regard to the number of significand digits we could
 * use float32 for both posit_log8 and posit_log16, float32 has insufficient
 * dynamic range in both cases.
 */
#define UTIL_UNARY_FLOAT_POSIT_WRAPPER(NAME, FLOAT_FUNCTION,                   \
                                       RESULT_FIXER_MACRO)                     \
	posit8 posit8_##NAME(posit8 t)                                         \
	{                                                                      \
		double arg = posit8_to_float64(t), res = FLOAT_FUNCTION(arg);  \
                                                                               \
		return posit8_from_float64(RESULT_FIXER_MACRO(arg, res));      \
	}                                                                      \
                                                                               \
	posit16 posit16_##NAME(posit16 t)                                      \
	{                                                                      \
		double arg = posit16_to_float64(t), res = FLOAT_FUNCTION(arg); \
                                                                               \
		return posit16_from_float64(RESULT_FIXER_MACRO(arg, res));     \
	}                                                                      \
                                                                               \
	posit32 posit32_##NAME(posit32 t)                                      \
	{                                                                      \
		double arg = posit32_to_float64(t), res = FLOAT_FUNCTION(arg); \
                                                                               \
		return posit32_from_float64(RESULT_FIXER_MACRO(arg, res));     \
	}                                                                      \
                                                                               \
	posit64 posit64_##NAME(posit64 t)                                      \
	{                                                                      \
		long double arg = posit64_to_extended_float(t),                \
			    res = FLOAT_FUNCTION##l(arg);                      \
                                                                               \
		return posit64_from_extended_float(                            \
			RESULT_FIXER_MACRO(arg, res));                         \
	}

#define UTIL_UNARY_FLOAT_POSIT_LOG_WRAPPER(NAME, FLOAT_FUNCTION,               \
                                           RESULT_FIXER_MACRO)                 \
	posit_log8 posit_log8_##NAME(posit_log8 t)                             \
	{                                                                      \
		long double arg = posit_log8_to_extended_float(t),             \
			    res = FLOAT_FUNCTION##l(arg);                      \
                                                                               \
		return posit_log8_from_extended_float(                         \
			RESULT_FIXER_MACRO(arg, res));                         \
	}                                                                      \
                                                                               \
	posit_log16 posit_log16_##NAME(posit_log16 t)                          \
	{                                                                      \
		long double arg = posit_log16_to_extended_float(t),            \
			    res = FLOAT_FUNCTION##l(arg);                      \
                                                                               \
		return posit_log16_from_extended_float(                        \
			RESULT_FIXER_MACRO(arg, res));                         \
	}                                                                      \
                                                                               \
	posit_log32 posit_log32_##NAME(posit_log32 t)                          \
	{                                                                      \
		long double arg = posit_log32_to_extended_float(t),            \
			    res = FLOAT_FUNCTION##l(arg);                      \
                                                                               \
		return posit_log32_from_extended_float(                        \
			RESULT_FIXER_MACRO(arg, res));                         \
	}                                                                      \
                                                                               \
	posit_log64 posit_log64_##NAME(posit_log64 t)                          \
	{                                                                      \
		long double arg = posit_log64_to_extended_float(t),            \
			    res = FLOAT_FUNCTION##l(arg);                      \
                                                                               \
		return posit_log64_from_extended_float(                        \
			RESULT_FIXER_MACRO(arg, res));                         \
	}

#define UTIL_BINARY_FLOAT_POSIT_WRAPPER(NAME, FLOAT_FUNCTION,                  \
                                        RESULT_FIXER_MACRO)                    \
	posit8 posit8_##NAME(posit8 a, posit8 b)                               \
	{                                                                      \
		double fa, fb, res;                                            \
                                                                               \
		fa = posit8_to_float64(a);                                     \
		fb = posit8_to_float64(b);                                     \
		res = FLOAT_FUNCTION(fa, fb);                                  \
                                                                               \
		return posit8_from_float64(RESULT_FIXER_MACRO(fa, fb, res));   \
	}                                                                      \
                                                                               \
	posit16 posit16_##NAME(posit16 a, posit16 b)                           \
	{                                                                      \
		double fa, fb, res;                                            \
                                                                               \
		fa = posit16_to_float64(a);                                    \
		fb = posit16_to_float64(b);                                    \
		res = FLOAT_FUNCTION(fa, fb);                                  \
                                                                               \
		return posit16_from_float64(RESULT_FIXER_MACRO(fa, fb, res));  \
	}                                                                      \
                                                                               \
	posit32 posit32_##NAME(posit32 a, posit32 b)                           \
	{                                                                      \
		double fa, fb, res;                                            \
                                                                               \
		fa = posit32_to_float64(a);                                    \
		fb = posit32_to_float64(b);                                    \
		res = FLOAT_FUNCTION(fa, fb);                                  \
                                                                               \
		return posit32_from_float64(RESULT_FIXER_MACRO(fa, fb, res));  \
	}                                                                      \
                                                                               \
	posit64 posit64_##NAME(posit64 a, posit64 b)                           \
	{                                                                      \
		long double fa, fb, res;                                       \
                                                                               \
		fa = posit64_to_extended_float(a);                             \
		fb = posit64_to_extended_float(b);                             \
		res = FLOAT_FUNCTION##l(fa, fb);                               \
                                                                               \
		return posit64_from_extended_float(                            \
			RESULT_FIXER_MACRO(fa, fb, res));                      \
	}

#define UTIL_BINARY_FLOAT_POSIT_LOG_WRAPPER(NAME, FLOAT_FUNCTION,              \
                                            RESULT_FIXER_MACRO)                \
	posit_log8 posit_log8_##NAME(posit_log8 a, posit_log8 b)               \
	{                                                                      \
		long double fa, fb, res;                                       \
                                                                               \
		fa = posit_log8_to_extended_float(a);                          \
		fb = posit_log8_to_extended_float(b);                          \
		res = FLOAT_FUNCTION##l(fa, fb);                               \
                                                                               \
		return posit_log8_from_extended_float(                         \
			RESULT_FIXER_MACRO(fa, fb, res));                      \
	}                                                                      \
                                                                               \
	posit_log16 posit_log16_##NAME(posit_log16 a, posit_log16 b)           \
	{                                                                      \
		long double fa, fb, res;                                       \
                                                                               \
		fa = posit_log16_to_extended_float(a);                         \
		fb = posit_log16_to_extended_float(b);                         \
		res = FLOAT_FUNCTION##l(fa, fb);                               \
                                                                               \
		return posit_log16_from_extended_float(                        \
			RESULT_FIXER_MACRO(fa, fb, res));                      \
	}                                                                      \
                                                                               \
	posit_log32 posit_log32_##NAME(posit_log32 a, posit_log32 b)           \
	{                                                                      \
		long double fa, fb, res;                                       \
                                                                               \
		fa = posit_log32_to_extended_float(a);                         \
		fb = posit_log32_to_extended_float(b);                         \
		res = FLOAT_FUNCTION##l(fa, fb);                               \
                                                                               \
		return posit_log32_from_extended_float(                        \
			RESULT_FIXER_MACRO(fa, fb, res));                      \
	}                                                                      \
                                                                               \
	posit_log64 posit_log64_##NAME(posit_log64 a, posit_log64 b)           \
	{                                                                      \
		long double fa, fb, res;                                       \
                                                                               \
		fa = posit_log64_to_extended_float(a);                         \
		fb = posit_log64_to_extended_float(b);                         \
		res = FLOAT_FUNCTION##l(fa, fb);                               \
                                                                               \
		return posit_log64_from_extended_float(                        \
			RESULT_FIXER_MACRO(fa, fb, res));                      \
	}

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

uint8_t util_round_uint8_to_number_of_bits(uint8_t, uint8_t);
uint16_t util_round_uint16_to_number_of_bits(uint16_t, uint8_t);
uint32_t util_round_uint32_to_number_of_bits(uint32_t, uint8_t);
uint64_t util_round_uint64_to_number_of_bits(uint64_t, uint8_t);

uint8_t util_clz8(uint8_t);
uint8_t util_clz16(uint16_t);
uint8_t util_clz32(uint32_t);
uint8_t util_clz64(uint64_t);

#endif

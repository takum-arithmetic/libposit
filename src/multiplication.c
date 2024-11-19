/* See LICENSE file for copyright and license details. */
#include <math.h>

#include "../posit.h"

#include "codec.h"
#include "util.h"

/* no need to fix the result */
#define RESULT_FIXER_MACRO(a, b, res) (res)

static double
multiplication(double a, double b)
{
	return a * b;
}

static long double
multiplicationl(long double a, long double b)
{
	return a * b;
}

UTIL_BINARY_FLOAT_POSIT_WRAPPER(multiplication, multiplication,
                                RESULT_FIXER_MACRO)

/*
 * As codec_posit*_to_l() returns -Inf for 0 and
 * NaN for NaR both cases are conveniently covered
 * without special checks as a + (-Inf) = -Inf
 * for regular a and a = -Inf, and a + NaN = NaN in
 * all cases.
 */
posit_log8
posit_log8_multiplication(posit_log8 a, posit_log8 b)
{
	return codec_posit_log8_from_s_and_l((a > 0) != (b > 0),
	                                     codec_posit_log8_to_l(a) +
	                                             codec_posit_log8_to_l(b));
}

posit_log16
posit_log16_multiplication(posit_log16 a, posit_log16 b)
{
	return codec_posit_log16_from_s_and_l(
		(a > 0) != (b > 0),
		codec_posit_log16_to_l(a) + codec_posit_log16_to_l(b));
}

posit_log32
posit_log32_multiplication(posit_log32 a, posit_log32 b)
{
	return codec_posit_log32_from_s_and_l(
		(a > 0) != (b > 0),
		codec_posit_log32_to_l(a) + codec_posit_log32_to_l(b));
}

posit_log64
posit_log64_multiplication(posit_log64 a, posit_log64 b)
{
	return codec_posit_log64_from_s_and_l(
		(a > 0) != (b > 0),
		codec_posit_log64_to_l(a) + codec_posit_log64_to_l(b));
}

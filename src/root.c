/* See LICENSE file for copyright and license details. */
#include <float.h>
#include <math.h>
#include <stdint.h>

#include "../posit.h"

#include "codec.h"
#include "util.h"

posit8
posit8_root(posit8 t, int64_t n)
{
	long double f, res;

	if (n == 0 || (t < 0 && n % 2 == 0)) {
		return POSIT8_NAR;
	}

	f = posit8_to_extended_float(t);
	res = powl(f, 1.0l / (long double)n);

	if (res == 0.0l && t != 0) {
		res = (t < 0 && n % 2 != 0) ? -DBL_MIN : DBL_MIN;
	}

	return posit8_from_extended_float(res);
}

posit16
posit16_root(posit16 t, int64_t n)
{
	long double f, res;

	if (n == 0 || (t < 0 && n % 2 == 0)) {
		return POSIT16_NAR;
	}

	f = posit16_to_extended_float(t);
	res = powl(f, 1.0l / (long double)n);

	if (res == 0.0l && t != 0) {
		res = (t < 0 && n % 2 != 0) ? -DBL_MIN : DBL_MIN;
	}

	return posit16_from_extended_float(res);
}

posit32
posit32_root(posit32 t, int64_t n)
{
	long double f, res;

	if (n == 0 || (t < 0 && n % 2 == 0)) {
		return POSIT32_NAR;
	}

	f = posit32_to_extended_float(t);
	res = powl(f, 1.0l / (long double)n);

	if (res == 0.0l && t != 0) {
		res = (t < 0 && n % 2 != 0) ? -DBL_MIN : DBL_MIN;
	}

	return posit32_from_extended_float(res);
}

posit64
posit64_root(posit64 t, int64_t n)
{
	long double f, res;

	if (n == 0 || (t < 0 && n % 2 == 0)) {
		return POSIT64_NAR;
	}

	f = posit64_to_extended_float(t);
	res = powl(f, 1.0l / (long double)n);

	if (res == 0.0l && t != 0) {
		res = (t < 0 && n % 2 != 0) ? -DBL_MIN : DBL_MIN;
	}

	return posit64_from_extended_float(res);
}

/*
 * The case NaR is automatically covered given NaN/n=NaN holds for any n.
 *
 * We use a 64 bit integer as a possible base root as even the smallest
 * positive l (which is 2^(-n+5)) divided by the largest signed 64
 * bit integer (2^63-1) is still within the dynamic range of float32,
 * let alone float64, which means that there will never be underflows
 * in terms of l. Of course the final posit representation may underflow
 * to 1.0 in the process.
 * Using different integer types for each posit bit string length would
 * serve no purpose other than to complicate the API. We allow signed n
 * as there is no reason not to.
 */
posit_log8
posit_log8_root(posit_log8 t, int64_t n)
{
	if (n == 0 || (t < 0 && n % 2 == 0) || (t == 0 && n < 0)) {
		return POSIT_LOG8_NAR;
	} else {
		return codec_posit_log8_from_s_and_l(
			(t < 0), codec_posit_log8_to_l(t) / n);
	}
}

posit_log16
posit_log16_root(posit_log16 t, int64_t n)
{
	if (n == 0 || (t < 0 && n % 2 == 0) || (t == 0 && n < 0)) {
		return POSIT_LOG16_NAR;
	} else {
		return codec_posit_log16_from_s_and_l(
			(t < 0), codec_posit_log16_to_l(t) / n);
	}
}

posit_log32
posit_log32_root(posit_log32 t, int64_t n)
{
	if (n == 0 || (t < 0 && n % 2 == 0) || (t == 0 && n < 0)) {
		return POSIT_LOG32_NAR;
	} else {
		return codec_posit_log32_from_s_and_l(
			(t < 0), codec_posit_log32_to_l(t) / n);
	}
}

posit_log64
posit_log64_root(posit_log64 t, int64_t n)
{
	if (n == 0 || (t < 0 && n % 2 == 0) || (t == 0 && n < 0)) {
		return POSIT_LOG64_NAR;
	} else {
		return codec_posit_log64_from_s_and_l(
			(t < 0), codec_posit_log64_to_l(t) / n);
	}
}
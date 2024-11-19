/* See LICENSE file for copyright and license details. */
#include <math.h>

#include "../posit.h"

#include "codec.h"
#include "util.h"

/* no need to fix the result */
#define RESULT_FIXER_MACRO(f, res) (res)

UTIL_UNARY_FLOAT_POSIT_WRAPPER(square_root, sqrt, RESULT_FIXER_MACRO)

/*
 * The case NaR is automatically covered given
 * NaN/2=NaN holds.
 */
posit_log8
posit_log8_square_root(posit_log8 t)
{
	if (t < 0) {
		return POSIT_LOG8_NAR;
	} else {
		return codec_posit_log8_from_s_and_l(
			0, ldexpf(codec_posit_log8_to_l(t), -1));
	}
}

posit_log16
posit_log16_square_root(posit_log16 t)
{
	if (t < 0) {
		return POSIT_LOG16_NAR;
	} else {
		return codec_posit_log16_from_s_and_l(
			0, ldexpf(codec_posit_log16_to_l(t), -1));
	}
}

posit_log32
posit_log32_square_root(posit_log32 t)
{
	if (t < 0) {
		return POSIT_LOG32_NAR;
	} else {
		return codec_posit_log32_from_s_and_l(
			0, ldexp(codec_posit_log32_to_l(t), -1));
	}
}

posit_log64
posit_log64_square_root(posit_log64 t)
{
	if (t < 0) {
		return POSIT_LOG64_NAR;
	} else {
		return codec_posit_log64_from_s_and_l(
			0, ldexpl(codec_posit_log64_to_l(t), -1));
	}
}

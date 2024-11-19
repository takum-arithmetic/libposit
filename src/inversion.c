/* See LICENSE file for copyright and license details. */
#include "../posit.h"

#include "util.h"

/* no need to fix the result, as inv(0)=inf yields NaR without our doing */
#define RESULT_FIXER_MACRO(arg, res) (res)

static long double
inversionl(long double f)
{
	return 1.0l / f;
}

static double
inversion(double f)
{
	return (double)inversionl((long double)f);
}

UTIL_UNARY_FLOAT_POSIT_WRAPPER(inversion, inversion, RESULT_FIXER_MACRO)

posit_log8
posit_log8_inversion(posit_log8 t)
{
	union util_posit8_union out = {
		.value = t,
	};

	out.bits = (out.bits ^ UINT8_C(0x7f)) + 1;

	return (t == POSIT_LOG8_NAR) ? POSIT_LOG8_NAR : out.value;
}

posit_log16
posit_log16_inversion(posit_log16 t)
{
	union util_posit16_union out = {
		.value = t,
	};

	out.bits = (out.bits ^ UINT16_C(0x7fff)) + 1;

	return (t == POSIT_LOG16_NAR) ? POSIT_LOG16_NAR : out.value;
}

posit_log32
posit_log32_inversion(posit_log32 t)
{
	union util_posit32_union out = {
		.value = t,
	};

	out.bits = (out.bits ^ UINT32_C(0x7fffffff)) + 1;

	return (t == POSIT_LOG32_NAR) ? POSIT_LOG32_NAR : out.value;
}

posit_log64
posit_log64_inversion(posit_log64 t)
{
	union util_posit64_union out = {
		.value = t,
	};

	out.bits = (out.bits ^ UINT64_C(0x7fffffffffffffff)) + 1;

	return (t == POSIT_LOG64_NAR) ? POSIT_LOG64_NAR : out.value;
}

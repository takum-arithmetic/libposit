/* See LICENSE file for copyright and license details. */
#include <math.h>
#include <stdint.h>
#include <stdio.h>

#include "../posit.h"
#include "util.h"

posit8
posit8_conversion_float64_roundtrip(posit8 t)
{
	return posit8_from_float64(posit8_to_float64(t));
}

posit16
posit16_conversion_float64_roundtrip(posit16 t)
{
	return posit16_from_float64(posit16_to_float64(t));
}

posit32
posit32_conversion_float64_roundtrip(posit32 t)
{
	return posit32_from_float64(posit32_to_float64(t));
}

posit_log8
posit_log8_conversion_float64_roundtrip(posit_log8 t)
{
	return posit_log8_from_float64(posit_log8_to_float64(t));
}

posit_log16
posit_log16_conversion_float64_roundtrip(posit_log16 t)
{
	return posit_log16_from_float64(posit_log16_to_float64(t));
}

posit_log32
posit_log32_conversion_float64_roundtrip(posit_log32 t)
{
	return posit_log32_from_float64(posit_log32_to_float64(t));
}

static const struct unit_test_block conversion_float64_utb = {
	.type = UNIT_TEST_BLOCK_TYPE_ROUNDTRIP,
	.function_name = "to_float64/from_float64",
	.data.roundtrip = {
		.posit8_function    = posit8_conversion_float64_roundtrip,
		.posit16_function   = posit16_conversion_float64_roundtrip,
		.posit32_function   = posit32_conversion_float64_roundtrip,
		.posit64_function   = NULL,
		.posit_log8_function    = posit_log8_conversion_float64_roundtrip,
		.posit_log16_function   = posit_log16_conversion_float64_roundtrip,
		.posit_log32_function   = posit_log32_conversion_float64_roundtrip,
		.posit_log64_function   = NULL,
	},
};

posit8
posit8_conversion_extended_float_roundtrip(posit8 t)
{
	return posit8_from_extended_float(posit8_to_extended_float(t));
}

posit16
posit16_conversion_extended_float_roundtrip(posit16 t)
{
	return posit16_from_extended_float(posit16_to_extended_float(t));
}

posit32
posit32_conversion_extended_float_roundtrip(posit32 t)
{
	return posit32_from_extended_float(posit32_to_extended_float(t));
}

posit64
posit64_conversion_extended_float_roundtrip(posit64 t)
{
	return posit64_from_extended_float(posit64_to_extended_float(t));
}

posit_log8
posit_log8_conversion_extended_float_roundtrip(posit_log8 t)
{
	return posit_log8_from_extended_float(posit_log8_to_extended_float(t));
}

posit_log16
posit_log16_conversion_extended_float_roundtrip(posit_log16 t)
{
	return posit_log16_from_extended_float(
		posit_log16_to_extended_float(t));
}

posit_log32
posit_log32_conversion_extended_float_roundtrip(posit_log32 t)
{
	return posit_log32_from_extended_float(
		posit_log32_to_extended_float(t));
}

posit_log64
posit_log64_conversion_extended_float_roundtrip(posit_log64 t)
{
	return posit_log64_from_extended_float(
		posit_log64_to_extended_float(t));
}

static const struct unit_test_block conversion_extended_float_utb = {
	.type = UNIT_TEST_BLOCK_TYPE_ROUNDTRIP,
	.function_name = "to_extended_float/from_extended_float",
	.data.roundtrip = {
		.posit8_function    = posit8_conversion_extended_float_roundtrip,
		.posit16_function   = posit16_conversion_extended_float_roundtrip,
		.posit32_function   = posit32_conversion_extended_float_roundtrip,
		.posit64_function   = posit64_conversion_extended_float_roundtrip,
		.posit_log8_function    = posit_log8_conversion_extended_float_roundtrip,
		.posit_log16_function   = posit_log16_conversion_extended_float_roundtrip,
		.posit_log32_function   = posit_log32_conversion_extended_float_roundtrip,
		.posit_log64_function   = posit_log64_conversion_extended_float_roundtrip,
	},
};

posit64
float64_conversion_posit64_roundtrip(posit64 t)
{
	union {
		posit64 posit64_value;
		double float64_value;
	} helper_union = {
		.posit64_value = t,
	};

	double f;

	/* Interpretthe input as a float64 */
	f = helper_union.float64_value;

	/*
	 * Check if it is real and in the range of numbers representable
	 * with posit64
	 */
	if (!isfinite(f) || fabs(f) >= exp2(248) || fabs(f) <= exp2(-248)) {
		/* skip this test case */
		return t;
	} else {
		/*
		 * Convert to a posit64 and back and reinterpret
		 * the result as a posit64 that is returned as
		 * output
		 */
		helper_union.float64_value =
			posit64_to_float64(posit64_from_float64(f));

		return helper_union.posit64_value;
	}
}

/*static const struct unit_test_block conversion_float64_full_utb = {
        .type = UNIT_TEST_BLOCK_TYPE_ROUNDTRIP,
        .function_name = "from_float64/to_float64",
        .data.roundtrip = {
                .posit8_function    = NULL,
                .posit16_function   = NULL,
                .posit32_function   = NULL,
                .posit64_function   = float64_conversion_posit64_roundtrip,
                .posit_log8_function    = NULL,
                .posit_log16_function   = NULL,
                .posit_log32_function   = NULL,
                .posit_log64_function   = NULL,
        },
};*/

int
main(int argc, char *argv[])
{
	(void)argc;
	argv0 = argv[0];

	return run_unit_test_block(&conversion_float64_utb) +
	       run_unit_test_block(&conversion_extended_float_utb) /* +
	        run_unit_test_block(&conversion_float64_full_utb)*/
		;
}

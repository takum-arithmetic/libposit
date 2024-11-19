/* See LICENSE file for copyright and license details. */
#include "../posit.h"
#include "util.h"

#include <math.h>

long double
ten_raised_reference(long double a)
{
	return powl(10.0L, a);
}

static const struct unit_test_block ten_raised_utb = {
	.type = UNIT_TEST_BLOCK_TYPE_POSIT_POSIT,
	.function_name = "10_raised",
	.data.posit_posit = {
		.reference_function = ten_raised_reference,
		.posit8_function    = posit8_10_raised,
		.posit16_function   = posit16_10_raised,
		.posit32_function   = posit32_10_raised,
		.posit64_function   = posit64_10_raised,
		.posit_log8_function    = posit_log8_10_raised,
		.posit_log16_function   = posit_log16_10_raised,
		.posit_log32_function   = posit_log32_10_raised,
		.posit_log64_function   = posit_log64_10_raised,
	},
};

long double
ten_raised_minus_1_reference(long double a)
{
	return powl(10.0L, a) - 1.0L;
}

static const struct unit_test_block ten_raised_minus_1_utb = {
	.type = UNIT_TEST_BLOCK_TYPE_POSIT_POSIT,
	.function_name = "10_raised_minus_1",
	.data.posit_posit = {
		.reference_function = ten_raised_minus_1_reference,
		.posit8_function    = posit8_10_raised_minus_1,
		.posit16_function   = posit16_10_raised_minus_1,
		.posit32_function   = posit32_10_raised_minus_1,
		.posit64_function   = posit64_10_raised_minus_1,
		.posit_log8_function    = posit_log8_10_raised_minus_1,
		.posit_log16_function   = posit_log16_10_raised_minus_1,
		.posit_log32_function   = posit_log32_10_raised_minus_1,
		.posit_log64_function   = posit_log64_10_raised_minus_1,
	},
};

int
main(int argc, char *argv[])
{
	(void)argc;
	argv0 = argv[0];

	return run_unit_test_block(&ten_raised_utb) +
	       run_unit_test_block(&ten_raised_minus_1_utb);
}

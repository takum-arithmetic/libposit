/* See LICENSE file for copyright and license details. */
#include "../posit.h"
#include "util.h"

#include <math.h>

long double
arctan2_reference(long double a, long double b)
{
	return atan2l(a, b);
}

static const struct unit_test_block arctan2_utb = {
	.type = UNIT_TEST_BLOCK_TYPE_POSIT_POSIT_POSIT,
	.function_name = "arctan2",
	.data.posit_posit_posit = {
		.reference_function = arctan2_reference,
		.posit8_function    = posit8_arctan2,
		.posit16_function   = posit16_arctan2,
		.posit32_function   = posit32_arctan2,
		.posit64_function   = posit64_arctan2,
		.posit_log8_function    = posit_log8_arctan2,
		.posit_log16_function   = posit_log16_arctan2,
		.posit_log32_function   = posit_log32_arctan2,
		.posit_log64_function   = posit_log64_arctan2,
	},
};

long double
arctan2_over_pi_reference(long double a, long double b)
{
	return atan2l(a, b) / PI;
}

static const struct unit_test_block arctan2_over_pi_utb = {
	.type = UNIT_TEST_BLOCK_TYPE_POSIT_POSIT_POSIT,
	.function_name = "arctan2_over_pi",
	.data.posit_posit_posit = {
		.reference_function = arctan2_over_pi_reference,
		.posit8_function    = posit8_arctan2_over_pi,
		.posit16_function   = posit16_arctan2_over_pi,
		.posit32_function   = posit32_arctan2_over_pi,
		.posit64_function   = posit64_arctan2_over_pi,
		.posit_log8_function    = posit_log8_arctan2_over_pi,
		.posit_log16_function   = posit_log16_arctan2_over_pi,
		.posit_log32_function   = posit_log32_arctan2_over_pi,
		.posit_log64_function   = posit_log64_arctan2_over_pi,
	},
};

int
main(int argc, char *argv[])
{
	(void)argc;
	argv0 = argv[0];

	return run_unit_test_block(&arctan2_utb) +
	       run_unit_test_block(&arctan2_over_pi_utb);
}

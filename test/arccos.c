/* See LICENSE file for copyright and license details. */
#include "../posit.h"
#include "util.h"

#include <math.h>

long double
arccos_reference(long double a)
{
	return acosl(a);
}

static const struct unit_test_block arccos_utb = {
	.type = UNIT_TEST_BLOCK_TYPE_POSIT_POSIT,
	.function_name = "arccos",
	.data.posit_posit = {
		.reference_function = arccos_reference,
		.posit8_function    = posit8_arccos,
		.posit16_function   = posit16_arccos,
		.posit32_function   = posit32_arccos,
		.posit64_function   = posit64_arccos,
		.posit_log8_function    = posit_log8_arccos,
		.posit_log16_function   = posit_log16_arccos,
		.posit_log32_function   = posit_log32_arccos,
		.posit_log64_function   = posit_log64_arccos,
	},
};

long double
arccos_over_pi_reference(long double a)
{
	return acosl(a) / PI;
}

static const struct unit_test_block arccos_over_pi_utb = {
	.type = UNIT_TEST_BLOCK_TYPE_POSIT_POSIT,
	.function_name = "arccos_over_pi",
	.data.posit_posit = {
		.reference_function = arccos_over_pi_reference,
		.posit8_function    = posit8_arccos_over_pi,
		.posit16_function   = posit16_arccos_over_pi,
		.posit32_function   = posit32_arccos_over_pi,
		.posit64_function   = posit64_arccos_over_pi,
		.posit_log8_function    = posit_log8_arccos_over_pi,
		.posit_log16_function   = posit_log16_arccos_over_pi,
		.posit_log32_function   = posit_log32_arccos_over_pi,
		.posit_log64_function   = posit_log64_arccos_over_pi,
	},
};

int
main(int argc, char *argv[])
{
	(void)argc;
	argv0 = argv[0];

	return run_unit_test_block(&arccos_utb) +
	       run_unit_test_block(&arccos_over_pi_utb);
}

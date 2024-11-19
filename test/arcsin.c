/* See LICENSE file for copyright and license details. */
#include "../posit.h"
#include "util.h"

#include <math.h>

long double
arcsin_reference(long double a)
{
	return asinl(a);
}

static const struct unit_test_block arcsin_utb = {
	.type = UNIT_TEST_BLOCK_TYPE_POSIT_POSIT,
	.function_name = "arcsin",
	.data.posit_posit = {
		.reference_function = arcsin_reference,
		.posit8_function    = posit8_arcsin,
		.posit16_function   = posit16_arcsin,
		.posit32_function   = posit32_arcsin,
		.posit64_function   = posit64_arcsin,
		.posit_log8_function    = posit_log8_arcsin,
		.posit_log16_function   = posit_log16_arcsin,
		.posit_log32_function   = posit_log32_arcsin,
		.posit_log64_function   = posit_log64_arcsin,
	},
};

long double
arcsin_over_pi_reference(long double a)
{
	return asinl(a) / PI;
}

static const struct unit_test_block arcsin_over_pi_utb = {
	.type = UNIT_TEST_BLOCK_TYPE_POSIT_POSIT,
	.function_name = "arcsin_over_pi",
	.data.posit_posit = {
		.reference_function = arcsin_over_pi_reference,
		.posit8_function    = posit8_arcsin_over_pi,
		.posit16_function   = posit16_arcsin_over_pi,
		.posit32_function   = posit32_arcsin_over_pi,
		.posit64_function   = posit64_arcsin_over_pi,
		.posit_log8_function    = posit_log8_arcsin_over_pi,
		.posit_log16_function   = posit_log16_arcsin_over_pi,
		.posit_log32_function   = posit_log32_arcsin_over_pi,
		.posit_log64_function   = posit_log64_arcsin_over_pi,
	},
};

int
main(int argc, char *argv[])
{
	(void)argc;
	argv0 = argv[0];

	return run_unit_test_block(&arcsin_utb) +
	       run_unit_test_block(&arcsin_over_pi_utb);
}

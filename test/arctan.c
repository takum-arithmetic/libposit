/* See LICENSE file for copyright and license details. */
#include "../posit.h"
#include "util.h"

#include <math.h>

long double
arctan_reference(long double a)
{
	return atanl(a);
}

static const struct unit_test_block arctan_utb = {
	.type = UNIT_TEST_BLOCK_TYPE_POSIT_POSIT,
	.function_name = "arctan",
	.data.posit_posit = {
		.reference_function = arctan_reference,
		.posit8_function    = posit8_arctan,
		.posit16_function   = posit16_arctan,
		.posit32_function   = posit32_arctan,
		.posit64_function   = posit64_arctan,
		.posit_log8_function    = posit_log8_arctan,
		.posit_log16_function   = posit_log16_arctan,
		.posit_log32_function   = posit_log32_arctan,
		.posit_log64_function   = posit_log64_arctan,
	},
};

long double
arctan_over_pi_reference(long double a)
{
	return atanl(a) / PI;
}

static const struct unit_test_block arctan_over_pi_utb = {
	.type = UNIT_TEST_BLOCK_TYPE_POSIT_POSIT,
	.function_name = "arctan_over_pi",
	.data.posit_posit = {
		.reference_function = arctan_over_pi_reference,
		.posit8_function    = posit8_arctan_over_pi,
		.posit16_function   = posit16_arctan_over_pi,
		.posit32_function   = posit32_arctan_over_pi,
		.posit64_function   = posit64_arctan_over_pi,
		.posit_log8_function    = posit_log8_arctan_over_pi,
		.posit_log16_function   = posit_log16_arctan_over_pi,
		.posit_log32_function   = posit_log32_arctan_over_pi,
		.posit_log64_function   = posit_log64_arctan_over_pi,
	},
};

int
main(int argc, char *argv[])
{
	(void)argc;
	argv0 = argv[0];

	return run_unit_test_block(&arctan_utb) +
	       run_unit_test_block(&arctan_over_pi_utb);
}

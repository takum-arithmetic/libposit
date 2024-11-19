/* See LICENSE file for copyright and license details. */
#include "../posit.h"
#include "util.h"

#include <math.h>

long double
arccsc_reference(long double a)
{
	return asinl(1.0L / a);
}

static const struct unit_test_block arccsc_utb = {
	.type = UNIT_TEST_BLOCK_TYPE_POSIT_POSIT,
	.function_name = "arccsc",
	.data.posit_posit = {
		.reference_function = arccsc_reference,
		.posit8_function    = posit8_arccsc,
		.posit16_function   = posit16_arccsc,
		.posit32_function   = posit32_arccsc,
		.posit64_function   = posit64_arccsc,
		.posit_log8_function    = posit_log8_arccsc,
		.posit_log16_function   = posit_log16_arccsc,
		.posit_log32_function   = posit_log32_arccsc,
		.posit_log64_function   = posit_log64_arccsc,
	},
};

long double
arccsc_over_pi_reference(long double a)
{
	return asinl(1.0L / a) / PI;
}

static const struct unit_test_block arccsc_over_pi_utb = {
	.type = UNIT_TEST_BLOCK_TYPE_POSIT_POSIT,
	.function_name = "arccsc_over_pi",
	.data.posit_posit = {
		.reference_function = arccsc_over_pi_reference,
		.posit8_function    = posit8_arccsc_over_pi,
		.posit16_function   = posit16_arccsc_over_pi,
		.posit32_function   = posit32_arccsc_over_pi,
		.posit64_function   = posit64_arccsc_over_pi,
		.posit_log8_function    = posit_log8_arccsc_over_pi,
		.posit_log16_function   = posit_log16_arccsc_over_pi,
		.posit_log32_function   = posit_log32_arccsc_over_pi,
		.posit_log64_function   = posit_log64_arccsc_over_pi,
	},
};

int
main(int argc, char *argv[])
{
	(void)argc;
	argv0 = argv[0];

	return run_unit_test_block(&arccsc_utb) +
	       run_unit_test_block(&arccsc_over_pi_utb);
}

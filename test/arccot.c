/* See LICENSE file for copyright and license details. */
#include "../posit.h"
#include "util.h"

#include <math.h>

long double
arccot_reference(long double a)
{
	if (a >= 0.0) {
		return atanl(1.0L / a);
	} else {
		return atanl(1.0L / a) + PI;
	}
}

static const struct unit_test_block arccot_utb = {
	.type = UNIT_TEST_BLOCK_TYPE_POSIT_POSIT,
	.function_name = "arccot",
	.data.posit_posit = {
		.reference_function = arccot_reference,
		.posit8_function    = posit8_arccot,
		.posit16_function   = posit16_arccot,
		.posit32_function   = posit32_arccot,
		.posit64_function   = posit64_arccot,
		.posit_log8_function    = posit_log8_arccot,
		.posit_log16_function   = posit_log16_arccot,
		.posit_log32_function   = posit_log32_arccot,
		.posit_log64_function   = posit_log64_arccot,
	},
};

long double
arccot_over_pi_reference(long double a)
{
	if (a >= 0.0) {
		return atanl(1.0L / a) / PI;
	} else {
		return atanl(1.0L / a) / PI + 1;
	}
}

static const struct unit_test_block arccot_over_pi_utb = {
	.type = UNIT_TEST_BLOCK_TYPE_POSIT_POSIT,
	.function_name = "arccot_over_pi",
	.data.posit_posit = {
		.reference_function = arccot_over_pi_reference,
		.posit8_function    = posit8_arccot_over_pi,
		.posit16_function   = posit16_arccot_over_pi,
		.posit32_function   = posit32_arccot_over_pi,
		.posit64_function   = posit64_arccot_over_pi,
		.posit_log8_function    = posit_log8_arccot_over_pi,
		.posit_log16_function   = posit_log16_arccot_over_pi,
		.posit_log32_function   = posit_log32_arccot_over_pi,
		.posit_log64_function   = posit_log64_arccot_over_pi,
	},
};

int
main(int argc, char *argv[])
{
	(void)argc;
	argv0 = argv[0];

	return run_unit_test_block(&arccot_utb) +
	       run_unit_test_block(&arccot_over_pi_utb);
}

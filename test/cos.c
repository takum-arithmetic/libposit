/* See LICENSE file for copyright and license details. */
#include "../posit.h"
#include "util.h"

#include <math.h>

long double
cos_reference(long double a)
{
	return cosl(a);
}

static const struct unit_test_block cos_utb = {
	.type = UNIT_TEST_BLOCK_TYPE_POSIT_POSIT,
	.function_name = "cos",
	.data.posit_posit = {
		.reference_function = cos_reference,
		.posit8_function    = posit8_cos,
		.posit16_function   = posit16_cos,
		.posit32_function   = posit32_cos,
		.posit64_function   = posit64_cos,
		.posit_log8_function    = posit_log8_cos,
		.posit_log16_function   = posit_log16_cos,
		.posit_log32_function   = posit_log32_cos,
		.posit_log64_function   = posit_log64_cos,
	},
};

long double
cos_pi_times_reference(long double a)
{
	long double a_mod_2;

	a_mod_2 = fmodl(a, 2.0l);

	if (a_mod_2 == 0.0l) {
		return 1.0l;
	} else if (a_mod_2 == 0.5l) {
		return 0.0l;
	} else if (a_mod_2 == 1.0l) {
		return -1.0l;
	} else if (a_mod_2 == 1.5l) {
		return 0.0l;
	} else {
		return cosl(PI * a);
	}
}

static const struct unit_test_block cos_pi_times_utb = {
	.type = UNIT_TEST_BLOCK_TYPE_POSIT_POSIT,
	.function_name = "cos_pi_times",
	.data.posit_posit = {
		.reference_function = cos_pi_times_reference,
		.posit8_function    = posit8_cos_pi_times,
		.posit16_function   = posit16_cos_pi_times,
		.posit32_function   = posit32_cos_pi_times,
		.posit64_function   = posit64_cos_pi_times,
		.posit_log8_function    = posit_log8_cos_pi_times,
		.posit_log16_function   = posit_log16_cos_pi_times,
		.posit_log32_function   = posit_log32_cos_pi_times,
		.posit_log64_function   = posit_log64_cos_pi_times,
	},
};

int
main(int argc, char *argv[])
{
	(void)argc;
	argv0 = argv[0];

	return run_unit_test_block(&cos_utb) +
	       run_unit_test_block(&cos_pi_times_utb);
}

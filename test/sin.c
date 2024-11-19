/* See LICENSE file for copyright and license details. */
#include "../posit.h"
#include "util.h"

#include <math.h>

long double
sin_reference(long double a)
{
	return sinl(a);
}

static const struct unit_test_block sin_utb = {
	.type = UNIT_TEST_BLOCK_TYPE_POSIT_POSIT,
	.function_name = "sin",
	.data.posit_posit = {
		.reference_function = sin_reference,
		.posit8_function    = posit8_sin,
		.posit16_function   = posit16_sin,
		.posit32_function   = posit32_sin,
		.posit64_function   = posit64_sin,
		.posit_log8_function    = posit_log8_sin,
		.posit_log16_function   = posit_log16_sin,
		.posit_log32_function   = posit_log32_sin,
		.posit_log64_function   = posit_log64_sin,
	},
};

long double
sin_pi_times_reference(long double a)
{
	long double a_mod_2;

	a_mod_2 = fmodl(a, 2.0l);

	if (a_mod_2 == 0.0l) {
		return 0.0l;
	} else if (a_mod_2 == 0.5l) {
		return 1.0l;
	} else if (a_mod_2 == 1.0l) {
		return 0.0l;
	} else if (a_mod_2 == 1.5l) {
		return -1.0l;
	} else {
		return sinl(PI * a);
	}
}

static const struct unit_test_block sin_pi_times_utb = {
	.type = UNIT_TEST_BLOCK_TYPE_POSIT_POSIT,
	.function_name = "sin_pi_times",
	.data.posit_posit = {
		.reference_function = sin_pi_times_reference,
		.posit8_function    = posit8_sin_pi_times,
		.posit16_function   = posit16_sin_pi_times,
		.posit32_function   = posit32_sin_pi_times,
		.posit64_function   = posit64_sin_pi_times,
		.posit_log8_function    = posit_log8_sin_pi_times,
		.posit_log16_function   = posit_log16_sin_pi_times,
		.posit_log32_function   = posit_log32_sin_pi_times,
		.posit_log64_function   = posit_log64_sin_pi_times,
	},
};

int
main(int argc, char *argv[])
{
	(void)argc;
	argv0 = argv[0];

	return run_unit_test_block(&sin_utb) +
	       run_unit_test_block(&sin_pi_times_utb);
}

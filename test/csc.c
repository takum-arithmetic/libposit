/* See LICENSE file for copyright and license details. */
#include "../posit.h"
#include "util.h"

#include <math.h>

long double
csc_reference(long double a)
{
	return 1.0l / sinl(a);
}

static const struct unit_test_block csc_utb = {
	.type = UNIT_TEST_BLOCK_TYPE_POSIT_POSIT,
	.function_name = "csc",
	.data.posit_posit = {
		.reference_function = csc_reference,
		.posit8_function    = posit8_csc,
		.posit16_function   = posit16_csc,
		.posit32_function   = posit32_csc,
		.posit64_function   = posit64_csc,
		.posit_log8_function    = posit_log8_csc,
		.posit_log16_function   = posit_log16_csc,
		.posit_log32_function   = posit_log32_csc,
		.posit_log64_function   = posit_log64_csc,
	},
};

long double
csc_pi_times_reference(long double a)
{
	long double a_mod_2;

	a_mod_2 = fmodl(a, 2.0l);

	if (a_mod_2 == 0.0l) {
		return NAN;
	} else if (a_mod_2 == 0.5l) {
		return 1.0l;
	} else if (a_mod_2 == 1.0l) {
		return NAN;
	} else if (a_mod_2 == 1.5l) {
		return -1.0l;
	} else {
		return csc_reference(PI * a);
	}
}

static const struct unit_test_block csc_pi_times_utb = {
	.type = UNIT_TEST_BLOCK_TYPE_POSIT_POSIT,
	.function_name = "csc_pi_times",
	.data.posit_posit = {
		.reference_function = csc_pi_times_reference,
		.posit8_function    = posit8_csc_pi_times,
		.posit16_function   = posit16_csc_pi_times,
		.posit32_function   = posit32_csc_pi_times,
		.posit64_function   = posit64_csc_pi_times,
		.posit_log8_function    = posit_log8_csc_pi_times,
		.posit_log16_function   = posit_log16_csc_pi_times,
		.posit_log32_function   = posit_log32_csc_pi_times,
		.posit_log64_function   = posit_log64_csc_pi_times,
	},
};

int
main(int argc, char *argv[])
{
	(void)argc;
	argv0 = argv[0];

	return run_unit_test_block(&csc_utb) +
	       run_unit_test_block(&csc_pi_times_utb);
}

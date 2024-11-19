/* See LICENSE file for copyright and license details. */
#include "../posit.h"
#include "util.h"

#include <math.h>

long double
sec_reference(long double a)
{
	return 1.0L / cosl(a);
}

static const struct unit_test_block sec_utb = {
	.type = UNIT_TEST_BLOCK_TYPE_POSIT_POSIT,
	.function_name = "sec",
	.data.posit_posit = {
		.reference_function = sec_reference,
		.posit8_function    = posit8_sec,
		.posit16_function   = posit16_sec,
		.posit32_function   = posit32_sec,
		.posit64_function   = posit64_sec,
		.posit_log8_function    = posit_log8_sec,
		.posit_log16_function   = posit_log16_sec,
		.posit_log32_function   = posit_log32_sec,
		.posit_log64_function   = posit_log64_sec,
	},
};

long double
sec_pi_times_reference(long double a)
{
	long double a_mod_2;

	a_mod_2 = fmodl(a, 2.0l);

	if (a_mod_2 == 0.0l) {
		return 1.0l;
	} else if (a_mod_2 == 0.5l) {
		return NAN;
	} else if (a_mod_2 == 1.0l) {
		return -1.0l;
	} else if (a_mod_2 == 1.5l) {
		return NAN;
	} else {
		return sec_reference(PI * a);
	}
}

static const struct unit_test_block sec_pi_times_utb = {
	.type = UNIT_TEST_BLOCK_TYPE_POSIT_POSIT,
	.function_name = "sec_pi_times",
	.data.posit_posit = {
		.reference_function = sec_pi_times_reference,
		.posit8_function    = posit8_sec_pi_times,
		.posit16_function   = posit16_sec_pi_times,
		.posit32_function   = posit32_sec_pi_times,
		.posit64_function   = posit64_sec_pi_times,
		.posit_log8_function    = posit_log8_sec_pi_times,
		.posit_log16_function   = posit_log16_sec_pi_times,
		.posit_log32_function   = posit_log32_sec_pi_times,
		.posit_log64_function   = posit_log64_sec_pi_times,
	},
};

int
main(int argc, char *argv[])
{
	(void)argc;
	argv0 = argv[0];

	return run_unit_test_block(&sec_utb) +
	       run_unit_test_block(&sec_pi_times_utb);
}

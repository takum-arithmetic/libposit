/* See LICENSE file for copyright and license details. */
#include "../posit.h"
#include "util.h"

#include <math.h>

long double
cot_reference(long double a)
{
	return 1.0l / tanl(a);
}

static const struct unit_test_block cot_utb = {
	.type = UNIT_TEST_BLOCK_TYPE_POSIT_POSIT,
	.function_name = "cot",
	.data.posit_posit = {
		.reference_function = cot_reference,
		.posit8_function    = posit8_cot,
		.posit16_function   = posit16_cot,
		.posit32_function   = posit32_cot,
		.posit64_function   = posit64_cot,
		.posit_log8_function    = posit_log8_cot,
		.posit_log16_function   = posit_log16_cot,
		.posit_log32_function   = posit_log32_cot,
		.posit_log64_function   = posit_log64_cot,
	},
};

long double
cot_pi_times_reference(long double a)
{
	long double a_mod_1;

	a_mod_1 = fmodl(a, 1.0l);

	if (a_mod_1 == 0.0l) {
		return NAN;
	} else if (a_mod_1 == 0.5) {
		return 0.0;
	} else {
		return cot_reference(PI * a);
	}
}

static const struct unit_test_block cot_pi_times_utb = {
	.type = UNIT_TEST_BLOCK_TYPE_POSIT_POSIT,
	.function_name = "cot_pi_times",
	.data.posit_posit = {
		.reference_function = cot_pi_times_reference,
		.posit8_function    = posit8_cot_pi_times,
		.posit16_function   = posit16_cot_pi_times,
		.posit32_function   = posit32_cot_pi_times,
		.posit64_function   = posit64_cot_pi_times,
		.posit_log8_function    = posit_log8_cot_pi_times,
		.posit_log16_function   = posit_log16_cot_pi_times,
		.posit_log32_function   = posit_log32_cot_pi_times,
		.posit_log64_function   = posit_log64_cot_pi_times,
	},
};

int
main(int argc, char *argv[])
{
	(void)argc;
	argv0 = argv[0];

	return run_unit_test_block(&cot_utb) +
	       run_unit_test_block(&cot_pi_times_utb);
}

/* See LICENSE file for copyright and license details. */
#include "../posit.h"
#include "util.h"

#include <math.h>

long double
tan_reference(long double a)
{
	return tanl(a);
}

static const struct unit_test_block tan_utb = {
	.type = UNIT_TEST_BLOCK_TYPE_POSIT_POSIT,
	.function_name = "tan",
	.data.posit_posit = {
		.reference_function = tan_reference,
		.posit8_function    = posit8_tan,
		.posit16_function   = posit16_tan,
		.posit32_function   = posit32_tan,
		.posit64_function   = posit64_tan,
		.posit_log8_function    = posit_log8_tan,
		.posit_log16_function   = posit_log16_tan,
		.posit_log32_function   = posit_log32_tan,
		.posit_log64_function   = posit_log64_tan,
	},
};

long double
tan_pi_times_reference(long double a)
{
	long double a_mod_1;

	a_mod_1 = fmodl(a, 1.0l);

	if (a_mod_1 == 0.0l) {
		return 0.0;
	} else if (a_mod_1 == 0.5) {
		return NAN;
	} else {
		return tan_reference(PI * a);
	}
}

static const struct unit_test_block tan_pi_times_utb = {
	.type = UNIT_TEST_BLOCK_TYPE_POSIT_POSIT,
	.function_name = "tan_pi_times",
	.data.posit_posit = {
		.reference_function = tan_pi_times_reference,
		.posit8_function    = posit8_tan_pi_times,
		.posit16_function   = posit16_tan_pi_times,
		.posit32_function   = posit32_tan_pi_times,
		.posit64_function   = posit64_tan_pi_times,
		.posit_log8_function    = posit_log8_tan_pi_times,
		.posit_log16_function   = posit_log16_tan_pi_times,
		.posit_log32_function   = posit_log32_tan_pi_times,
		.posit_log64_function   = posit_log64_tan_pi_times,
	},
};

int
main(int argc, char *argv[])
{
	(void)argc;
	argv0 = argv[0];

	return run_unit_test_block(&tan_utb) +
	       run_unit_test_block(&tan_pi_times_utb);
}

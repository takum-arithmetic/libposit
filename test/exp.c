/* See LICENSE file for copyright and license details. */
#include "../posit.h"
#include "util.h"

#include <math.h>

long double
exp_reference(long double a)
{
	return expl(a);
}

static const struct unit_test_block exp_utb = {
	.type = UNIT_TEST_BLOCK_TYPE_POSIT_POSIT,
	.function_name = "exp",
	.data.posit_posit = {
		.reference_function = exp_reference,
		.posit8_function    = posit8_exp,
		.posit16_function   = posit16_exp,
		.posit32_function   = posit32_exp,
		.posit64_function   = posit64_exp,
		.posit_log8_function    = posit_log8_exp,
		.posit_log16_function   = posit_log16_exp,
		.posit_log32_function   = posit_log32_exp,
		.posit_log64_function   = posit_log64_exp,
	},
};

long double
exp_minus_1_reference(long double a)
{
	return expm1l(a);
}

static const struct unit_test_block exp_minus_1_utb = {
	.type = UNIT_TEST_BLOCK_TYPE_POSIT_POSIT,
	.function_name = "exp_minus_1",
	.data.posit_posit = {
		.reference_function = exp_minus_1_reference,
		.posit8_function    = posit8_exp_minus_1,
		.posit16_function   = posit16_exp_minus_1,
		.posit32_function   = posit32_exp_minus_1,
		.posit64_function   = posit64_exp_minus_1,
		.posit_log8_function    = posit_log8_exp_minus_1,
		.posit_log16_function   = posit_log16_exp_minus_1,
		.posit_log32_function   = posit_log32_exp_minus_1,
		.posit_log64_function   = posit_log64_exp_minus_1,
	},
};

int
main(int argc, char *argv[])
{
	(void)argc;
	argv0 = argv[0];

	return run_unit_test_block(&exp_utb) +
	       run_unit_test_block(&exp_minus_1_utb);
}

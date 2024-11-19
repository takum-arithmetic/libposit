/* See LICENSE file for copyright and license details. */
#include "../posit.h"
#include "util.h"

#include <math.h>

long double
ln_reference(long double a)
{
	return logl(a);
}

static const struct unit_test_block ln_utb = {
	.type = UNIT_TEST_BLOCK_TYPE_POSIT_POSIT,
	.function_name = "ln",
	.data.posit_posit = {
		.reference_function = ln_reference,
		.posit8_function    = posit8_ln,
		.posit16_function   = posit16_ln,
		.posit32_function   = posit32_ln,
		.posit64_function   = posit64_ln,
		.posit_log8_function    = posit_log8_ln,
		.posit_log16_function   = posit_log16_ln,
		.posit_log32_function   = posit_log32_ln,
		.posit_log64_function   = posit_log64_ln,
	},
};

long double
ln_1_plus_reference(long double a)
{
	return log1pl(a);
}

static const struct unit_test_block ln_1_plus_utb = {
	.type = UNIT_TEST_BLOCK_TYPE_POSIT_POSIT,
	.function_name = "ln_1_plus",
	.data.posit_posit = {
		.reference_function = ln_1_plus_reference,
		.posit8_function    = posit8_ln_1_plus,
		.posit16_function   = posit16_ln_1_plus,
		.posit32_function   = posit32_ln_1_plus,
		.posit64_function   = posit64_ln_1_plus,
		.posit_log8_function    = posit_log8_ln_1_plus,
		.posit_log16_function   = posit_log16_ln_1_plus,
		.posit_log32_function   = posit_log32_ln_1_plus,
		.posit_log64_function   = posit_log64_ln_1_plus,
	},
};

int
main(int argc, char *argv[])
{
	(void)argc;
	argv0 = argv[0];

	return run_unit_test_block(&ln_utb) +
	       run_unit_test_block(&ln_1_plus_utb);
}

/* See LICENSE file for copyright and license details. */
#include "../posit.h"
#include "util.h"

#include <math.h>

long double
lg_reference(long double a)
{
	return log10l(a);
}

static const struct unit_test_block lg_utb = {
	.type = UNIT_TEST_BLOCK_TYPE_POSIT_POSIT,
	.function_name = "lg",
	.data.posit_posit = {
		.reference_function = lg_reference,
		.posit8_function    = posit8_lg,
		.posit16_function   = posit16_lg,
		.posit32_function   = posit32_lg,
		.posit64_function   = posit64_lg,
		.posit_log8_function    = posit_log8_lg,
		.posit_log16_function   = posit_log16_lg,
		.posit_log32_function   = posit_log32_lg,
		.posit_log64_function   = posit_log64_lg,
	},
};

long double
lg_1_plus_reference(long double a)
{
	return LG_E * log1pl(a);
}

static const struct unit_test_block lg_1_plus_utb = {
	.type = UNIT_TEST_BLOCK_TYPE_POSIT_POSIT,
	.function_name = "lg_1_plus",
	.data.posit_posit = {
		.reference_function = lg_1_plus_reference,
		.posit8_function    = posit8_lg_1_plus,
		.posit16_function   = posit16_lg_1_plus,
		.posit32_function   = posit32_lg_1_plus,
		.posit64_function   = posit64_lg_1_plus,
		.posit_log8_function    = posit_log8_lg_1_plus,
		.posit_log16_function   = posit_log16_lg_1_plus,
		.posit_log32_function   = posit_log32_lg_1_plus,
		.posit_log64_function   = posit_log64_lg_1_plus,
	},
};

int
main(int argc, char *argv[])
{
	(void)argc;
	argv0 = argv[0];

	return run_unit_test_block(&lg_utb) +
	       run_unit_test_block(&lg_1_plus_utb);
}

/* See LICENSE file for copyright and license details. */
#include "../posit.h"
#include "util.h"

#include <math.h>

long double
addition_reference(long double a, long double b)
{
	return a + b;
}

static const struct unit_test_block addition_utb = {
	.type = UNIT_TEST_BLOCK_TYPE_POSIT_POSIT_POSIT,
	.function_name = "addition",
	.data.posit_posit_posit = {
		.reference_function = addition_reference,
		.posit8_function    = posit8_addition,
		.posit16_function   = posit16_addition,
		.posit32_function   = posit32_addition,
		.posit64_function   = posit64_addition,
		.posit_log8_function    = posit_log8_addition,
		.posit_log16_function   = posit_log16_addition,
		.posit_log32_function   = posit_log32_addition,
		.posit_log64_function   = posit_log64_addition,
	},
};

int
main(int argc, char *argv[])
{
	(void)argc;
	argv0 = argv[0];

	return run_unit_test_block(&addition_utb);
}

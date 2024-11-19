/* See LICENSE file for copyright and license details. */
#include "../posit.h"
#include "util.h"

#include <math.h>

long double
subtraction_reference(long double a, long double b)
{
	return a - b;
}

static const struct unit_test_block subtraction_utb = {
	.type = UNIT_TEST_BLOCK_TYPE_POSIT_POSIT_POSIT,
	.function_name = "subtraction",
	.data.posit_posit_posit = {
		.reference_function = subtraction_reference,
		.posit8_function    = posit8_subtraction,
		.posit16_function   = posit16_subtraction,
		.posit32_function   = posit32_subtraction,
		.posit64_function   = posit64_subtraction,
		.posit_log8_function    = posit_log8_subtraction,
		.posit_log16_function   = posit_log16_subtraction,
		.posit_log32_function   = posit_log32_subtraction,
		.posit_log64_function   = posit_log64_subtraction,
	},
};

int
main(int argc, char *argv[])
{
	(void)argc;
	argv0 = argv[0];

	return run_unit_test_block(&subtraction_utb);
}

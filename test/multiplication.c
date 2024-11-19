/* See LICENSE file for copyright and license details. */
#include "../posit.h"
#include "util.h"

#include <math.h>

long double
multiplication_reference(long double a, long double b)
{
	return a * b;
}

static const struct unit_test_block multiplication_utb = {
	.type = UNIT_TEST_BLOCK_TYPE_POSIT_POSIT_POSIT,
	.function_name = "multiplication",
	.data.posit_posit_posit = {
		.reference_function = multiplication_reference,
		.posit8_function    = posit8_multiplication,
		.posit16_function   = posit16_multiplication,
		.posit32_function   = posit32_multiplication,
		.posit64_function   = posit64_multiplication,
		.posit_log8_function    = posit_log8_multiplication,
		.posit_log16_function   = posit_log16_multiplication,
		.posit_log32_function   = posit_log32_multiplication,
		.posit_log64_function   = posit_log64_multiplication,
	},
};

int
main(int argc, char *argv[])
{
	(void)argc;
	argv0 = argv[0];

	return run_unit_test_block(&multiplication_utb);
}

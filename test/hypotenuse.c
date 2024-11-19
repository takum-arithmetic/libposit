/* See LICENSE file for copyright and license details. */
#include "../posit.h"
#include "util.h"

#include <math.h>

long double
hypotenuse_reference(long double a, long double b)
{
	return hypotl(a, b);
}

static const struct unit_test_block hypotenuse_utb = {
	.type = UNIT_TEST_BLOCK_TYPE_POSIT_POSIT_POSIT,
	.function_name = "hypotenuse",
	.data.posit_posit_posit = {
		.reference_function = hypotenuse_reference,
		.posit8_function    = posit8_hypotenuse,
		.posit16_function   = posit16_hypotenuse,
		.posit32_function   = posit32_hypotenuse,
		.posit64_function   = posit64_hypotenuse,
		.posit_log8_function    = posit_log8_hypotenuse,
		.posit_log16_function   = posit_log16_hypotenuse,
		.posit_log32_function   = posit_log32_hypotenuse,
		.posit_log64_function   = posit_log64_hypotenuse,
	},
};

int
main(int argc, char *argv[])
{
	(void)argc;
	argv0 = argv[0];

	return run_unit_test_block(&hypotenuse_utb);
}

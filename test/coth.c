/* See LICENSE file for copyright and license details. */
#include "../posit.h"
#include "util.h"

#include <math.h>

long double
coth_reference(long double a)
{
	return 1.0L / tanhl(a);
}

static const struct unit_test_block coth_utb = {
	.type = UNIT_TEST_BLOCK_TYPE_POSIT_POSIT,
	.function_name = "coth",
	.data.posit_posit = {
		.reference_function = coth_reference,
		.posit8_function    = posit8_coth,
		.posit16_function   = posit16_coth,
		.posit32_function   = posit32_coth,
		.posit64_function   = posit64_coth,
		.posit_log8_function    = posit_log8_coth,
		.posit_log16_function   = posit_log16_coth,
		.posit_log32_function   = posit_log32_coth,
		.posit_log64_function   = posit_log64_coth,
	},
};

int
main(int argc, char *argv[])
{
	(void)argc;
	argv0 = argv[0];

	return run_unit_test_block(&coth_utb);
}

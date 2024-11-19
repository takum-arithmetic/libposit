/* See LICENSE file for copyright and license details. */
#include "../posit.h"
#include "util.h"

#include <math.h>

long double
cosh_reference(long double a)
{
	return coshl(a);
}

static const struct unit_test_block cosh_utb = {
	.type = UNIT_TEST_BLOCK_TYPE_POSIT_POSIT,
	.function_name = "cosh",
	.data.posit_posit = {
		.reference_function = cosh_reference,
		.posit8_function    = posit8_cosh,
		.posit16_function   = posit16_cosh,
		.posit32_function   = posit32_cosh,
		.posit64_function   = posit64_cosh,
		.posit_log8_function    = posit_log8_cosh,
		.posit_log16_function   = posit_log16_cosh,
		.posit_log32_function   = posit_log32_cosh,
		.posit_log64_function   = posit_log64_cosh,
	},
};

int
main(int argc, char *argv[])
{
	(void)argc;
	argv0 = argv[0];

	return run_unit_test_block(&cosh_utb);
}

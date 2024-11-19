/* See LICENSE file for copyright and license details. */
#include "../posit.h"
#include "util.h"

#include <math.h>

long double
arcosh_reference(long double a)
{
	return acoshl(a);
}

static const struct unit_test_block arcosh_utb = {
	.type = UNIT_TEST_BLOCK_TYPE_POSIT_POSIT,
	.function_name = "arcosh",
	.data.posit_posit = {
		.reference_function = arcosh_reference,
		.posit8_function    = posit8_arcosh,
		.posit16_function   = posit16_arcosh,
		.posit32_function   = posit32_arcosh,
		.posit64_function   = posit64_arcosh,
		.posit_log8_function    = posit_log8_arcosh,
		.posit_log16_function   = posit_log16_arcosh,
		.posit_log32_function   = posit_log32_arcosh,
		.posit_log64_function   = posit_log64_arcosh,
	},
};

int
main(int argc, char *argv[])
{
	(void)argc;
	argv0 = argv[0];

	return run_unit_test_block(&arcosh_utb);
}

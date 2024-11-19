/* See LICENSE file for copyright and license details. */
#include "../posit.h"
#include "util.h"

#include <math.h>

long double
arcoth_reference(long double a)
{
	return atanh(1.0L / a);
}

static const struct unit_test_block arcoth_utb = {
	.type = UNIT_TEST_BLOCK_TYPE_POSIT_POSIT,
	.function_name = "arcoth",
	.data.posit_posit = {
		.reference_function = arcoth_reference,
		.posit8_function    = posit8_arcoth,
		.posit16_function   = posit16_arcoth,
		.posit32_function   = posit32_arcoth,
		.posit64_function   = posit64_arcoth,
		.posit_log8_function    = posit_log8_arcoth,
		.posit_log16_function   = posit_log16_arcoth,
		.posit_log32_function   = posit_log32_arcoth,
		.posit_log64_function   = posit_log64_arcoth,
	},
};

int
main(int argc, char *argv[])
{
	(void)argc;
	argv0 = argv[0];

	return run_unit_test_block(&arcoth_utb);
}

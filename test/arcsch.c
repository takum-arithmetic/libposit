/* See LICENSE file for copyright and license details. */
#include "../posit.h"
#include "util.h"

#include <math.h>

long double
arcsch_reference(long double a)
{
	return asinh(1.0L / a);
}

static const struct unit_test_block arcsch_utb = {
	.type = UNIT_TEST_BLOCK_TYPE_POSIT_POSIT,
	.function_name = "arcsch",
	.data.posit_posit = {
		.reference_function = arcsch_reference,
		.posit8_function    = posit8_arcsch,
		.posit16_function   = posit16_arcsch,
		.posit32_function   = posit32_arcsch,
		.posit64_function   = posit64_arcsch,
		.posit_log8_function    = posit_log8_arcsch,
		.posit_log16_function   = posit_log16_arcsch,
		.posit_log32_function   = posit_log32_arcsch,
		.posit_log64_function   = posit_log64_arcsch,
	},
};

int
main(int argc, char *argv[])
{
	(void)argc;
	argv0 = argv[0];

	return run_unit_test_block(&arcsch_utb);
}

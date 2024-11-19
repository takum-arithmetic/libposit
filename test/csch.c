/* See LICENSE file for copyright and license details. */
#include "../posit.h"
#include "util.h"

#include <math.h>

static long double
csch_reference(long double a)
{
	return 1.0l / sinhl(a);
}

static const struct unit_test_block csch_utb = {
	.type = UNIT_TEST_BLOCK_TYPE_POSIT_POSIT,
	.function_name = "csch",
	.data.posit_posit = {
		.reference_function = csch_reference,
		.posit8_function    = posit8_csch,
		.posit16_function   = posit16_csch,
		.posit32_function   = posit32_csch,
		.posit64_function   = posit64_csch,
		.posit_log8_function    = posit_log8_csch,
		.posit_log16_function   = posit_log16_csch,
		.posit_log32_function   = posit_log32_csch,
		.posit_log64_function   = posit_log64_csch,
	},
};

int
main(int argc, char *argv[])
{
	(void)argc;
	argv0 = argv[0];

	return run_unit_test_block(&csch_utb);
}

/* See LICENSE file for copyright and license details. */
#include "../posit.h"
#include "util.h"

#include <math.h>

long double
inversion_reference(long double a)
{
	return 1.0L / a;
}

static const struct unit_test_block inversion_utb = {
	.type = UNIT_TEST_BLOCK_TYPE_POSIT_POSIT,
	.function_name = "inversion",
	.data.posit_posit = {
		.reference_function = inversion_reference,
		.posit8_function    = posit8_inversion,
		.posit16_function   = posit16_inversion,
		.posit32_function   = posit32_inversion,
		.posit64_function   = posit64_inversion,
		.posit_log8_function    = posit_log8_inversion,
		.posit_log16_function   = posit_log16_inversion,
		.posit_log32_function   = posit_log32_inversion,
		.posit_log64_function   = posit_log64_inversion,
	},
};

int
main(int argc, char *argv[])
{
	(void)argc;
	argv0 = argv[0];

	return run_unit_test_block(&inversion_utb);
}
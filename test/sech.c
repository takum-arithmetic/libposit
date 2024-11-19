/* See LICENSE file for copyright and license details. */
#include "../posit.h"
#include "util.h"

#include <math.h>

long double
sech_reference(long double a)
{
	return 1.0L / coshl(a);
}

static const struct unit_test_block sech_utb = {
	.type = UNIT_TEST_BLOCK_TYPE_POSIT_POSIT,
	.function_name = "sech",
	.data.posit_posit = {
		.reference_function = sech_reference,
		.posit8_function    = posit8_sech,
		.posit16_function   = posit16_sech,
		.posit32_function   = posit32_sech,
		.posit64_function   = posit64_sech,
		.posit_log8_function    = posit_log8_sech,
		.posit_log16_function   = posit_log16_sech,
		.posit_log32_function   = posit_log32_sech,
		.posit_log64_function   = posit_log64_sech,
	},
};

int
main(int argc, char *argv[])
{
	(void)argc;
	argv0 = argv[0];

	return run_unit_test_block(&sech_utb);
}

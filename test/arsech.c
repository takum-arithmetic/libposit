/* See LICENSE file for copyright and license details. */
#include "../posit.h"
#include "util.h"

#include <math.h>

long double
arsech_reference(long double a)
{
	return acoshl(1.0l / a);
}

static const struct unit_test_block arsech_utb = {
	.type = UNIT_TEST_BLOCK_TYPE_POSIT_POSIT,
	.function_name = "arsech",
	.data.posit_posit = {
		.reference_function = arsech_reference,
		.posit8_function    = posit8_arsech,
		.posit16_function   = posit16_arsech,
		.posit32_function   = posit32_arsech,
		.posit64_function   = posit64_arsech,
		.posit_log8_function    = posit_log8_arsech,
		.posit_log16_function   = posit_log16_arsech,
		.posit_log32_function   = posit_log32_arsech,
		.posit_log64_function   = posit_log64_arsech,
	},
};

int
main(int argc, char *argv[])
{
	(void)argc;
	argv0 = argv[0];

	return run_unit_test_block(&arsech_utb);
}

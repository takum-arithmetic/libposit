/* See LICENSE file for copyright and license details. */
#include "../posit.h"
#include "util.h"

#include <math.h>

static long double
power_reference(long double a, long double b)
{
	return powl(a, b);
}

static const struct unit_test_block power_utb = {
	.type = UNIT_TEST_BLOCK_TYPE_POSIT_POSIT_POSIT,
	.function_name = "power",
	.data.posit_posit_posit = {
		.reference_function = power_reference,
		.posit8_function    = posit8_power,
		.posit16_function   = posit16_power,
		.posit32_function   = posit32_power,
		.posit64_function   = posit64_power,
		.posit_log8_function    = posit_log8_power,
		.posit_log16_function   = posit_log16_power,
		.posit_log32_function   = posit_log32_power,
		.posit_log64_function   = posit_log64_power,
	},
};

int
main(int argc, char *argv[])
{
	(void)argc;
	argv0 = argv[0];

	return run_unit_test_block(&power_utb);
}

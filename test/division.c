/* See LICENSE file for copyright and license details. */
#include "../posit.h"
#include "util.h"

#include <math.h>

long double
division_reference(long double a, long double b)
{
	return a / b;
}

static const struct unit_test_block division_utb = {
	.type = UNIT_TEST_BLOCK_TYPE_POSIT_POSIT_POSIT,
	.function_name = "division",
	.data.posit_posit_posit = {
		.reference_function = division_reference,
		.posit8_function    = posit8_division,
		.posit16_function   = posit16_division,
		.posit32_function   = posit32_division,
		.posit64_function   = posit64_division,
		.posit_log8_function    = posit_log8_division,
		.posit_log16_function   = posit_log16_division,
		.posit_log32_function   = posit_log32_division,
		.posit_log64_function   = posit_log64_division,
	},
};

int
main(int argc, char *argv[])
{
	(void)argc;
	argv0 = argv[0];

	return run_unit_test_block(&division_utb);
}

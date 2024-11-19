/* See LICENSE file for copyright and license details. */
#include "../posit.h"
#include "util.h"

#include <math.h>

long double
sinh_reference(long double a)
{
	return sinhl(a);
}

static const struct unit_test_block sinh_utb = {
	.type = UNIT_TEST_BLOCK_TYPE_POSIT_POSIT,
	.function_name = "sinh",
	.data.posit_posit = {
		.reference_function = sinh_reference,
		.posit8_function    = posit8_sinh,
		.posit16_function   = posit16_sinh,
		.posit32_function   = posit32_sinh,
		.posit64_function   = posit64_sinh,
		.posit_log8_function    = posit_log8_sinh,
		.posit_log16_function   = posit_log16_sinh,
		.posit_log32_function   = posit_log32_sinh,
		.posit_log64_function   = posit_log64_sinh,
	},
};

int
main(int argc, char *argv[])
{
	(void)argc;
	argv0 = argv[0];

	return run_unit_test_block(&sinh_utb);
}

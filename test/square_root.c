/* See LICENSE file for copyright and license details. */
#include "../posit.h"
#include "util.h"

#include <math.h>

long double
square_root_reference(long double a)
{
	return sqrtl(a);
}

static const struct unit_test_block square_root_utb = {
	.type = UNIT_TEST_BLOCK_TYPE_POSIT_POSIT,
	.function_name = "square_root",
	.data.posit_posit = {
		.reference_function = square_root_reference,
		.posit8_function    = posit8_square_root,
		.posit16_function   = posit16_square_root,
		.posit32_function   = posit32_square_root,
		.posit64_function   = posit64_square_root,
		.posit_log8_function    = posit_log8_square_root,
		.posit_log16_function   = posit_log16_square_root,
		.posit_log32_function   = posit_log32_square_root,
		.posit_log64_function   = posit_log64_square_root,
	},
};

int
main(int argc, char *argv[])
{
	(void)argc;
	argv0 = argv[0];

	return run_unit_test_block(&square_root_utb);
}

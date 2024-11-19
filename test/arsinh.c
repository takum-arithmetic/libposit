/* See LICENSE file for copyright and license details. */
#include "../posit.h"
#include "util.h"

#include <math.h>

long double
arsinh_reference(long double a)
{
	return asinhl(a);
}

static const struct unit_test_block arsinh_utb = {
	.type = UNIT_TEST_BLOCK_TYPE_POSIT_POSIT,
	.function_name = "arsinh",
	.data.posit_posit = {
		.reference_function = arsinh_reference,
		.posit8_function    = posit8_arsinh,
		.posit16_function   = posit16_arsinh,
		.posit32_function   = posit32_arsinh,
		.posit64_function   = posit64_arsinh,
		.posit_log8_function    = posit_log8_arsinh,
		.posit_log16_function   = posit_log16_arsinh,
		.posit_log32_function   = posit_log32_arsinh,
		.posit_log64_function   = posit_log64_arsinh,
	},
};

int
main(int argc, char *argv[])
{
	(void)argc;
	argv0 = argv[0];

	return run_unit_test_block(&arsinh_utb);
}

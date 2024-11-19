/* See LICENSE file for copyright and license details. */
#include "../posit.h"
#include "util.h"

#include <math.h>

long double
tanh_reference(long double a)
{
	return tanhl(a);
}

static const struct unit_test_block tanh_utb = {
	.type = UNIT_TEST_BLOCK_TYPE_POSIT_POSIT,
	.function_name = "tanh",
	.data.posit_posit = {
		.reference_function = tanh_reference,
		.posit8_function    = posit8_tanh,
		.posit16_function   = posit16_tanh,
		.posit32_function   = posit32_tanh,
		.posit64_function   = posit64_tanh,
		.posit_log8_function    = posit_log8_tanh,
		.posit_log16_function   = posit_log16_tanh,
		.posit_log32_function   = posit_log32_tanh,
		.posit_log64_function   = posit_log64_tanh,
	},
};

int
main(int argc, char *argv[])
{
	(void)argc;
	argv0 = argv[0];

	return run_unit_test_block(&tanh_utb);
}

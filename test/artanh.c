/* See LICENSE file for copyright and license details. */
#include "../posit.h"
#include "util.h"

#include <math.h>

long double
artanh_reference(long double a)
{
	return atanhl(a);
}

static const struct unit_test_block artanh_utb = {
	.type = UNIT_TEST_BLOCK_TYPE_POSIT_POSIT,
	.function_name = "artanh",
	.data.posit_posit = {
		.reference_function = artanh_reference,
		.posit8_function    = posit8_artanh,
		.posit16_function   = posit16_artanh,
		.posit32_function   = posit32_artanh,
		.posit64_function   = posit64_artanh,
		.posit_log8_function    = posit_log8_artanh,
		.posit_log16_function   = posit_log16_artanh,
		.posit_log32_function   = posit_log32_artanh,
		.posit_log64_function   = posit_log64_artanh,
	},
};

int
main(int argc, char *argv[])
{
	(void)argc;
	argv0 = argv[0];

	return run_unit_test_block(&artanh_utb);
}

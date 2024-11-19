/* See LICENSE file for copyright and license details. */
#include "../posit.h"
#include "util.h"

#include <math.h>

long double
absolute_reference(long double a)
{
	if (isfinite(a)) {
		return (a < 0) ? -a : a;
	} else {
		return NAN;
	}
}

static const struct unit_test_block absolute_utb = {
	.type = UNIT_TEST_BLOCK_TYPE_POSIT_POSIT,
	.function_name = "absolute",
	.data.posit_posit = {
		.reference_function = absolute_reference,
		.posit8_function    = posit8_absolute,
		.posit16_function   = posit16_absolute,
		.posit32_function   = posit32_absolute,
		.posit64_function   = posit64_absolute,
		.posit_log8_function    = posit_log8_absolute,
		.posit_log16_function   = posit_log16_absolute,
		.posit_log32_function   = posit_log32_absolute,
		.posit_log64_function   = posit_log64_absolute,
	},
};

int
main(int argc, char *argv[])
{
	(void)argc;
	argv0 = argv[0];

	return run_unit_test_block(&absolute_utb);
}

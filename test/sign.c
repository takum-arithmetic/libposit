/* See LICENSE file for copyright and license details. */
#include "../posit.h"
#include "util.h"

#include <math.h>

long double
sign_reference(long double a)
{
	if (isfinite(a)) {
		return (a == 0.0L) ? 0.0L : (a > 0.0L) ? 1.0 : -1.0;
	} else {
		return NAN;
	}
}

static const struct unit_test_block sign_utb = {
	.type = UNIT_TEST_BLOCK_TYPE_POSIT_POSIT,
	.function_name = "sign",
	.data.posit_posit = {
		.reference_function = sign_reference,
		.posit8_function    = posit8_sign,
		.posit16_function   = posit16_sign,
		.posit32_function   = posit32_sign,
		.posit64_function   = posit64_sign,
		.posit_log8_function    = posit_log8_sign,
		.posit_log16_function   = posit_log16_sign,
		.posit_log32_function   = posit_log32_sign,
		.posit_log64_function   = posit_log64_sign,
	},
};

int
main(int argc, char *argv[])
{
	(void)argc;
	argv0 = argv[0];

	return run_unit_test_block(&sign_utb);
}

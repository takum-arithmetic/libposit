/* See LICENSE file for copyright and license details. */
#include "../posit.h"
#include "util.h"

#include <math.h>

long double
lb_reference(long double a)
{
	return log2l(a);
}

static const struct unit_test_block lb_utb = {
	.type = UNIT_TEST_BLOCK_TYPE_POSIT_POSIT,
	.function_name = "lb",
	.data.posit_posit = {
		.reference_function = lb_reference,
		.posit8_function    = posit8_lb,
		.posit16_function   = posit16_lb,
		.posit32_function   = posit32_lb,
		.posit64_function   = posit64_lb,
		.posit_log8_function    = posit_log8_lb,
		.posit_log16_function   = posit_log16_lb,
		.posit_log32_function   = posit_log32_lb,
		.posit_log64_function   = posit_log64_lb,
	},
};

long double
lb_1_plus_reference(long double a)
{
	return LB_E * log1pl(a);
}

static const struct unit_test_block lb_1_plus_utb = {
	.type = UNIT_TEST_BLOCK_TYPE_POSIT_POSIT,
	.function_name = "lb_1_plus",
	.data.posit_posit = {
		.reference_function = lb_1_plus_reference,
		.posit8_function    = posit8_lb_1_plus,
		.posit16_function   = posit16_lb_1_plus,
		.posit32_function   = posit32_lb_1_plus,
		.posit64_function   = posit64_lb_1_plus,
		.posit_log8_function    = posit_log8_lb_1_plus,
		.posit_log16_function   = posit_log16_lb_1_plus,
		.posit_log32_function   = posit_log32_lb_1_plus,
		.posit_log64_function   = posit_log64_lb_1_plus,
	},
};

int
main(int argc, char *argv[])
{
	(void)argc;
	argv0 = argv[0];

	return run_unit_test_block(&lb_utb) +
	       run_unit_test_block(&lb_1_plus_utb);
}

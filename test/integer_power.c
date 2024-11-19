/* See LICENSE file for copyright and license details. */
#include "../posit.h"
#include "util.h"

#include <math.h>
#include <stdint.h>

long double
integer_power_reference(long double a, int64_t b)
{
	if (isnan(a) || (a == 0.0 && b == 0)) {
		return NAN;
	} else {
		return powl(a, (long double)b);
	}
}

static const int64_t integer_test_cases[] = {
	-100, -10, -1, 0, 1, 10, 100,
};

static const struct unit_test_block integer_power_utb = {
	.type = UNIT_TEST_BLOCK_TYPE_POSIT_INT64_POSIT,
	.function_name = "integer_power",
	.data.posit_int64_posit = {
		.reference_function      = integer_power_reference,
		.posit8_function         = posit8_integer_power,
		.posit16_function        = posit16_integer_power,
		.posit32_function        = posit32_integer_power,
		.posit64_function        = posit64_integer_power,
		.posit_log8_function         = posit_log8_integer_power,
		.posit_log16_function        = posit_log16_integer_power,
		.posit_log32_function        = posit_log32_integer_power,
		.posit_log64_function        = posit_log64_integer_power,
		.integer_test_cases      = integer_test_cases,
		.integer_test_case_count = LEN(integer_test_cases),
	},
};

int
main(int argc, char *argv[])
{
	(void)argc;
	argv0 = argv[0];

	return run_unit_test_block(&integer_power_utb);
}

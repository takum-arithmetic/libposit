/* See LICENSE file for copyright and license details. */
#include "../posit.h"
#include "util.h"

#include <float.h>
#include <math.h>
#include <stdint.h>

long double
root_reference(long double a, int64_t b)
{
	if (b == 0) {
		return NAN;
	}

	return powl(a, 1.0l / (long double)b);
}

static const int64_t integer_test_cases[] = {
	-100, -10, -1, 0, 1, 10, 100,
};

static const struct unit_test_block root_utb = {
	.type = UNIT_TEST_BLOCK_TYPE_POSIT_INT64_POSIT,
	.function_name = "root",
	.data.posit_int64_posit = {
		.reference_function      = root_reference,
		.posit8_function         = posit8_root,
		.posit16_function        = posit16_root,
		.posit32_function        = posit32_root,
		.posit64_function        = posit64_root,
		.posit_log8_function         = posit_log8_root,
		.posit_log16_function        = posit_log16_root,
		.posit_log32_function        = posit_log32_root,
		.posit_log64_function        = posit_log64_root,
		.integer_test_cases      = integer_test_cases,
		.integer_test_case_count = LEN(integer_test_cases),
	},
};

int
main(int argc, char *argv[])
{
	(void)argc;
	argv0 = argv[0];

	return run_unit_test_block(&root_utb);
}

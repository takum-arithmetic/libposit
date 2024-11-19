/* See LICENSE file for copyright and license details. */
#include "../posit.h"
#include "util.h"

#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <sys/types.h>

uint8_t
precision_reference(long double a, enum posit_type posit_type)
{
	if (!isfinite(a) || a == 0.0L) {
		/* return worst case precision 0 */
		return 0;
	} else {
		union util_posit64_union t = { 0 };
		bool R, tmp;
		uint8_t k;

		/* obtain the clean posit from the long double in the
		 * native type, then shift it to a 64-bit posit */
		switch (posit_type) {
		case POSIT8:
			t.value = (int64_t)posit8_from_extended_float(a);
			t.bits <<= 56;
			break;
		case POSIT16:
			t.value = (int64_t)posit16_from_extended_float(a);
			t.bits <<= 48;
			break;
		case POSIT32:
			t.value = (int64_t)posit32_from_extended_float(a);
			t.bits <<= 32;
			break;
		case POSIT64:
			t.value = (int64_t)posit64_from_extended_float(a);
			break;
		case POSIT_LOG8:
			t.value = (int64_t)posit_log8_from_extended_float(a);
			t.bits <<= 56;
			break;
		case POSIT_LOG16:
			t.value = (int64_t)posit_log16_from_extended_float(a);
			t.bits <<= 48;
			break;
		case POSIT_LOG32:
			t.value = (int64_t)posit_log32_from_extended_float(a);
			t.bits <<= 32;
			break;
		case POSIT_LOG64:
			t.value = (int64_t)posit_log64_from_extended_float(a);
			break;
		}

		/* determine k */

		/* shift the bits one to the left to discard the sign */
		t.bits <<= 1;

		/* get the regime bit value, which is the MSB */
		R = ((t.bits & (UINT64_C(1) << 63)) != 0);

		/* shift t.bits to the left until the MSB is NOT(R) */
		k = 0;
		do {
			t.bits <<= 1;
			tmp = ((t.bits & (UINT64_C(1) << 63)) != 0);
			k++;
		} while (R == tmp);

		return ((size_t)(k + 4) < posit_type_parameters[posit_type].n) ?
		               (posit_type_parameters[posit_type].n - (k + 4)) :
		               0;
	}
}

static const struct unit_test_block precision_utb = {
	.type = UNIT_TEST_BLOCK_TYPE_POSIT_UINT8,
	.function_name = "precision",
	.data.posit_uint8 = {
		.reference_function = precision_reference,
		.posit8_function    = posit8_precision,
		.posit16_function   = posit16_precision,
		.posit32_function   = posit32_precision,
		.posit64_function   = posit64_precision,
		.posit_log8_function    = posit_log8_precision,
		.posit_log16_function   = posit_log16_precision,
		.posit_log32_function   = posit_log32_precision,
		.posit_log64_function   = posit_log64_precision,
	},
};

int
main(int argc, char *argv[])
{
	(void)argc;
	argv0 = argv[0];

	return run_unit_test_block(&precision_utb);
}

/* See LICENSE file for copyright and license details. */
#include <stdint.h>

#include "../posit.h"

#include "util.h"

uint8_t
posit8_precision(posit8 t)
{
	const union util_posit8_union in = {
		.value = t,
	};

	if (t == 0 || t == POSIT8_NAR) {
		/* return the worst case precision 0 */
		return 0;
	} else {
		uint8_t k;

		/* Determine k as in explained in codec_posit*_to_l() */
		k = util_clz8((in.bits << 1) ^ (in.bits << 2)) + 1;

		return (k + 4 < 8) ? (8 - (k + 4)) : 0;
	}
}

uint8_t
posit16_precision(posit16 t)
{
	const union util_posit16_union in = {
		.value = t,
	};

	if (t == 0 || t == POSIT16_NAR) {
		/* return the worst case precision 0 */
		return 0;
	} else {
		uint8_t k;

		/* Determine k as in explained in codec_posit*_to_l() */
		k = util_clz16((in.bits << 1) ^ (in.bits << 2)) + 1;

		return (k + 4 < 16) ? (16 - (k + 4)) : 0;
	}
}

uint8_t
posit32_precision(posit32 t)
{
	const union util_posit32_union in = {
		.value = t,
	};

	if (t == 0 || t == POSIT32_NAR) {
		/* return the worst case precision 0 */
		return 0;
	} else {
		uint8_t k;

		/* Determine k as in explained in codec_posit*_to_l() */
		k = util_clz32((in.bits << 1) ^ (in.bits << 2)) + 1;

		return (k + 4 < 32) ? (32 - (k + 4)) : 0;
	}
}

uint8_t
posit64_precision(posit64 t)
{
	const union util_posit64_union in = {
		.value = t,
	};

	if (t == 0 || t == POSIT64_NAR) {
		/* return the worst case precision 0 */
		return 0;
	} else {
		uint8_t k;

		/* Determine k as in explained in codec_posit*_to_l() */
		k = util_clz64((in.bits << 1) ^ (in.bits << 2)) + 1;

		return (k + 4 < 64) ? (64 - (k + 4)) : 0;
	}
}

uint8_t
posit_log8_precision(posit_log8 t)
{
	/* logarithmic and (linear) posits don't differ here */
	return posit8_precision((posit8)t);
}

uint8_t
posit_log16_precision(posit_log16 t)
{
	/* logarithmic and (linear) posits don't differ here */
	return posit16_precision((posit16)t);
}

uint8_t
posit_log32_precision(posit_log32 t)
{
	/* logarithmic and (linear) posits don't differ here */
	return posit32_precision((posit32)t);
}

uint8_t
posit_log64_precision(posit_log64 t)
{
	/* linear and (logarithmic) posits don't differ here */
	return posit64_precision((posit64)t);
}

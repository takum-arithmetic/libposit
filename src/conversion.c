/* See LICENSE file for copyright and license details. */
#include <math.h>
#include <stdbool.h>

#include "../posit.h"

#include "codec.h"
#include "util.h"

/* Posit conversion helper macros */
#define POSIT_LOG_INTERNAL_CONVERT_EXPAND(FROM, TO)                            \
	do {                                                                   \
		const union util_posit##FROM##_union in = {                    \
			.value = t,                                            \
		};                                                             \
		union util_posit##TO##_union out = {                           \
			.bits = ((uint##TO##_t)in.bits) << (TO - FROM),        \
		};                                                             \
                                                                               \
		return out.value;                                              \
	} while (0);

#define POSIT_LOG_INTERNAL_CONVERT_REDUCE(FROM, TO)                            \
	do {                                                                   \
		const union util_posit##FROM##_union in = {                    \
			.value = t,                                            \
		};                                                             \
		union util_posit##TO##_union out;                              \
                                                                               \
		out.bits = (uint##TO##_t)                                      \
			util_round_uint##FROM##_to_number_of_bits(in.bits,     \
		                                                  TO);         \
                                                                               \
		/* saturate over-/underflows */                                \
		out.bits += (((out.bits == 0) & (in.bits != 0)) -              \
		             ((out.value == POSIT_LOG##TO##_NAR) &             \
		              (in.value != POSIT_LOG##FROM##_NAR))) *          \
		            (1 - 2 * (in.value < 0));                          \
                                                                               \
		return out.value;                                              \
	} while (0);

/* Conversion from float32 */
posit_log8
posit_log8_from_float32(float f)
{
	if (f == 0.0f) {
		return 0;
	} else if (!isfinite(f)) {
		return POSIT_LOG8_NAR;
	} else {
		return codec_posit_log8_from_s_and_l(f < 0,
		                                     log2(fabs((double)f)));
	}
}

posit_log16
posit_log16_from_float32(float f)
{
	if (f == 0.0f) {
		return 0;
	} else if (!isfinite(f)) {
		return POSIT_LOG16_NAR;
	} else {
		return codec_posit_log16_from_s_and_l(f < 0,
		                                      log2(fabs((double)f)));
	}
}

posit_log32
posit_log32_from_float32(float f)
{
	if (f == 0.0f) {
		return 0;
	} else if (!isfinite(f)) {
		return POSIT_LOG32_NAR;
	} else {
		return codec_posit_log32_from_s_and_l(f < 0,
		                                      log2(fabs((double)f)));
	}
}

posit_log64
posit_log64_from_float32(float f)
{
	if (f == 0.0f) {
		return 0;
	} else if (!isfinite(f)) {
		return POSIT_LOG64_NAR;
	} else {
		return codec_posit_log64_from_s_and_l(
			f < 0, log2l(fabsl((long double)f)));
	}
}

posit8
posit8_from_float32(float f)
{
	return (posit8)codec_posit_log8_from_s_and_l(
		f < 0, (float)codec_linear_l_from_float32(f));
}

posit16
posit16_from_float32(float f)
{
	return (posit16)codec_posit_log16_from_s_and_l(
		f < 0, (float)codec_linear_l_from_float32(f));
}

posit32
posit32_from_float32(float f)
{
	return (posit32)codec_posit_log32_from_s_and_l(
		f < 0, codec_linear_l_from_float32(f));
}

posit64
posit64_from_float32(float f)
{
	return (posit64)codec_posit_log64_from_s_and_l(
		f < 0, (long double)codec_linear_l_from_float32(f));
}

/* Conversion from float64 */
posit_log8
posit_log8_from_float64(double f)
{
	if (f == 0.0) {
		return 0;
	} else if (!isfinite(f)) {
		return POSIT_LOG8_NAR;
	} else {
		return posit_log8_from_posit_log64(
			codec_posit_log64_from_s_and_l(
				f < 0, log2l(fabsl((long double)f))));
	}
}

posit_log16
posit_log16_from_float64(double f)
{
	if (f == 0.0) {
		return 0;
	} else if (!isfinite(f)) {
		return POSIT_LOG16_NAR;
	} else {
		return posit_log16_from_posit_log64(
			codec_posit_log64_from_s_and_l(
				f < 0, log2l(fabsl((long double)f))));
	}
}

posit_log32
posit_log32_from_float64(double f)
{
	if (f == 0.0) {
		return 0;
	} else if (!isfinite(f)) {
		return POSIT_LOG32_NAR;
	} else {
		return codec_posit_log32_from_s_and_l(
			f < 0, log2l(fabsl((long double)f)));
	}
}

posit_log64
posit_log64_from_float64(double f)
{
	if (f == 0.0) {
		return 0;
	} else if (!isfinite(f)) {
		return POSIT_LOG64_NAR;
	} else {
		return codec_posit_log64_from_s_and_l(
			f < 0, (long double)(log2l(fabsl((long double)f))));
	}
}

posit8
posit8_from_float64(double f)
{
	return (posit8)codec_posit_log8_from_s_and_l(
		f < 0, (float)codec_linear_l_from_float64(f));
}

posit16
posit16_from_float64(double f)
{
	return (posit16)codec_posit_log16_from_s_and_l(
		f < 0, (float)codec_linear_l_from_float64(f));
}

posit32
posit32_from_float64(double f)
{
	return (posit32)codec_posit_log32_from_s_and_l(
		f < 0, (double)codec_linear_l_from_float64(f));
}

posit64
posit64_from_float64(double f)
{
	return (posit64)codec_posit_log64_from_s_and_l(
		f < 0, codec_linear_l_from_float64(f));
}

/* Conversion from extended float */
posit_log8
posit_log8_from_extended_float(long double f)
{
	if (f == 0.0L) {
		return 0;
	} else if (!isfinite(f)) {
		return POSIT_LOG8_NAR;
	} else {
		return posit_log8_from_posit_log64(
			codec_posit_log64_from_s_and_l(f < 0, log2l(fabsl(f))));
	}
}

posit_log16
posit_log16_from_extended_float(long double f)
{
	if (f == 0.0L) {
		return 0;
	} else if (!isfinite(f)) {
		return POSIT_LOG16_NAR;
	} else {
		return posit_log16_from_posit_log64(
			codec_posit_log64_from_s_and_l(f < 0, log2l(fabsl(f))));
	}
}

posit_log32
posit_log32_from_extended_float(long double f)
{
	if (f == 0.0L) {
		return 0;
	} else if (!isfinite(f)) {
		return POSIT_LOG32_NAR;
	} else {
		return posit_log32_from_posit_log64(
			codec_posit_log64_from_s_and_l(f < 0, log2l(fabsl(f))));
	}
}

posit_log64
posit_log64_from_extended_float(long double f)
{
	if (f == 0.0L) {
		return 0;
	} else if (!isfinite(f)) {
		return POSIT_LOG64_NAR;
	} else {
		return codec_posit_log64_from_s_and_l(f < 0, log2l(fabsl(f)));
	}
}

posit8
posit8_from_extended_float(long double f)
{
	return (posit8)codec_posit_log8_from_s_and_l(
		f < 0, (float)codec_linear_l_from_extended_float(f));
}

posit16
posit16_from_extended_float(long double f)
{
	return (posit16)codec_posit_log16_from_s_and_l(
		f < 0, (float)codec_linear_l_from_extended_float(f));
}

posit32
posit32_from_extended_float(long double f)
{
	return (posit32)codec_posit_log32_from_s_and_l(
		f < 0, (double)codec_linear_l_from_extended_float(f));
}

posit64
posit64_from_extended_float(long double f)
{
	return (posit64)codec_posit_log64_from_s_and_l(
		f < 0, codec_linear_l_from_extended_float(f));
}

/* Conversion from posit_log8 */
posit_log16
posit_log16_from_posit_log8(posit_log8 t)
{
	POSIT_LOG_INTERNAL_CONVERT_EXPAND(8, 16);
}

posit_log32
posit_log32_from_posit_log8(posit_log8 t)
{
	POSIT_LOG_INTERNAL_CONVERT_EXPAND(8, 32);
}

posit_log64
posit_log64_from_posit_log8(posit_log8 t)
{
	POSIT_LOG_INTERNAL_CONVERT_EXPAND(8, 64);
}

posit8
posit8_from_posit_log8(posit_log8 t)
{
	return posit8_from_float64(posit_log8_to_float64(t));
}

posit16
posit16_from_posit_log8(posit_log8 t)
{
	return posit16_from_float64(posit_log8_to_float64(t));
}

posit32
posit32_from_posit_log8(posit_log8 t)
{
	return posit32_from_float64(posit_log8_to_float64(t));
}

posit64
posit64_from_posit_log8(posit_log8 t)
{
	return posit64_from_extended_float(posit_log8_to_extended_float(t));
}

/* Conversion from posit_log16 */
posit_log8
posit_log8_from_posit_log16(posit_log16 t)
{
	POSIT_LOG_INTERNAL_CONVERT_REDUCE(16, 8);
}

posit_log32
posit_log32_from_posit_log16(posit_log16 t)
{
	POSIT_LOG_INTERNAL_CONVERT_EXPAND(16, 32);
}

posit_log64
posit_log64_from_posit_log16(posit_log16 t)
{
	POSIT_LOG_INTERNAL_CONVERT_EXPAND(16, 64);
}

posit8
posit8_from_posit_log16(posit_log16 t)
{
	return posit8_from_float64(posit_log16_to_float64(t));
}

posit16
posit16_from_posit_log16(posit_log16 t)
{
	return posit16_from_float64(posit_log16_to_float64(t));
}

posit32
posit32_from_posit_log16(posit_log16 t)
{
	return posit32_from_float64(posit_log16_to_float64(t));
}

posit64
posit64_from_posit_log16(posit_log16 t)
{
	return posit64_from_extended_float(posit_log16_to_extended_float(t));
}

/* Conversion from posit_log32 */
posit_log8
posit_log8_from_posit_log32(posit_log32 t)
{
	POSIT_LOG_INTERNAL_CONVERT_REDUCE(32, 8);
}

posit_log16
posit_log16_from_posit_log32(posit_log32 t)
{
	POSIT_LOG_INTERNAL_CONVERT_REDUCE(32, 16);
}

posit_log64
posit_log64_from_posit_log32(posit_log32 t)
{
	POSIT_LOG_INTERNAL_CONVERT_EXPAND(32, 64);
}

posit8
posit8_from_posit_log32(posit_log32 t)
{
	return posit8_from_float64(posit_log32_to_float64(t));
}

posit16
posit16_from_posit_log32(posit_log32 t)
{
	return posit16_from_float64(posit_log32_to_float64(t));
}

posit32
posit32_from_posit_log32(posit_log32 t)
{
	return posit32_from_float64(posit_log32_to_float64(t));
}

posit64
posit64_from_posit_log32(posit_log32 t)
{
	return posit64_from_extended_float(posit_log32_to_extended_float(t));
}

/* Conversion from posit_log64 */
posit_log8
posit_log8_from_posit_log64(posit_log64 t)
{
	POSIT_LOG_INTERNAL_CONVERT_REDUCE(64, 8);
}

posit_log16
posit_log16_from_posit_log64(posit_log64 t)
{
	POSIT_LOG_INTERNAL_CONVERT_REDUCE(64, 16);
}

posit_log32
posit_log32_from_posit_log64(posit_log64 t)
{
	POSIT_LOG_INTERNAL_CONVERT_REDUCE(64, 32);
}

posit8
posit8_from_posit_log64(posit_log64 t)
{
	return posit8_from_extended_float(posit_log64_to_extended_float(t));
}

posit16
posit16_from_posit_log64(posit_log64 t)
{
	return posit16_from_extended_float(posit_log64_to_extended_float(t));
}

posit32
posit32_from_posit_log64(posit_log64 t)
{
	return posit32_from_extended_float(posit_log64_to_extended_float(t));
}

posit64
posit64_from_posit_log64(posit_log64 t)
{
	return posit64_from_extended_float(posit_log64_to_extended_float(t));
}

/* Conversion from posit8 */
posit_log8
posit_log8_from_posit8(posit8 t)
{
	return posit_log8_from_float64(posit8_to_float64(t));
}

posit_log16
posit_log16_from_posit8(posit8 t)
{
	return posit_log16_from_float64(posit8_to_float64(t));
}

posit_log32
posit_log32_from_posit8(posit8 t)
{
	return posit_log32_from_float64(posit8_to_float64(t));
}

posit_log64
posit_log64_from_posit8(posit8 t)
{
	return posit_log64_from_extended_float(posit8_to_extended_float(t));
}

posit16
posit16_from_posit8(posit8 t)
{
	POSIT_LOG_INTERNAL_CONVERT_EXPAND(8, 16);
}

posit32
posit32_from_posit8(posit8 t)
{
	POSIT_LOG_INTERNAL_CONVERT_EXPAND(8, 32);
}

posit64
posit64_from_posit8(posit8 t)
{
	POSIT_LOG_INTERNAL_CONVERT_EXPAND(8, 64);
}

/* Conversion from posit16 */
posit_log8
posit_log8_from_posit16(posit16 t)
{
	return posit_log8_from_float64(posit16_to_float64(t));
}

posit_log16
posit_log16_from_posit16(posit16 t)
{
	return posit_log16_from_float64(posit16_to_float64(t));
}

posit_log32
posit_log32_from_posit16(posit16 t)
{
	return posit_log32_from_float64(posit16_to_float64(t));
}

posit_log64
posit_log64_from_posit16(posit16 t)
{
	return posit_log64_from_extended_float(posit16_to_extended_float(t));
}

posit8
posit8_from_posit16(posit16 t)
{
	POSIT_LOG_INTERNAL_CONVERT_REDUCE(16, 8);
}

posit32
posit32_from_posit16(posit16 t)
{
	POSIT_LOG_INTERNAL_CONVERT_EXPAND(16, 32);
}

posit64
posit64_from_posit16(posit16 t)
{
	POSIT_LOG_INTERNAL_CONVERT_EXPAND(16, 64);
}

/* Conversion from posit32 */
posit_log8
posit_log8_from_posit32(posit32 t)
{
	return posit_log8_from_float64(posit32_to_float64(t));
}

posit_log16
posit_log16_from_posit32(posit32 t)
{
	return posit_log16_from_float64(posit32_to_float64(t));
}

posit_log32
posit_log32_from_posit32(posit32 t)
{
	return posit_log32_from_float64(posit32_to_float64(t));
}

posit_log64
posit_log64_from_posit32(posit32 t)
{
	return posit_log64_from_extended_float(posit32_to_extended_float(t));
}

posit8
posit8_from_posit32(posit32 t)
{
	POSIT_LOG_INTERNAL_CONVERT_REDUCE(32, 8);
}

posit16
posit16_from_posit32(posit32 t)
{
	POSIT_LOG_INTERNAL_CONVERT_REDUCE(32, 16);
}

posit64
posit64_from_posit32(posit32 t)
{
	POSIT_LOG_INTERNAL_CONVERT_EXPAND(32, 64);
}

/* Conversion from posit64 */
posit_log8
posit_log8_from_posit64(posit64 t)
{
	return posit_log8_from_extended_float(posit64_to_extended_float(t));
}

posit_log16
posit_log16_from_posit64(posit64 t)
{
	return posit_log16_from_extended_float(posit64_to_extended_float(t));
}

posit_log32
posit_log32_from_posit64(posit64 t)
{
	return posit_log32_from_extended_float(posit64_to_extended_float(t));
}

posit_log64
posit_log64_from_posit64(posit64 t)
{
	return posit_log64_from_extended_float(posit64_to_extended_float(t));
}

posit8
posit8_from_posit64(posit64 t)
{
	POSIT_LOG_INTERNAL_CONVERT_REDUCE(64, 8);
}

posit16
posit16_from_posit64(posit64 t)
{
	POSIT_LOG_INTERNAL_CONVERT_REDUCE(64, 16);
}

posit32
posit32_from_posit64(posit64 t)
{
	POSIT_LOG_INTERNAL_CONVERT_REDUCE(64, 32);
}

/* Conversion to float32 */
float
posit_log8_to_float32(posit_log8 t)
{
	return (t != 0) * (1 - 2 * (t < 0)) *
	       powf(2.0f, codec_posit_log8_to_l(t));
}

float
posit_log16_to_float32(posit_log16 t)
{
	return (t != 0) * (1 - 2 * (t < 0)) *
	       powf(2.0f, codec_posit_log16_to_l(t));
}

float
posit_log32_to_float32(posit_log32 t)
{
	return (t != 0) * (1 - 2 * (t < 0)) *
	       powf(2.0f, (float)codec_posit_log32_to_l(t));
}

float
posit_log64_to_float32(posit_log64 t)
{
	return (t != 0) * (1 - 2 * (t < 0)) *
	       powf(2.0f, (float)codec_posit_log64_to_l(t));
}

float
posit8_to_float32(posit8 t)
{
	return (float)codec_s_and_linear_l_to_float64(
		t < 0, (long double)codec_posit_log8_to_l((posit_log8)t));
}

float
posit16_to_float32(posit16 t)
{
	return (float)codec_s_and_linear_l_to_float64(
		t < 0, (long double)codec_posit_log16_to_l((posit_log16)t));
}

float
posit32_to_float32(posit32 t)
{
	return (float)codec_s_and_linear_l_to_float64(
		t < 0, (long double)codec_posit_log32_to_l((posit_log32)t));
}

float
posit64_to_float32(posit64 t)
{
	return (float)codec_s_and_linear_l_to_float64(
		t < 0, codec_posit_log64_to_l((posit_log64)t));
}

/* Conversion to float64 */
double
posit_log8_to_float64(posit_log8 t)
{
	return (t != 0) * (1 - 2 * (t < 0)) *
	       powl(2.0L, (long double)codec_posit_log8_to_l(t));
}

double
posit_log16_to_float64(posit_log16 t)
{
	return (t != 0) * (1 - 2 * (t < 0)) *
	       pow(2.0, (double)codec_posit_log16_to_l(t));
}

double
posit_log32_to_float64(posit_log32 t)
{
	return (t != 0) * (1 - 2 * (t < 0)) *
	       pow(2.0, codec_posit_log32_to_l(t));
}

double
posit_log64_to_float64(posit_log64 t)
{
	return (t != 0) * (1 - 2 * (t < 0)) *
	       pow(2.0, (double)codec_posit_log64_to_l(t));
}

double
posit8_to_float64(posit8 t)
{
	return codec_s_and_linear_l_to_float64(
		t < 0, (long double)codec_posit_log8_to_l((posit_log8)t));
}

double
posit16_to_float64(posit16 t)
{
	return codec_s_and_linear_l_to_float64(
		t < 0, (long double)codec_posit_log16_to_l((posit_log16)t));
}

double
posit32_to_float64(posit32 t)
{
	return codec_s_and_linear_l_to_float64(
		t < 0, (long double)codec_posit_log32_to_l((posit_log32)t));
}

double
posit64_to_float64(posit64 t)
{
	return codec_s_and_linear_l_to_float64(
		t < 0, codec_posit_log64_to_l((posit_log64)t));
}

/* Conversion to extended float */
long double
posit_log8_to_extended_float(posit_log8 t)
{
	return (t != 0) * (1 - 2 * (t < 0)) *
	       powl(2.0L, (long double)codec_posit_log8_to_l(t));
}

long double
posit_log16_to_extended_float(posit_log16 t)
{
	return (t != 0) * (1 - 2 * (t < 0)) *
	       powl(2.0L, (long double)codec_posit_log16_to_l(t));
}

long double
posit_log32_to_extended_float(posit_log32 t)
{
	return (t != 0) * (1 - 2 * (t < 0)) *
	       powl(2.0L, (long double)codec_posit_log32_to_l(t));
}

long double
posit_log64_to_extended_float(posit_log64 t)
{
	return (t != 0) * (1 - 2 * (t < 0)) *
	       powl(2.0L, codec_posit_log64_to_l(t));
}

long double
posit8_to_extended_float(posit8 t)
{
	return (long double)codec_s_and_linear_l_to_float64(
		t < 0, (double)codec_posit_log8_to_l((posit_log8)t));
}

long double
posit16_to_extended_float(posit16 t)
{
	return (long double)codec_s_and_linear_l_to_float64(
		t < 0, codec_posit_log16_to_l((posit_log16)t));
}

long double
posit32_to_extended_float(posit32 t)
{
	return (long double)codec_s_and_linear_l_to_float64(
		t < 0, codec_posit_log32_to_l((posit_log32)t));
}

long double
posit64_to_extended_float(posit64 t)
{
	return codec_s_and_linear_l_to_extended_float(
		t < 0, codec_posit_log64_to_l((posit_log64)t));
}

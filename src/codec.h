/* See LICENSE file for copyright and license details. */
#ifndef CODEC_H
#define CODEC_H

#include <stdbool.h>

#include "../posit.h"

float codec_posit_log8_to_l(posit_log8);
float codec_posit_log16_to_l(posit_log16);
double codec_posit_log32_to_l(posit_log32);
long double codec_posit_log64_to_l(posit_log64);

double codec_s_and_linear_l_to_float64(bool, long double);
long double codec_s_and_linear_l_to_extended_float(bool, long double);

double codec_linear_l_from_float32(float);
long double codec_linear_l_from_float64(double);
long double codec_linear_l_from_extended_float(long double);

posit_log8 codec_posit_log8_from_s_and_l(bool, float);
posit_log16 codec_posit_log16_from_s_and_l(bool, double);
posit_log32 codec_posit_log32_from_s_and_l(bool, long double);
posit_log64 codec_posit_log64_from_s_and_l(bool, long double);

#endif /* CODEC_H */

/* See LICENSE file for copyright and license details. */
#include <stdint.h>
#include <stdio.h>

#include "../posit.h"
#include "util.h"

#include "../src/codec.h"

posit8
posit8_codec_roundtrip(posit8 t)
{
	return posit8_from_float64(posit8_to_float64(t));
}

posit16
posit16_codec_roundtrip(posit16 t)
{
	return posit16_from_float64(posit16_to_float64(t));
}

posit32
posit32_codec_roundtrip(posit32 t)
{
	return posit32_from_float64(posit32_to_float64(t));
}

posit64
posit64_codec_roundtrip(posit64 t)
{
	return posit64_from_extended_float(posit64_to_extended_float(t));
}

posit_log8
posit_log8_codec_roundtrip(posit_log8 t)
{
	return codec_posit_log8_from_s_and_l(t < 0, codec_posit_log8_to_l(t));
}

posit_log16
posit_log16_codec_roundtrip(posit_log16 t)
{
	return codec_posit_log16_from_s_and_l(t < 0, codec_posit_log16_to_l(t));
}

posit_log32
posit_log32_codec_roundtrip(posit_log32 t)
{
	return codec_posit_log32_from_s_and_l(t < 0, codec_posit_log32_to_l(t));
}

posit_log64
posit_log64_codec_roundtrip(posit_log64 t)
{
	return codec_posit_log64_from_s_and_l(t < 0, codec_posit_log64_to_l(t));
}

static const struct unit_test_block codec_utb = {
	.type = UNIT_TEST_BLOCK_TYPE_ROUNDTRIP,
	.function_name = "to_l/from_s_and_l",
	.data.roundtrip = {
		.posit8_function    = posit8_codec_roundtrip,
		.posit16_function   = posit16_codec_roundtrip,
		.posit32_function   = posit32_codec_roundtrip,
		.posit64_function   = posit64_codec_roundtrip,
		.posit_log8_function    = posit_log8_codec_roundtrip,
		.posit_log16_function   = posit_log16_codec_roundtrip,
		.posit_log32_function   = posit_log32_codec_roundtrip,
		.posit_log64_function   = posit_log64_codec_roundtrip,
	},
};

int
main(int argc, char *argv[])
{
	(void)argc;
	argv0 = argv[0];

	return run_unit_test_block(&codec_utb);
}

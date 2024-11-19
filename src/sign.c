/* See LICENSE file for copyright and license details. */
#include "../posit.h"

#include "util.h"

posit8
posit8_sign(posit8 t)
{
	return (t == POSIT8_NAR) ? POSIT8_NAR :
	       (t < 0)           ? -POSIT8_ONE :
	       (t > 0)           ? POSIT8_ONE :
	                           0;
}

posit16
posit16_sign(posit16 t)
{
	return (t == POSIT16_NAR) ? POSIT16_NAR :
	       (t < 0)            ? -POSIT16_ONE :
	       (t > 0)            ? POSIT16_ONE :
	                            0;
}

posit32
posit32_sign(posit32 t)
{
	return (t == POSIT32_NAR) ? POSIT32_NAR :
	       (t < 0)            ? -POSIT32_ONE :
	       (t > 0)            ? POSIT32_ONE :
	                            0;
}

posit64
posit64_sign(posit64 t)
{
	return (t == POSIT64_NAR) ? POSIT64_NAR :
	       (t < 0)            ? -POSIT64_ONE :
	       (t > 0)            ? POSIT64_ONE :
	                            0;
}

posit_log8
posit_log8_sign(posit_log8 t)
{
	return (t == POSIT_LOG8_NAR) ? POSIT_LOG8_NAR :
	       (t < 0)               ? -POSIT_LOG8_ONE :
	       (t > 0)               ? POSIT_LOG8_ONE :
	                               0;
}

posit_log16
posit_log16_sign(posit_log16 t)
{
	return (t == POSIT_LOG16_NAR) ? POSIT_LOG16_NAR :
	       (t < 0)                ? -POSIT_LOG16_ONE :
	       (t > 0)                ? POSIT_LOG16_ONE :
	                                0;
}

posit_log32
posit_log32_sign(posit_log32 t)
{
	return (t == POSIT_LOG32_NAR) ? POSIT_LOG32_NAR :
	       (t < 0)                ? -POSIT_LOG32_ONE :
	       (t > 0)                ? POSIT_LOG32_ONE :
	                                0;
}

posit_log64
posit_log64_sign(posit_log64 t)
{
	return (t == POSIT_LOG64_NAR) ? POSIT_LOG64_NAR :
	       (t < 0)                ? -POSIT_LOG64_ONE :
	       (t > 0)                ? POSIT_LOG64_ONE :
	                                0;
}

/* See LICENSE file for copyright and license details. */
#include "../posit.h"

#include "util.h"

posit8
posit8_absolute(posit8 t)
{
	return (t < 0) * (-t) + (t >= 0) * t;
}

posit16
posit16_absolute(posit16 t)
{
	return (t < 0) * (-t) + (t >= 0) * t;
}

posit32
posit32_absolute(posit32 t)
{
	return (t < 0) * (-t) + (t >= 0) * t;
}

posit64
posit64_absolute(posit64 t)
{
	return (t < 0) * (-t) + (t >= 0) * t;
}

posit_log8
posit_log8_absolute(posit_log8 t)
{
	return (t < 0) * (-t) + (t >= 0) * t;
}

posit_log16
posit_log16_absolute(posit_log16 t)
{
	return (t < 0) * (-t) + (t >= 0) * t;
}

posit_log32
posit_log32_absolute(posit_log32 t)
{
	return (t < 0) * (-t) + (t >= 0) * t;
}

posit_log64
posit_log64_absolute(posit_log64 t)
{
	return (t < 0) * (-t) + (t >= 0) * t;
}

/* See LICENSE file for copyright and license details. */
#include <inttypes.h>
#include <stdio.h>

#include "../posit.h"
#include "util.h"

struct {
	const char *name;
	long double value;
	posit8 posit8_value;
	posit16 posit16_value;
	posit32 posit32_value;
	posit64 posit64_value;
	posit_log8 posit_log8_value;
	posit_log16 posit_log16_value;
	posit_log32 posit_log32_value;
	posit_log64 posit_log64_value;
} constant_tests[] = {
	{
		.name = "2π",
		.value = 6.2831853071795864769252867665590057683943L,
		.posit8_value = POSIT8_2_PI,
		.posit16_value = POSIT16_2_PI,
		.posit32_value = POSIT32_2_PI,
		.posit64_value = POSIT64_2_PI,
		.posit_log8_value = POSIT_LOG8_2_PI,
		.posit_log16_value = POSIT_LOG16_2_PI,
		.posit_log32_value = POSIT_LOG32_2_PI,
		.posit_log64_value = POSIT_LOG64_2_PI,
	},
	{
		.name = "2π/3",
		.value = 2.0943951023931954923084289221863352561314L,
		.posit8_value = POSIT8_2_PI_OVER_3,
		.posit16_value = POSIT16_2_PI_OVER_3,
		.posit32_value = POSIT32_2_PI_OVER_3,
		.posit64_value = POSIT64_2_PI_OVER_3,
		.posit_log8_value = POSIT_LOG8_2_PI_OVER_3,
		.posit_log16_value = POSIT_LOG16_2_PI_OVER_3,
		.posit_log32_value = POSIT_LOG32_2_PI_OVER_3,
		.posit_log64_value = POSIT_LOG64_2_PI_OVER_3,
	},
	{
		.name = "2π/5",
		.value = 1.2566370614359172953850573533118011536789L,
		.posit8_value = POSIT8_2_PI_OVER_5,
		.posit16_value = POSIT16_2_PI_OVER_5,
		.posit32_value = POSIT32_2_PI_OVER_5,
		.posit64_value = POSIT64_2_PI_OVER_5,
		.posit_log8_value = POSIT_LOG8_2_PI_OVER_5,
		.posit_log16_value = POSIT_LOG16_2_PI_OVER_5,
		.posit_log32_value = POSIT_LOG32_2_PI_OVER_5,
		.posit_log64_value = POSIT_LOG64_2_PI_OVER_5,
	},
	{
		.name = "3π",
		.value = 9.4247779607693797153879301498385086525915L,
		.posit8_value = POSIT8_3_PI,
		.posit16_value = POSIT16_3_PI,
		.posit32_value = POSIT32_3_PI,
		.posit64_value = POSIT64_3_PI,
		.posit_log8_value = POSIT_LOG8_3_PI,
		.posit_log16_value = POSIT_LOG16_3_PI,
		.posit_log32_value = POSIT_LOG32_3_PI,
		.posit_log64_value = POSIT_LOG64_3_PI,
	},
	{
		.name = "3π/2",
		.value = 4.7123889803846898576939650749192543262958L,
		.posit8_value = POSIT8_3_PI_OVER_2,
		.posit16_value = POSIT16_3_PI_OVER_2,
		.posit32_value = POSIT32_3_PI_OVER_2,
		.posit64_value = POSIT64_3_PI_OVER_2,
		.posit_log8_value = POSIT_LOG8_3_PI_OVER_2,
		.posit_log16_value = POSIT_LOG16_3_PI_OVER_2,
		.posit_log32_value = POSIT_LOG32_3_PI_OVER_2,
		.posit_log64_value = POSIT_LOG64_3_PI_OVER_2,
	},
	{
		.name = "3π/4",
		.value = 2.3561944901923449288469825374596271631479L,
		.posit8_value = POSIT8_3_PI_OVER_4,
		.posit16_value = POSIT16_3_PI_OVER_4,
		.posit32_value = POSIT32_3_PI_OVER_4,
		.posit64_value = POSIT64_3_PI_OVER_4,
		.posit_log8_value = POSIT_LOG8_3_PI_OVER_4,
		.posit_log16_value = POSIT_LOG16_3_PI_OVER_4,
		.posit_log32_value = POSIT_LOG32_3_PI_OVER_4,
		.posit_log64_value = POSIT_LOG64_3_PI_OVER_4,
	},
	{
		.name = "3π/5",
		.value = 1.8849555921538759430775860299677017305183L,
		.posit8_value = POSIT8_3_PI_OVER_5,
		.posit16_value = POSIT16_3_PI_OVER_5,
		.posit32_value = POSIT32_3_PI_OVER_5,
		.posit64_value = POSIT64_3_PI_OVER_5,
		.posit_log8_value = POSIT_LOG8_3_PI_OVER_5,
		.posit_log16_value = POSIT_LOG16_3_PI_OVER_5,
		.posit_log32_value = POSIT_LOG32_3_PI_OVER_5,
		.posit_log64_value = POSIT_LOG64_3_PI_OVER_5,
	},
	{
		.name = "4π",
		.value = 12.566370614359172953850573533118011536789L,
		.posit8_value = POSIT8_4_PI,
		.posit16_value = POSIT16_4_PI,
		.posit32_value = POSIT32_4_PI,
		.posit64_value = POSIT64_4_PI,
		.posit_log8_value = POSIT_LOG8_4_PI,
		.posit_log16_value = POSIT_LOG16_4_PI,
		.posit_log32_value = POSIT_LOG32_4_PI,
		.posit_log64_value = POSIT_LOG64_4_PI,
	},
	{
		.name = "4π/3",
		.value = 4.1887902047863909846168578443726705122629L,
		.posit8_value = POSIT8_4_PI_OVER_3,
		.posit16_value = POSIT16_4_PI_OVER_3,
		.posit32_value = POSIT32_4_PI_OVER_3,
		.posit64_value = POSIT64_4_PI_OVER_3,
		.posit_log8_value = POSIT_LOG8_4_PI_OVER_3,
		.posit_log16_value = POSIT_LOG16_4_PI_OVER_3,
		.posit_log32_value = POSIT_LOG32_4_PI_OVER_3,
		.posit_log64_value = POSIT_LOG64_4_PI_OVER_3,
	},
	{
		.name = "4π/5",
		.value = 2.5132741228718345907701147066236023073577L,
		.posit8_value = POSIT8_4_PI_OVER_5,
		.posit16_value = POSIT16_4_PI_OVER_5,
		.posit32_value = POSIT32_4_PI_OVER_5,
		.posit64_value = POSIT64_4_PI_OVER_5,
		.posit_log8_value = POSIT_LOG8_4_PI_OVER_5,
		.posit_log16_value = POSIT_LOG16_4_PI_OVER_5,
		.posit_log32_value = POSIT_LOG32_4_PI_OVER_5,
		.posit_log64_value = POSIT_LOG64_4_PI_OVER_5,
	},
	{
		.name = "5π",
		.value = 15.707963267948966192313216916397514420986L,
		.posit8_value = POSIT8_5_PI,
		.posit16_value = POSIT16_5_PI,
		.posit32_value = POSIT32_5_PI,
		.posit64_value = POSIT64_5_PI,
		.posit_log8_value = POSIT_LOG8_5_PI,
		.posit_log16_value = POSIT_LOG16_5_PI,
		.posit_log32_value = POSIT_LOG32_5_PI,
		.posit_log64_value = POSIT_LOG64_5_PI,
	},
	{
		.name = "5π/2",
		.value = 7.8539816339744830961566084581987572104929L,
		.posit8_value = POSIT8_5_PI_OVER_2,
		.posit16_value = POSIT16_5_PI_OVER_2,
		.posit32_value = POSIT32_5_PI_OVER_2,
		.posit64_value = POSIT64_5_PI_OVER_2,
		.posit_log8_value = POSIT_LOG8_5_PI_OVER_2,
		.posit_log16_value = POSIT_LOG16_5_PI_OVER_2,
		.posit_log32_value = POSIT_LOG32_5_PI_OVER_2,
		.posit_log64_value = POSIT_LOG64_5_PI_OVER_2,
	},
	{
		.name = "5π/3",
		.value = 5.2359877559829887307710723054658381403286L,
		.posit8_value = POSIT8_5_PI_OVER_3,
		.posit16_value = POSIT16_5_PI_OVER_3,
		.posit32_value = POSIT32_5_PI_OVER_3,
		.posit64_value = POSIT64_5_PI_OVER_3,
		.posit_log8_value = POSIT_LOG8_5_PI_OVER_3,
		.posit_log16_value = POSIT_LOG16_5_PI_OVER_3,
		.posit_log32_value = POSIT_LOG32_5_PI_OVER_3,
		.posit_log64_value = POSIT_LOG64_5_PI_OVER_3,
	},
	{
		.name = "5π/4",
		.value = 3.9269908169872415480783042290993786052465L,
		.posit8_value = POSIT8_5_PI_OVER_4,
		.posit16_value = POSIT16_5_PI_OVER_4,
		.posit32_value = POSIT32_5_PI_OVER_4,
		.posit64_value = POSIT64_5_PI_OVER_4,
		.posit_log8_value = POSIT_LOG8_5_PI_OVER_4,
		.posit_log16_value = POSIT_LOG16_5_PI_OVER_4,
		.posit_log32_value = POSIT_LOG32_5_PI_OVER_4,
		.posit_log64_value = POSIT_LOG64_5_PI_OVER_4,
	},
	{
		.name = "5π/6",
		.value = 2.6179938779914943653855361527329190701643L,
		.posit8_value = POSIT8_5_PI_OVER_6,
		.posit16_value = POSIT16_5_PI_OVER_6,
		.posit32_value = POSIT32_5_PI_OVER_6,
		.posit64_value = POSIT64_5_PI_OVER_6,
		.posit_log8_value = POSIT_LOG8_5_PI_OVER_6,
		.posit_log16_value = POSIT_LOG16_5_PI_OVER_6,
		.posit_log32_value = POSIT_LOG32_5_PI_OVER_6,
		.posit_log64_value = POSIT_LOG64_5_PI_OVER_6,
	},
	{
		.name = "6π",
		.value = 18.849555921538759430775860299677017305183L,
		.posit8_value = POSIT8_6_PI,
		.posit16_value = POSIT16_6_PI,
		.posit32_value = POSIT32_6_PI,
		.posit64_value = POSIT64_6_PI,
		.posit_log8_value = POSIT_LOG8_6_PI,
		.posit_log16_value = POSIT_LOG16_6_PI,
		.posit_log32_value = POSIT_LOG32_6_PI,
		.posit_log64_value = POSIT_LOG64_6_PI,
	},
	{
		.name = "6π/5",
		.value = 3.7699111843077518861551720599354034610366L,
		.posit8_value = POSIT8_6_PI_OVER_5,
		.posit16_value = POSIT16_6_PI_OVER_5,
		.posit32_value = POSIT32_6_PI_OVER_5,
		.posit64_value = POSIT64_6_PI_OVER_5,
		.posit_log8_value = POSIT_LOG8_6_PI_OVER_5,
		.posit_log16_value = POSIT_LOG16_6_PI_OVER_5,
		.posit_log32_value = POSIT_LOG32_6_PI_OVER_5,
		.posit_log64_value = POSIT_LOG64_6_PI_OVER_5,
	},
	{
		.name = "γ",
		.value = 0.5772156649015328606065120900824024310422L,
		.posit8_value = POSIT8_GAMMA,
		.posit16_value = POSIT16_GAMMA,
		.posit32_value = POSIT32_GAMMA,
		.posit64_value = POSIT64_GAMMA,
		.posit_log8_value = POSIT_LOG8_GAMMA,
		.posit_log16_value = POSIT_LOG16_GAMMA,
		.posit_log32_value = POSIT_LOG32_GAMMA,
		.posit_log64_value = POSIT_LOG64_GAMMA,
	},
	{
		.name = "lb(10)",
		.value = 3.3219280948873623478703194294893901758648L,
		.posit8_value = POSIT8_LB_10,
		.posit16_value = POSIT16_LB_10,
		.posit32_value = POSIT32_LB_10,
		.posit64_value = POSIT64_LB_10,
		.posit_log8_value = POSIT_LOG8_LB_10,
		.posit_log16_value = POSIT_LOG16_LB_10,
		.posit_log32_value = POSIT_LOG32_LB_10,
		.posit_log64_value = POSIT_LOG64_LB_10,
	},
	{
		.name = "lb(e)",
		.value = 1.4426950408889634073599246810018921374266L,
		.posit8_value = POSIT8_LB_E,
		.posit16_value = POSIT16_LB_E,
		.posit32_value = POSIT32_LB_E,
		.posit64_value = POSIT64_LB_E,
		.posit_log8_value = POSIT_LOG8_LB_E,
		.posit_log16_value = POSIT_LOG16_LB_E,
		.posit_log32_value = POSIT_LOG32_LB_E,
		.posit_log64_value = POSIT_LOG64_LB_E,
	},
	{
		.name = "lg(2)",
		.value = 0.3010299956639811952137388947244930267682L,
		.posit8_value = POSIT8_LG_2,
		.posit16_value = POSIT16_LG_2,
		.posit32_value = POSIT32_LG_2,
		.posit64_value = POSIT64_LG_2,
		.posit_log8_value = POSIT_LOG8_LG_2,
		.posit_log16_value = POSIT_LOG16_LG_2,
		.posit_log32_value = POSIT_LOG32_LG_2,
		.posit_log64_value = POSIT_LOG64_LG_2,
	},
	{
		.name = "lg(e)",
		.value = 0.4342944819032518276511289189166050822944L,
		.posit8_value = POSIT8_LG_E,
		.posit16_value = POSIT16_LG_E,
		.posit32_value = POSIT32_LG_E,
		.posit64_value = POSIT64_LG_E,
		.posit_log8_value = POSIT_LOG8_LG_E,
		.posit_log16_value = POSIT_LOG16_LG_E,
		.posit_log32_value = POSIT_LOG32_LG_E,
		.posit_log64_value = POSIT_LOG64_LG_E,
	},
	{
		.name = "ln(10)",
		.value = 2.3025850929940456840179914546843642076011L,
		.posit8_value = POSIT8_LN_10,
		.posit16_value = POSIT16_LN_10,
		.posit32_value = POSIT32_LN_10,
		.posit64_value = POSIT64_LN_10,
		.posit_log8_value = POSIT_LOG8_LN_10,
		.posit_log16_value = POSIT_LOG16_LN_10,
		.posit_log32_value = POSIT_LOG32_LN_10,
		.posit_log64_value = POSIT_LOG64_LN_10,
	},
	{
		.name = "ln(2)",
		.value = 0.6931471805599453094172321214581765680755L,
		.posit8_value = POSIT8_LN_2,
		.posit16_value = POSIT16_LN_2,
		.posit32_value = POSIT32_LN_2,
		.posit64_value = POSIT64_LN_2,
		.posit_log8_value = POSIT_LOG8_LN_2,
		.posit_log16_value = POSIT_LOG16_LN_2,
		.posit_log32_value = POSIT_LOG32_LN_2,
		.posit_log64_value = POSIT_LOG64_LN_2,
	},
	{
		.name = "1",
		.value = 1.0L,
		.posit8_value = POSIT8_ONE,
		.posit16_value = POSIT16_ONE,
		.posit32_value = POSIT32_ONE,
		.posit64_value = POSIT64_ONE,
		.posit_log8_value = POSIT_LOG8_ONE,
		.posit_log16_value = POSIT_LOG16_ONE,
		.posit_log32_value = POSIT_LOG32_ONE,
		.posit_log64_value = POSIT_LOG64_ONE,
	},
	{
		.name = "φ",
		.value = 1.6180339887498948482045868343656381177203L,
		.posit8_value = POSIT8_PHI,
		.posit16_value = POSIT16_PHI,
		.posit32_value = POSIT32_PHI,
		.posit64_value = POSIT64_PHI,
		.posit_log8_value = POSIT_LOG8_PHI,
		.posit_log16_value = POSIT_LOG16_PHI,
		.posit_log32_value = POSIT_LOG32_PHI,
		.posit_log64_value = POSIT_LOG64_PHI,
	},
	{
		.name = "π",
		.value = 3.1415926535897932384626433832795028841972L,
		.posit8_value = POSIT8_PI,
		.posit16_value = POSIT16_PI,
		.posit32_value = POSIT32_PI,
		.posit64_value = POSIT64_PI,
		.posit_log8_value = POSIT_LOG8_PI,
		.posit_log16_value = POSIT_LOG16_PI,
		.posit_log32_value = POSIT_LOG32_PI,
		.posit_log64_value = POSIT_LOG64_PI,
	},
	{
		.name = "π/2",
		.value = 1.5707963267948966192313216916397514420986L,
		.posit8_value = POSIT8_PI_OVER_2,
		.posit16_value = POSIT16_PI_OVER_2,
		.posit32_value = POSIT32_PI_OVER_2,
		.posit64_value = POSIT64_PI_OVER_2,
		.posit_log8_value = POSIT_LOG8_PI_OVER_2,
		.posit_log16_value = POSIT_LOG16_PI_OVER_2,
		.posit_log32_value = POSIT_LOG32_PI_OVER_2,
		.posit_log64_value = POSIT_LOG64_PI_OVER_2,
	},
	{
		.name = "π/3",
		.value = 1.0471975511965977461542144610931676280657L,
		.posit8_value = POSIT8_PI_OVER_3,
		.posit16_value = POSIT16_PI_OVER_3,
		.posit32_value = POSIT32_PI_OVER_3,
		.posit64_value = POSIT64_PI_OVER_3,
		.posit_log8_value = POSIT_LOG8_PI_OVER_3,
		.posit_log16_value = POSIT_LOG16_PI_OVER_3,
		.posit_log32_value = POSIT_LOG32_PI_OVER_3,
		.posit_log64_value = POSIT_LOG64_PI_OVER_3,
	},
	{
		.name = "π/4",
		.value = 0.78539816339744830961566084581987572104929L,
		.posit8_value = POSIT8_PI_OVER_4,
		.posit16_value = POSIT16_PI_OVER_4,
		.posit32_value = POSIT32_PI_OVER_4,
		.posit64_value = POSIT64_PI_OVER_4,
		.posit_log8_value = POSIT_LOG8_PI_OVER_4,
		.posit_log16_value = POSIT_LOG16_PI_OVER_4,
		.posit_log32_value = POSIT_LOG32_PI_OVER_4,
		.posit_log64_value = POSIT_LOG64_PI_OVER_4,
	},
	{
		.name = "π/5",
		.value = 0.62831853071795864769252867665590057683943L,
		.posit8_value = POSIT8_PI_OVER_5,
		.posit16_value = POSIT16_PI_OVER_5,
		.posit32_value = POSIT32_PI_OVER_5,
		.posit64_value = POSIT64_PI_OVER_5,
		.posit_log8_value = POSIT_LOG8_PI_OVER_5,
		.posit_log16_value = POSIT_LOG16_PI_OVER_5,
		.posit_log32_value = POSIT_LOG32_PI_OVER_5,
		.posit_log64_value = POSIT_LOG64_PI_OVER_5,
	},
	{
		.name = "π/6",
		.value = 0.52359877559829887307710723054658381403286L,
		.posit8_value = POSIT8_PI_OVER_6,
		.posit16_value = POSIT16_PI_OVER_6,
		.posit32_value = POSIT32_PI_OVER_6,
		.posit64_value = POSIT64_PI_OVER_6,
		.posit_log8_value = POSIT_LOG8_PI_OVER_6,
		.posit_log16_value = POSIT_LOG16_PI_OVER_6,
		.posit_log32_value = POSIT_LOG32_PI_OVER_6,
		.posit_log64_value = POSIT_LOG64_PI_OVER_6,
	},
	{
		.name = "√2",
		.value = 1.4142135623730950488016887242096980785697L,
		.posit8_value = POSIT8_SQUARE_ROOT_2,
		.posit16_value = POSIT16_SQUARE_ROOT_2,
		.posit32_value = POSIT32_SQUARE_ROOT_2,
		.posit64_value = POSIT64_SQUARE_ROOT_2,
		.posit_log8_value = POSIT_LOG8_SQUARE_ROOT_2,
		.posit_log16_value = POSIT_LOG16_SQUARE_ROOT_2,
		.posit_log32_value = POSIT_LOG32_SQUARE_ROOT_2,
		.posit_log64_value = POSIT_LOG64_SQUARE_ROOT_2,
	},
	{
		.name = "√3",
		.value = 1.7320508075688772935274463415058723669428L,
		.posit8_value = POSIT8_SQUARE_ROOT_3,
		.posit16_value = POSIT16_SQUARE_ROOT_3,
		.posit32_value = POSIT32_SQUARE_ROOT_3,
		.posit64_value = POSIT64_SQUARE_ROOT_3,
		.posit_log8_value = POSIT_LOG8_SQUARE_ROOT_3,
		.posit_log16_value = POSIT_LOG16_SQUARE_ROOT_3,
		.posit_log32_value = POSIT_LOG32_SQUARE_ROOT_3,
		.posit_log64_value = POSIT_LOG64_SQUARE_ROOT_3,
	},
	{
		.name = "√5",
		.value = 2.2360679774997896964091736687312762354406L,
		.posit8_value = POSIT8_SQUARE_ROOT_5,
		.posit16_value = POSIT16_SQUARE_ROOT_5,
		.posit32_value = POSIT32_SQUARE_ROOT_5,
		.posit64_value = POSIT64_SQUARE_ROOT_5,
		.posit_log8_value = POSIT_LOG8_SQUARE_ROOT_5,
		.posit_log16_value = POSIT_LOG16_SQUARE_ROOT_5,
		.posit_log32_value = POSIT_LOG32_SQUARE_ROOT_5,
		.posit_log64_value = POSIT_LOG64_SQUARE_ROOT_5,
	},
	{
		.name = "√6",
		.value = 2.4494897427831780981972840747058913919659L,
		.posit8_value = POSIT8_SQUARE_ROOT_6,
		.posit16_value = POSIT16_SQUARE_ROOT_6,
		.posit32_value = POSIT32_SQUARE_ROOT_6,
		.posit64_value = POSIT64_SQUARE_ROOT_6,
		.posit_log8_value = POSIT_LOG8_SQUARE_ROOT_6,
		.posit_log16_value = POSIT_LOG16_SQUARE_ROOT_6,
		.posit_log32_value = POSIT_LOG32_SQUARE_ROOT_6,
		.posit_log64_value = POSIT_LOG64_SQUARE_ROOT_6,
	},
};

int
main(int argc, char *argv[])
{
	size_t i, failed_count;
	posit8 posit8_reference_value;
	posit16 posit16_reference_value;
	posit32 posit32_reference_value;
	posit64 posit64_reference_value;
	posit_log8 posit_log8_reference_value;
	posit_log16 posit_log16_reference_value;
	posit_log32 posit_log32_reference_value;
	posit_log64 posit_log64_reference_value;

	(void)argc;
	argv0 = argv[0];

	for (i = 0, failed_count = 0; i < LEN(constant_tests); i++) {
		posit8_reference_value =
			posit8_from_extended_float(constant_tests[i].value);

		if (constant_tests[i].posit8_value != posit8_reference_value) {
			fprintf(stderr,
			        "%s: %s: Failed posit8 unit test "
			        "(constant wrongly defined as %" PRIi8
			        " instead of %" PRIi8 ")\n",
			        argv0, constant_tests[i].name,
			        constant_tests[i].posit8_value,
			        posit8_reference_value);
			failed_count++;
		}

		posit16_reference_value =
			posit16_from_extended_float(constant_tests[i].value);

		if (constant_tests[i].posit16_value !=
		    posit16_reference_value) {
			fprintf(stderr,
			        "%s: %s: Failed posit16 unit test "
			        "(constant wrongly defined as %" PRIi16
			        " instead of %" PRIi16 ")\n",
			        argv0, constant_tests[i].name,
			        constant_tests[i].posit16_value,
			        posit16_reference_value);
			failed_count++;
		}

		posit32_reference_value =
			posit32_from_extended_float(constant_tests[i].value);

		if (constant_tests[i].posit32_value !=
		    posit32_reference_value) {
			fprintf(stderr,
			        "%s: %s: Failed posit32 unit test "
			        "(constant wrongly defined as %" PRIi32
			        " instead of %" PRIi32 ")\n",
			        argv0, constant_tests[i].name,
			        constant_tests[i].posit32_value,
			        posit32_reference_value);
			failed_count++;
		}

		posit64_reference_value =
			posit64_from_extended_float(constant_tests[i].value);

		if (constant_tests[i].posit64_value !=
		    posit64_reference_value) {
			fprintf(stderr,
			        "%s: %s: Failed posit64 unit test "
			        "(constant wrongly defined as %" PRIi64
			        " instead of %" PRIi64 ")\n",
			        argv0, constant_tests[i].name,
			        constant_tests[i].posit64_value,
			        posit64_reference_value);
			failed_count++;
		}

		posit_log8_reference_value =
			posit_log8_from_extended_float(constant_tests[i].value);

		if (constant_tests[i].posit_log8_value !=
		    posit_log8_reference_value) {
			fprintf(stderr,
			        "%s: %s: Failed posit_log8 unit test "
			        "(constant wrongly defined as %" PRIi8
			        " instead of %" PRIi8 ")\n",
			        argv0, constant_tests[i].name,
			        constant_tests[i].posit_log8_value,
			        posit_log8_reference_value);
			failed_count++;
		}

		posit_log16_reference_value = posit_log16_from_extended_float(
			constant_tests[i].value);

		if (constant_tests[i].posit_log16_value !=
		    posit_log16_reference_value) {
			fprintf(stderr,
			        "%s: %s: Failed posit_log16 unit test "
			        "(constant wrongly defined as %" PRIi16
			        " instead of %" PRIi16 ")\n",
			        argv0, constant_tests[i].name,
			        constant_tests[i].posit_log16_value,
			        posit_log16_reference_value);
			failed_count++;
		}

		posit_log32_reference_value = posit_log32_from_extended_float(
			constant_tests[i].value);

		if (constant_tests[i].posit_log32_value !=
		    posit_log32_reference_value) {
			fprintf(stderr,
			        "%s: %s: Failed posit_log32 unit test "
			        "(constant wrongly defined as %" PRIi32
			        " instead of %" PRIi32 ")\n",
			        argv0, constant_tests[i].name,
			        constant_tests[i].posit_log32_value,
			        posit_log32_reference_value);
			failed_count++;
		}

		posit_log64_reference_value = posit_log64_from_extended_float(
			constant_tests[i].value);

		if (constant_tests[i].posit_log64_value !=
		    posit_log64_reference_value) {
			fprintf(stderr,
			        "%s: %s: Failed posit_log64 unit test "
			        "(constant wrongly defined as %" PRIi64
			        " instead of %" PRIi64 ")\n",
			        argv0, constant_tests[i].name,
			        constant_tests[i].posit_log64_value,
			        posit_log64_reference_value);
			failed_count++;
		}
	}

	printf("%s: %zu/%zu unit tests passed.\n", argv0,
	       8 * LEN(constant_tests) - failed_count, 8 * LEN(constant_tests));

	return failed_count;
}

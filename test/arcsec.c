/* See LICENSE file for copyright and license details. */
#include "../posit.h"
#include "util.h"

#include <math.h>

long double
arcsec_reference(long double a)
{
	return acosl(1.0L / a);
}

static const struct unit_test_block arcsec_utb = {
	.type = UNIT_TEST_BLOCK_TYPE_POSIT_POSIT,
	.function_name = "arcsec",
	.data.posit_posit = {
		.reference_function = arcsec_reference,
		.posit8_function    = posit8_arcsec,
		.posit16_function   = posit16_arcsec,
		.posit32_function   = posit32_arcsec,
		.posit64_function   = posit64_arcsec,
		.posit_log8_function    = posit_log8_arcsec,
		.posit_log16_function   = posit_log16_arcsec,
		.posit_log32_function   = posit_log32_arcsec,
		.posit_log64_function   = posit_log64_arcsec,
	},
};

long double
arcsec_over_pi_reference(long double a)
{
	return acosl(1.0L / a) / PI;
}

static const struct unit_test_block arcsec_over_pi_utb = {
	.type = UNIT_TEST_BLOCK_TYPE_POSIT_POSIT,
	.function_name = "arcsec_over_pi",
	.data.posit_posit = {
		.reference_function = arcsec_over_pi_reference,
		.posit8_function    = posit8_arcsec_over_pi,
		.posit16_function   = posit16_arcsec_over_pi,
		.posit32_function   = posit32_arcsec_over_pi,
		.posit64_function   = posit64_arcsec_over_pi,
		.posit_log8_function    = posit_log8_arcsec_over_pi,
		.posit_log16_function   = posit_log16_arcsec_over_pi,
		.posit_log32_function   = posit_log32_arcsec_over_pi,
		.posit_log64_function   = posit_log64_arcsec_over_pi,
	},
};

int
main(int argc, char *argv[])
{
	(void)argc;
	argv0 = argv[0];

	return run_unit_test_block(&arcsec_utb) +
	       run_unit_test_block(&arcsec_over_pi_utb);
}

# See LICENSE file for copyright and license details
# libposit - posit arithmetic C99 implementation
.POSIX:
.SUFFIXES:

VERSION_MAJOR = 1
VERSION_MINOR = 0
VERSION_PATCH = 2
MAN_DATE = 2025-09-10

include config.mk

VERSION = $(VERSION_MAJOR).$(VERSION_MINOR).$(VERSION_PATCH)

EXAMPLE =\
	example/calculator\

SRC =\
	src/10_raised\
	src/2_raised\
	src/absolute\
	src/addition\
	src/arccos\
	src/arccot\
	src/arccsc\
	src/arcosh\
	src/arcoth\
	src/arcsch\
	src/arcsec\
	src/arcsin\
	src/arctan\
	src/arctan2\
	src/arsech\
	src/arsinh\
	src/artanh\
	src/codec\
	src/conversion\
	src/cos\
	src/cosh\
	src/cot\
	src/coth\
	src/csc\
	src/csch\
	src/integer_power\
	src/division\
	src/exp\
	src/hypotenuse\
	src/inversion\
	src/lb\
	src/lg\
	src/ln\
	src/multiplication\
	src/power\
	src/precision\
	src/root\
	src/sec\
	src/sech\
	src/sign\
	src/sin\
	src/sinh\
	src/square_root\
	src/subtraction\
	src/tan\
	src/tanh\
	src/util\

TEST =\
	test/10_raised\
	test/2_raised\
	test/absolute\
	test/addition\
	test/arccos\
	test/arccot\
	test/arccsc\
	test/arcosh\
	test/arcoth\
	test/arcsch\
	test/arcsec\
	test/arcsin\
	test/arctan\
	test/arctan2\
	test/arsech\
	test/arsinh\
	test/artanh\
	test/codec\
	test/constants\
	test/conversion\
	test/cos\
	test/cosh\
	test/cot\
	test/coth\
	test/csc\
	test/csch\
	test/division\
	test/exp\
	test/hypotenuse\
	test/integer_power\
	test/inversion\
	test/lb\
	test/lg\
	test/ln\
	test/multiplication\
	test/power\
	test/precision\
	test/root\
	test/sec\
	test/sech\
	test/sign\
	test/sin\
	test/sinh\
	test/square_root\
	test/subtraction\
	test/tan\
	test/tanh\

MAN_TEMPLATE =\
	man/template/conversion_from_float.sh\
	man/template/conversion_to_float.sh\
	man/template/math_function.sh\

MAN3 =\
	man/posit8_10_raised\
	man/posit16_10_raised\
	man/posit32_10_raised\
	man/posit64_10_raised\
	man/posit_log8_10_raised\
	man/posit_log16_10_raised\
	man/posit_log32_10_raised\
	man/posit_log64_10_raised\
	man/posit8_10_raised_minus_1\
	man/posit16_10_raised_minus_1\
	man/posit32_10_raised_minus_1\
	man/posit64_10_raised_minus_1\
	man/posit_log8_10_raised_minus_1\
	man/posit_log16_10_raised_minus_1\
	man/posit_log32_10_raised_minus_1\
	man/posit_log64_10_raised_minus_1\
	man/posit8_2_raised\
	man/posit16_2_raised\
	man/posit32_2_raised\
	man/posit64_2_raised\
	man/posit_log8_2_raised\
	man/posit_log16_2_raised\
	man/posit_log32_2_raised\
	man/posit_log64_2_raised\
	man/posit8_2_raised_minus_1\
	man/posit16_2_raised_minus_1\
	man/posit32_2_raised_minus_1\
	man/posit64_2_raised_minus_1\
	man/posit_log8_2_raised_minus_1\
	man/posit_log16_2_raised_minus_1\
	man/posit_log32_2_raised_minus_1\
	man/posit_log64_2_raised_minus_1\
	man/posit8_absolute\
	man/posit16_absolute\
	man/posit32_absolute\
	man/posit64_absolute\
	man/posit_log8_absolute\
	man/posit_log16_absolute\
	man/posit_log32_absolute\
	man/posit_log64_absolute\
	man/posit8_addition\
	man/posit16_addition\
	man/posit32_addition\
	man/posit64_addition\
	man/posit_log8_addition\
	man/posit_log16_addition\
	man/posit_log32_addition\
	man/posit_log64_addition\
	man/posit8_arccos\
	man/posit16_arccos\
	man/posit32_arccos\
	man/posit64_arccos\
	man/posit_log8_arccos\
	man/posit_log16_arccos\
	man/posit_log32_arccos\
	man/posit_log64_arccos\
	man/posit8_arccos_over_pi\
	man/posit16_arccos_over_pi\
	man/posit32_arccos_over_pi\
	man/posit64_arccos_over_pi\
	man/posit_log8_arccos_over_pi\
	man/posit_log16_arccos_over_pi\
	man/posit_log32_arccos_over_pi\
	man/posit_log64_arccos_over_pi\
	man/posit8_arccot\
	man/posit16_arccot\
	man/posit32_arccot\
	man/posit64_arccot\
	man/posit_log8_arccot\
	man/posit_log16_arccot\
	man/posit_log32_arccot\
	man/posit_log64_arccot\
	man/posit8_arccot_over_pi\
	man/posit16_arccot_over_pi\
	man/posit32_arccot_over_pi\
	man/posit64_arccot_over_pi\
	man/posit_log8_arccot_over_pi\
	man/posit_log16_arccot_over_pi\
	man/posit_log32_arccot_over_pi\
	man/posit_log64_arccot_over_pi\
	man/posit8_arccsc\
	man/posit16_arccsc\
	man/posit32_arccsc\
	man/posit64_arccsc\
	man/posit_log8_arccsc\
	man/posit_log16_arccsc\
	man/posit_log32_arccsc\
	man/posit_log64_arccsc\
	man/posit8_arccsc_over_pi\
	man/posit16_arccsc_over_pi\
	man/posit32_arccsc_over_pi\
	man/posit64_arccsc_over_pi\
	man/posit_log8_arccsc_over_pi\
	man/posit_log16_arccsc_over_pi\
	man/posit_log32_arccsc_over_pi\
	man/posit_log64_arccsc_over_pi\
	man/posit8_arcosh\
	man/posit16_arcosh\
	man/posit32_arcosh\
	man/posit64_arcosh\
	man/posit_log8_arcosh\
	man/posit_log16_arcosh\
	man/posit_log32_arcosh\
	man/posit_log64_arcosh\
	man/posit8_arcoth\
	man/posit16_arcoth\
	man/posit32_arcoth\
	man/posit64_arcoth\
	man/posit_log8_arcoth\
	man/posit_log16_arcoth\
	man/posit_log32_arcoth\
	man/posit_log64_arcoth\
	man/posit8_arcsch\
	man/posit16_arcsch\
	man/posit32_arcsch\
	man/posit64_arcsch\
	man/posit_log8_arcsch\
	man/posit_log16_arcsch\
	man/posit_log32_arcsch\
	man/posit_log64_arcsch\
	man/posit8_arcsec\
	man/posit16_arcsec\
	man/posit32_arcsec\
	man/posit64_arcsec\
	man/posit_log8_arcsec\
	man/posit_log16_arcsec\
	man/posit_log32_arcsec\
	man/posit_log64_arcsec\
	man/posit8_arcsec_over_pi\
	man/posit16_arcsec_over_pi\
	man/posit32_arcsec_over_pi\
	man/posit64_arcsec_over_pi\
	man/posit_log8_arcsec_over_pi\
	man/posit_log16_arcsec_over_pi\
	man/posit_log32_arcsec_over_pi\
	man/posit_log64_arcsec_over_pi\
	man/posit8_arcsin\
	man/posit16_arcsin\
	man/posit32_arcsin\
	man/posit64_arcsin\
	man/posit_log8_arcsin\
	man/posit_log16_arcsin\
	man/posit_log32_arcsin\
	man/posit_log64_arcsin\
	man/posit8_arcsin_over_pi\
	man/posit16_arcsin_over_pi\
	man/posit32_arcsin_over_pi\
	man/posit64_arcsin_over_pi\
	man/posit_log8_arcsin_over_pi\
	man/posit_log16_arcsin_over_pi\
	man/posit_log32_arcsin_over_pi\
	man/posit_log64_arcsin_over_pi\
	man/posit8_arctan2\
	man/posit16_arctan2\
	man/posit32_arctan2\
	man/posit64_arctan2\
	man/posit_log8_arctan2\
	man/posit_log16_arctan2\
	man/posit_log32_arctan2\
	man/posit_log64_arctan2\
	man/posit8_arctan2_over_pi\
	man/posit16_arctan2_over_pi\
	man/posit32_arctan2_over_pi\
	man/posit64_arctan2_over_pi\
	man/posit_log8_arctan2_over_pi\
	man/posit_log16_arctan2_over_pi\
	man/posit_log32_arctan2_over_pi\
	man/posit_log64_arctan2_over_pi\
	man/posit8_arctan\
	man/posit16_arctan\
	man/posit32_arctan\
	man/posit64_arctan\
	man/posit_log8_arctan\
	man/posit_log16_arctan\
	man/posit_log32_arctan\
	man/posit_log64_arctan\
	man/posit8_arctan_over_pi\
	man/posit16_arctan_over_pi\
	man/posit32_arctan_over_pi\
	man/posit64_arctan_over_pi\
	man/posit_log8_arctan_over_pi\
	man/posit_log16_arctan_over_pi\
	man/posit_log32_arctan_over_pi\
	man/posit_log64_arctan_over_pi\
	man/posit8_arsech\
	man/posit16_arsech\
	man/posit32_arsech\
	man/posit64_arsech\
	man/posit_log8_arsech\
	man/posit_log16_arsech\
	man/posit_log32_arsech\
	man/posit_log64_arsech\
	man/posit8_arsinh\
	man/posit16_arsinh\
	man/posit32_arsinh\
	man/posit64_arsinh\
	man/posit_log8_arsinh\
	man/posit_log16_arsinh\
	man/posit_log32_arsinh\
	man/posit_log64_arsinh\
	man/posit8_artanh\
	man/posit16_artanh\
	man/posit32_artanh\
	man/posit64_artanh\
	man/posit_log8_artanh\
	man/posit_log16_artanh\
	man/posit_log32_artanh\
	man/posit_log64_artanh\
	man/posit8_cos\
	man/posit16_cos\
	man/posit32_cos\
	man/posit64_cos\
	man/posit_log8_cos\
	man/posit_log16_cos\
	man/posit_log32_cos\
	man/posit_log64_cos\
	man/posit8_cos_pi_times\
	man/posit16_cos_pi_times\
	man/posit32_cos_pi_times\
	man/posit64_cos_pi_times\
	man/posit_log8_cos_pi_times\
	man/posit_log16_cos_pi_times\
	man/posit_log32_cos_pi_times\
	man/posit_log64_cos_pi_times\
	man/posit8_cosh\
	man/posit16_cosh\
	man/posit32_cosh\
	man/posit64_cosh\
	man/posit_log8_cosh\
	man/posit_log16_cosh\
	man/posit_log32_cosh\
	man/posit_log64_cosh\
	man/posit8_cot\
	man/posit16_cot\
	man/posit32_cot\
	man/posit64_cot\
	man/posit_log8_cot\
	man/posit_log16_cot\
	man/posit_log32_cot\
	man/posit_log64_cot\
	man/posit8_cot_pi_times\
	man/posit16_cot_pi_times\
	man/posit32_cot_pi_times\
	man/posit64_cot_pi_times\
	man/posit_log8_cot_pi_times\
	man/posit_log16_cot_pi_times\
	man/posit_log32_cot_pi_times\
	man/posit_log64_cot_pi_times\
	man/posit8_coth\
	man/posit16_coth\
	man/posit32_coth\
	man/posit64_coth\
	man/posit_log8_coth\
	man/posit_log16_coth\
	man/posit_log32_coth\
	man/posit_log64_coth\
	man/posit8_csc\
	man/posit16_csc\
	man/posit32_csc\
	man/posit64_csc\
	man/posit_log8_csc\
	man/posit_log16_csc\
	man/posit_log32_csc\
	man/posit_log64_csc\
	man/posit8_csc_pi_times\
	man/posit16_csc_pi_times\
	man/posit32_csc_pi_times\
	man/posit64_csc_pi_times\
	man/posit_log8_csc_pi_times\
	man/posit_log16_csc_pi_times\
	man/posit_log32_csc_pi_times\
	man/posit_log64_csc_pi_times\
	man/posit8_csch\
	man/posit16_csch\
	man/posit32_csch\
	man/posit64_csch\
	man/posit_log8_csch\
	man/posit_log16_csch\
	man/posit_log32_csch\
	man/posit_log64_csch\
	man/posit8_division\
	man/posit16_division\
	man/posit32_division\
	man/posit64_division\
	man/posit_log8_division\
	man/posit_log16_division\
	man/posit_log32_division\
	man/posit_log64_division\
	man/posit8_exp\
	man/posit16_exp\
	man/posit32_exp\
	man/posit64_exp\
	man/posit_log8_exp\
	man/posit_log16_exp\
	man/posit_log32_exp\
	man/posit_log64_exp\
	man/posit8_exp_minus_1\
	man/posit16_exp_minus_1\
	man/posit32_exp_minus_1\
	man/posit64_exp_minus_1\
	man/posit_log8_exp_minus_1\
	man/posit_log16_exp_minus_1\
	man/posit_log32_exp_minus_1\
	man/posit_log64_exp_minus_1\
	man/posit8_from_extended_float\
	man/posit16_from_extended_float\
	man/posit32_from_extended_float\
	man/posit64_from_extended_float\
	man/posit_log8_from_extended_float\
	man/posit_log16_from_extended_float\
	man/posit_log32_from_extended_float\
	man/posit_log64_from_extended_float\
	man/posit8_from_float32\
	man/posit16_from_float32\
	man/posit32_from_float32\
	man/posit64_from_float32\
	man/posit_log8_from_float32\
	man/posit_log16_from_float32\
	man/posit_log32_from_float32\
	man/posit_log64_from_float32\
	man/posit8_from_float64\
	man/posit16_from_float64\
	man/posit32_from_float64\
	man/posit64_from_float64\
	man/posit_log8_from_float64\
	man/posit_log16_from_float64\
	man/posit_log32_from_float64\
	man/posit_log64_from_float64\
	man/posit16_from_posit8\
	man/posit32_from_posit8\
	man/posit64_from_posit8\
	man/posit_log8_from_posit8\
	man/posit_log16_from_posit8\
	man/posit_log32_from_posit8\
	man/posit_log64_from_posit8\
	man/posit8_from_posit16\
	man/posit32_from_posit16\
	man/posit64_from_posit16\
	man/posit_log8_from_posit16\
	man/posit_log16_from_posit16\
	man/posit_log32_from_posit16\
	man/posit_log64_from_posit16\
	man/posit8_from_posit32\
	man/posit16_from_posit32\
	man/posit64_from_posit32\
	man/posit_log8_from_posit32\
	man/posit_log16_from_posit32\
	man/posit_log32_from_posit32\
	man/posit_log64_from_posit32\
	man/posit8_from_posit64\
	man/posit16_from_posit64\
	man/posit32_from_posit64\
	man/posit_log8_from_posit64\
	man/posit_log16_from_posit64\
	man/posit_log32_from_posit64\
	man/posit_log64_from_posit64\
	man/posit8_from_posit_log8\
	man/posit16_from_posit_log8\
	man/posit32_from_posit_log8\
	man/posit64_from_posit_log8\
	man/posit_log16_from_posit_log8\
	man/posit_log32_from_posit_log8\
	man/posit_log64_from_posit_log8\
	man/posit8_from_posit_log16\
	man/posit16_from_posit_log16\
	man/posit32_from_posit_log16\
	man/posit64_from_posit_log16\
	man/posit_log8_from_posit_log16\
	man/posit_log32_from_posit_log16\
	man/posit_log64_from_posit_log16\
	man/posit8_from_posit_log32\
	man/posit16_from_posit_log32\
	man/posit32_from_posit_log32\
	man/posit64_from_posit_log32\
	man/posit_log8_from_posit_log32\
	man/posit_log16_from_posit_log32\
	man/posit_log64_from_posit_log32\
	man/posit8_from_posit_log64\
	man/posit16_from_posit_log64\
	man/posit32_from_posit_log64\
	man/posit64_from_posit_log64\
	man/posit_log8_from_posit_log64\
	man/posit_log16_from_posit_log64\
	man/posit_log32_from_posit_log64\
	man/posit8_hypotenuse\
	man/posit16_hypotenuse\
	man/posit32_hypotenuse\
	man/posit64_hypotenuse\
	man/posit_log8_hypotenuse\
	man/posit_log16_hypotenuse\
	man/posit_log32_hypotenuse\
	man/posit_log64_hypotenuse\
	man/posit8_integer_power\
	man/posit16_integer_power\
	man/posit32_integer_power\
	man/posit64_integer_power\
	man/posit_log8_integer_power\
	man/posit_log16_integer_power\
	man/posit_log32_integer_power\
	man/posit_log64_integer_power\
	man/posit8_inversion\
	man/posit16_inversion\
	man/posit32_inversion\
	man/posit64_inversion\
	man/posit_log8_inversion\
	man/posit_log16_inversion\
	man/posit_log32_inversion\
	man/posit_log64_inversion\
	man/posit8_lb\
	man/posit16_lb\
	man/posit32_lb\
	man/posit64_lb\
	man/posit_log8_lb\
	man/posit_log16_lb\
	man/posit_log32_lb\
	man/posit_log64_lb\
	man/posit8_lb_1_plus\
	man/posit16_lb_1_plus\
	man/posit32_lb_1_plus\
	man/posit64_lb_1_plus\
	man/posit_log8_lb_1_plus\
	man/posit_log16_lb_1_plus\
	man/posit_log32_lb_1_plus\
	man/posit_log64_lb_1_plus\
	man/posit8_lg\
	man/posit16_lg\
	man/posit32_lg\
	man/posit64_lg\
	man/posit_log8_lg\
	man/posit_log16_lg\
	man/posit_log32_lg\
	man/posit_log64_lg\
	man/posit8_lg_1_plus\
	man/posit16_lg_1_plus\
	man/posit32_lg_1_plus\
	man/posit64_lg_1_plus\
	man/posit_log8_lg_1_plus\
	man/posit_log16_lg_1_plus\
	man/posit_log32_lg_1_plus\
	man/posit_log64_lg_1_plus\
	man/posit8_ln\
	man/posit16_ln\
	man/posit32_ln\
	man/posit64_ln\
	man/posit_log8_ln\
	man/posit_log16_ln\
	man/posit_log32_ln\
	man/posit_log64_ln\
	man/posit8_ln_1_plus\
	man/posit16_ln_1_plus\
	man/posit32_ln_1_plus\
	man/posit64_ln_1_plus\
	man/posit_log8_ln_1_plus\
	man/posit_log16_ln_1_plus\
	man/posit_log32_ln_1_plus\
	man/posit_log64_ln_1_plus\
	man/posit8_multiplication\
	man/posit16_multiplication\
	man/posit32_multiplication\
	man/posit64_multiplication\
	man/posit_log8_multiplication\
	man/posit_log16_multiplication\
	man/posit_log32_multiplication\
	man/posit_log64_multiplication\
	man/posit8_power\
	man/posit16_power\
	man/posit32_power\
	man/posit64_power\
	man/posit_log8_power\
	man/posit_log16_power\
	man/posit_log32_power\
	man/posit_log64_power\
	man/posit8_precision\
	man/posit16_precision\
	man/posit32_precision\
	man/posit64_precision\
	man/posit_log8_precision\
	man/posit_log16_precision\
	man/posit_log32_precision\
	man/posit_log64_precision\
	man/posit8_root\
	man/posit16_root\
	man/posit32_root\
	man/posit64_root\
	man/posit_log8_root\
	man/posit_log16_root\
	man/posit_log32_root\
	man/posit_log64_root\
	man/posit8_sec\
	man/posit16_sec\
	man/posit32_sec\
	man/posit64_sec\
	man/posit_log8_sec\
	man/posit_log16_sec\
	man/posit_log32_sec\
	man/posit_log64_sec\
	man/posit8_sec_pi_times\
	man/posit16_sec_pi_times\
	man/posit32_sec_pi_times\
	man/posit64_sec_pi_times\
	man/posit_log8_sec_pi_times\
	man/posit_log16_sec_pi_times\
	man/posit_log32_sec_pi_times\
	man/posit_log64_sec_pi_times\
	man/posit8_sech\
	man/posit16_sech\
	man/posit32_sech\
	man/posit64_sech\
	man/posit_log8_sech\
	man/posit_log16_sech\
	man/posit_log32_sech\
	man/posit_log64_sech\
	man/posit8_sign\
	man/posit16_sign\
	man/posit32_sign\
	man/posit64_sign\
	man/posit_log8_sign\
	man/posit_log16_sign\
	man/posit_log32_sign\
	man/posit_log64_sign\
	man/posit8_sin\
	man/posit16_sin\
	man/posit32_sin\
	man/posit64_sin\
	man/posit_log8_sin\
	man/posit_log16_sin\
	man/posit_log32_sin\
	man/posit_log64_sin\
	man/posit8_sin_pi_times\
	man/posit16_sin_pi_times\
	man/posit32_sin_pi_times\
	man/posit64_sin_pi_times\
	man/posit_log8_sin_pi_times\
	man/posit_log16_sin_pi_times\
	man/posit_log32_sin_pi_times\
	man/posit_log64_sin_pi_times\
	man/posit8_sinh\
	man/posit16_sinh\
	man/posit32_sinh\
	man/posit64_sinh\
	man/posit_log8_sinh\
	man/posit_log16_sinh\
	man/posit_log32_sinh\
	man/posit_log64_sinh\
	man/posit8_square_root\
	man/posit16_square_root\
	man/posit32_square_root\
	man/posit64_square_root\
	man/posit_log8_square_root\
	man/posit_log16_square_root\
	man/posit_log32_square_root\
	man/posit_log64_square_root\
	man/posit8_subtraction\
	man/posit16_subtraction\
	man/posit32_subtraction\
	man/posit64_subtraction\
	man/posit_log8_subtraction\
	man/posit_log16_subtraction\
	man/posit_log32_subtraction\
	man/posit_log64_subtraction\
	man/posit8_tan\
	man/posit16_tan\
	man/posit32_tan\
	man/posit64_tan\
	man/posit_log8_tan\
	man/posit_log16_tan\
	man/posit_log32_tan\
	man/posit_log64_tan\
	man/posit8_tan_pi_times\
	man/posit16_tan_pi_times\
	man/posit32_tan_pi_times\
	man/posit64_tan_pi_times\
	man/posit_log8_tan_pi_times\
	man/posit_log16_tan_pi_times\
	man/posit_log32_tan_pi_times\
	man/posit_log64_tan_pi_times\
	man/posit8_tanh\
	man/posit16_tanh\
	man/posit32_tanh\
	man/posit64_tanh\
	man/posit_log8_tanh\
	man/posit_log16_tanh\
	man/posit_log32_tanh\
	man/posit_log64_tanh\
	man/posit8_to_extended_float\
	man/posit16_to_extended_float\
	man/posit32_to_extended_float\
	man/posit64_to_extended_float\
	man/posit_log8_to_extended_float\
	man/posit_log16_to_extended_float\
	man/posit_log32_to_extended_float\
	man/posit_log64_to_extended_float\
	man/posit8_to_float32\
	man/posit16_to_float32\
	man/posit32_to_float32\
	man/posit64_to_float32\
	man/posit_log8_to_float32\
	man/posit_log16_to_float32\
	man/posit_log32_to_float32\
	man/posit_log64_to_float32\
	man/posit8_to_float64\
	man/posit16_to_float64\
	man/posit32_to_float64\
	man/posit64_to_float64\
	man/posit_log8_to_float64\
	man/posit_log16_to_float64\
	man/posit_log32_to_float64\
	man/posit_log64_to_float64\

MAN7 = man/libposit

all: $(MAN3:=.3) $(MAN7:=.7) $(ANAME) $(SONAME)

example/calculator.o: example/calculator.c Makefile config.mk posit.h example/util.h
example/util.o: example/util.c Makefile config.mk posit.h example/util.h
src/addition.o: src/addition.c Makefile config.mk posit.h src/util.h
src/arccos.o: src/arccos.c Makefile config.mk posit.h src/util.h
src/arccot.o: src/arccot.c Makefile config.mk posit.h src/util.h
src/arccsc.o: src/arccsc.c Makefile config.mk posit.h src/util.h
src/arcosh.o: src/arcosh.c Makefile config.mk posit.h src/util.h
src/arcoth.o: src/arcoth.c Makefile config.mk posit.h src/util.h
src/arcsch.o: src/arcsch.c Makefile config.mk posit.h src/util.h
src/arcsec.o: src/arcsec.c Makefile config.mk posit.h src/util.h
src/arcsin.o: src/arcsin.c Makefile config.mk posit.h src/util.h
src/arctan.o: src/arctan.c Makefile config.mk posit.h src/util.h
src/arctan2.o: src/arctan2.c Makefile config.mk posit.h src/util.h
src/arsech.o: src/arsech.c Makefile config.mk posit.h src/util.h
src/arsinh.o: src/arsinh.c Makefile config.mk posit.h src/util.h
src/artanh.o: src/artanh.c Makefile config.mk posit.h src/util.h
src/codec.o: src/codec.c Makefile config.mk posit.h src/util.h
src/conversion.o: src/conversion.c Makefile config.mk posit.h src/util.h
src/cos.o: src/cos.c Makefile config.mk posit.h src/util.h
src/cot.o: src/cot.c Makefile config.mk posit.h src/util.h
src/cosh.o: src/cosh.c Makefile config.mk posit.h src/util.h
src/coth.o: src/coth.c Makefile config.mk posit.h src/util.h
src/csc.o: src/csc.c Makefile config.mk posit.h src/util.h
src/csch.o: src/csch.c Makefile config.mk posit.h src/util.h
src/division.o: src/division.c Makefile config.mk posit.h src/util.h
src/exp.o: src/exp.c Makefile config.mk posit.h src/util.h
src/exp2.o: src/exp2.c Makefile config.mk posit.h src/util.h
src/exp10.o: src/exp10.c Makefile config.mk posit.h src/util.h
src/hypotenuse.o: src/hypotenuse.c Makefile config.mk posit.h src/util.h
src/inversion.o: src/inversion.c Makefile config.mk posit.h src/util.h
src/lb.o: src/lb.c Makefile config.mk posit.h src/util.h
src/lg.o: src/lg.c Makefile config.mk posit.h src/util.h
src/ln.o: src/ln.c Makefile config.mk posit.h src/util.h
src/multiplication.o: src/multiplication.c Makefile config.mk posit.h src/util.h
src/power.o: src/power.c Makefile config.mk posit.h src/util.h
src/precision.o: src/precision.c Makefile config.mk posit.h src/util.h
src/sec.o: src/sec.c Makefile config.mk posit.h src/util.h
src/sech.o: src/sech.c Makefile config.mk posit.h src/util.h
src/sin.o: src/sin.c Makefile config.mk posit.h src/util.h
src/sinh.o: src/sinh.c Makefile config.mk posit.h src/util.h
src/square_root.o: src/square_root.c Makefile config.mk posit.h src/util.h
src/subtraction.o: src/subtraction.c Makefile config.mk posit.h src/util.h
src/tan.o: src/tan.c Makefile config.mk posit.h src/util.h
src/tanh.o: src/tanh.c Makefile config.mk posit.h src/util.h
src/util.o: src/util.c Makefile config.mk posit.h src/util.h
test/10_raised.o: test/10_raised.c Makefile config.mk posit.h test/util.h
test/2_raised.o: test/2_raised.c Makefile config.mk posit.h test/util.h
test/absolute.o: test/absolute.c Makefile config.mk posit.h test/util.h
test/addition.o: test/addition.c Makefile config.mk posit.h test/util.h
test/arccos.o: test/arccos.c Makefile config.mk posit.h test/util.h
test/arccot.o: test/arccot.c Makefile config.mk posit.h test/util.h
test/arccsc.o: test/arccsc.c Makefile config.mk posit.h test/util.h
test/arcosh.o: test/arcosh.c Makefile config.mk posit.h test/util.h
test/arcoth.o: test/arcoth.c Makefile config.mk posit.h test/util.h
test/arcsch.o: test/arcsch.c Makefile config.mk posit.h test/util.h
test/arcsec.o: test/arcsec.c Makefile config.mk posit.h test/util.h
test/arcsin.o: test/arcsin.c Makefile config.mk posit.h test/util.h
test/arctan.o: test/arctan.c Makefile config.mk posit.h test/util.h
test/arctan2.o: test/arctan2.c Makefile config.mk posit.h test/util.h
test/arsech.o: test/arsech.c Makefile config.mk posit.h test/util.h
test/arsinh.o: test/arsinh.c Makefile config.mk posit.h test/util.h
test/artanh.o: test/artanh.c Makefile config.mk posit.h test/util.h
test/codec.o: test/codec.c Makefile config.mk posit.h test/util.h
test/constants.o: test/constants.c Makefile config.mk posit.h test/util.h
test/conversion.o: test/conversion.c Makefile config.mk posit.h test/util.h
test/cos.o: test/cos.c Makefile config.mk posit.h test/util.h
test/cosh.o: test/cosh.c Makefile config.mk posit.h test/util.h
test/cot.o: test/cot.c Makefile config.mk posit.h test/util.h
test/coth.o: test/coth.c Makefile config.mk posit.h test/util.h
test/csc.o: test/csc.c Makefile config.mk posit.h test/util.h
test/csch.o: test/csch.c Makefile config.mk posit.h test/util.h
test/division.o: test/division.c Makefile config.mk posit.h test/util.h
test/exp.o: test/exp.c Makefile config.mk posit.h test/util.h
test/hypotenuse.o: test/hypotenuse.c Makefile config.mk posit.h test/util.h
test/integer_power.o: test/integer_power.c Makefile config.mk posit.h test/util.h
test/inversion.o: test/inversion.c Makefile config.mk posit.h test/util.h
test/lb.o: test/lb.c Makefile config.mk posit.h test/util.h
test/lg.o: test/lg.c Makefile config.mk posit.h test/util.h
test/ln.o: test/ln.c Makefile config.mk posit.h test/util.h
test/multiplication.o: test/multiplication.c Makefile config.mk posit.h test/util.h
test/power.o: test/power.c Makefile config.mk posit.h test/util.h
test/precision.o: test/precision.c Makefile config.mk posit.h test/util.h
test/root.o: test/root.c Makefile config.mk posit.h test/util.h
test/sec.o: test/sec.c Makefile config.mk posit.h test/util.h
test/sech.o: test/sech.c Makefile config.mk posit.h test/util.h
test/sign.o: test/sign.c Makefile config.mk posit.h test/util.h
test/sin.o: test/sin.c Makefile config.mk posit.h test/util.h
test/sinh.o: test/sinh.c Makefile config.mk posit.h test/util.h
test/square_root.o: test/square_root.c Makefile config.mk posit.h test/util.h
test/subtraction.o: test/subtraction.c Makefile config.mk posit.h test/util.h
test/tan.o: test/tan.c Makefile config.mk posit.h test/util.h
test/tanh.o: test/tanh.c Makefile config.mk posit.h test/util.h
test/util.o: test/util.c Makefile config.mk posit.h test/util.h

$(ANAME) $(SONAME): $(SRC:=.o)

example/calculator$(BINSUFFIX): example/calculator.o example/util.o $(ANAME)
test/10_raised$(BINSUFFIX): test/10_raised.o test/util.o $(ANAME)
test/2_raised$(BINSUFFIX): test/2_raised.o test/util.o $(ANAME)
test/absolute$(BINSUFFIX): test/absolute.o test/util.o $(ANAME)
test/addition$(BINSUFFIX): test/addition.o test/util.o $(ANAME)
test/arccos$(BINSUFFIX): test/arccos.o test/util.o $(ANAME)
test/arccot$(BINSUFFIX): test/arccot.o test/util.o $(ANAME)
test/arccsc$(BINSUFFIX): test/arccsc.o test/util.o $(ANAME)
test/arcosh$(BINSUFFIX): test/arcosh.o test/util.o $(ANAME)
test/arcoth$(BINSUFFIX): test/arcoth.o test/util.o $(ANAME)
test/arcsch$(BINSUFFIX): test/arcsch.o test/util.o $(ANAME)
test/arcsec$(BINSUFFIX): test/arcsec.o test/util.o $(ANAME)
test/arcsin$(BINSUFFIX): test/arcsin.o test/util.o $(ANAME)
test/arctan$(BINSUFFIX): test/arctan.o test/util.o $(ANAME)
test/arctan2$(BINSUFFIX): test/arctan2.o test/util.o $(ANAME)
test/arsech$(BINSUFFIX): test/arsech.o test/util.o $(ANAME)
test/arsinh$(BINSUFFIX): test/arsinh.o test/util.o $(ANAME)
test/artanh$(BINSUFFIX): test/artanh.o test/util.o $(ANAME)
test/codec$(BINSUFFIX): test/codec.o test/util.o $(ANAME)
test/constants$(BINSUFFIX): test/constants.o test/util.o $(ANAME)
test/conversion$(BINSUFFIX): test/conversion.o test/util.o $(ANAME)
test/cos$(BINSUFFIX): test/cos.o test/util.o $(ANAME)
test/cosh$(BINSUFFIX): test/cosh.o test/util.o $(ANAME)
test/cot$(BINSUFFIX): test/cot.o test/util.o $(ANAME)
test/coth$(BINSUFFIX): test/coth.o test/util.o $(ANAME)
test/csc$(BINSUFFIX): test/csc.o test/util.o $(ANAME)
test/csch$(BINSUFFIX): test/csch.o test/util.o $(ANAME)
test/division$(BINSUFFIX): test/division.o test/util.o $(ANAME)
test/exp$(BINSUFFIX): test/exp.o test/util.o $(ANAME)
test/hypotenuse$(BINSUFFIX): test/hypotenuse.o test/util.o $(ANAME)
test/integer_power$(BINSUFFIX): test/integer_power.o test/util.o $(ANAME)
test/inversion$(BINSUFFIX): test/inversion.o test/util.o $(ANAME)
test/lb$(BINSUFFIX): test/lb.o test/util.o $(ANAME)
test/lg$(BINSUFFIX): test/lg.o test/util.o $(ANAME)
test/ln$(BINSUFFIX): test/ln.o test/util.o $(ANAME)
test/multiplication$(BINSUFFIX): test/multiplication.o test/util.o $(ANAME)
test/power$(BINSUFFIX): test/power.o test/util.o $(ANAME)
test/precision$(BINSUFFIX): test/precision.o test/util.o $(ANAME)
test/root$(BINSUFFIX): test/root.o test/util.o $(ANAME)
test/sec$(BINSUFFIX): test/sec.o test/util.o $(ANAME)
test/sech$(BINSUFFIX): test/sech.o test/util.o $(ANAME)
test/sign$(BINSUFFIX): test/sign.o test/util.o $(ANAME)
test/sin$(BINSUFFIX): test/sin.o test/util.o $(ANAME)
test/sinh$(BINSUFFIX): test/sinh.o test/util.o $(ANAME)
test/square_root$(BINSUFFIX): test/square_root.o test/util.o $(ANAME)
test/subtraction$(BINSUFFIX): test/subtraction.o test/util.o $(ANAME)
test/tan$(BINSUFFIX): test/tan.o test/util.o $(ANAME)
test/tanh$(BINSUFFIX): test/tanh.o test/util.o $(ANAME)

test/10_raised.success: test/10_raised$(BINSUFFIX)
test/2_raised.success: test/2_raised$(BINSUFFIX)
test/absolute.success: test/absolute$(BINSUFFIX)
test/addition.success: test/addition$(BINSUFFIX)
test/arccos.success: test/arccos$(BINSUFFIX)
test/arccot.success: test/arccot$(BINSUFFIX)
test/arccsc.success: test/arccsc$(BINSUFFIX)
test/arcosh.success: test/arcosh$(BINSUFFIX)
test/arcoth.success: test/arcoth$(BINSUFFIX)
test/arcsch.success: test/arcsch$(BINSUFFIX)
test/arcsec.success: test/arcsec$(BINSUFFIX)
test/arcsin.success: test/arcsin$(BINSUFFIX)
test/arctan.success: test/arctan$(BINSUFFIX)
test/arctan2.success: test/arctan2$(BINSUFFIX)
test/arsech.success: test/arsech$(BINSUFFIX)
test/arsinh.success: test/arsinh$(BINSUFFIX)
test/artanh.success: test/artanh$(BINSUFFIX)
test/codec.success: test/codec$(BINSUFFIX)
test/constants.success: test/constants$(BINSUFFIX)
test/conversion.success: test/conversion$(BINSUFFIX)
test/cos.success: test/cos$(BINSUFFIX)
test/cosh.success: test/cosh$(BINSUFFIX)
test/cot.success: test/cot$(BINSUFFIX)
test/coth.success: test/coth$(BINSUFFIX)
test/csc.success: test/csc$(BINSUFFIX)
test/csch.success: test/csch$(BINSUFFIX)
test/division.success: test/division$(BINSUFFIX)
test/exp.success: test/exp$(BINSUFFIX)
test/hypotenuse.success: test/hypotenuse$(BINSUFFIX)
test/integer_power.success: test/integer_power$(BINSUFFIX)
test/inversion.success: test/inversion$(BINSUFFIX)
test/lb.success: test/lb$(BINSUFFIX)
test/lg.success: test/lg$(BINSUFFIX)
test/ln.success: test/ln$(BINSUFFIX)
test/multiplication.success: test/multiplication$(BINSUFFIX)
test/power.success: test/power$(BINSUFFIX)
test/precision.success: test/precision$(BINSUFFIX)
test/root.success: test/root$(BINSUFFIX)
test/sec.success: test/sec$(BINSUFFIX)
test/sech.success: test/sech$(BINSUFFIX)
test/sign.success: test/sign$(BINSUFFIX)
test/sin.success: test/sin$(BINSUFFIX)
test/sinh.success: test/sinh$(BINSUFFIX)
test/square_root.success: test/square_root$(BINSUFFIX)
test/subtraction.success: test/subtraction$(BINSUFFIX)
test/tan.success: test/tan$(BINSUFFIX)
test/tanh.success: test/tanh$(BINSUFFIX)

man/posit8_10_raised.3: man/posit8_10_raised.sh man/posit64_10_raised.sh man/template/math_function.sh Makefile config.mk
man/posit16_10_raised.3: man/posit16_10_raised.sh man/posit64_10_raised.sh man/template/math_function.sh Makefile config.mk
man/posit32_10_raised.3: man/posit32_10_raised.sh man/posit64_10_raised.sh man/template/math_function.sh Makefile config.mk
man/posit64_10_raised.3: man/posit64_10_raised.sh man/template/math_function.sh Makefile config.mk
man/posit8_10_raised_minus_1.3: man/posit8_10_raised_minus_1.sh man/posit64_10_raised_minus_1.sh man/template/math_function.sh Makefile config.mk
man/posit16_10_raised_minus_1.3: man/posit16_10_raised_minus_1.sh man/posit64_10_raised_minus_1.sh man/template/math_function.sh Makefile config.mk
man/posit32_10_raised_minus_1.3: man/posit32_10_raised_minus_1.sh man/posit64_10_raised_minus_1.sh man/template/math_function.sh Makefile config.mk
man/posit64_10_raised_minus_1.3: man/posit64_10_raised_minus_1.sh man/template/math_function.sh Makefile config.mk
man/posit8_2_raised.3: man/posit8_2_raised.sh man/posit64_2_raised.sh man/template/math_function.sh Makefile config.mk
man/posit16_2_raised.3: man/posit16_2_raised.sh man/posit64_2_raised.sh man/template/math_function.sh Makefile config.mk
man/posit32_2_raised.3: man/posit32_2_raised.sh man/posit64_2_raised.sh man/template/math_function.sh Makefile config.mk
man/posit64_2_raised.3: man/posit64_2_raised.sh man/template/math_function.sh Makefile config.mk
man/posit8_2_raised_minus_1.3: man/posit8_2_raised_minus_1.sh man/posit64_2_raised_minus_1.sh man/template/math_function.sh Makefile config.mk
man/posit16_2_raised_minus_1.3: man/posit16_2_raised_minus_1.sh man/posit64_2_raised_minus_1.sh man/template/math_function.sh Makefile config.mk
man/posit32_2_raised_minus_1.3: man/posit32_2_raised_minus_1.sh man/posit64_2_raised_minus_1.sh man/template/math_function.sh Makefile config.mk
man/posit64_2_raised_minus_1.3: man/posit64_2_raised_minus_1.sh man/template/math_function.sh Makefile config.mk
man/posit8_absolute.3: man/posit8_absolute.sh man/posit64_absolute.sh man/template/math_function.sh Makefile config.mk
man/posit16_absolute.3: man/posit16_absolute.sh man/posit64_absolute.sh man/template/math_function.sh Makefile config.mk
man/posit32_absolute.3: man/posit32_absolute.sh man/posit64_absolute.sh man/template/math_function.sh Makefile config.mk
man/posit64_absolute.3: man/posit64_absolute.sh man/template/math_function.sh Makefile config.mk
man/posit8_addition.3: man/posit8_addition.sh man/posit64_addition.sh man/template/math_function.sh Makefile config.mk
man/posit16_addition.3: man/posit16_addition.sh man/posit64_addition.sh man/template/math_function.sh Makefile config.mk
man/posit32_addition.3: man/posit32_addition.sh man/posit64_addition.sh man/template/math_function.sh Makefile config.mk
man/posit64_addition.3: man/posit64_addition.sh man/template/math_function.sh Makefile config.mk
man/posit8_arccos.3: man/posit8_arccos.sh man/posit64_arccos.sh man/template/math_function.sh Makefile config.mk
man/posit16_arccos.3: man/posit16_arccos.sh man/posit64_arccos.sh man/template/math_function.sh Makefile config.mk
man/posit32_arccos.3: man/posit32_arccos.sh man/posit64_arccos.sh man/template/math_function.sh Makefile config.mk
man/posit64_arccos.3: man/posit64_arccos.sh man/template/math_function.sh Makefile config.mk
man/posit8_arccos_over_pi.3: man/posit8_arccos_over_pi.sh man/posit64_arccos_over_pi.sh man/template/math_function.sh Makefile config.mk
man/posit16_arccos_over_pi.3: man/posit16_arccos_over_pi.sh man/posit64_arccos_over_pi.sh man/template/math_function.sh Makefile config.mk
man/posit32_arccos_over_pi.3: man/posit32_arccos_over_pi.sh man/posit64_arccos_over_pi.sh man/template/math_function.sh Makefile config.mk
man/posit64_arccos_over_pi.3: man/posit64_arccos_over_pi.sh man/template/math_function.sh Makefile config.mk
man/posit8_arccot.3: man/posit8_arccot.sh man/posit64_arccot.sh man/template/math_function.sh Makefile config.mk
man/posit16_arccot.3: man/posit16_arccot.sh man/posit64_arccot.sh man/template/math_function.sh Makefile config.mk
man/posit32_arccot.3: man/posit32_arccot.sh man/posit64_arccot.sh man/template/math_function.sh Makefile config.mk
man/posit64_arccot.3: man/posit64_arccot.sh man/template/math_function.sh Makefile config.mk
man/posit8_arccot_over_pi.3: man/posit8_arccot_over_pi.sh man/posit64_arccot_over_pi.sh man/template/math_function.sh Makefile config.mk
man/posit16_arccot_over_pi.3: man/posit16_arccot_over_pi.sh man/posit64_arccot_over_pi.sh man/template/math_function.sh Makefile config.mk
man/posit32_arccot_over_pi.3: man/posit32_arccot_over_pi.sh man/posit64_arccot_over_pi.sh man/template/math_function.sh Makefile config.mk
man/posit64_arccot_over_pi.3: man/posit64_arccot_over_pi.sh man/template/math_function.sh Makefile config.mk
man/posit8_arccsc.3: man/posit8_arccsc.sh man/posit64_arccsc.sh man/template/math_function.sh Makefile config.mk
man/posit16_arccsc.3: man/posit16_arccsc.sh man/posit64_arccsc.sh man/template/math_function.sh Makefile config.mk
man/posit32_arccsc.3: man/posit32_arccsc.sh man/posit64_arccsc.sh man/template/math_function.sh Makefile config.mk
man/posit64_arccsc.3: man/posit64_arccsc.sh man/template/math_function.sh Makefile config.mk
man/posit8_arccsc_over_pi.3: man/posit8_arccsc_over_pi.sh man/posit64_arccsc_over_pi.sh man/template/math_function.sh Makefile config.mk
man/posit16_arccsc_over_pi.3: man/posit16_arccsc_over_pi.sh man/posit64_arccsc_over_pi.sh man/template/math_function.sh Makefile config.mk
man/posit32_arccsc_over_pi.3: man/posit32_arccsc_over_pi.sh man/posit64_arccsc_over_pi.sh man/template/math_function.sh Makefile config.mk
man/posit64_arccsc_over_pi.3: man/posit64_arccsc_over_pi.sh man/template/math_function.sh Makefile config.mk
man/posit8_arcosh.3: man/posit8_arcosh.sh man/posit64_arcosh.sh man/template/math_function.sh Makefile config.mk
man/posit16_arcosh.3: man/posit16_arcosh.sh man/posit64_arcosh.sh man/template/math_function.sh Makefile config.mk
man/posit32_arcosh.3: man/posit32_arcosh.sh man/posit64_arcosh.sh man/template/math_function.sh Makefile config.mk
man/posit64_arcosh.3: man/posit64_arcosh.sh man/template/math_function.sh Makefile config.mk
man/posit8_arcoth.3: man/posit8_arcoth.sh man/posit64_arcoth.sh man/template/math_function.sh Makefile config.mk
man/posit16_arcoth.3: man/posit16_arcoth.sh man/posit64_arcoth.sh man/template/math_function.sh Makefile config.mk
man/posit32_arcoth.3: man/posit32_arcoth.sh man/posit64_arcoth.sh man/template/math_function.sh Makefile config.mk
man/posit64_arcoth.3: man/posit64_arcoth.sh man/template/math_function.sh Makefile config.mk
man/posit8_arcsch.3: man/posit8_arcsch.sh man/posit64_arcsch.sh man/template/math_function.sh Makefile config.mk
man/posit16_arcsch.3: man/posit16_arcsch.sh man/posit64_arcsch.sh man/template/math_function.sh Makefile config.mk
man/posit32_arcsch.3: man/posit32_arcsch.sh man/posit64_arcsch.sh man/template/math_function.sh Makefile config.mk
man/posit64_arcsch.3: man/posit64_arcsch.sh man/template/math_function.sh Makefile config.mk
man/posit8_arcsec.3: man/posit8_arcsec.sh man/posit64_arcsec.sh man/template/math_function.sh Makefile config.mk
man/posit16_arcsec.3: man/posit16_arcsec.sh man/posit64_arcsec.sh man/template/math_function.sh Makefile config.mk
man/posit32_arcsec.3: man/posit32_arcsec.sh man/posit64_arcsec.sh man/template/math_function.sh Makefile config.mk
man/posit64_arcsec.3: man/posit64_arcsec.sh man/template/math_function.sh Makefile config.mk
man/posit8_arcsec_over_pi.3: man/posit8_arcsec_over_pi.sh man/posit64_arcsec_over_pi.sh man/template/math_function.sh Makefile config.mk
man/posit16_arcsec_over_pi.3: man/posit16_arcsec_over_pi.sh man/posit64_arcsec_over_pi.sh man/template/math_function.sh Makefile config.mk
man/posit32_arcsec_over_pi.3: man/posit32_arcsec_over_pi.sh man/posit64_arcsec_over_pi.sh man/template/math_function.sh Makefile config.mk
man/posit64_arcsec_over_pi.3: man/posit64_arcsec_over_pi.sh man/template/math_function.sh Makefile config.mk
man/posit8_arcsin.3: man/posit8_arcsin.sh man/posit64_arcsin.sh man/template/math_function.sh Makefile config.mk
man/posit16_arcsin.3: man/posit16_arcsin.sh man/posit64_arcsin.sh man/template/math_function.sh Makefile config.mk
man/posit32_arcsin.3: man/posit32_arcsin.sh man/posit64_arcsin.sh man/template/math_function.sh Makefile config.mk
man/posit64_arcsin.3: man/posit64_arcsin.sh man/template/math_function.sh Makefile config.mk
man/posit8_arcsin_over_pi.3: man/posit8_arcsin_over_pi.sh man/posit64_arcsin_over_pi.sh man/template/math_function.sh Makefile config.mk
man/posit16_arcsin_over_pi.3: man/posit16_arcsin_over_pi.sh man/posit64_arcsin_over_pi.sh man/template/math_function.sh Makefile config.mk
man/posit32_arcsin_over_pi.3: man/posit32_arcsin_over_pi.sh man/posit64_arcsin_over_pi.sh man/template/math_function.sh Makefile config.mk
man/posit64_arcsin_over_pi.3: man/posit64_arcsin_over_pi.sh man/template/math_function.sh Makefile config.mk
man/posit8_arctan2.3: man/posit8_arctan2.sh man/posit64_arctan2.sh man/template/math_function.sh Makefile config.mk
man/posit16_arctan2.3: man/posit16_arctan2.sh man/posit64_arctan2.sh man/template/math_function.sh Makefile config.mk
man/posit32_arctan2.3: man/posit32_arctan2.sh man/posit64_arctan2.sh man/template/math_function.sh Makefile config.mk
man/posit64_arctan2.3: man/posit64_arctan2.sh man/template/math_function.sh Makefile config.mk
man/posit8_arctan2_over_pi.3: man/posit8_arctan2_over_pi.sh man/posit64_arctan2_over_pi.sh man/template/math_function.sh Makefile config.mk
man/posit16_arctan2_over_pi.3: man/posit16_arctan2_over_pi.sh man/posit64_arctan2_over_pi.sh man/template/math_function.sh Makefile config.mk
man/posit32_arctan2_over_pi.3: man/posit32_arctan2_over_pi.sh man/posit64_arctan2_over_pi.sh man/template/math_function.sh Makefile config.mk
man/posit64_arctan2_over_pi.3: man/posit64_arctan2_over_pi.sh man/template/math_function.sh Makefile config.mk
man/posit8_arctan.3: man/posit8_arctan.sh man/posit64_arctan.sh man/template/math_function.sh Makefile config.mk
man/posit16_arctan.3: man/posit16_arctan.sh man/posit64_arctan.sh man/template/math_function.sh Makefile config.mk
man/posit32_arctan.3: man/posit32_arctan.sh man/posit64_arctan.sh man/template/math_function.sh Makefile config.mk
man/posit64_arctan.3: man/posit64_arctan.sh man/template/math_function.sh Makefile config.mk
man/posit8_arctan_over_pi.3: man/posit8_arctan_over_pi.sh man/posit64_arctan_over_pi.sh man/template/math_function.sh Makefile config.mk
man/posit16_arctan_over_pi.3: man/posit16_arctan_over_pi.sh man/posit64_arctan_over_pi.sh man/template/math_function.sh Makefile config.mk
man/posit32_arctan_over_pi.3: man/posit32_arctan_over_pi.sh man/posit64_arctan_over_pi.sh man/template/math_function.sh Makefile config.mk
man/posit64_arctan_over_pi.3: man/posit64_arctan_over_pi.sh man/template/math_function.sh Makefile config.mk
man/posit8_arsech.3: man/posit8_arsech.sh man/posit64_arsech.sh man/template/math_function.sh Makefile config.mk
man/posit16_arsech.3: man/posit16_arsech.sh man/posit64_arsech.sh man/template/math_function.sh Makefile config.mk
man/posit32_arsech.3: man/posit32_arsech.sh man/posit64_arsech.sh man/template/math_function.sh Makefile config.mk
man/posit64_arsech.3: man/posit64_arsech.sh man/template/math_function.sh Makefile config.mk
man/posit8_arsinh.3: man/posit8_arsinh.sh man/posit64_arsinh.sh man/template/math_function.sh Makefile config.mk
man/posit16_arsinh.3: man/posit16_arsinh.sh man/posit64_arsinh.sh man/template/math_function.sh Makefile config.mk
man/posit32_arsinh.3: man/posit32_arsinh.sh man/posit64_arsinh.sh man/template/math_function.sh Makefile config.mk
man/posit64_arsinh.3: man/posit64_arsinh.sh man/template/math_function.sh Makefile config.mk
man/posit8_artanh.3: man/posit8_artanh.sh man/posit64_artanh.sh man/template/math_function.sh Makefile config.mk
man/posit16_artanh.3: man/posit16_artanh.sh man/posit64_artanh.sh man/template/math_function.sh Makefile config.mk
man/posit32_artanh.3: man/posit32_artanh.sh man/posit64_artanh.sh man/template/math_function.sh Makefile config.mk
man/posit64_artanh.3: man/posit64_artanh.sh man/template/math_function.sh Makefile config.mk
man/posit8_cos.3: man/posit8_cos.sh man/posit64_cos.sh man/template/math_function.sh Makefile config.mk
man/posit16_cos.3: man/posit16_cos.sh man/posit64_cos.sh man/template/math_function.sh Makefile config.mk
man/posit32_cos.3: man/posit32_cos.sh man/posit64_cos.sh man/template/math_function.sh Makefile config.mk
man/posit64_cos.3: man/posit64_cos.sh man/template/math_function.sh Makefile config.mk
man/posit8_cos_pi_times.3: man/posit8_cos_pi_times.sh man/posit64_cos_pi_times.sh man/template/math_function.sh Makefile config.mk
man/posit16_cos_pi_times.3: man/posit16_cos_pi_times.sh man/posit64_cos_pi_times.sh man/template/math_function.sh Makefile config.mk
man/posit32_cos_pi_times.3: man/posit32_cos_pi_times.sh man/posit64_cos_pi_times.sh man/template/math_function.sh Makefile config.mk
man/posit64_cos_pi_times.3: man/posit64_cos_pi_times.sh man/template/math_function.sh Makefile config.mk
man/posit8_cosh.3: man/posit8_cosh.sh man/posit64_cosh.sh man/template/math_function.sh Makefile config.mk
man/posit16_cosh.3: man/posit16_cosh.sh man/posit64_cosh.sh man/template/math_function.sh Makefile config.mk
man/posit32_cosh.3: man/posit32_cosh.sh man/posit64_cosh.sh man/template/math_function.sh Makefile config.mk
man/posit64_cosh.3: man/posit64_cosh.sh man/template/math_function.sh Makefile config.mk
man/posit8_cot.3: man/posit8_cot.sh man/posit64_cot.sh man/template/math_function.sh Makefile config.mk
man/posit16_cot.3: man/posit16_cot.sh man/posit64_cot.sh man/template/math_function.sh Makefile config.mk
man/posit32_cot.3: man/posit32_cot.sh man/posit64_cot.sh man/template/math_function.sh Makefile config.mk
man/posit64_cot.3: man/posit64_cot.sh man/template/math_function.sh Makefile config.mk
man/posit8_cot_pi_times.3: man/posit8_cot_pi_times.sh man/posit64_cot_pi_times.sh man/template/math_function.sh Makefile config.mk
man/posit16_cot_pi_times.3: man/posit16_cot_pi_times.sh man/posit64_cot_pi_times.sh man/template/math_function.sh Makefile config.mk
man/posit32_cot_pi_times.3: man/posit32_cot_pi_times.sh man/posit64_cot_pi_times.sh man/template/math_function.sh Makefile config.mk
man/posit64_cot_pi_times.3: man/posit64_cot_pi_times.sh man/template/math_function.sh Makefile config.mk
man/posit8_coth.3: man/posit8_coth.sh man/posit64_coth.sh man/template/math_function.sh Makefile config.mk
man/posit16_coth.3: man/posit16_coth.sh man/posit64_coth.sh man/template/math_function.sh Makefile config.mk
man/posit32_coth.3: man/posit32_coth.sh man/posit64_coth.sh man/template/math_function.sh Makefile config.mk
man/posit64_coth.3: man/posit64_coth.sh man/template/math_function.sh Makefile config.mk
man/posit8_csc.3: man/posit8_csc.sh man/posit64_csc.sh man/template/math_function.sh Makefile config.mk
man/posit16_csc.3: man/posit16_csc.sh man/posit64_csc.sh man/template/math_function.sh Makefile config.mk
man/posit32_csc.3: man/posit32_csc.sh man/posit64_csc.sh man/template/math_function.sh Makefile config.mk
man/posit64_csc.3: man/posit64_csc.sh man/template/math_function.sh Makefile config.mk
man/posit8_csc_pi_times.3: man/posit8_csc_pi_times.sh man/posit64_csc_pi_times.sh man/template/math_function.sh Makefile config.mk
man/posit16_csc_pi_times.3: man/posit16_csc_pi_times.sh man/posit64_csc_pi_times.sh man/template/math_function.sh Makefile config.mk
man/posit32_csc_pi_times.3: man/posit32_csc_pi_times.sh man/posit64_csc_pi_times.sh man/template/math_function.sh Makefile config.mk
man/posit64_csc_pi_times.3: man/posit64_csc_pi_times.sh man/template/math_function.sh Makefile config.mk
man/posit8_csch.3: man/posit8_csch.sh man/posit64_csch.sh man/template/math_function.sh Makefile config.mk
man/posit16_csch.3: man/posit16_csch.sh man/posit64_csch.sh man/template/math_function.sh Makefile config.mk
man/posit32_csch.3: man/posit32_csch.sh man/posit64_csch.sh man/template/math_function.sh Makefile config.mk
man/posit64_csch.3: man/posit64_csch.sh man/template/math_function.sh Makefile config.mk
man/posit8_division.3: man/posit8_division.sh man/posit64_division.sh man/template/math_function.sh Makefile config.mk
man/posit16_division.3: man/posit16_division.sh man/posit64_division.sh man/template/math_function.sh Makefile config.mk
man/posit32_division.3: man/posit32_division.sh man/posit64_division.sh man/template/math_function.sh Makefile config.mk
man/posit64_division.3: man/posit64_division.sh man/template/math_function.sh Makefile config.mk
man/posit8_exp.3: man/posit8_exp.sh man/posit64_exp.sh man/template/math_function.sh Makefile config.mk
man/posit16_exp.3: man/posit16_exp.sh man/posit64_exp.sh man/template/math_function.sh Makefile config.mk
man/posit32_exp.3: man/posit32_exp.sh man/posit64_exp.sh man/template/math_function.sh Makefile config.mk
man/posit64_exp.3: man/posit64_exp.sh man/template/math_function.sh Makefile config.mk
man/posit8_exp_minus_1.3: man/posit8_exp_minus_1.sh man/posit64_exp_minus_1.sh man/template/math_function.sh Makefile config.mk
man/posit16_exp_minus_1.3: man/posit16_exp_minus_1.sh man/posit64_exp_minus_1.sh man/template/math_function.sh Makefile config.mk
man/posit32_exp_minus_1.3: man/posit32_exp_minus_1.sh man/posit64_exp_minus_1.sh man/template/math_function.sh Makefile config.mk
man/posit64_exp_minus_1.3: man/posit64_exp_minus_1.sh man/template/math_function.sh Makefile config.mk
man/posit8_from_extended_float.3: man/posit8_from_extended_float.sh man/posit64_from_extended_float.sh man/template/conversion_from_float.sh Makefile config.mk
man/posit16_from_extended_float.3: man/posit16_from_extended_float.sh man/posit64_from_extended_float.sh man/template/conversion_from_float.sh Makefile config.mk
man/posit32_from_extended_float.3: man/posit32_from_extended_float.sh man/posit64_from_extended_float.sh man/template/conversion_from_float.sh Makefile config.mk
man/posit64_from_extended_float.3: man/posit64_from_extended_float.sh man/template/conversion_from_float.sh Makefile config.mk
man/posit8_from_float32.3: man/posit8_from_float32.sh man/posit64_from_float32.sh man/template/conversion_from_float.sh Makefile config.mk
man/posit16_from_float32.3: man/posit16_from_float32.sh man/posit64_from_float32.sh man/template/conversion_from_float.sh Makefile config.mk
man/posit32_from_float32.3: man/posit32_from_float32.sh man/posit64_from_float32.sh man/template/conversion_from_float.sh Makefile config.mk
man/posit64_from_float32.3: man/posit64_from_float32.sh man/template/conversion_from_float.sh Makefile config.mk
man/posit8_from_float64.3: man/posit8_from_float64.sh man/posit64_from_float64.sh man/template/conversion_from_float.sh Makefile config.mk
man/posit16_from_float64.3: man/posit16_from_float64.sh man/posit64_from_float64.sh man/template/conversion_from_float.sh Makefile config.mk
man/posit32_from_float64.3: man/posit32_from_float64.sh man/posit64_from_float64.sh man/template/conversion_from_float.sh Makefile config.mk
man/posit64_from_float64.3: man/posit64_from_float64.sh man/template/conversion_from_float.sh Makefile config.mk
man/posit16_from_posit8.3: man/posit16_from_posit8.sh man/posit64_from_posit8.sh man/template/conversion.sh Makefile config.mk
man/posit32_from_posit8.3: man/posit32_from_posit8.sh man/posit64_from_posit8.sh man/template/conversion.sh Makefile config.mk
man/posit64_from_posit8.3: man/posit64_from_posit8.sh man/template/conversion.sh Makefile config.mk
man/posit8_from_posit16.3: man/posit8_from_posit16.sh man/posit64_from_posit16.sh man/template/conversion.sh Makefile config.mk
man/posit32_from_posit16.3: man/posit32_from_posit16.sh man/posit64_from_posit16.sh man/template/conversion.sh Makefile config.mk
man/posit64_from_posit16.3: man/posit64_from_posit16.sh man/template/conversion.sh Makefile config.mk
man/posit8_from_posit32.3: man/posit8_from_posit32.sh man/posit64_from_posit32.sh man/template/conversion.sh Makefile config.mk
man/posit16_from_posit32.3: man/posit16_from_posit32.sh man/posit64_from_posit32.sh man/template/conversion.sh Makefile config.mk
man/posit64_from_posit32.3: man/posit64_from_posit32.sh man/template/conversion.sh Makefile config.mk
man/posit8_from_posit64.3: man/posit8_from_posit64.sh man/posit32_from_posit64.sh man/template/conversion.sh Makefile config.mk
man/posit16_from_posit64.3: man/posit16_from_posit64.sh man/posit32_from_posit64.sh man/template/conversion.sh Makefile config.mk
man/posit32_from_posit64.3: man/posit32_from_posit64.sh man/template/conversion.sh Makefile config.mk
man/posit8_hypotenuse.3: man/posit8_hypotenuse.sh man/posit64_hypotenuse.sh man/template/math_function.sh Makefile config.mk
man/posit16_hypotenuse.3: man/posit16_hypotenuse.sh man/posit64_hypotenuse.sh man/template/math_function.sh Makefile config.mk
man/posit32_hypotenuse.3: man/posit32_hypotenuse.sh man/posit64_hypotenuse.sh man/template/math_function.sh Makefile config.mk
man/posit64_hypotenuse.3: man/posit64_hypotenuse.sh man/template/math_function.sh Makefile config.mk
man/posit8_integer_power.3: man/posit8_integer_power.sh man/posit64_integer_power.sh man/template/math_function.sh Makefile config.mk
man/posit16_integer_power.3: man/posit16_integer_power.sh man/posit64_integer_power.sh man/template/math_function.sh Makefile config.mk
man/posit32_integer_power.3: man/posit32_integer_power.sh man/posit64_integer_power.sh man/template/math_function.sh Makefile config.mk
man/posit64_integer_power.3: man/posit64_integer_power.sh man/template/math_function.sh Makefile config.mk
man/posit8_inversion.3: man/posit8_inversion.sh man/posit64_inversion.sh man/template/math_function.sh Makefile config.mk
man/posit16_inversion.3: man/posit16_inversion.sh man/posit64_inversion.sh man/template/math_function.sh Makefile config.mk
man/posit32_inversion.3: man/posit32_inversion.sh man/posit64_inversion.sh man/template/math_function.sh Makefile config.mk
man/posit64_inversion.3: man/posit64_inversion.sh man/template/math_function.sh Makefile config.mk
man/posit8_lb.3: man/posit8_lb.sh man/posit64_lb.sh man/template/math_function.sh Makefile config.mk
man/posit16_lb.3: man/posit16_lb.sh man/posit64_lb.sh man/template/math_function.sh Makefile config.mk
man/posit32_lb.3: man/posit32_lb.sh man/posit64_lb.sh man/template/math_function.sh Makefile config.mk
man/posit64_lb.3: man/posit64_lb.sh man/template/math_function.sh Makefile config.mk
man/posit8_lb_1_plus.3: man/posit8_lb_1_plus.sh man/posit64_lb_1_plus.sh man/template/math_function.sh Makefile config.mk
man/posit16_lb_1_plus.3: man/posit16_lb_1_plus.sh man/posit64_lb_1_plus.sh man/template/math_function.sh Makefile config.mk
man/posit32_lb_1_plus.3: man/posit32_lb_1_plus.sh man/posit64_lb_1_plus.sh man/template/math_function.sh Makefile config.mk
man/posit64_lb_1_plus.3: man/posit64_lb_1_plus.sh man/template/math_function.sh Makefile config.mk
man/posit8_lg.3: man/posit8_lg.sh man/posit64_lg.sh man/template/math_function.sh Makefile config.mk
man/posit16_lg.3: man/posit16_lg.sh man/posit64_lg.sh man/template/math_function.sh Makefile config.mk
man/posit32_lg.3: man/posit32_lg.sh man/posit64_lg.sh man/template/math_function.sh Makefile config.mk
man/posit64_lg.3: man/posit64_lg.sh man/template/math_function.sh Makefile config.mk
man/posit8_lg_1_plus.3: man/posit8_lg_1_plus.sh man/posit64_lg_1_plus.sh man/template/math_function.sh Makefile config.mk
man/posit16_lg_1_plus.3: man/posit16_lg_1_plus.sh man/posit64_lg_1_plus.sh man/template/math_function.sh Makefile config.mk
man/posit32_lg_1_plus.3: man/posit32_lg_1_plus.sh man/posit64_lg_1_plus.sh man/template/math_function.sh Makefile config.mk
man/posit64_lg_1_plus.3: man/posit64_lg_1_plus.sh man/template/math_function.sh Makefile config.mk
man/posit8_ln.3: man/posit8_ln.sh man/posit64_ln.sh man/template/math_function.sh Makefile config.mk
man/posit16_ln.3: man/posit16_ln.sh man/posit64_ln.sh man/template/math_function.sh Makefile config.mk
man/posit32_ln.3: man/posit32_ln.sh man/posit64_ln.sh man/template/math_function.sh Makefile config.mk
man/posit64_ln.3: man/posit64_ln.sh man/template/math_function.sh Makefile config.mk
man/posit8_ln_1_plus.3: man/posit8_ln_1_plus.sh man/posit64_ln_1_plus.sh man/template/math_function.sh Makefile config.mk
man/posit16_ln_1_plus.3: man/posit16_ln_1_plus.sh man/posit64_ln_1_plus.sh man/template/math_function.sh Makefile config.mk
man/posit32_ln_1_plus.3: man/posit32_ln_1_plus.sh man/posit64_ln_1_plus.sh man/template/math_function.sh Makefile config.mk
man/posit64_ln_1_plus.3: man/posit64_ln_1_plus.sh man/template/math_function.sh Makefile config.mk
man/posit8_multiplication.3: man/posit8_multiplication.sh man/posit64_multiplication.sh man/template/math_function.sh Makefile config.mk
man/posit16_multiplication.3: man/posit16_multiplication.sh man/posit64_multiplication.sh man/template/math_function.sh Makefile config.mk
man/posit32_multiplication.3: man/posit32_multiplication.sh man/posit64_multiplication.sh man/template/math_function.sh Makefile config.mk
man/posit64_multiplication.3: man/posit64_multiplication.sh man/template/math_function.sh Makefile config.mk
man/posit8_power.3: man/posit8_power.sh man/posit64_power.sh man/template/math_function.sh Makefile config.mk
man/posit16_power.3: man/posit16_power.sh man/posit64_power.sh man/template/math_function.sh Makefile config.mk
man/posit32_power.3: man/posit32_power.sh man/posit64_power.sh man/template/math_function.sh Makefile config.mk
man/posit64_power.3: man/posit64_power.sh man/template/math_function.sh Makefile config.mk
man/posit8_precision.3: man/posit8_precision.sh man/posit64_precision.sh man/template/math_function.sh Makefile config.mk
man/posit16_precision.3: man/posit16_precision.sh man/posit64_precision.sh man/template/math_function.sh Makefile config.mk
man/posit32_precision.3: man/posit32_precision.sh man/posit64_precision.sh man/template/math_function.sh Makefile config.mk
man/posit64_precision.3: man/posit64_precision.sh man/template/math_function.sh Makefile config.mk
man/posit8_root.3: man/posit8_root.sh man/posit64_root.sh man/template/math_function.sh Makefile config.mk
man/posit16_root.3: man/posit16_root.sh man/posit64_root.sh man/template/math_function.sh Makefile config.mk
man/posit32_root.3: man/posit32_root.sh man/posit64_root.sh man/template/math_function.sh Makefile config.mk
man/posit64_root.3: man/posit64_root.sh man/template/math_function.sh Makefile config.mk
man/posit8_sec.3: man/posit8_sec.sh man/posit64_sec.sh man/template/math_function.sh Makefile config.mk
man/posit16_sec.3: man/posit16_sec.sh man/posit64_sec.sh man/template/math_function.sh Makefile config.mk
man/posit32_sec.3: man/posit32_sec.sh man/posit64_sec.sh man/template/math_function.sh Makefile config.mk
man/posit64_sec.3: man/posit64_sec.sh man/template/math_function.sh Makefile config.mk
man/posit8_sec_pi_times.3: man/posit8_sec_pi_times.sh man/posit64_sec_pi_times.sh man/template/math_function.sh Makefile config.mk
man/posit16_sec_pi_times.3: man/posit16_sec_pi_times.sh man/posit64_sec_pi_times.sh man/template/math_function.sh Makefile config.mk
man/posit32_sec_pi_times.3: man/posit32_sec_pi_times.sh man/posit64_sec_pi_times.sh man/template/math_function.sh Makefile config.mk
man/posit64_sec_pi_times.3: man/posit64_sec_pi_times.sh man/template/math_function.sh Makefile config.mk
man/posit8_sech.3: man/posit8_sech.sh man/posit64_sech.sh man/template/math_function.sh Makefile config.mk
man/posit16_sech.3: man/posit16_sech.sh man/posit64_sech.sh man/template/math_function.sh Makefile config.mk
man/posit32_sech.3: man/posit32_sech.sh man/posit64_sech.sh man/template/math_function.sh Makefile config.mk
man/posit64_sech.3: man/posit64_sech.sh man/template/math_function.sh Makefile config.mk
man/posit8_sign.3: man/posit8_sign.sh man/posit64_sign.sh man/template/math_function.sh Makefile config.mk
man/posit16_sign.3: man/posit16_sign.sh man/posit64_sign.sh man/template/math_function.sh Makefile config.mk
man/posit32_sign.3: man/posit32_sign.sh man/posit64_sign.sh man/template/math_function.sh Makefile config.mk
man/posit64_sign.3: man/posit64_sign.sh man/template/math_function.sh Makefile config.mk
man/posit8_sin.3: man/posit8_sin.sh man/posit64_sin.sh man/template/math_function.sh Makefile config.mk
man/posit16_sin.3: man/posit16_sin.sh man/posit64_sin.sh man/template/math_function.sh Makefile config.mk
man/posit32_sin.3: man/posit32_sin.sh man/posit64_sin.sh man/template/math_function.sh Makefile config.mk
man/posit64_sin.3: man/posit64_sin.sh man/template/math_function.sh Makefile config.mk
man/posit8_sin_pi_times.3: man/posit8_sin_pi_times.sh man/posit64_sin_pi_times.sh man/template/math_function.sh Makefile config.mk
man/posit16_sin_pi_times.3: man/posit16_sin_pi_times.sh man/posit64_sin_pi_times.sh man/template/math_function.sh Makefile config.mk
man/posit32_sin_pi_times.3: man/posit32_sin_pi_times.sh man/posit64_sin_pi_times.sh man/template/math_function.sh Makefile config.mk
man/posit64_sin_pi_times.3: man/posit64_sin_pi_times.sh man/template/math_function.sh Makefile config.mk
man/posit8_sinh.3: man/posit8_sinh.sh man/posit64_sinh.sh man/template/math_function.sh Makefile config.mk
man/posit16_sinh.3: man/posit16_sinh.sh man/posit64_sinh.sh man/template/math_function.sh Makefile config.mk
man/posit32_sinh.3: man/posit32_sinh.sh man/posit64_sinh.sh man/template/math_function.sh Makefile config.mk
man/posit64_sinh.3: man/posit64_sinh.sh man/template/math_function.sh Makefile config.mk
man/posit8_square_root.3: man/posit8_square_root.sh man/posit64_square_root.sh man/template/math_function.sh Makefile config.mk
man/posit16_square_root.3: man/posit16_square_root.sh man/posit64_square_root.sh man/template/math_function.sh Makefile config.mk
man/posit32_square_root.3: man/posit32_square_root.sh man/posit64_square_root.sh man/template/math_function.sh Makefile config.mk
man/posit64_square_root.3: man/posit64_square_root.sh man/template/math_function.sh Makefile config.mk
man/posit8_subtraction.3: man/posit8_subtraction.sh man/posit64_subtraction.sh man/template/math_function.sh Makefile config.mk
man/posit16_subtraction.3: man/posit16_subtraction.sh man/posit64_subtraction.sh man/template/math_function.sh Makefile config.mk
man/posit32_subtraction.3: man/posit32_subtraction.sh man/posit64_subtraction.sh man/template/math_function.sh Makefile config.mk
man/posit64_subtraction.3: man/posit64_subtraction.sh man/template/math_function.sh Makefile config.mk
man/posit8_tan.3: man/posit8_tan.sh man/posit64_tan.sh man/template/math_function.sh Makefile config.mk
man/posit16_tan.3: man/posit16_tan.sh man/posit64_tan.sh man/template/math_function.sh Makefile config.mk
man/posit32_tan.3: man/posit32_tan.sh man/posit64_tan.sh man/template/math_function.sh Makefile config.mk
man/posit64_tan.3: man/posit64_tan.sh man/template/math_function.sh Makefile config.mk
man/posit8_tan_pi_times.3: man/posit8_tan_pi_times.sh man/posit64_tan_pi_times.sh man/template/math_function.sh Makefile config.mk
man/posit16_tan_pi_times.3: man/posit16_tan_pi_times.sh man/posit64_tan_pi_times.sh man/template/math_function.sh Makefile config.mk
man/posit32_tan_pi_times.3: man/posit32_tan_pi_times.sh man/posit64_tan_pi_times.sh man/template/math_function.sh Makefile config.mk
man/posit64_tan_pi_times.3: man/posit64_tan_pi_times.sh man/template/math_function.sh Makefile config.mk
man/posit8_tanh.3: man/posit8_tanh.sh man/posit64_tanh.sh man/template/math_function.sh Makefile config.mk
man/posit16_tanh.3: man/posit16_tanh.sh man/posit64_tanh.sh man/template/math_function.sh Makefile config.mk
man/posit32_tanh.3: man/posit32_tanh.sh man/posit64_tanh.sh man/template/math_function.sh Makefile config.mk
man/posit64_tanh.3: man/posit64_tanh.sh man/template/math_function.sh Makefile config.mk
man/posit8_to_extended_float.3: man/posit8_to_extended_float.sh man/posit64_to_extended_float.sh man/template/conversion_to_float.sh Makefile config.mk
man/posit16_to_extended_float.3: man/posit16_to_extended_float.sh man/posit64_to_extended_float.sh man/template/conversion_to_float.sh Makefile config.mk
man/posit32_to_extended_float.3: man/posit32_to_extended_float.sh man/posit64_to_extended_float.sh man/template/conversion_to_float.sh Makefile config.mk
man/posit64_to_extended_float.3: man/posit64_to_extended_float.sh man/template/conversion_to_float.sh Makefile config.mk
man/posit8_to_float32.3: man/posit8_to_float32.sh man/posit64_to_float32.sh man/template/conversion_to_float.sh Makefile config.mk
man/posit16_to_float32.3: man/posit16_to_float32.sh man/posit64_to_float32.sh man/template/conversion_to_float.sh Makefile config.mk
man/posit32_to_float32.3: man/posit32_to_float32.sh man/posit64_to_float32.sh man/template/conversion_to_float.sh Makefile config.mk
man/posit64_to_float32.3: man/posit64_to_float32.sh man/template/conversion_to_float.sh Makefile config.mk
man/posit8_to_float64.3: man/posit8_to_float64.sh man/posit64_to_float64.sh man/template/conversion_to_float.sh Makefile config.mk
man/posit16_to_float64.3: man/posit16_to_float64.sh man/posit64_to_float64.sh man/template/conversion_to_float.sh Makefile config.mk
man/posit32_to_float64.3: man/posit32_to_float64.sh man/posit64_to_float64.sh man/template/conversion_to_float.sh Makefile config.mk
man/posit64_to_float64.3: man/posit64_to_float64.sh man/template/conversion_to_float.sh Makefile config.mk

man/libposit.7: man/libposit.sh Makefile config.mk

$(EXAMPLE:=.o) example/util.o $(TEST:=.o) test/util.o:
	$(CC) -c -o $@ $(CPPFLAGS) $(CFLAGS) $(@:.o=.c)

$(SRC:=.o):
	$(CC) -c -o $@ $(CPPFLAGS) $(CFLAGS) $(SHFLAGS) $(@:.o=.c)

$(EXAMPLE:=$(BINSUFFIX)):
	$(CC) -o $@ $(LDFLAGS) $(@:$(BINSUFFIX)=.o) example/util.o $(ANAME) $(LDLIBS)

$(TEST:=$(BINSUFFIX)):
	$(CC) -o $@ $(LDFLAGS) $(@:$(BINSUFFIX)=.o) test/util.o $(ANAME) $(LDLIBS)

$(TEST:=.success):
	./$(@:.success=$(BINSUFFIX)) && touch $@

$(ANAME): $(SRC:=.o)
	$(AR) -rc $@ $?
	$(RANLIB) $@

$(SONAME): $(SRC:=.o)
	$(CC) -o $@ $(SOFLAGS) $(LDFLAGS) $(SRC:=.o) $(LDLIBS)

$(MAN3:=.3):
	env -i SH="$(SH)" MAN_DATE="$(MAN_DATE)" $(SH) $(@:.3=.sh) > $@

$(MAN7:=.7):
	env -i SH="$(SH)" MAN_DATE="$(MAN_DATE)" MAN3_LIST="$(MAN3)" $(SH) $(@:.7=.sh) > $@

example: $(EXAMPLE:=$(BINSUFFIX))

check: test

test: $(TEST:=.success)

install: all
	mkdir -p "$(DESTDIR)$(LIBPREFIX)"
	mkdir -p "$(DESTDIR)$(LICPREFIX)/libposit"
	mkdir -p "$(DESTDIR)$(INCPREFIX)"
	mkdir -p "$(DESTDIR)$(MANPREFIX)/man3"
	mkdir -p "$(DESTDIR)$(MANPREFIX)/man7"
	cp -f LICENSE "$(DESTDIR)$(LICPREFIX)/libposit"
	cp -f $(MAN3:=.3) "$(DESTDIR)$(MANPREFIX)/man3"
	cp -f $(MAN7:=.7) "$(DESTDIR)$(MANPREFIX)/man7"
	cp -f $(ANAME) "$(DESTDIR)$(LIBPREFIX)"
	cp -f $(SONAME) "$(DESTDIR)$(LIBPREFIX)"
	if [ "$(SOSYMLINK)" = "true" ]; then i=0; while [ "$$i" -le $(VERSION_MINOR) ]; do ln -sf "$(SONAME)" "$(DESTDIR)$(LIBPREFIX)/libposit.so.$(VERSION_MAJOR).$$i"; i=$$((i+1)); done; fi
	if [ "$(SOSYMLINK)" = "true" ]; then ln -sf "$(SONAME)" "$(DESTDIR)$(LIBPREFIX)/libposit.so.$(VERSION_MAJOR)"; fi
	if [ "$(SOSYMLINK)" = "true" ]; then ln -sf "$(SONAME)" "$(DESTDIR)$(LIBPREFIX)/libposit.so"; fi
	cp -f posit.h "$(DESTDIR)$(INCPREFIX)"
	if ! [ -z "$(LDCONFIG)" ]; then $(SHELL) -c "$(LDCONFIG)"; fi
	if ! [ -z "$(PCPREFIX)" ]; then mkdir -p "$(DESTDIR)$(PCPREFIX)"; printf "Name: libposit\nDescription: Posit arithmetic reference implementation\nURL: https://takum.org/\nVersion: $(VERSION)\nCflags: -I$(INCPREFIX)\nLibs: -L$(LIBPREFIX) -lposit -lm\n" > "$(DESTDIR)$(PCPREFIX)/libposit.pc"; fi

uninstall:
	for m in $(MAN3:=.3); do rm -f "$(DESTDIR)$(MANPREFIX)/man3/`basename $$m`"; done
	for m in $(MAN7:=.7); do rm -f "$(DESTDIR)$(MANPREFIX)/man7/`basename $$m`"; done
	rm -f "$(DESTDIR)$(LICPREFIX)/libposit/LICENSE"
	rmdir "$(DESTDIR)$(LICPREFIX)/libposit"
	rm -f "$(DESTDIR)$(LIBPREFIX)/$(ANAME)"
	rm -f "$(DESTDIR)$(LIBPREFIX)/$(SONAME)"
	if [ "$(SOSYMLINK)" = "true" ]; then i=0; while [ "$$i" -le $(VERSION_MINOR) ]; do rm -f "$(DESTDIR)$(LIBPREFIX)/libposit.so.$(VERSION_MAJOR).$$i"; i=$$((i+1)); done; fi
	if [ "$(SOSYMLINK)" = "true" ]; then rm -f "$(DESTDIR)$(LIBPREFIX)/libposit.so.$(VERSION_MAJOR)"; fi
	if [ "$(SOSYMLINK)" = "true" ]; then rm -f "$(DESTDIR)$(LIBPREFIX)/libposit.so"; fi
	rm -f "$(DESTDIR)$(INCPREFIX)/posit.h"
	if ! [ -z "$(LDCONFIG)" ]; then $(SHELL) -c "$(LDCONFIG)"; fi
	if ! [ -z "$(PCPREFIX)" ]; then rm -f "$(DESTDIR)$(PCPREFIX)/libposit.pc"; fi

clean:
	rm -f $(EXAMPLE:=.o) example/util.o $(EXAMPLE:=$(BINSUFFIX)) $(SRC:=.o) $(TEST:=.o) test/util.o $(TEST:=$(BINSUFFIX)) $(TEST:=.success) $(ANAME) $(SONAME) $(MAN3:=.3) $(MAN7:=.7)

dist:
	rm -rf "libposit-$(VERSION)"
	mkdir "libposit-$(VERSION)"
	for m in example man man/template src test; do mkdir "libposit-$(VERSION)/$$m"; done
	cp config.mk configure posit.h LICENSE Makefile README "libposit-$(VERSION)"
	cp $(DATA) "libposit-$(VERSION)/data"
	cp $(EXAMPLE:=.c) example/util.c example/util.h "libposit-$(VERSION)/example"
	cp $(MAN3:=.sh) $(MAN7:=.sh) "libposit-$(VERSION)/man"
	cp $(MAN_TEMPLATE) "libposit-$(VERSION)/man/template"
	cp $(SRC:=.c) src/codec.h src/util.h "libposit-$(VERSION)/src"
	cp $(TEST:=.c) test/util.c test/util.h "libposit-$(VERSION)/test"
	tar -cf - "libposit-$(VERSION)" | gzip -c > "libposit-$(VERSION).tar.gz"
	rm -rf "libposit-$(VERSION)"

format:
	clang-format -i posit.h $(EXAMPLE:=.c) example/util.c example/util.h $(SRC:=.c) src/codec.h src/util.h $(TEST:=.c) test/util.c test/util.h

.PHONY: all check clean dist example format install test uninstall

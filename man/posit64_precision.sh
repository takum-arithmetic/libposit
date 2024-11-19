export POSIT_TYPE_SUFFIX=$(if [ -n "$POSIT_TYPE_SUFFIX" ]; then printf "$POSIT_TYPE_SUFFIX"; else printf "64"; fi)
export COMPUTE_DESCRIPTION="the precision of a posit"
export COMPUTE_LONG_DESCRIPTION="the precision, i.e. the mantissa bit count (one less than the fraction bit count for floating-point numbers), of \n.Va a "
export FUNCTION_NAME="precision"
export NAN_CONDITION=""
export RETURN_TYPE_OVERRIDE="uint8_t"
export SECOND_ARGUMENT_TYPE=""
export SEE_ALSO=""

$SH man/template/math_function.sh

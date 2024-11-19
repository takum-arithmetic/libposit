export POSIT_TYPE_SUFFIX=$(if [ -n "$POSIT_TYPE_SUFFIX" ]; then printf "$POSIT_TYPE_SUFFIX"; else printf "64"; fi)
export COMPUTE_DESCRIPTION="the exponential function of a posit"
export COMPUTE_LONG_DESCRIPTION="e raised to \n.Va a "
export FUNCTION_NAME="exp"
export NAN_CONDITION=""
export RETURN_TYPE_OVERRIDE=""
export SECOND_ARGUMENT_TYPE=""
export SEE_ALSO="exp_minus_1"

$SH man/template/math_function.sh

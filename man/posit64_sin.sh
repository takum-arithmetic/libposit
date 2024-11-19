export POSIT_TYPE_SUFFIX=$(if [ -n "$POSIT_TYPE_SUFFIX" ]; then printf "$POSIT_TYPE_SUFFIX"; else printf "64"; fi)
export COMPUTE_DESCRIPTION="the sine of a posit"
export COMPUTE_LONG_DESCRIPTION="the sine of\n.Va a "
export FUNCTION_NAME="sin"
export NAN_CONDITION=""
export RETURN_TYPE_OVERRIDE=""
export SECOND_ARGUMENT_TYPE=""
export SEE_ALSO="sin_pi_times"

$SH man/template/math_function.sh

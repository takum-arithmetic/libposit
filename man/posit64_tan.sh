export POSIT_TYPE_SUFFIX=$(if [ -n "$POSIT_TYPE_SUFFIX" ]; then printf "$POSIT_TYPE_SUFFIX"; else printf "64"; fi)
export COMPUTE_DESCRIPTION="the tangent of a posit"
export COMPUTE_LONG_DESCRIPTION="the tangent of\n.Va a "
export FUNCTION_NAME="tan"
export NAN_CONDITION="" # multiples of (n+0.5)π are not representable
export RETURN_TYPE_OVERRIDE=""
export SECOND_ARGUMENT_TYPE=""
export SEE_ALSO="tan_pi_times"

$SH man/template/math_function.sh

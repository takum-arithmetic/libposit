export POSIT_TYPE_SUFFIX=$(if [ -n "$POSIT_TYPE_SUFFIX" ]; then printf "$POSIT_TYPE_SUFFIX"; else printf "64"; fi)
export COMPUTE_DESCRIPTION="the cosecant of a posit"
export COMPUTE_LONG_DESCRIPTION="the cosecant of\n.Va a "
export FUNCTION_NAME="csc"
export NAN_CONDITION="" # multiples of π are not exactly representable in any posit type
export RETURN_TYPE_OVERRIDE=""
export SECOND_ARGUMENT_TYPE=""
export SEE_ALSO="csc_pi_times"

$SH man/template/math_function.sh

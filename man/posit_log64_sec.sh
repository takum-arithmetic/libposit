export POSIT_TYPE_SUFFIX=$(if [ -n "$POSIT_TYPE_SUFFIX" ]; then printf "$POSIT_TYPE_SUFFIX"; else printf "_log64"; fi)
export COMPUTE_DESCRIPTION="the secant of a linear posit"
export COMPUTE_LONG_DESCRIPTION="the secant of\n.Va a "
export FUNCTION_NAME="sec"
export NAN_CONDITION="" # 1/2 + multiples of π are not exactly representable in any posit type
export RETURN_TYPE_OVERRIDE=""
export SECOND_ARGUMENT_TYPE=""
export SEE_ALSO="sec_pi_times"

$SH man/template/math_function.sh

export POSIT_TYPE_SUFFIX=$(if [ -n "$POSIT_TYPE_SUFFIX" ]; then printf "$POSIT_TYPE_SUFFIX"; else printf "_log64"; fi)
export COMPUTE_DESCRIPTION="the secant of π times a linear posit"
export COMPUTE_LONG_DESCRIPTION="the secant of π times\n.Va a "
export FUNCTION_NAME="sec_pi_times"
export NAN_CONDITION="" # integral values + 0.5 are not exactly representable
export RETURN_TYPE_OVERRIDE=""
export SECOND_ARGUMENT_TYPE=""
export SEE_ALSO="sec"

$SH man/template/math_function.sh

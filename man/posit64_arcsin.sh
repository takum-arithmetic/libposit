export POSIT_TYPE_SUFFIX=$(if [ -n "$POSIT_TYPE_SUFFIX" ]; then printf "$POSIT_TYPE_SUFFIX"; else printf "64"; fi)
export COMPUTE_DESCRIPTION="the arcsine of a posit"
export COMPUTE_LONG_DESCRIPTION="the arcsine of\n.Va a "
export FUNCTION_NAME="arcsin"
export NAN_CONDITION="\n.Va a\nis outside [-1, 1]"
export RETURN_TYPE_OVERRIDE=""
export SECOND_ARGUMENT_TYPE=""
export SEE_ALSO="arcsin_over_pi"

$SH man/template/math_function.sh

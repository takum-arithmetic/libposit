export POSIT_TYPE_SUFFIX=$(if [ -n "$POSIT_TYPE_SUFFIX" ]; then printf "$POSIT_TYPE_SUFFIX"; else printf "64"; fi)
export COMPUTE_DESCRIPTION="the cotangent of a posit"
export COMPUTE_LONG_DESCRIPTION="the cotangent of\n.Va a "
export FUNCTION_NAME="cot"
export NAN_CONDITION="\n.Va a\nis zero" # other multiples of π are not representable
export RETURN_TYPE_OVERRIDE=""
export SECOND_ARGUMENT_TYPE=""
export SEE_ALSO="cot_pi_times"

$SH man/template/math_function.sh

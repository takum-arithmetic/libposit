export POSIT_TYPE_SUFFIX=$(if [ -n "$POSIT_TYPE_SUFFIX" ]; then printf "$POSIT_TYPE_SUFFIX"; else printf "64"; fi)
export COMPUTE_DESCRIPTION="the decadic logarithm of a posit"
export COMPUTE_LONG_DESCRIPTION="the decadic, i.e. base 10, logarithm of\n.Va a "
export FUNCTION_NAME="lg"
export NAN_CONDITION="\n.Va a\nis smaller than or equal to zero"
export RETURN_TYPE_OVERRIDE=""
export SECOND_ARGUMENT_TYPE=""
export SEE_ALSO="lg_1_plus"

$SH man/template/math_function.sh

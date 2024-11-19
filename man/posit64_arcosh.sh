export POSIT_TYPE_SUFFIX=$(if [ -n "$POSIT_TYPE_SUFFIX" ]; then printf "$POSIT_TYPE_SUFFIX"; else printf "64"; fi)
export COMPUTE_DESCRIPTION="the area hyperbolic cosine of a posit"
export COMPUTE_LONG_DESCRIPTION="the area hyperbolic cosine of\n.Va a "
export FUNCTION_NAME="arcosh"
export NAN_CONDITION="\n.Va a\nis smaller than one"
export RETURN_TYPE_OVERRIDE=""
export SECOND_ARGUMENT_TYPE=""
export SEE_ALSO=""

$SH man/template/math_function.sh

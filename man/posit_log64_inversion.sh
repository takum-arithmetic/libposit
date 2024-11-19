export POSIT_TYPE_SUFFIX=$(if [ -n "$POSIT_TYPE_SUFFIX" ]; then printf "$POSIT_TYPE_SUFFIX"; else printf "_log64"; fi)
export COMPUTE_DESCRIPTION="the inverse of a linear posit"
export COMPUTE_LONG_DESCRIPTION="the inverse of\n.Va a "
export FUNCTION_NAME="inversion"
export NAN_CONDITION="\n.Va a\nis zero"
export RETURN_TYPE_OVERRIDE=""
export SECOND_ARGUMENT_TYPE=""
export SEE_ALSO=""

$SH man/template/math_function.sh

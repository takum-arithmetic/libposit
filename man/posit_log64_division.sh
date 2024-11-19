export POSIT_TYPE_SUFFIX=$(if [ -n "$POSIT_TYPE_SUFFIX" ]; then printf "$POSIT_TYPE_SUFFIX"; else printf "_log64"; fi)
export COMPUTE_DESCRIPTION="the quotient of two linear posits"
export COMPUTE_LONG_DESCRIPTION="\n.Va a\ndivided by\n.Va b "
export FUNCTION_NAME="division"
export NAN_CONDITION="\n.Va b\nis zero"
export RETURN_TYPE_OVERRIDE=""
export SECOND_ARGUMENT_TYPE=$(if [ -n "$SECOND_ARGUMENT_TYPE" ]; then printf "$SECOND_ARGUMENT_TYPE"; else printf "posit_log64"; fi)
export SEE_ALSO=""

$SH man/template/math_function.sh

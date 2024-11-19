export POSIT_TYPE_SUFFIX=$(if [ -n "$POSIT_TYPE_SUFFIX" ]; then printf "$POSIT_TYPE_SUFFIX"; else printf "_log64"; fi)
export COMPUTE_DESCRIPTION="exponential function minus 1 of a linear posit"
export COMPUTE_LONG_DESCRIPTION="e raised to \n.Va a ,\nminus one"
export FUNCTION_NAME="exp_minus_1"
export NAN_CONDITION=""
export RETURN_TYPE_OVERRIDE=""
export SECOND_ARGUMENT_TYPE=""
export SEE_ALSO="exp"

$SH man/template/math_function.sh

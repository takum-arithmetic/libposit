export POSIT_TYPE_SUFFIX=$(if [ -n "$POSIT_TYPE_SUFFIX" ]; then printf "$POSIT_TYPE_SUFFIX"; else printf "64"; fi)
export COMPUTE_DESCRIPTION="the arccosecant of a posit, divided by π"
export COMPUTE_LONG_DESCRIPTION="the arccosecant of\n.Va a, \ndivided by π"
export FUNCTION_NAME="arccsc_over_pi"
export NAN_CONDITION="\n.Va a\nis in (-1, 1)"
export RETURN_TYPE_OVERRIDE=""
export SECOND_ARGUMENT_TYPE=""
export SEE_ALSO="arccsc"

$SH man/template/math_function.sh

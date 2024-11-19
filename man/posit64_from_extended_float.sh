export POSIT_TYPE_SUFFIX=$(if [ -n "$POSIT_TYPE_SUFFIX" ]; then printf "$POSIT_TYPE_SUFFIX"; else printf "64"; fi)
export FLOAT_LONG_NAME="an IEEE 754 extended precision floating-point number"
export FLOAT_NAME="extended_float"
export FLOAT_TYPE="long double"

$SH man/template/conversion_from_float.sh

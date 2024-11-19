export POSIT_TYPE_SUFFIX=$(if [ -n "$POSIT_TYPE_SUFFIX" ]; then printf "$POSIT_TYPE_SUFFIX"; else printf "64"; fi)
export FLOAT_LONG_NAME="an IEEE 754 single-precision floating-point number"
export FLOAT_NAME="float32"
export FLOAT_TYPE="float"

$SH man/template/conversion_to_float.sh

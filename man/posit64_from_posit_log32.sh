export POSIT_TYPE_SUFFIX=$(if [ -n "$POSIT_TYPE_SUFFIX" ]; then printf "$POSIT_TYPE_SUFFIX"; else printf "64"; fi)
export POSIT_TYPE_SUFFIX_INPUT="_log32"

$SH man/template/conversion.sh
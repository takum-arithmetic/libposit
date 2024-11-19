export POSIT_TYPE_SUFFIX=$(if [ -n "$POSIT_TYPE_SUFFIX" ]; then printf "$POSIT_TYPE_SUFFIX"; else printf "_log64"; fi)
export POSIT_TYPE_SUFFIX_INPUT="8"

$SH man/template/conversion.sh

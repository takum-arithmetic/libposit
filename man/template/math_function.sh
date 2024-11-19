FULL_FUNCTION_NAME=$(printf "posit%s_%s" $POSIT_TYPE_SUFFIX $FUNCTION_NAME)

cat << EOF
.Dd ${MAN_DATE}
.Dt $(printf "%s" "$FULL_FUNCTION_NAME" | tr [:lower:] [:upper:]) 3
.Os "libposit"
.Sh NAME
.Nm ${FULL_FUNCTION_NAME}
.Nd compute ${COMPUTE_DESCRIPTION}
.Sh SYNOPSIS
.In posit.h
.Ft $(if [ -n "$RETURN_TYPE_OVERRIDE" ]; then printf "$RETURN_TYPE_OVERRIDE"; else printf "posit${POSIT_TYPE_SUFFIX}"; fi)
.Fn ${FULL_FUNCTION_NAME} "posit${POSIT_TYPE_SUFFIX} a" $(if [ -n "$SECOND_ARGUMENT_TYPE" ]; then printf "\"%s b\"" "$SECOND_ARGUMENT_TYPE"; fi)
.Sh DESCRIPTION
The
.Fn ${FULL_FUNCTION_NAME}
function computes $(printf "${COMPUTE_LONG_DESCRIPTION}").
.Sh RETURN VALUES
The
.Fn ${FULL_FUNCTION_NAME}
function returns $(printf "${COMPUTE_LONG_DESCRIPTION}")
as a posit${POSIT_TYPE_SUFFIX}.$(if [ -n "$NAN_CONDITION" ]; then printf " If $NAN_CONDITION, the function returns\n.Dv POSIT$(printf "%s" "$POSIT_TYPE_SUFFIX" | tr [:lower:] [:upper:])_NAR ."; fi)
.Sh SEE ALSO$(if [ -n "$SEE_ALSO" ]; then printf "\n.Xr posit%s_%s 3 ," "$POSIT_TYPE_SUFFIX" "$SEE_ALSO"; fi)
.Xr libposit 7
.Sh AUTHORS
.An Laslo Hunhold Aq Mt laslo@hunhold.de
EOF

FULL_FUNCTION_NAME=$(printf "posit%s_from_posit%s" $POSIT_TYPE_SUFFIX $POSIT_TYPE_SUFFIX_INPUT)

cat << EOF
.Dd ${MAN_DATE}
.Dt $(printf "%s" "$FULL_FUNCTION_NAME" | tr [:lower:] [:upper:]) 3
.Os "libposit"
.Sh NAME
.Nm ${FULL_FUNCTION_NAME}
.Nd convert a posit${POSIT_TYPE_SUFFIX_INPUT} to a posit${POSIT_TYPE_SUFFIX}
.Sh SYNOPSIS
.In posit.h
.Ft posit${POSIT_TYPE_SUFFIX}
.Fn ${FULL_FUNCTION_NAME} "posit${POSIT_TYPE_SUFFIX_INPUT} t"
.Sh DESCRIPTION
The
.Fn ${FULL_FUNCTION_NAME}
converts a posit${POSIT_TYPE_SUFFIX_INPUT} to a posit${POSIT_TYPE_SUFFIX}, properly
rounding and adhering to saturation arithmetic.
.Sh RETURN VALUES
The
.Fn ${FULL_FUNCTION_NAME}
function returns a posit${POSIT_TYPE_SUFFIX}, and in particular
.Dv POSIT$(printf "%s" "$POSIT_TYPE_SUFFIX" | tr [:lower:] [:upper:])_NAR
if
.Va t
is
.Dv POSIT$(printf "%s" "$POSIT_TYPE_SUFFIX_INPUT" | tr [:lower:] [:upper:])_NAR .
.Sh SEE ALSO
.Xr libposit 7
.Sh AUTHORS
.An Laslo Hunhold Aq Mt laslo@hunhold.de
EOF

FULL_FUNCTION_NAME=$(printf "posit%s_from_%s" $POSIT_TYPE_SUFFIX $FLOAT_NAME)

cat << EOF
.Dd ${MAN_DATE}
.Dt $(printf "%s" "$FULL_FUNCTION_NAME" | tr [:lower:] [:upper:]) 3
.Os "libposit"
.Sh NAME
.Nm ${FULL_FUNCTION_NAME}
.Nd convert ${FLOAT_LONG_NAME} to a posit${POSIT_TYPE_SUFFIX}
.Sh SYNOPSIS
.In posit.h
.Ft posit${POSIT_TYPE_SUFFIX}
.Fn ${FULL_FUNCTION_NAME} "${FLOAT_TYPE} f"
.Sh DESCRIPTION
The
.Fn ${FULL_FUNCTION_NAME}
converts ${FLOAT_LONG_NAME} to a posit${POSIT_TYPE_SUFFIX}.
.Sh RETURN VALUES
The
.Fn ${FULL_FUNCTION_NAME}
function returns a posit${POSIT_TYPE_SUFFIX}, and in particular
.Dv POSIT$(printf "%s" "$POSIT_TYPE_SUFFIX" | tr [:lower:] [:upper:])_NAR
if
.Va f
is
.Dv NAN .
.Sh SEE ALSO
.Xr libposit 7
.Sh AUTHORS
.An Laslo Hunhold Aq Mt laslo@hunhold.de
EOF

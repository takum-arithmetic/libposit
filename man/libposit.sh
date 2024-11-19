cat << EOF
.Dd ${MAN_DATE}
.Dt LIBPOSIT 7
.Os libposit
.Sh NAME
.Nm libposit
.Nd posit arithmetic library
.Sh SYNOPSIS
.In posit.h

.Fd #typedef posit8
.Fd #typedef posit16
.Fd #typedef posit32
.Fd #typedef posit64
.Fd #typedef posit_log8
.Fd #typedef posit_log16
.Fd #typedef posit_log32
.Fd #typedef posit_log64

.Fd #define POSIT{,_LINEAR}{8,16,32,64}_NAR /* NaR (Not a Real) */
.Fd #define POSIT{,_LINEAR}{8,16,32,64}_POSITIVE_MINIMUM /* Smallest Pos. */
.Fd #define POSIT{,_LINEAR}{8,16,32,64}_POSITIVE_MAXIMUM /* Largest Pos. */

.Fd #define POSIT{,_LINEAR}{8,16,32,64}_2_PI /* 2π */
.Fd #define POSIT{,_LINEAR}{8,16,32,64}_2_PI_OVER_3 /* 2π/3 */
.Fd #define POSIT{,_LINEAR}{8,16,32,64}_2_PI_OVER_5 /* 2π/5 */
.Fd #define POSIT{,_LINEAR}{8,16,32,64}_3_PI /* 3π */
.Fd #define POSIT{,_LINEAR}{8,16,32,64}_3_PI_OVER_2 /* 3π/2 */
.Fd #define POSIT{,_LINEAR}{8,16,32,64}_3_PI_OVER_4 /* 3π/4 */
.Fd #define POSIT{,_LINEAR}{8,16,32,64}_3_PI_OVER_5 /* 3π/5 */
.Fd #define POSIT{,_LINEAR}{8,16,32,64}_4_PI /* 4π */
.Fd #define POSIT{,_LINEAR}{8,16,32,64}_4_PI_OVER_3 /* 4π/3 */
.Fd #define POSIT{,_LINEAR}{8,16,32,64}_4_PI_OVER_5 /* 4π/5 */
.Fd #define POSIT{,_LINEAR}{8,16,32,64}_5_PI /* 5π */
.Fd #define POSIT{,_LINEAR}{8,16,32,64}_5_PI_OVER_2 /* 5π/2 */
.Fd #define POSIT{,_LINEAR}{8,16,32,64}_5_PI_OVER_3 /* 5π/3 */
.Fd #define POSIT{,_LINEAR}{8,16,32,64}_5_PI_OVER_4 /* 5π/4 */
.Fd #define POSIT{,_LINEAR}{8,16,32,64}_5_PI_OVER_6 /* 5π/6 */
.Fd #define POSIT{,_LINEAR}{8,16,32,64}_6_PI /* 6π */
.Fd #define POSIT{,_LINEAR}{8,16,32,64}_6_PI_OVER_5 /* 6π/5 */
.Fd #define POSIT{,_LINEAR}{8,16,32,64}_GAMMA /* Euler-Mascheroni const. γ */
.Fd #define POSIT{,_LINEAR}{8,16,32,64}_LB_10 /* lb(10) */
.Fd #define POSIT{,_LINEAR}{8,16,32,64}_LB_E /* lb(e) */
.Fd #define POSIT{,_LINEAR}{8,16,32,64}_LG_2 /* lg(2) */
.Fd #define POSIT{,_LINEAR}{8,16,32,64}_LG_E /* lg(e) */
.Fd #define POSIT{,_LINEAR}{8,16,32,64}_LN_10 /* ln(10) */
.Fd #define POSIT{,_LINEAR}{8,16,32,64}_LN_2 /* ln(2) */
.Fd #define POSIT{,_LINEAR}{8,16,32,64}_ONE /* 1 */
.Fd #define POSIT{,_LINEAR}{8,16,32,64}_PHI /* Golden ratio φ */
.Fd #define POSIT{,_LINEAR}{8,16,32,64}_PI /* π */
.Fd #define POSIT{,_LINEAR}{8,16,32,64}_PI_OVER_2 /* π/2 */
.Fd #define POSIT{,_LINEAR}{8,16,32,64}_PI_OVER_3 /* π/3 */
.Fd #define POSIT{,_LINEAR}{8,16,32,64}_PI_OVER_4 /* π/4 */
.Fd #define POSIT{,_LINEAR}{8,16,32,64}_PI_OVER_5 /* π/5 */
.Fd #define POSIT{,_LINEAR}{8,16,32,64}_PI_OVER_6 /* π/6 */
.Fd #define POSIT{,_LINEAR}{8,16,32,64}_SQUARE_ROOT_2 /* √2 */
.Fd #define POSIT{,_LINEAR}{8,16,32,64}_SQUARE_ROOT_3 /* √3 */
.Fd #define POSIT{,_LINEAR}{8,16,32,64}_SQUARE_ROOT_5 /* √5 */
.Fd #define POSIT{,_LINEAR}{8,16,32,64}_SQUARE_ROOT_6 /* √6 */
.Sh DESCRIPTION
The
.Nm
library is an ISO C99 implementation of posit arithmetic, an alternative machine number format to IEEE 754 floating-point numbers. The functions contained in this library allow proper conversion from and to IEEE 754 floating-point types and facilitate the computation with posits.
.Pp
The library defines the four types
.Vt posit8 , posit16 , posit32
and
.Vt posit64
representing (logarithmic) posits and
.Vt posit_log8 , posit_log16 , posit_log32
and
.Vt posit_log64
representing linear posits for the respective 8-, 16-, 32- and 64-bit precisions. Negation negates the represented number. Comparisons (==, <, <=, >=, >) are also well-defined for two posits of the same type. The literal 0 represents zero and can be directly used for assignments and comparisons.
.Pp
Each type has a unique not-a-number type called NaR (not a real), which is
defined as
.Dv POSIT8_NAR , POSIT16_NAR , POSIT32_NAR , POSIT64_NAR, POSIT_LOG8_NAR , POSIT_LOG16_NAR , POSIT_LOG32_NAR , POSIT_LOG64_NAR
respectively. NaR is equal to itself and smaller than any other posit. If any argument of a function is NaR the result is NaR by convention. There is no dedicated symbol for infinity and NaR is also used to represent infinity.
.Pp
Also defined are the smallest and largest positive representable numbers for each type as
.Dv POSIT8_POSITIVE_MINIMUM , POSIT16_POSITIVE_MINIMUM , POSIT32_POSITIVE_MINIMUM , POSIT64_POSITIVE_MINIMUM, POSIT_LOG8_POSITIVE_MINIMUM , POSIT_LOG16_POSITIVE_MINIMUM , POSIT_LOG32_POSITIVE_MINIMUM , POSIT_LOG64_POSITIVE_MINIMUM
and
.Dv POSIT8_POSITIVE_MAXIMUM , POSIT16_POSITIVE_MAXIMUM , POSIT32_POSITIVE_MAXIMUM , POSIT64_POSITIVE_MAXIMUM, POSIT_LOG8_POSITIVE_MAXIMUM , POSIT_LOG16_POSITIVE_MAXIMUM , POSIT_LOG32_POSITIVE_MAXIMUM , POSIT_LOG64_POSITIVE_MAXIMUM
respectively. Given the set of posits is symmetric under negation, the smallest and largest representable negative numbers are obtained via negation, e.g. for
.Vt posit8
as
.Dv -POSIT8_POSITIVE_MAXIMUM
and
.Dv -POSIT8_POSITIVE_MINIMUM .
.Pp
For numerical purposes
.Nm
defines a range of useful numerical constants, including the Euler-Mascheroni constant γ as
.Dv POSIT8_GAMMA , POSIT16_GAMMA , POSIT32_GAMMA , POSIT64_GAMMA , POSIT_LOG8_GAMMA , POSIT_LOG16_GAMMA , POSIT_LOG32_GAMMA , POSIT_LOG64_GAMMA ,
the golden ratio φ as
.Dv POSIT8_PHI , POSIT16_PHI , POSIT32_PHI , POSIT64_PHI , POSIT_LOG8_PHI , POSIT_LOG16_PHI , POSIT_LOG32_PHI , POSIT_LOG64_PHI ,
the square root of 2 as
.Dv POSIT8_SQUARE_ROOT_2 , POSIT16_SQUARE_ROOT_2 , POSIT32_SQUARE_ROOT_2 , POSIT64_SQUARE_ROOT_2 , POSIT_LOG8_SQUARE_ROOT_2 , POSIT_LOG16_SQUARE_ROOT_2 , POSIT_LOG32_SQUARE_ROOT_2 , POSIT_LOG64_SQUARE_ROOT_2 ,
the square root of 3 as
.Dv POSIT8_SQUARE_ROOT_3 , POSIT16_SQUARE_ROOT_3 , POSIT32_SQUARE_ROOT_3 , POSIT64_SQUARE_ROOT_3 , POSIT_LOG8_SQUARE_ROOT_3 , POSIT_LOG16_SQUARE_ROOT_3 , POSIT_LOG32_SQUARE_ROOT_3 , POSIT_LOG64_SQUARE_ROOT_3 ,
the square root of 5 as
.Dv POSIT8_SQUARE_ROOT_5 , POSIT16_SQUARE_ROOT_5 , POSIT32_SQUARE_ROOT_5 , POSIT64_SQUARE_ROOT_5 , POSIT_LOG8_SQUARE_ROOT_5 , POSIT_LOG16_SQUARE_ROOT_5 , POSIT_LOG32_SQUARE_ROOT_5 , POSIT_LOG64_SQUARE_ROOT_5 ,
the square root of 6 as
.Dv POSIT8_SQUARE_ROOT_6 , POSIT16_SQUARE_ROOT_6 , POSIT32_SQUARE_ROOT_6 , POSIT64_SQUARE_ROOT_6, POSIT_LOG8_SQUARE_ROOT_6 , POSIT_LOG16_SQUARE_ROOT_6 , POSIT_LOG32_SQUARE_ROOT_6 , POSIT_LOG64_SQUARE_ROOT_6
and one as
.Dv POSIT8_ONE , POSIT16_ONE , POSIT32_ONE , POSIT64_ONE , POSIT_LOG8_ONE , POSIT_LOG16_ONE , POSIT_LOG32_ONE , POSIT_LOG64_ONE
respectively.
.Pp
To faciliate conversion between logarithms the conversion factors are defined as well, explicitly the binary logarithm of 10 as
.Dv POSIT8_LB_10 , POSIT16_LB_10 , POSIT32_LB_10 , POSIT64_LB_10 , POSIT_LOG8_LB_10 , POSIT_LOG16_LB_10 , POSIT_LOG32_LB_10 , POSIT_LOG64_LB_10 ,
the binary logarithm of e as
.Dv POSIT8_LB_E , POSIT16_LB_E , POSIT32_LB_E , POSIT64_LB_E , POSIT_LOG8_LB_E , POSIT_LOG16_LB_E , POSIT_LOG32_LB_E , POSIT_LOG64_LB_E ,
the decadic logarithm of 2 as
.Dv POSIT8_LG_2 , POSIT16_LG_2 , POSIT32_LG_2 , POSIT64_LG_2 , POSIT_LOG8_LG_2 , POSIT_LOG16_LG_2 , POSIT_LOG32_LG_2 , POSIT_LOG64_LG_2 ,
the decadic logarithm of e as
.Dv POSIT8_LG_E , POSIT16_LG_E , POSIT32_LG_E , POSIT64_LG_E , POSIT_LOG8_LG_E , POSIT_LOG16_LG_E , POSIT_LOG32_LG_E , POSIT_LOG64_LG_E ,
the natural logarithm of 10 as
.Dv POSIT8_LN_10 , POSIT16_LN_10 , POSIT32_LN_10 , POSIT64_LN_10 , POSIT_LOG8_LN_10 , POSIT_LOG16_LN_10 , POSIT_LOG32_LN_10 , POSIT_LOG64_LN_10
and the natural logarithm of 2 as
.Dv POSIT8_LN_2 , POSIT16_LN_2 , POSIT32_LN_2 , POSIT64_LN_2 , POSIT_LOG8_LN_2 , POSIT_LOG16_LN_2 , POSIT_LOG32_LN_2 , POSIT_LOG64_LN_2
respectively.
.Pp
Given the many uses of the constant π
.Nm
specifies all reduced fractions aπ/b with a and b in {1,...,6} (which includes π,...,6π) as
.Dv POSIT8_2_PI , POSIT8_2_PI_OVER_3 , POSIT8_2_PI_OVER_5 , POSIT8_3_PI , POSIT8_3_PI_OVER_2 , POSIT8_3_PI_OVER_4 , POSIT8_3_PI_OVER_5 , POSIT8_4_PI , POSIT8_4_PI_OVER_3 , POSIT8_4_PI_OVER_5 , POSIT8_5_PI , POSIT8_5_PI_OVER_2 , POSIT8_5_PI_OVER_3 , POSIT8_5_PI_OVER_4 , POSIT8_5_PI_OVER_6 , POSIT8_6_PI , POSIT8_6_PI_OVER_5 , POSIT8_PI , POSIT8_PI_OVER_2, POSIT8_PI_OVER_3 , POSIT8_PI_OVER_4 , POSIT8_PI_OVER_5 , POSIT8_PI_OVER_6 , POSIT_LOG8_2_PI , POSIT_LOG8_2_PI_OVER_3 , POSIT_LOG8_2_PI_OVER_5 , POSIT_LOG8_3_PI , POSIT_LOG8_3_PI_OVER_2 , POSIT_LOG8_3_PI_OVER_4 , POSIT_LOG8_3_PI_OVER_5 , POSIT_LOG8_4_PI , POSIT_LOG8_4_PI_OVER_3 , POSIT_LOG8_4_PI_OVER_5 , POSIT_LOG8_5_PI , POSIT_LOG8_5_PI_OVER_2 , POSIT_LOG8_5_PI_OVER_3 , POSIT_LOG8_5_PI_OVER_4 , POSIT_LOG8_5_PI_OVER_6 , POSIT_LOG8_6_PI , POSIT_LOG8_6_PI_OVER_5 , POSIT_LOG8_PI , POSIT_LOG8_PI_OVER_2, POSIT_LOG8_PI_OVER_3 , POSIT_LOG8_PI_OVER_4 , POSIT_LOG8_PI_OVER_5 , POSIT_LOG8_PI_OVER_6
for
.Vt posit8 ,
.Dv POSIT16_2_PI , POSIT16_2_PI_OVER_3 , POSIT16_2_PI_OVER_5 , POSIT16_3_PI , POSIT16_3_PI_OVER_2 , POSIT16_3_PI_OVER_4 , POSIT16_3_PI_OVER_5 , POSIT16_4_PI , POSIT16_4_PI_OVER_3 , POSIT16_4_PI_OVER_5 , POSIT16_5_PI , POSIT16_5_PI_OVER_2 , POSIT16_5_PI_OVER_3 , POSIT16_5_PI_OVER_4 , POSIT16_5_PI_OVER_6 , POSIT16_6_PI , POSIT16_6_PI_OVER_5 , POSIT16_PI , POSIT16_PI_OVER_2, POSIT16_PI_OVER_3 , POSIT16_PI_OVER_4 , POSIT16_PI_OVER_5 , POSIT16_PI_OVER_6 , POSIT_LOG16_2_PI , POSIT_LOG16_2_PI_OVER_3 , POSIT_LOG16_2_PI_OVER_5 , POSIT_LOG16_3_PI , POSIT_LOG16_3_PI_OVER_2 , POSIT_LOG16_3_PI_OVER_4 , POSIT_LOG16_3_PI_OVER_5 , POSIT_LOG16_4_PI , POSIT_LOG16_4_PI_OVER_3 , POSIT_LOG16_4_PI_OVER_5 , POSIT_LOG16_5_PI , POSIT_LOG16_5_PI_OVER_2 , POSIT_LOG16_5_PI_OVER_3 , POSIT_LOG16_5_PI_OVER_4 , POSIT_LOG16_5_PI_OVER_6 , POSIT_LOG16_6_PI , POSIT_LOG16_6_PI_OVER_5 , POSIT_LOG16_PI , POSIT_LOG16_PI_OVER_2, POSIT_LOG16_PI_OVER_3 , POSIT_LOG16_PI_OVER_4 , POSIT_LOG16_PI_OVER_5 , POSIT_LOG16_PI_OVER_6
for
.Vt posit16 ,
.Dv POSIT32_2_PI , POSIT32_2_PI_OVER_3 , POSIT32_2_PI_OVER_5 , POSIT32_3_PI , POSIT32_3_PI_OVER_2 , POSIT32_3_PI_OVER_4 , POSIT32_3_PI_OVER_5 , POSIT32_4_PI , POSIT32_4_PI_OVER_3 , POSIT32_4_PI_OVER_5 , POSIT32_5_PI , POSIT32_5_PI_OVER_2 , POSIT32_5_PI_OVER_3 , POSIT32_5_PI_OVER_4 , POSIT32_5_PI_OVER_6 , POSIT32_6_PI , POSIT32_6_PI_OVER_5 , POSIT32_PI , POSIT32_PI_OVER_2, POSIT32_PI_OVER_3 , POSIT32_PI_OVER_4 , POSIT32_PI_OVER_5 , POSIT32_PI_OVER_6 , POSIT_LOG32_2_PI , POSIT_LOG32_2_PI_OVER_3 , POSIT_LOG32_2_PI_OVER_5 , POSIT_LOG32_3_PI , POSIT_LOG32_3_PI_OVER_2 , POSIT_LOG32_3_PI_OVER_4 , POSIT_LOG32_3_PI_OVER_5 , POSIT_LOG32_4_PI , POSIT_LOG32_4_PI_OVER_3 , POSIT_LOG32_4_PI_OVER_5 , POSIT_LOG32_5_PI , POSIT_LOG32_5_PI_OVER_2 , POSIT_LOG32_5_PI_OVER_3 , POSIT_LOG32_5_PI_OVER_4 , POSIT_LOG32_5_PI_OVER_6 , POSIT_LOG32_6_PI , POSIT_LOG32_6_PI_OVER_5 , POSIT_LOG32_PI , POSIT_LOG32_PI_OVER_2, POSIT_LOG32_PI_OVER_3 , POSIT_LOG32_PI_OVER_4 , POSIT_LOG32_PI_OVER_5 , POSIT_LOG32_PI_OVER_6
for
.Vt posit32
and
.Dv POSIT64_2_PI , POSIT64_2_PI_OVER_3 , POSIT64_2_PI_OVER_5 , POSIT64_3_PI , POSIT64_3_PI_OVER_2 , POSIT64_3_PI_OVER_4 , POSIT64_3_PI_OVER_5 , POSIT64_4_PI , POSIT64_4_PI_OVER_3 , POSIT64_4_PI_OVER_5 , POSIT64_5_PI , POSIT64_5_PI_OVER_2 , POSIT64_5_PI_OVER_3 , POSIT64_5_PI_OVER_4 , POSIT64_5_PI_OVER_6 , POSIT64_6_PI , POSIT64_6_PI_OVER_5 , POSIT64_PI , POSIT64_PI_OVER_2, POSIT64_PI_OVER_3 , POSIT64_PI_OVER_4 , POSIT64_PI_OVER_5 , POSIT64_PI_OVER_6 , POSIT_LOG64_2_PI , POSIT_LOG64_2_PI_OVER_3 , POSIT_LOG64_2_PI_OVER_5 , POSIT_LOG64_3_PI , POSIT_LOG64_3_PI_OVER_2 , POSIT_LOG64_3_PI_OVER_4 , POSIT_LOG64_3_PI_OVER_5 , POSIT_LOG64_4_PI , POSIT_LOG64_4_PI_OVER_3 , POSIT_LOG64_4_PI_OVER_5 , POSIT_LOG64_5_PI , POSIT_LOG64_5_PI_OVER_2 , POSIT_LOG64_5_PI_OVER_3 , POSIT_LOG64_5_PI_OVER_4 , POSIT_LOG64_5_PI_OVER_6 , POSIT_LOG64_6_PI , POSIT_LOG64_6_PI_OVER_5 , POSIT_LOG64_PI , POSIT_LOG64_PI_OVER_2, POSIT_LOG64_PI_OVER_3 , POSIT_LOG64_PI_OVER_4 , POSIT_LOG64_PI_OVER_5 , POSIT_LOG64_PI_OVER_6
for
.Vt posit64.
As inversion is a lossless operation for logarithmic posits, one can invert the constants to also
obtain all reduced fractions b/(aπ) with a and b in {1,...,6}.
.Sh SEE ALSO
EOF

# list all manual pages, using a phase-shift to omit a comma for the last entry
LAST_MAN3=""
for man3 in $MAN3_LIST; do
	if [ ! -z $LAST_MAN3 ]; then
		printf ".Xr $man3 3 ,\n"
	fi
	LAST_MAN3=$man3
done
if [ ! -z $LAST_MAN3 ]; then
	printf ".Xr $LAST_MAN3 3\n"
fi

cat << EOF
.Sh AUTHORS
.An Laslo Hunhold Aq Mt laslo@hunhold.de
EOF

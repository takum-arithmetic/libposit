/* See LICENSE file for copyright and license details. */
#include <float.h>
#include <math.h>
#include <stdbool.h>
#include <stdint.h>

#include "../posit.h"

#include "codec.h"
#include "util.h"

/*
 * Posits have the form
 *
 * 	SR...RNEEM...M
 *
 * where N = NOT(R) and there are k R's, with k >= 1. If we shift the
 * posit one to the left we obtain
 *
 * 	R...RNEEM...M0
 *
 * and it holds, when we XOR this with it once more shifted to the left
 *
 *     R...RNEEM...M0
 *     R..RNEEM...M00 XOR
 *     ------------------
 *     00001xxxxxxxx0
 *
 * If we count the leading zeros of this result we directly obtain k-1.
 *
 * By handling the special cases beforehand we know that the result of
 * (p << 1) ^ (p << 2) is never zero.
 */
float
codec_posit_log8_to_l(posit_log8 t)
{
	const union util_posit8_union in = {
		.value = t,
	};
	bool R0;
	uint8_t k, e, M;
	int_fast16_t c;

	/* Catch special cases */
	if (t == 0) {
		return -INFINITY;
	} else if (t == POSIT_LOG8_NAR) {
		return NAN;
	}

	/* determine k as explained above */
	k = util_clz8((in.bits << 1) ^ (in.bits << 2)) + 1;

	/* Determine c = 4r+e with r = (R0 = 0) ? -k : k-1 */
	R0 = ((in.bits & UINT8_C(0x40)) != 0) ? 1 : 0;

	/* determine the exponent value */
	if (k <= 8 - 4) {
		/* both exponent bits are explicitly given */
		e = (in.bits >> (8 - 4 - k)) & UINT8_C(0x03);
	} else if (k == 8 - 4 + 1) {
		/* only the higher exponent bit is given, right at the end */
		e = 2 * (in.bits & UINT8_C(0x01));
	} else {
		/* no exponent bit is given, ghost bits imply zero */
		e = 0;
	}

	c = ((R0 == 0) ? (-4 * k) : (4 * (k - 1))) + e;

	/* the mantissa bits follow by shifting p by k+4 to the left */
	M = (k < 8 - 4) ? (in.bits << (k + 4)) : 0;

	/*
	 * Convert c and M to floats and add them. The
	 * conversions and the addition are lossless as
	 * |c| is at most 8 bits, M is at most 3 bits,
	 * which easily fits in the 23 bits provided by
	 * float32.
	 */
	return (1 - 2 * (t < 0)) * ((float)c + ldexpf((float)M, -8));
}

float
codec_posit_log16_to_l(posit_log16 t)
{
	const union util_posit16_union in = {
		.value = t,
	};
	bool R0;
	uint8_t k, e;
	int_fast16_t c;
	uint16_t M;

	/* Catch special cases */
	if (t == 0) {
		return -INFINITY;
	} else if (t == POSIT_LOG16_NAR) {
		return NAN;
	}

	/* determine k as explained above */
	k = util_clz16((in.bits << 1) ^ (in.bits << 2)) + 1;

	/* Determine c = 4r+e with r = (R0 = 0) ? -k : k-1 */
	R0 = ((in.bits & UINT16_C(0x4000)) != 0) ? 1 : 0;

	/* determine the exponent value */
	if (k <= 16 - 4) {
		/* both exponent bits are explicitly given */
		e = (in.bits >> (16 - 4 - k)) & UINT16_C(0x0003);
	} else if (k == 16 - 4 + 1) {
		/* only the higher exponent bit is given, right at the end */
		e = 2 * (in.bits & UINT16_C(0x0001));
	} else {
		/* no exponent bit is given, ghost bits imply zero */
		e = 0;
	}

	c = ((R0 == 0) ? (-4 * k) : (4 * (k - 1))) + e;

	/* the mantissa bits follow by shifting p by k+4 to the left */
	M = (k < 16 - 4) ? (in.bits << (k + 4)) : 0;

	/*
	 * Convert c and M to floats and add them. The
	 * conversions and the addition are lossless as
	 * |c| is at most 8 bits, M is at most 11 bits,
	 * which easily fits in the 23 bits provided by
	 * float32.
	 */
	return (1 - 2 * (t < 0)) * ((float)c + ldexpf((float)M, -16));
}

double
codec_posit_log32_to_l(posit_log32 t)
{
	const union util_posit32_union in = {
		.value = t,
	};
	bool R0;
	uint8_t k, e;
	int_fast16_t c;
	uint32_t M;

	/* Catch special cases */
	if (t == 0) {
		return -INFINITY;
	} else if (t == POSIT_LOG32_NAR) {
		return NAN;
	}

	/* determine k as explained above */
	k = util_clz32((in.bits << 1) ^ (in.bits << 2)) + 1;

	/* Determine c = 4r+e with r = (R0 = 0) ? -k : k-1 */
	R0 = ((in.bits & UINT32_C(0x40000000)) != 0) ? 1 : 0;

	/* determine the exponent value */
	if (k <= 32 - 4) {
		/* both exponent bits are explicitly given */
		e = (in.bits >> (32 - 4 - k)) & UINT32_C(0x00000003);
	} else if (k == 32 - 4 + 1) {
		/* only the higher exponent bit is given, right at the end */
		e = 2 * (in.bits & UINT32_C(0x00000001));
	} else {
		/* no exponent bit is given, ghost bits imply zero */
		e = 0;
	}

	c = ((R0 == 0) ? (-4 * k) : (4 * (k - 1))) + e;

	/* the mantissa bits follow by shifting p by k+4 to the left */
	M = (k < 32 - 4) ? (in.bits << (k + 4)) : 0;

	/*
	 * Convert c and M to floats and add them. The
	 * conversions and the addition are lossless as
	 * |c| is at most 8 bits, M is at most 27 bits,
	 * which easily fits in the 52 bits provided by
	 * float64.
	 */
	return (1 - 2 * (t < 0)) * ((double)c + ldexp((double)M, -32));
}

long double
codec_posit_log64_to_l(posit_log64 t)
{
#if LDBL_MANT_DIG >= 64
	const union util_posit64_union in = {
		.value = t,
	};
	bool R0;
	uint8_t k, e;
	int_fast16_t c;
	uint64_t M;

	/* Catch special cases */
	if (t == 0) {
		return -INFINITY;
	} else if (t == POSIT_LOG64_NAR) {
		return NAN;
	}

	/* determine k as explained above */
	k = util_clz64((in.bits << 1) ^ (in.bits << 2)) + 1;

	/* Determine c = 4r+e with r = (R0 = 0) ? -k : k-1 */
	R0 = ((in.bits & UINT64_C(0x4000000000000000)) != 0) ? 1 : 0;

	/* determine the exponent value */
	if (k <= 64 - 4) {
		/* both exponent bits are explicitly given */
		e = (in.bits >> (64 - 4 - k)) & UINT64_C(0x0000000000000003);
	} else if (k == 64 - 4 + 1) {
		/* only the higher exponent bit is given, right at the end */
		e = 2 * (in.bits & UINT64_C(0x0000000000000001));
	} else {
		/* no exponent bit is given, ghost bits imply zero */
		e = 0;
	}

	c = ((R0 == 0) ? (-4 * k) : (4 * (k - 1))) + e;

	/* the mantissa bits follow by shifting p by k+4 to the left */
	M = (k < 64 - 4) ? (in.bits << (k + 4)) : 0;

	/*
	 * Convert c and M to floats and add them. The
	 * conversions and the addition are lossless as
	 * |c| is at most 8 bits, M is at most 59 bits,
	 * which easily fits in the 64 bits provided by
	 * extended float.
	 */
	return (1 - 2 * (t < 0)) *
	       ((long double)c + ldexpl((long double)M, -64));
#else
#pragma message                                                                \
	"Extended float format is too small to hold what posit_log64 offers, posit_log64 decoding is stubbed"
	(void)t;

	return NAN;
#endif
}

static inline uint32_t
float32_fraction_to_rounded_bits(float f, uint_fast8_t num_bits)
{
	uint32_t F;

	/*
	 * This function converts f in [0,1) to a num_bit fixed
	 * point representation, returning the correctly rounded
	 * num_bit LSB's
	 */
	if (f == 0 || num_bits == 0) {
		F = 0;
	} else {
		union {
			float val;
			uint32_t bits;
		} fu = {
			.val = f,
		};

		int q;

		/*
		 * We know that f has the form (1+x)*2^q with q <= 0.
		 * First mask out the fraction bits and add the
		 * implicit 1 bit
		 */
		F = (fu.bits & ((UINT32_C(1) << 23) - 1)) | (UINT32_C(1) << 23);

		/* shift to the left until the 1 bit is the MSB */
		F <<= 9 - 1;

		/*
		 * If q = 0 we would be done here (because then the
		 * implicit 1 bit would be the first 'decimal' bit,
		 * which matches our normalised form). However q is
		 * generally <= 0, so we shift the bits by -q to the
		 * right which 'normalises' it, as desired.
		 */
		frexpf(f, &q);
		F = (-q < 32) ? (F >> -q) : UINT32_C(0);

		/*
		 * Round F to num_bit bits, possibly rounding up when the
		 * num_bit+1'th bit is set, but resolving a tie to even.
		 * The result will never be zero (under- or overflow) as we
		 * ensured this before with clamping
		 */
		F = util_round_uint32_to_number_of_bits(F, num_bits);
	}

	return F;
}

static inline uint64_t
float64_fraction_to_rounded_bits(double f, uint_fast8_t num_bits)
{
	uint64_t F;

	/*
	 * This function converts f in [0,1) to a num_bit fixed
	 * point representation, returning the correctly rounded
	 * num_bit LSB's
	 */
	if (f == 0 || num_bits == 0) {
		F = 0;
	} else {
		union {
			double val;
			uint64_t bits;
		} fu = {
			.val = f,
		};

		int q;

		/*
		 * We know that f has the form (1+x)*2^q with q < 0.
		 * First mask out the fraction bits and add the
		 * implicit 1 bit
		 */
		F = (fu.bits & ((UINT64_C(1) << 52) - 1)) | (UINT64_C(1) << 52);

		/* shift to the left until the 1 bit is the MSB */
		F <<= 12 - 1;

		/*
		 * If q = 0 we would be done here (because then the
		 * implicit 1 bit would be the first 'decimal' bit,
		 * which matches our normalised form). However q is
		 * generally <= 0, so we shift the bits by -q to the
		 * right which 'normalises' it, as desired.
		 */
		frexp(f, &q);
		F = (-q < 64) ? (F >> -q) : UINT64_C(0);

		/*
		 * Round F to num_bit bits, possibly rounding up when the
		 * num_bit+1'th bit is set, but resolving a tie to even.
		 * The result will never be zero (under- or overflow) as we
		 * ensured this before with clamping
		 */
		F = util_round_uint64_to_number_of_bits(F, num_bits);
	}

	return F;
}

static inline uint64_t
extended_float_fraction_to_rounded_bits(long double f, uint_fast8_t num_bits)
{
	uint64_t F;

	/*
	 * This function converts f in [0,1) to a num_bit fixed
	 * point representation, returning the correctly rounded
	 * num_bit LSB's
	 */
	if (f == 0 || num_bits == 0) {
		F = 0;
	} else {
		union {
			long double val;

			struct __attribute__((__packed__)) {
#if LDBL_MANT_DIG == 53 && LDBL_MAX_EXP == 1024
				/* 64-bit long double, i.e. double is equal to
				 * long double */
				uint64_t sign_exp_fraction;
#elif LDBL_MANT_DIG == 64 && LDBL_MAX_EXP == 16384
/* 80-bit long double */
#if __BYTE_ORDER == __BIG_ENDIAN
				uint64_t fraction;
				uint16_t sign_exp;
#else
				uint16_t sign_exp;
				uint64_t fraction;
#endif
#elif LDBL_MANT_DIG == 113 && LDBL_MAX_EXP == 16384
/* 128-bit long double */
#if __BYTE_ORDER == __BIG_ENDIAN
				uint16_t fraction_reallydontcare;
				uint32_t fraction_dontcare;
				uint64_t fraction;
				uint16_t sign_exp;
#else
				uint16_t sign_exp;
				uint64_t fraction;
				uint32_t fraction_dontcare;
				uint16_t fraction_reallydontcare;
#endif
#else
				char junk;
#endif
			} bits;
		} fu = {
			.val = f,
		};

		int q;

		/*
		 * We know that f has the form (1+x)*2^q with q < 0.
		 * The fraction bits are in fu.bits.fraction.
		 */
		frexpl(f, &q);

#if LDBL_MANT_DIG == 53 && LDBL_MAX_EXP == 1024
		/* 64-bit double, lower 52 bits are fractions, implicit 1 */
		F = ((UINT64_C(0x000fffffffffffff) & fu.bits.sign_exp_fraction)
		     << 11) |
		    (UINT64_C(1) << 63);

		/*
		 * We correct q to reflect our shift from 1.xxx... to
		 * 0.1xxx...
		 */
		q++;
#elif LDBL_MANT_DIG == 64 && LDBL_MAX_EXP == 16384
		/* 80-bit long double, has explicit 1 */
		F = fu.bits.fraction;
#elif LDBL_MANT_DIG == 113 && LDBL_MAX_EXP == 16384
		/*
		 * 128-bit long double, has implicit 1
		 *
		 * We shift one to the right (we don't care about
		 * rounding because we don't need that kind of
		 * precision) and add the implicit 1 bit. The 1 bit
		 * is automatically the MSB.
		 */
		F = (fu.bits.fraction >> 1) | (UINT64_C(1) << 63);

		/*
		 * We correct q to reflect our shift from 1.xxx... to
		 * 0.1xxx...
		 */
		q++;
#else
		(void)fu;
		F = 0;
#endif

		/*
		 * If q = 0 we would be done here (because then the
		 * implicit 1 bit would be the first 'decimal' bit,
		 * which matches our normalised form). However q is
		 * generally <= 0, so we shift the bits by -q (given
		 * we did one right-shift earlier) to the right which
		 * 'normalises' it, as desired.
		 */
		F = (-q < 64) ? (F >> -q) : UINT64_C(0);

		/*
		 * Round F to num_bit bits, possibly rounding up when the
		 * num_bit+1'th bit is set, but resolving a tie to even.
		 * The result will never be zero (under- or overflow) as we
		 * ensured this before with clamping
		 */
		F = util_round_uint64_to_number_of_bits(F, num_bits);
	}

	return F;
}

/*
 * For linear posits, instead of duplicating all the machinery,
 * we simply treat a linear posit as a logarithmic one: We obtain c and
 * m from the logarithmic value l and compute f and e, which are then
 * converted to g and h as in Algorithm 5 from the takum paper, yielding
 * the final floating point.
 */
double
codec_s_and_linear_l_to_float64(bool s, long double l)
{
	long double cpm, m, f, g;
	int16_t c, e, h;

	/* catch special cases */
	if (isnan(l) || (isinf(l) && l > 0.0L)) {
		return NAN;
	} else if (isinf(l) && l < 0.0L) {
		return 0.0;
	}

	/* obtain c and m from l */
	cpm = (s == 0) ? l : -l;
	c = floorl(cpm);
	m = cpm - c;

	/* m could have overflowed to 1.0 */
	if (m == 1.0L) {
		c += 1;
		m = 0.0L;
	}

	/* convert c and m to f and e */
	f = m;
	e = (1 - 2 * s) * (c + s);

	/* convert f and e to g and h as in Algorithm 5 */
	if (s == 0) {
		h = e;
		g = f;
	} else {
		if (f == 0.0) {
			h = e + 1;
			g = 0.0L;
		} else {
			h = e;
			g = 1.0L - f;
		}
	}

	/* (-1)^s (1 + g) 2^h is our final floating-point number */
	return (double)((1 - 2 * s) * ldexpl(1.0L + g, h));
}

long double
codec_s_and_linear_l_to_extended_float(bool s, long double l)
{
	long double cpm, m, f, g;
	int16_t c, e, h;

	/* catch special cases */
	if (isnan(l) || (isinf(l) && l > 0.0l)) {
		return NAN;
	} else if (isinf(l) && l < 0.0l) {
		return 0.0;
	}

	/* obtain c and m from l */
	cpm = (s == 0) ? l : -l;
	c = floorl(cpm);
	m = cpm - c;

	/* m could have overflowed to 1.0 */
	if (m == 1.0l) {
		c += 1;
		m = 0.0l;
	}

	/* convert c and m to f and e */
	f = m;
	e = (1 - 2 * s) * (c + s);

	/* convert f and e to g and h as in Algorithm 5 */
	if (s == 0) {
		h = e;
		g = f;
	} else {
		if (f == 0.0l) {
			h = e + 1;
			g = 0.0l;
		} else {
			h = e;
			g = 1.0l - f;
		}
	}

	/* (-1)^s (1 + g) 2^h is our final floating-point number */
	return (1 - 2 * s) * ldexpl(1.0l + g, h);
}

/*
 * For the linear posits we abuse the encoder a bit by creating a
 * 'fake' linear l. In the end l is just (-1)^s (c+m), so if we just
 * get c and m from f and e, which in turn are derived from g and h
 * via Algorithm 4 in the takum paper.
 */
double
codec_linear_l_from_float32(float f)
{
	bool s;
	double g, m;
	int h;
	int16_t c;

	/* catch special cases */
	if (isnan(f) || isinf(f)) {
		return NAN;
	} else if (f == 0.0f) {
		return -INFINITY;
	}

	/* first extract sign and absolutise f */
	if (f < 0.0f) {
		s = 1;
		f = -f;
	} else {
		s = 0;
	}

	/* convert f to fractional and integral components */
	g = frexpf(f, &h);

	/*
	 * g is in range [0.5,1), so we multiply it by 2 and likewise
	 * decrement h to obtain g in the range [1,2). Then we subtract
	 * 1.0 to obtain the final g in the range [0,1)
	 */
	g = 2 * g - 1.0;
	h--;

	/*
	 * the number has the form (-1)^s (1+g) 2^h. Use Algorithm 4
	 * in the takum paper to obtain c and m (which is equal to f)
	 */
	if (s == 0) {
		c = h;
		m = g;
	} else {
		if (g == 0.0f) {
			c = -h;
			m = 0.0;
		} else {
			c = -h - 1;
			m = 1.0 - g;
		}
	}

	/* l is (-1)^s (c+m) */
	return (1 - 2 * s) * (c + m);
}

long double
codec_linear_l_from_float64(double f)
{
	bool s;
	long double g, m;
	int h;
	int16_t c;

	/* catch special cases */
	if (isnan(f) || isinf(f)) {
		return NAN;
	} else if (f == 0.0) {
		return -INFINITY;
	}

	/* first extract sign and absolutise f */
	if (f < 0.0) {
		s = 1;
		f = -f;
	} else {
		s = 0;
	}

	/* convert f to fractional and integral components */
	g = frexp(f, &h);

	/*
	 * g is in range [0.5,1), so we multiply it by 2 and likewise
	 * decrement h to obtain g in the range [1,2). Then we subtract
	 * 1.0 to obtain the final g in the range [0,1)
	 */
	g = 2 * g - 1.0L;
	h--;

	/*
	 * the number has the form (-1)^s (1+g) 2^h. Use Algorithm 4
	 * in the takum paper to obtain c and m (which is equal to f)
	 */
	if (s == 0) {
		c = h;
		m = g;
	} else {
		if (g == 0.0) {
			c = -h;
			m = 0.0;
		} else {
			c = -h - 1;
			m = 1.0 - g;
		}
	}

	/* l is (-1)^s (c+m) */
	return (1 - 2 * s) * (c + m);
}

long double
codec_linear_l_from_extended_float(long double f)
{
	bool s;
	long double g, m;
	int h;
	int16_t c;

	/* catch special cases */
	if (isnan(f) || isinf(f)) {
		return NAN;
	} else if (f == 0.0l) {
		return -INFINITY;
	}

	/* first extract sign and absolutise f */
	if (f < 0.0l) {
		s = 1;
		f = -f;
	} else {
		s = 0;
	}

	/* convert f to fractional and integral components */
	g = frexpl(f, &h);

	/*
	 * g is in range [0.5,1), so we multiply it by 2 and likewise
	 * decrement h to obtain g in the range [1,2). Then we subtract
	 * 1.0 to obtain the final g in the range [0,1)
	 */
	g = 2 * g - 1.0l;
	h--;

	/*
	 * the number has the form (-1)^s (1+g) 2^h. Use Algorithm 4
	 * in the takum paper to obtain c and m (which is equal to f)
	 */
	if (s == 0) {
		c = h;
		m = g;
	} else {
		if (g == 0.0l) {
			c = -h;
			m = 0.0l;
		} else {
			c = -h - 1;
			m = 1.0l - g;
		}
	}

	/* l is (-1)^s (c+m) */
	return (1 - 2 * s) * (c + m);
}

static uint64_t
get_RR0bE_and_k_from_c(int_fast16_t c, uint8_t n, long double f, uint8_t *p)
{
	bool R0b;
	uint64_t RR0bE;
	int_fast16_t tmp;
	uint8_t k, e;

	/* It holds c = 4r+e with r = (R0 == 0) ? -k : k-1 */
	if (c >= 0) {
		/* R0 = 1 -> c = 4k + e - 4 -> c + 4 = 4k + e */
		R0b = 0;
		tmp = c + 4;
		e = tmp % 4;
		k = tmp / 4;
	} else {
		/* R0 = 0 -> c = -4k + e -> -c = 4k - e -> -c + 3 = 4k + (3-e)
		 */
		R0b = 1;
		tmp = -c + 3;
		e = 3 - (tmp % 4);
		k = tmp / 4;
	}

	/* just a sanity check that should only trigger if we didn't
	 * bound properly
	 */
	if (k >= n) {
		return 0;
	}

	if (R0b == 0) {
		/* fill RR0bE with k 1s */
		RR0bE = (UINT64_C(1) << k) - 1;
	} else {
		/* fill RR0bE with zeroes */
		RR0bE = 0;
	}

	/*
	 * Naively you would shift RR0bE 3 bits to the left to fill
	 * it up with R0b and the two exponent bits, but k can be up to
	 * n-1, which would overflow the integer.
	 *
	 * Instead we proceed on a case-by-case basis.
	 */
	if (k == n - 1) {
		/* The posit has the form SR...R, the precision is 0 */
		*p = 0;

		/* We still need to round in R0bEE. */
		if (R0b == 0) {
			/*
			 * This implies R=1, so we don't round at all
			 * as rounding up would lead to an overflow
			 * to NaR, which is explicitly forbidden
			 */
		} else {
			/*
			 * This implies R=0, so round with tie-to-even
			 * using the bits R0bEEF...F, but given R=0 it
			 * holds R0b=1, so the rounding bits are
			 * 1EEF...F. This means that we either get
			 * a tie to even for e=0 and f=0, or we round up
			 */
			if (e == 0 && f == 0) {
				/* tie to even */
				RR0bE += (RR0bE % 2 != 0) ? 1 : 0;
			} else {
				/* round up */
				RR0bE += 1;
			}
		}
	} else if (k == n - 2) {
		/* The posit has the form SR...RR0b, the precision is 0 */
		*p = 0;

		/* Shift RR0bE one to the left and set the LSB to R0b */
		RR0bE <<= 1;
		RR0bE |= R0b;

		/*
		 * We still have to round now using the bits EEF...F.
		 * We round up if e >= 2 or e == 2 and f > 0.0, and
		 * have a tie if e = 2 and f = 0.0.
		 */
		if (e >= 2 || (e == 2 && f > 0.0L)) {
			/* round up */
			RR0bE += 1;
		} else if (e == 2 && f == 0.0L) {
			/* tie to even */
			RR0bE += (RR0bE % 2 != 0) ? 1 : 0;
		}
	} else if (k == n - 3) {
		/* The posit has the form SR...RR0bE, the precision is 0 */
		*p = 0;

		/* Shift RR0bE two to the left and set the two LSBs to R0b
		 * and the higher e-bit */
		RR0bE <<= 1;
		RR0bE |= R0b;
		RR0bE <<= 1;
		RR0bE |= (e >= 2);

		/*
		 * We round in the bits EF...F, i.e. round up if
		 * e % 2 == 1 and f > 0.0 and tie to even if
		 * e % 2 == 1 and f = 0.0.
		 */
		if (e % 2 == 1 && f > 0.0L) {
			/* round up */
			RR0bE += 1;
		} else if (e % 2 == 1 && f == 0.0L) {
			/* tie to even */
			RR0bE += (RR0bE % 2 != 0) ? 1 : 0;
		}
	} else {
		/*
		 * We have no space issues. Shift RR0bE 3 to the left
		 * and set R0b and EE.
		 */
		RR0bE <<= 1;
		RR0bE |= R0b;
		RR0bE <<= 2;
		RR0bE |= e;

		/* The precision follows from k */
		*p = n - k - 4;

		/* Shift RR0bE p to the left */
		RR0bE <<= *p;
	}

	return RR0bE;
}

posit_log8
codec_posit_log8_from_s_and_l(bool s, float l)
{
	return posit_log8_from_posit_log32(
		codec_posit_log32_from_s_and_l(s, l));
}

posit_log16
codec_posit_log16_from_s_and_l(bool s, float l)
{
	uint8_t p;
	uint16_t RR0bE;
	uint32_t M;
	int_fast16_t c;
	float cpm, m;
	const float bound = 56.0f;

	if (isnan(l) || (isinf(l) && l > 0)) {
		return POSIT_LOG16_NAR;
	} else if (isinf(l) && l < 0) {
		return 0;
	}

	/*
	 * Clamp l to representable exponents,
	 * the maximum 0111111111111111 has l=56
	 */
	l = (l < -bound) ? -bound : (l > bound) ? bound : l;

	/* Apply sign to l to obtain c + m (cpm) */
	cpm = (1 - 2 * s) * l;

	/* Obtain c and m from cpm */
	c = floorf(cpm);
	m = cpm - c;

	/* m could have overflowed to 1.0 */
	if (m == 1.0f) {
		c += 1;
		m = 0.0;
	}

	/* get RR0bE */
	RR0bE = (uint16_t)get_RR0bE_and_k_from_c(c, 16, (long double)m, &p);

	/* Determine mantissa bits */
	M = float32_fraction_to_rounded_bits(m, p);

	/*
	 * Assemble, optionally apply the carry to SDR which is guaranteed
	 * not to yield NaR as we bounded l earlier and return
	 */
	return ((((uint16_t)s) << (16 - 1)) | ((uint16_t)RR0bE)) + (uint16_t)M;
}

posit_log32
codec_posit_log32_from_s_and_l(bool s, double l)
{
	uint8_t p;
	uint32_t RR0bE;
	uint64_t M;
	int_fast16_t c;
	double cpm, m;
	const double bound = 120.0;

	if (isnan(l) || (isinf(l) && l > 0)) {
		return POSIT_LOG32_NAR;
	} else if (isinf(l) && l < 0) {
		return 0;
	}

	/*
	 * Clamp l to representable exponents,
	 * the maximum 0111111111111111... has l=120
	 */
	l = (l < -bound) ? -bound : (l > bound) ? bound : l;

	/* Apply sign to l to obtain c + m (cpm) */
	cpm = (1 - 2 * s) * l;

	/* Obtain c and m from cpm */
	c = floor(cpm);
	m = cpm - c;

	/* m could have overflowed to 1.0 */
	if (m == 1.0) {
		c += 1;
		m = 0.0;
	}

	/* get RR0bE */
	RR0bE = (uint32_t)get_RR0bE_and_k_from_c(c, 32, (long double)m, &p);

	/* Determine mantissa bits */
	M = float64_fraction_to_rounded_bits(m, p);

	/*
	 * Assemble, optionally apply the carry to SDR which is guaranteed
	 * not to yield NaR as we bounded l earlier and return
	 */
	return ((((uint32_t)s) << (32 - 1)) | ((uint32_t)RR0bE)) + (uint32_t)M;
}

posit_log64
codec_posit_log64_from_s_and_l(bool s, long double l)
{
#if (LDBL_MANT_DIG == 53 && LDBL_MAX_EXP == 1024) ||                           \
	(LDBL_MANT_DIG == 64 && LDBL_MAX_EXP == 16384) ||                      \
	(LDBL_MANT_DIG == 113 && LDBL_MAX_EXP == 16384)
	uint8_t p;
	uint64_t RR0bE, M;
	int_fast16_t c;
	long double cpm, m;
	const long double bound = 248.0L;

	if (isnan(l) || (isinf(l) && l > 0)) {
		return POSIT_LOG64_NAR;
	} else if (isinf(l) && l < 0) {
		return 0;
	}

	/*
	 * Clamp l to representable exponents,
	 * the maximum 0111111111111111... has l=248.0
	 */
	l = (l < -bound) ? -bound : (l > bound) ? bound : l;

	/* Apply sign to l to obtain c + m (cpm) */
	cpm = (1 - 2 * s) * l;

	/* Obtain c and m from cpm */
	c = floorl(cpm);
	m = cpm - c;

	/* m could have overflowed to 1.0 */
	if (m == 1.0) {
		c += 1;
		m = 0.0;
	}

	/* get RR0bE */
	RR0bE = (uint64_t)get_RR0bE_and_k_from_c(c, 64, m, &p);

	/* Determine mantissa bits */
	M = extended_float_fraction_to_rounded_bits(m, p);

	/*
	 * Assemble, optionally apply the carry to SDR which is guaranteed
	 * not to yield NaR as we bounded l earlier and return
	 */
	return ((((uint64_t)s) << (64 - 1)) | ((uint64_t)RR0bE)) + (uint64_t)M;
#else
#pragma message                                                                \
	"Unimplemented extended float format, posit_log64 encoding is stubbed"
	(void)s;
	(void)l;

	return POSIT_LOG64_NAR;
#endif
}

/* See LICENSE file for copyright and license details. */
#include <stdbool.h>

#include "../posit.h"

#include "util.h"

/*
 * Assume the input is a left-aligned fixed-point representation of a
 * value [0,1) with N bits. This function rounds the value to a right-aligned
 * representation with exactly the given number of bits; any more
 * significant bits are zero. Round to the nearest value and break
 * ties by rounding to the respective even value.
 */
#define GENERATE_UTIL_ROUND_UINTN_TO_NUMBER_OF_BITS(N)                         \
	uint##N##_t util_round_uint##N##_to_number_of_bits(                    \
		uint##N##_t input, uint8_t number_of_bits)                     \
	{                                                                      \
		bool rounding_bit, is_tied;                                    \
		uint##N##_t rounding_bit_mask, filter_mask, result;            \
                                                                               \
		/* We assume number of bits is within the proper range 0..N-1  \
		 * and have the following bitwise representation of the input: \
		 *                                                             \
		 *                         R                                   \
		 *                         |                                   \
		 *                         v                                   \
		 * |xxxxxxxxxxxxxxxxxxxxxxx.............................|      \
		 *                                                             \
		 * <--- number_of_bits ---><--- (N - number_of_bits) --->      \
		 * <---------------------- N --------------------------->      \
		 *                                                             \
		 * where R marks the position of the rounding bit.             \
		 */                                                            \
                                                                               \
		/*                                                             \
		 * Obtain the rounding bit by using a mask 10...0 of length    \
		 * (N - number_of_bits)                                        \
		 */                                                            \
		rounding_bit_mask = UINT##N##_C(1)                             \
		                    << (N - number_of_bits - 1);               \
		rounding_bit = ((input & rounding_bit_mask) != 0);             \
                                                                               \
		/*                                                             \
		 * Check if we have a tie, which is the case when the lowest   \
		 * (N - number_of_bits) bits are 10...0. We do this by         \
		 * removing all more significant bits with a filter mask and   \
		 * checking equality with the rounding bit mask.               \
		 */                                                            \
		filter_mask = (UINT##N##_C(1) << (N - number_of_bits)) - 1;    \
		is_tied = ((input & filter_mask) == rounding_bit_mask);        \
                                                                               \
		/*                                                             \
		 * Shift the input (N - number_of_bits) to the right such that \
		 * it has the desired number of bits.                          \
		 */                                                            \
		result = input >> (N - number_of_bits);                        \
                                                                               \
		/*                                                             \
		 * Round up if the rounding bit is set, but treat a tie by     \
		 * rounding to even                                            \
		 */                                                            \
		result += rounding_bit && (!is_tied || (result % 2 == 1));     \
                                                                               \
		return result;                                                 \
	}

GENERATE_UTIL_ROUND_UINTN_TO_NUMBER_OF_BITS(8)
GENERATE_UTIL_ROUND_UINTN_TO_NUMBER_OF_BITS(16)
GENERATE_UTIL_ROUND_UINTN_TO_NUMBER_OF_BITS(32)
GENERATE_UTIL_ROUND_UINTN_TO_NUMBER_OF_BITS(64)

/* check if the compiler has clz */
#ifndef __has_builtin
#define __has_builtin(x) (false)
#endif

#if __has_builtin(__builtin_clz)
uint8_t
util_clz8(uint8_t x)
{
	/*
	 * __builtin_clz operates on unsigned int, which is at least
	 * 16 bits wide. We cast uint8_t to unsigned int and subtract
	 * the difference in number of bits from the result
	 */
	return __builtin_clz((unsigned int)x) -
	       (sizeof(unsigned int) - sizeof(uint8_t)) * 8;
}
#else
uint8_t
util_clz8(uint8_t x)
{
	if (x == 0) {
		return 8;
	} else {
		uint8_t leading_zeros;

		for (leading_zeros = 0; x < UINT8_C(0x80); leading_zeros++) {
			x <<= 1;
		}

		return leading_zeros;
	}
}
#endif

#if __has_builtin(__builtin_clz)
uint8_t
util_clz16(uint16_t x)
{
	/*
	 * __builtin_clz operates on unsigned int, which is at least
	 * 16 bits wide. We cast uint16_t to unsigned int and subtract
	 * the difference in number of bits from the result
	 */
	return __builtin_clz((unsigned int)x) -
	       (sizeof(unsigned int) - sizeof(uint16_t)) * 8;
}
#else
uint8_t
util_clz16(uint16_t x)
{
	if (x == 0) {
		return 16;
	} else {
		uint8_t leading_zeros;

		for (leading_zeros = 0; x < UINT16_C(0x8000); leading_zeros++) {
			x <<= 1;
		}

		return leading_zeros;
	}
}
#endif

#if __has_builtin(__builtin_clzl)
uint8_t
util_clz32(uint32_t x)
{
	/*
	 * __builtin_clzl operates on unsigned long, which is at least
	 * 32 bits wide. We cast uint32_t to unsigned long and subtract
	 * the difference in number of bits from the result
	 */
	return __builtin_clzl((unsigned long)x) -
	       (sizeof(unsigned long) - sizeof(uint32_t)) * 8;
}
#else
uint8_t
util_clz32(uint32_t x)
{
	if (x == 0) {
		return 32;
	} else {
		uint8_t leading_zeros;

		for (leading_zeros = 0; x < UINT32_C(0x80000000);
		     leading_zeros++) {
			x <<= 1;
		}

		return leading_zeros;
	}
}
#endif

#if __has_builtin(__builtin_clzll)
uint8_t
util_clz64(uint64_t x)
{
	/*
	 * __builtin_clzll operates on unsigned long long, which is at
	 * least 64 bits wide. We cast uint64_t to unsigned long long and
	 * subtract the difference in number of bits from the result
	 */
	return __builtin_clzll((unsigned long long)x) -
	       (sizeof(unsigned long long) - sizeof(uint64_t)) * 8;
}
#else
uint8_t
util_clz64(uint64_t x)
{
	if (x == 0) {
		return 64;
	} else {
		uint8_t leading_zeros;

		for (leading_zeros = 0; x < UINT64_C(0x8000000000000000);
		     leading_zeros++) {
			x <<= 1;
		}

		return leading_zeros;
	}
}
#endif

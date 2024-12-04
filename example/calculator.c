/* See LICENSE file for copyright and license details. */
#include <inttypes.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../posit.h"

#include "util.h"

enum posit_type {
	POSIT_TYPE_POSIT8,
	POSIT_TYPE_POSIT16,
	POSIT_TYPE_POSIT32,
	POSIT_TYPE_POSIT64,
	POSIT_TYPE_POSIT_LOG8,
	POSIT_TYPE_POSIT_LOG16,
	POSIT_TYPE_POSIT_LOG32,
	POSIT_TYPE_POSIT_LOG64,
};

struct number {
	enum posit_type posit_type;
	posit8 posit8_value;
	posit16 posit16_value;
	posit32 posit32_value;
	posit64 posit64_value;
	posit_log8 posit_log8_value;
	posit_log16 posit_log16_value;
	posit_log32 posit_log32_value;
	posit_log64 posit_log64_value;
	int64_t integer_value;
};

static int
number_from_string(const char *token, enum posit_type posit_type,
                   struct number *number)
{
	long long raw_integer_value;
	long double raw_float_value, float_value;
	int64_t integer_value;
	char *integer_endptr, *float_endptr;

	/*
	 * First attempt to parse the string as an integer, specifying
	 * base 0 to support prefixes '0' and '0x' for octal and
	 * hexadecimal numbers respectively.
	 */
	raw_integer_value = strtoll(token, &integer_endptr, 0);
	raw_float_value = strtold(token, &float_endptr);

	if (*integer_endptr == '\0') {
		/*
		 * The number is integral, but we still have to check
		 * the bounds as long long can be larger than int64_t.
		 */
		if (raw_integer_value >= INT64_MAX ||
		    raw_integer_value < INT64_MIN) {
			/* Set the output to a non-integral NaR */
			float_value = NAN;
			integer_value = INT64_MAX;
		} else {
			float_value = (long double)raw_integer_value;
			integer_value = (int64_t)raw_integer_value;
		}
	} else if (*float_endptr == '\0') {
		if (raw_float_value == -1.0 || raw_float_value == 0.0 ||
		    raw_float_value == 1.0) {
			/* The number is integral -1, 0 or 1 */
			float_value = raw_float_value;
			integer_value = (int64_t)raw_float_value;
		} else {
			/*
			 * The number is not integral, but a decimal number.
			 * The cases infinity and NaN are just passed along.
			 */
			float_value = raw_float_value;
			integer_value = INT64_MAX;
		}
	} else {
		/* The number is neither integral nor decimal */
		fprintf(stderr, "invalid token '%s'\n", token);
		return 1;
	}

	/* Write the number's posit type into the number struct */
	number->posit_type = posit_type;

	/*
	 * Convert the float depending on the posit type, but also
	 * convert the posit value to the other types so we can always
	 * use them even if we mix types.
	 */
	switch (posit_type) {
	case POSIT_TYPE_POSIT8:
		number->posit8_value = posit8_from_extended_float(float_value);

		number->posit16_value =
			posit16_from_posit8(number->posit8_value);
		number->posit32_value =
			posit32_from_posit8(number->posit8_value);
		number->posit64_value =
			posit64_from_posit8(number->posit8_value);
		number->posit_log8_value =
			posit_log8_from_posit8(number->posit8_value);
		number->posit_log16_value =
			posit_log16_from_posit8(number->posit8_value);
		number->posit_log32_value =
			posit_log32_from_posit8(number->posit8_value);
		number->posit_log64_value =
			posit_log64_from_posit8(number->posit8_value);

		break;
	case POSIT_TYPE_POSIT16:
		number->posit16_value =
			posit16_from_extended_float(float_value);

		number->posit8_value =
			posit8_from_posit16(number->posit16_value);
		number->posit32_value =
			posit32_from_posit16(number->posit16_value);
		number->posit64_value =
			posit64_from_posit16(number->posit16_value);
		number->posit_log8_value =
			posit_log8_from_posit16(number->posit16_value);
		number->posit_log16_value =
			posit_log16_from_posit16(number->posit16_value);
		number->posit_log32_value =
			posit_log32_from_posit16(number->posit16_value);
		number->posit_log64_value =
			posit_log64_from_posit16(number->posit16_value);

		break;
	case POSIT_TYPE_POSIT32:
		number->posit32_value =
			posit32_from_extended_float(float_value);

		number->posit8_value =
			posit8_from_posit32(number->posit32_value);
		number->posit16_value =
			posit16_from_posit32(number->posit32_value);
		number->posit64_value =
			posit64_from_posit32(number->posit32_value);
		number->posit_log8_value =
			posit_log8_from_posit32(number->posit32_value);
		number->posit_log16_value =
			posit_log16_from_posit32(number->posit32_value);
		number->posit_log32_value =
			posit_log32_from_posit32(number->posit32_value);
		number->posit_log64_value =
			posit_log64_from_posit32(number->posit32_value);

		break;
	case POSIT_TYPE_POSIT64:
		number->posit64_value =
			posit64_from_extended_float(float_value);

		number->posit8_value =
			posit8_from_posit64(number->posit64_value);
		number->posit16_value =
			posit16_from_posit64(number->posit64_value);
		number->posit32_value =
			posit32_from_posit64(number->posit64_value);
		number->posit_log8_value =
			posit_log8_from_posit64(number->posit64_value);
		number->posit_log16_value =
			posit_log16_from_posit64(number->posit64_value);
		number->posit_log32_value =
			posit_log32_from_posit64(number->posit64_value);
		number->posit_log64_value =
			posit_log64_from_posit64(number->posit64_value);

		break;
	case POSIT_TYPE_POSIT_LOG8:
		number->posit_log8_value =
			posit_log8_from_extended_float(float_value);

		number->posit8_value =
			posit8_from_posit_log8(number->posit_log8_value);
		number->posit16_value =
			posit16_from_posit_log8(number->posit_log8_value);
		number->posit32_value =
			posit32_from_posit_log8(number->posit_log8_value);
		number->posit64_value =
			posit64_from_posit_log8(number->posit_log8_value);
		number->posit_log16_value =
			posit_log16_from_posit_log8(number->posit_log8_value);
		number->posit_log32_value =
			posit_log32_from_posit_log8(number->posit_log8_value);
		number->posit_log64_value =
			posit_log64_from_posit_log8(number->posit_log8_value);

		break;
	case POSIT_TYPE_POSIT_LOG16:
		number->posit_log16_value =
			posit_log16_from_extended_float(float_value);

		number->posit8_value =
			posit8_from_posit_log16(number->posit_log16_value);
		number->posit16_value =
			posit16_from_posit_log16(number->posit_log16_value);
		number->posit32_value =
			posit32_from_posit_log16(number->posit_log16_value);
		number->posit64_value =
			posit64_from_posit_log16(number->posit_log16_value);
		number->posit_log8_value =
			posit_log8_from_posit_log16(number->posit_log16_value);
		number->posit_log32_value =
			posit_log32_from_posit_log16(number->posit_log16_value);
		number->posit_log64_value =
			posit_log64_from_posit_log16(number->posit_log16_value);

		break;
	case POSIT_TYPE_POSIT_LOG32:
		number->posit_log32_value =
			posit_log32_from_extended_float(float_value);

		number->posit8_value =
			posit8_from_posit_log32(number->posit_log32_value);
		number->posit16_value =
			posit16_from_posit_log32(number->posit_log32_value);
		number->posit32_value =
			posit32_from_posit_log32(number->posit_log32_value);
		number->posit64_value =
			posit64_from_posit_log32(number->posit_log32_value);
		number->posit_log8_value =
			posit_log8_from_posit_log32(number->posit_log32_value);
		number->posit_log16_value =
			posit_log16_from_posit_log32(number->posit_log32_value);
		number->posit_log64_value =
			posit_log64_from_posit_log32(number->posit_log32_value);

		break;
	case POSIT_TYPE_POSIT_LOG64:
		number->posit_log64_value =
			posit_log64_from_extended_float(float_value);

		number->posit8_value =
			posit8_from_posit_log64(number->posit_log64_value);
		number->posit16_value =
			posit16_from_posit_log64(number->posit_log64_value);
		number->posit32_value =
			posit32_from_posit_log64(number->posit_log64_value);
		number->posit64_value =
			posit64_from_posit_log64(number->posit_log64_value);
		number->posit_log8_value =
			posit_log8_from_posit_log64(number->posit_log64_value);
		number->posit_log16_value =
			posit_log16_from_posit_log64(number->posit_log64_value);
		number->posit_log32_value =
			posit_log32_from_posit_log64(number->posit_log64_value);

		break;
	}

	number->integer_value = integer_value;

	return 0;
}

static void
number_from_posit8(posit8 t, struct number *number)
{
	number->posit_type = POSIT_TYPE_POSIT8;
	number->posit8_value = t;

	if (t == 0) {
		number->integer_value = 0;
	} else if (t == POSIT8_ONE) {
		number->integer_value = 1;
	} else if (t == -POSIT8_ONE) {
		number->integer_value = -1;
	} else {
		number->integer_value = INT64_MAX;
	}

	/* fill up the other types */
	number->posit16_value = posit16_from_posit8(number->posit8_value);
	number->posit32_value = posit32_from_posit8(number->posit8_value);
	number->posit64_value = posit64_from_posit8(number->posit8_value);
	number->posit_log8_value = posit_log8_from_posit8(number->posit8_value);
	number->posit_log16_value =
		posit_log16_from_posit8(number->posit8_value);
	number->posit_log32_value =
		posit_log32_from_posit8(number->posit8_value);
	number->posit_log64_value =
		posit_log64_from_posit8(number->posit8_value);
}

static void
number_from_posit16(posit16 t, struct number *number)
{
	number->posit_type = POSIT_TYPE_POSIT16;
	number->posit16_value = t;

	if (t == 0) {
		number->integer_value = 0;
	} else if (t == POSIT16_ONE) {
		number->integer_value = 1;
	} else if (t == -POSIT16_ONE) {
		number->integer_value = -1;
	} else {
		number->integer_value = INT64_MAX;
	}

	/* fill up the other types */
	number->posit8_value = posit8_from_posit16(number->posit16_value);
	number->posit32_value = posit32_from_posit16(number->posit16_value);
	number->posit64_value = posit64_from_posit16(number->posit16_value);
	number->posit_log8_value =
		posit_log8_from_posit16(number->posit16_value);
	number->posit_log16_value =
		posit_log16_from_posit16(number->posit16_value);
	number->posit_log32_value =
		posit_log32_from_posit16(number->posit16_value);
	number->posit_log64_value =
		posit_log64_from_posit16(number->posit16_value);
}

static void
number_from_posit32(posit32 t, struct number *number)
{
	number->posit_type = POSIT_TYPE_POSIT32;
	number->posit32_value = t;

	if (t == 0) {
		number->integer_value = 0;
	} else if (t == POSIT32_ONE) {
		number->integer_value = 1;
	} else if (t == -POSIT32_ONE) {
		number->integer_value = -1;
	} else {
		number->integer_value = INT64_MAX;
	}

	/* fill up the other types */
	number->posit8_value = posit8_from_posit32(number->posit32_value);
	number->posit16_value = posit16_from_posit32(number->posit32_value);
	number->posit64_value = posit64_from_posit32(number->posit32_value);
	number->posit_log8_value =
		posit_log8_from_posit32(number->posit32_value);
	number->posit_log16_value =
		posit_log16_from_posit32(number->posit32_value);
	number->posit_log32_value =
		posit_log32_from_posit32(number->posit32_value);
	number->posit_log64_value =
		posit_log64_from_posit32(number->posit32_value);
}

static void
number_from_posit64(posit64 t, struct number *number)
{
	number->posit_type = POSIT_TYPE_POSIT64;
	number->posit64_value = t;

	if (t == 0) {
		number->integer_value = 0;
	} else if (t == POSIT64_ONE) {
		number->integer_value = 1;
	} else if (t == -POSIT64_ONE) {
		number->integer_value = -1;
	} else {
		number->integer_value = INT64_MAX;
	}

	/* fill up the other types */
	number->posit8_value = posit8_from_posit64(number->posit64_value);
	number->posit16_value = posit16_from_posit64(number->posit64_value);
	number->posit32_value = posit32_from_posit64(number->posit64_value);
	number->posit_log8_value =
		posit_log8_from_posit64(number->posit64_value);
	number->posit_log16_value =
		posit_log16_from_posit64(number->posit64_value);
	number->posit_log32_value =
		posit_log32_from_posit64(number->posit64_value);
	number->posit_log64_value =
		posit_log64_from_posit64(number->posit64_value);
}

static void
number_from_posit_log8(posit_log8 t, struct number *number)
{
	double float_value;

	number->posit_type = POSIT_TYPE_POSIT_LOG8;
	number->posit_log8_value = t;

	float_value = posit_log8_to_float64(t);
	if (float_value == (int64_t)float_value) {
		number->integer_value = (int64_t)float_value;
	} else {
		number->integer_value = INT64_MAX;
	}

	/* fill up the other types */
	number->posit8_value = posit8_from_posit_log8(number->posit_log8_value);
	number->posit16_value =
		posit16_from_posit_log8(number->posit_log8_value);
	number->posit32_value =
		posit32_from_posit_log8(number->posit_log8_value);
	number->posit64_value =
		posit64_from_posit_log8(number->posit_log8_value);
	number->posit_log16_value =
		posit_log16_from_posit_log8(number->posit_log8_value);
	number->posit_log32_value =
		posit_log32_from_posit_log8(number->posit_log8_value);
	number->posit_log64_value =
		posit_log64_from_posit_log8(number->posit_log8_value);
}

static void
number_from_posit_log16(posit_log16 t, struct number *number)
{
	double float_value;

	number->posit_type = POSIT_TYPE_POSIT_LOG16;
	number->posit_log16_value = t;

	float_value = posit_log16_to_float64(t);
	if (float_value == (int64_t)float_value) {
		number->integer_value = (int64_t)float_value;
	} else {
		number->integer_value = INT64_MAX;
	}

	/* fill up the other types */
	number->posit8_value =
		posit8_from_posit_log16(number->posit_log16_value);
	number->posit16_value =
		posit16_from_posit_log16(number->posit_log16_value);
	number->posit32_value =
		posit32_from_posit_log16(number->posit_log16_value);
	number->posit64_value =
		posit64_from_posit_log16(number->posit_log16_value);
	number->posit_log8_value =
		posit_log8_from_posit_log16(number->posit_log16_value);
	number->posit_log32_value =
		posit_log32_from_posit_log16(number->posit_log16_value);
	number->posit_log64_value =
		posit_log64_from_posit_log16(number->posit_log16_value);
}

static void
number_from_posit_log32(posit_log32 t, struct number *number)
{
	double float_value;

	number->posit_type = POSIT_TYPE_POSIT_LOG32;
	number->posit_log32_value = t;

	float_value = posit_log32_to_float64(t);
	if (float_value == (int64_t)float_value) {
		number->integer_value = (int64_t)float_value;
	} else {
		number->integer_value = INT64_MAX;
	}

	/* fill up the other types */
	number->posit8_value =
		posit8_from_posit_log32(number->posit_log32_value);
	number->posit16_value =
		posit16_from_posit_log32(number->posit_log32_value);
	number->posit32_value =
		posit32_from_posit_log32(number->posit_log32_value);
	number->posit64_value =
		posit64_from_posit_log32(number->posit_log32_value);
	number->posit_log8_value =
		posit_log8_from_posit_log32(number->posit_log32_value);
	number->posit_log16_value =
		posit_log16_from_posit_log32(number->posit_log32_value);
	number->posit_log64_value =
		posit_log64_from_posit_log32(number->posit_log32_value);
}

static void
number_from_posit_log64(posit_log64 t, struct number *number)
{
	long double float_value;

	number->posit_type = POSIT_TYPE_POSIT_LOG64;
	number->posit_log64_value = t;

	float_value = posit_log64_to_extended_float(t);
	if (float_value == (int64_t)float_value) {
		number->integer_value = (int64_t)float_value;
	} else {
		number->integer_value = INT64_MAX;
	}

	/* fill up the other types */
	number->posit8_value =
		posit8_from_posit_log64(number->posit_log64_value);
	number->posit16_value =
		posit16_from_posit_log64(number->posit_log64_value);
	number->posit32_value =
		posit32_from_posit_log64(number->posit_log64_value);
	number->posit64_value =
		posit64_from_posit_log64(number->posit_log64_value);
	number->posit_log8_value =
		posit_log8_from_posit_log64(number->posit_log64_value);
	number->posit_log16_value =
		posit_log16_from_posit_log64(number->posit_log64_value);
	number->posit_log32_value =
		posit_log32_from_posit_log64(number->posit_log64_value);
}

static void
number_print(const struct number *number)
{
	if (number->integer_value != INT64_MAX) {
		/* the number is integral */
		printf("%" PRIi64 "\n", number->integer_value);
	} else {
		long double float_value = 0.0;

		switch (number->posit_type) {
		case POSIT_TYPE_POSIT8:
			float_value =
				posit8_to_extended_float(number->posit8_value);
			break;
		case POSIT_TYPE_POSIT16:
			float_value = posit16_to_extended_float(
				number->posit16_value);
			break;
		case POSIT_TYPE_POSIT32:
			float_value = posit32_to_extended_float(
				number->posit32_value);
			break;
		case POSIT_TYPE_POSIT64:
			float_value = posit64_to_extended_float(
				number->posit64_value);
			break;
		case POSIT_TYPE_POSIT_LOG8:
			float_value = posit_log8_to_extended_float(
				number->posit_log8_value);
			break;
		case POSIT_TYPE_POSIT_LOG16:
			float_value = posit_log16_to_extended_float(
				number->posit_log16_value);
			break;
		case POSIT_TYPE_POSIT_LOG32:
			float_value = posit_log32_to_extended_float(
				number->posit_log32_value);
			break;
		case POSIT_TYPE_POSIT_LOG64:
			float_value = posit_log64_to_extended_float(
				number->posit_log64_value);
			break;
		}

		if (isnan(float_value)) {
			printf("NaR\n");
		} else {
			printf("%Lg\n", float_value);
		}
	}
}

struct stack {
	struct number *data;
	size_t size;
	size_t capacity;
};

static void
stack_init(struct stack *stack)
{
	stack->data = NULL;
	stack->size = 0;
	stack->capacity = 0;
}

static void
stack_free(struct stack *stack)
{
	free(stack->data);
	stack->data = NULL;
	stack->size = 0;
	stack->capacity = 0;
}

static int
stack_push(struct stack *stack, const struct number *number)
{
	if (stack->size == stack->capacity) {
		/* expand stack */
		stack->capacity += 1;
		if ((stack->data = realloc(stack->data,
		                           stack->capacity *
		                                   sizeof(*(stack->data)))) ==
		    NULL) {
			fprintf(stderr, "could not expand stack due to memory "
			                "exhaustion\n");
			return 1;
		}
	}

	memcpy(&(stack->data[stack->size++]), number, sizeof(*number));

	return 0;
}

static int
stack_pop(struct stack *stack, struct number **number)
{
	if (stack->size == 0) {
		fprintf(stderr, "stack underflow\n");
		return 1;
	} else {
		*number = &(stack->data[--(stack->size)]);
		return 0;
	}
}

enum operator_type {
	OPERATOR_TYPE_HELP,
	OPERATOR_TYPE_POWER,
	OPERATOR_TYPE_PRECISION,
	OPERATOR_TYPE_SWITCH_POSIT_TYPE,
	OPERATOR_TYPE_POSIT_INT64_POSIT,
	OPERATOR_TYPE_POSIT_POSIT,
	OPERATOR_TYPE_POSIT_POSIT_POSIT,
};

static const struct {
	const char *identifier;
	enum operator_type type;

	union {
		struct {
			enum posit_type type;
		} switch_posit_type;

		struct {
			posit8 (*posit8_function)(posit8, int64_t);
			posit16 (*posit16_function)(posit16, int64_t);
			posit32 (*posit32_function)(posit32, int64_t);
			posit64 (*posit64_function)(posit64, int64_t);
			posit_log8 (*posit_log8_function)(posit_log8, int64_t);
			posit_log16 (*posit_log16_function)(posit_log16,
			                                    int64_t);
			posit_log32 (*posit_log32_function)(posit_log32,
			                                    int64_t);
			posit_log64 (*posit_log64_function)(posit_log64,
			                                    int64_t);
		} posit_int64_posit;

		struct {
			posit8 (*posit8_function)(posit8);
			posit16 (*posit16_function)(posit16);
			posit32 (*posit32_function)(posit32);
			posit64 (*posit64_function)(posit64);
			posit_log8 (*posit_log8_function)(posit_log8);
			posit_log16 (*posit_log16_function)(posit_log16);
			posit_log32 (*posit_log32_function)(posit_log32);
			posit_log64 (*posit_log64_function)(posit_log64);
		} posit_posit;

		struct {
			posit8 (*posit8_function)(posit8, posit8);
			posit16 (*posit16_function)(posit16, posit16);
			posit32 (*posit32_function)(posit32, posit32);
			posit64 (*posit64_function)(posit64, posit64);
			posit_log8 (*posit_log8_function)(posit_log8,
			                                  posit_log8);
			posit_log16 (*posit_log16_function)(posit_log16,
			                                    posit_log16);
			posit_log32 (*posit_log32_function)(posit_log32,
			                                    posit_log32);
			posit_log64 (*posit_log64_function)(posit_log64,
			                                    posit_log64);
		} posit_posit_posit;
	} implementation;
} operators[] = {
	{
		.identifier = "?",
		.type = OPERATOR_TYPE_HELP,
	},
	{
		.identifier = "+",
		.type = OPERATOR_TYPE_POSIT_POSIT_POSIT,
		.implementation.posit_posit_posit = {
			.posit8_function = posit8_addition,
			.posit16_function = posit16_addition,
			.posit32_function = posit32_addition,
			.posit64_function = posit64_addition,
			.posit_log8_function = posit_log8_addition,
			.posit_log16_function = posit_log16_addition,
			.posit_log32_function = posit_log32_addition,
			.posit_log64_function = posit_log64_addition,
		},
	},
	{
		.identifier = "-",
		.type = OPERATOR_TYPE_POSIT_POSIT_POSIT,
		.implementation.posit_posit_posit = {
			.posit8_function = posit8_subtraction,
			.posit16_function = posit16_subtraction,
			.posit32_function = posit32_subtraction,
			.posit64_function = posit64_subtraction,
			.posit_log8_function = posit_log8_subtraction,
			.posit_log16_function = posit_log16_subtraction,
			.posit_log32_function = posit_log32_subtraction,
			.posit_log64_function = posit_log64_subtraction,
		},
	},
	{
		.identifier = "*",
		.type = OPERATOR_TYPE_POSIT_POSIT_POSIT,
		.implementation.posit_posit_posit = {
			.posit8_function = posit8_multiplication,
			.posit16_function = posit16_multiplication,
			.posit32_function = posit32_multiplication,
			.posit64_function = posit64_multiplication,
			.posit_log8_function = posit_log8_multiplication,
			.posit_log16_function = posit_log16_multiplication,
			.posit_log32_function = posit_log32_multiplication,
			.posit_log64_function = posit_log64_multiplication,
		},
	},
	{
		.identifier = "/",
		.type = OPERATOR_TYPE_POSIT_POSIT_POSIT,
		.implementation.posit_posit_posit = {
			.posit8_function = posit8_division,
			.posit16_function = posit16_division,
			.posit32_function = posit32_division,
			.posit64_function = posit64_division,
			.posit_log8_function = posit_log8_division,
			.posit_log16_function = posit_log16_division,
			.posit_log32_function = posit_log32_division,
			.posit_log64_function = posit_log64_division,
		},
	},
	{
		.identifier = "^",
		.type = OPERATOR_TYPE_POWER,
	},
	{
		.identifier = "abs",
		.type = OPERATOR_TYPE_POSIT_POSIT,
		.implementation.posit_posit = {
			.posit8_function = posit8_absolute,
			.posit16_function = posit16_absolute,
			.posit32_function = posit32_absolute,
			.posit64_function = posit64_absolute,
			.posit_log8_function = posit_log8_absolute,
			.posit_log16_function = posit_log16_absolute,
			.posit_log32_function = posit_log32_absolute,
			.posit_log64_function = posit_log64_absolute,
		},
	},
	{
		.identifier = "arccos",
		.type = OPERATOR_TYPE_POSIT_POSIT,
		.implementation.posit_posit = {
			.posit8_function = posit8_arccos,
			.posit16_function = posit16_arccos,
			.posit32_function = posit32_arccos,
			.posit64_function = posit64_arccos,
			.posit_log8_function = posit_log8_arccos,
			.posit_log16_function = posit_log16_arccos,
			.posit_log32_function = posit_log32_arccos,
			.posit_log64_function = posit_log64_arccos,
		},
	},
	{
		.identifier = "arccos_over_pi",
		.type = OPERATOR_TYPE_POSIT_POSIT,
		.implementation.posit_posit = {
			.posit8_function = posit8_arccos_over_pi,
			.posit16_function = posit16_arccos_over_pi,
			.posit32_function = posit32_arccos_over_pi,
			.posit64_function = posit64_arccos_over_pi,
			.posit_log8_function = posit_log8_arccos_over_pi,
			.posit_log16_function = posit_log16_arccos_over_pi,
			.posit_log32_function = posit_log32_arccos_over_pi,
			.posit_log64_function = posit_log64_arccos_over_pi,
		},
	},
	{
		.identifier = "arccot",
		.type = OPERATOR_TYPE_POSIT_POSIT,
		.implementation.posit_posit = {
			.posit8_function = posit8_arccot,
			.posit16_function = posit16_arccot,
			.posit32_function = posit32_arccot,
			.posit64_function = posit64_arccot,
			.posit_log8_function = posit_log8_arccot,
			.posit_log16_function = posit_log16_arccot,
			.posit_log32_function = posit_log32_arccot,
			.posit_log64_function = posit_log64_arccot,
		},
	},
	{
		.identifier = "arccot_over_pi",
		.type = OPERATOR_TYPE_POSIT_POSIT,
		.implementation.posit_posit = {
			.posit8_function = posit8_arccot_over_pi,
			.posit16_function = posit16_arccot_over_pi,
			.posit32_function = posit32_arccot_over_pi,
			.posit64_function = posit64_arccot_over_pi,
			.posit_log8_function = posit_log8_arccot_over_pi,
			.posit_log16_function = posit_log16_arccot_over_pi,
			.posit_log32_function = posit_log32_arccot_over_pi,
			.posit_log64_function = posit_log64_arccot_over_pi,
		},
	},
	{
		.identifier = "arccsc",
		.type = OPERATOR_TYPE_POSIT_POSIT,
		.implementation.posit_posit = {
			.posit8_function = posit8_arccsc,
			.posit16_function = posit16_arccsc,
			.posit32_function = posit32_arccsc,
			.posit64_function = posit64_arccsc,
			.posit_log8_function = posit_log8_arccsc,
			.posit_log16_function = posit_log16_arccsc,
			.posit_log32_function = posit_log32_arccsc,
			.posit_log64_function = posit_log64_arccsc,
		},
	},
	{
		.identifier = "arccsc_over_pi",
		.type = OPERATOR_TYPE_POSIT_POSIT,
		.implementation.posit_posit = {
			.posit8_function = posit8_arccsc_over_pi,
			.posit16_function = posit16_arccsc_over_pi,
			.posit32_function = posit32_arccsc_over_pi,
			.posit64_function = posit64_arccsc_over_pi,
			.posit_log8_function = posit_log8_arccsc_over_pi,
			.posit_log16_function = posit_log16_arccsc_over_pi,
			.posit_log32_function = posit_log32_arccsc_over_pi,
			.posit_log64_function = posit_log64_arccsc_over_pi,
		},
	},
	{
		.identifier = "arcosh",
		.type = OPERATOR_TYPE_POSIT_POSIT,
		.implementation.posit_posit = {
			.posit8_function = posit8_arcosh,
			.posit16_function = posit16_arcosh,
			.posit32_function = posit32_arcosh,
			.posit64_function = posit64_arcosh,
			.posit_log8_function = posit_log8_arcosh,
			.posit_log16_function = posit_log16_arcosh,
			.posit_log32_function = posit_log32_arcosh,
			.posit_log64_function = posit_log64_arcosh,
		},
	},
	{
		.identifier = "arcoth",
		.type = OPERATOR_TYPE_POSIT_POSIT,
		.implementation.posit_posit = {
			.posit8_function = posit8_arcoth,
			.posit16_function = posit16_arcoth,
			.posit32_function = posit32_arcoth,
			.posit64_function = posit64_arcoth,
			.posit_log8_function = posit_log8_arcoth,
			.posit_log16_function = posit_log16_arcoth,
			.posit_log32_function = posit_log32_arcoth,
			.posit_log64_function = posit_log64_arcoth,
		},
	},
	{
		.identifier = "arcsch",
		.type = OPERATOR_TYPE_POSIT_POSIT,
		.implementation.posit_posit = {
			.posit8_function = posit8_arcsch,
			.posit16_function = posit16_arcsch,
			.posit32_function = posit32_arcsch,
			.posit64_function = posit64_arcsch,
			.posit_log8_function = posit_log8_arcsch,
			.posit_log16_function = posit_log16_arcsch,
			.posit_log32_function = posit_log32_arcsch,
			.posit_log64_function = posit_log64_arcsch,
		},
	},
	{
		.identifier = "arcsec",
		.type = OPERATOR_TYPE_POSIT_POSIT,
		.implementation.posit_posit = {
			.posit8_function = posit8_arcsec,
			.posit16_function = posit16_arcsec,
			.posit32_function = posit32_arcsec,
			.posit64_function = posit64_arcsec,
			.posit_log8_function = posit_log8_arcsec,
			.posit_log16_function = posit_log16_arcsec,
			.posit_log32_function = posit_log32_arcsec,
			.posit_log64_function = posit_log64_arcsec,
		},
	},
	{
		.identifier = "arcsec_over_pi",
		.type = OPERATOR_TYPE_POSIT_POSIT,
		.implementation.posit_posit = {
			.posit8_function = posit8_arcsec_over_pi,
			.posit16_function = posit16_arcsec_over_pi,
			.posit32_function = posit32_arcsec_over_pi,
			.posit64_function = posit64_arcsec_over_pi,
			.posit_log8_function = posit_log8_arcsec_over_pi,
			.posit_log16_function = posit_log16_arcsec_over_pi,
			.posit_log32_function = posit_log32_arcsec_over_pi,
			.posit_log64_function = posit_log64_arcsec_over_pi,
		},
	},
	{
		.identifier = "arcsin",
		.type = OPERATOR_TYPE_POSIT_POSIT,
		.implementation.posit_posit = {
			.posit8_function = posit8_arcsin,
			.posit16_function = posit16_arcsin,
			.posit32_function = posit32_arcsin,
			.posit64_function = posit64_arcsin,
			.posit_log8_function = posit_log8_arcsin,
			.posit_log16_function = posit_log16_arcsin,
			.posit_log32_function = posit_log32_arcsin,
			.posit_log64_function = posit_log64_arcsin,
		},
	},
	{
		.identifier = "arcsin_over_pi",
		.type = OPERATOR_TYPE_POSIT_POSIT,
		.implementation.posit_posit = {
			.posit8_function = posit8_arcsin_over_pi,
			.posit16_function = posit16_arcsin_over_pi,
			.posit32_function = posit32_arcsin_over_pi,
			.posit64_function = posit64_arcsin_over_pi,
			.posit_log8_function = posit_log8_arcsin_over_pi,
			.posit_log16_function = posit_log16_arcsin_over_pi,
			.posit_log32_function = posit_log32_arcsin_over_pi,
			.posit_log64_function = posit_log64_arcsin_over_pi,
		},
	},
	{
		.identifier = "arctan2",
		.type = OPERATOR_TYPE_POSIT_POSIT_POSIT,
		.implementation.posit_posit_posit = {
			.posit8_function = posit8_arctan2,
			.posit16_function = posit16_arctan2,
			.posit32_function = posit32_arctan2,
			.posit64_function = posit64_arctan2,
			.posit_log8_function = posit_log8_arctan2,
			.posit_log16_function = posit_log16_arctan2,
			.posit_log32_function = posit_log32_arctan2,
			.posit_log64_function = posit_log64_arctan2,
		}
	},
	{
		.identifier = "arctan2_over_pi",
		.type = OPERATOR_TYPE_POSIT_POSIT_POSIT,
		.implementation.posit_posit_posit = {
			.posit8_function = posit8_arctan2_over_pi,
			.posit16_function = posit16_arctan2_over_pi,
			.posit32_function = posit32_arctan2_over_pi,
			.posit64_function = posit64_arctan2_over_pi,
			.posit_log8_function = posit_log8_arctan2_over_pi,
			.posit_log16_function = posit_log16_arctan2_over_pi,
			.posit_log32_function = posit_log32_arctan2_over_pi,
			.posit_log64_function = posit_log64_arctan2_over_pi,
		},
	},
	{
		.identifier = "arctan",
		.type = OPERATOR_TYPE_POSIT_POSIT,
		.implementation.posit_posit = {
			.posit8_function = posit8_arctan,
			.posit16_function = posit16_arctan,
			.posit32_function = posit32_arctan,
			.posit64_function = posit64_arctan,
			.posit_log8_function = posit_log8_arctan,
			.posit_log16_function = posit_log16_arctan,
			.posit_log32_function = posit_log32_arctan,
			.posit_log64_function = posit_log64_arctan,
		},
	},
	{
		.identifier = "arctan_over_pi",
		.type = OPERATOR_TYPE_POSIT_POSIT,
		.implementation.posit_posit = {
			.posit8_function = posit8_arctan_over_pi,
			.posit16_function = posit16_arctan_over_pi,
			.posit32_function = posit32_arctan_over_pi,
			.posit64_function = posit64_arctan_over_pi,
			.posit_log8_function = posit_log8_arctan_over_pi,
			.posit_log16_function = posit_log16_arctan_over_pi,
			.posit_log32_function = posit_log32_arctan_over_pi,
			.posit_log64_function = posit_log64_arctan_over_pi,
		},
	},
	{
		.identifier = "arsech",
		.type = OPERATOR_TYPE_POSIT_POSIT,
		.implementation.posit_posit = {
			.posit8_function = posit8_arsech,
			.posit16_function = posit16_arsech,
			.posit32_function = posit32_arsech,
			.posit64_function = posit64_arsech,
			.posit_log8_function = posit_log8_arsech,
			.posit_log16_function = posit_log16_arsech,
			.posit_log32_function = posit_log32_arsech,
			.posit_log64_function = posit_log64_arsech,
		},
	},
	{
		.identifier = "arsinh",
		.type = OPERATOR_TYPE_POSIT_POSIT,
		.implementation.posit_posit = {
			.posit8_function = posit8_arsinh,
			.posit16_function = posit16_arsinh,
			.posit32_function = posit32_arsinh,
			.posit64_function = posit64_arsinh,
			.posit_log8_function = posit_log8_arsinh,
			.posit_log16_function = posit_log16_arsinh,
			.posit_log32_function = posit_log32_arsinh,
			.posit_log64_function = posit_log64_arsinh,
		},
	},
	{
		.identifier = "artanh",
		.type = OPERATOR_TYPE_POSIT_POSIT,
		.implementation.posit_posit = {
			.posit8_function = posit8_artanh,
			.posit16_function = posit16_artanh,
			.posit32_function = posit32_artanh,
			.posit64_function = posit64_artanh,
			.posit_log8_function = posit_log8_artanh,
			.posit_log16_function = posit_log16_artanh,
			.posit_log32_function = posit_log32_artanh,
			.posit_log64_function = posit_log64_artanh,
		},
	},
	{
		.identifier = "cos",
		.type = OPERATOR_TYPE_POSIT_POSIT,
		.implementation.posit_posit = {
			.posit8_function = posit8_cos,
			.posit16_function = posit16_cos,
			.posit32_function = posit32_cos,
			.posit64_function = posit64_cos,
			.posit_log8_function = posit_log8_cos,
			.posit_log16_function = posit_log16_cos,
			.posit_log32_function = posit_log32_cos,
			.posit_log64_function = posit_log64_cos,
		},
	},
	{
		.identifier = "cos_pi_times",
		.type = OPERATOR_TYPE_POSIT_POSIT,
		.implementation.posit_posit = {
			.posit8_function = posit8_cos_pi_times,
			.posit16_function = posit16_cos_pi_times,
			.posit32_function = posit32_cos_pi_times,
			.posit64_function = posit64_cos_pi_times,
			.posit_log8_function = posit_log8_cos_pi_times,
			.posit_log16_function = posit_log16_cos_pi_times,
			.posit_log32_function = posit_log32_cos_pi_times,
			.posit_log64_function = posit_log64_cos_pi_times,
		},
	},
	{
		.identifier = "cosh",
		.type = OPERATOR_TYPE_POSIT_POSIT,
		.implementation.posit_posit = {
			.posit8_function = posit8_cosh,
			.posit16_function = posit16_cosh,
			.posit32_function = posit32_cosh,
			.posit64_function = posit64_cosh,
			.posit_log8_function = posit_log8_cosh,
			.posit_log16_function = posit_log16_cosh,
			.posit_log32_function = posit_log32_cosh,
			.posit_log64_function = posit_log64_cosh,
		},
	},
	{
		.identifier = "cot",
		.type = OPERATOR_TYPE_POSIT_POSIT,
		.implementation.posit_posit = {
			.posit8_function = posit8_cot,
			.posit16_function = posit16_cot,
			.posit32_function = posit32_cot,
			.posit64_function = posit64_cot,
			.posit_log8_function = posit_log8_cot,
			.posit_log16_function = posit_log16_cot,
			.posit_log32_function = posit_log32_cot,
			.posit_log64_function = posit_log64_cot,
		},
	},
	{
		.identifier = "cot_pi_times",
		.type = OPERATOR_TYPE_POSIT_POSIT,
		.implementation.posit_posit = {
			.posit8_function = posit8_cot_pi_times,
			.posit16_function = posit16_cot_pi_times,
			.posit32_function = posit32_cot_pi_times,
			.posit64_function = posit64_cot_pi_times,
			.posit_log8_function = posit_log8_cot_pi_times,
			.posit_log16_function = posit_log16_cot_pi_times,
			.posit_log32_function = posit_log32_cot_pi_times,
			.posit_log64_function = posit_log64_cot_pi_times,
		},
	},
	{
		.identifier = "coth",
		.type = OPERATOR_TYPE_POSIT_POSIT,
		.implementation.posit_posit = {
			.posit8_function = posit8_coth,
			.posit16_function = posit16_coth,
			.posit32_function = posit32_coth,
			.posit64_function = posit64_coth,
			.posit_log8_function = posit_log8_coth,
			.posit_log16_function = posit_log16_coth,
			.posit_log32_function = posit_log32_coth,
			.posit_log64_function = posit_log64_coth,
		},
	},
	{
		.identifier = "csc",
		.type = OPERATOR_TYPE_POSIT_POSIT,
		.implementation.posit_posit = {
			.posit8_function = posit8_csc,
			.posit16_function = posit16_csc,
			.posit32_function = posit32_csc,
			.posit64_function = posit64_csc,
			.posit_log8_function = posit_log8_csc,
			.posit_log16_function = posit_log16_csc,
			.posit_log32_function = posit_log32_csc,
			.posit_log64_function = posit_log64_csc,
		},
	},
	{
		.identifier = "csc_pi_times",
		.type = OPERATOR_TYPE_POSIT_POSIT,
		.implementation.posit_posit = {
			.posit8_function = posit8_csc_pi_times,
			.posit16_function = posit16_csc_pi_times,
			.posit32_function = posit32_csc_pi_times,
			.posit64_function = posit64_csc_pi_times,
			.posit_log8_function = posit_log8_csc_pi_times,
			.posit_log16_function = posit_log16_csc_pi_times,
			.posit_log32_function = posit_log32_csc_pi_times,
			.posit_log64_function = posit_log64_csc_pi_times,
		},
	},
	{
		.identifier = "csch",
		.type = OPERATOR_TYPE_POSIT_POSIT,
		.implementation.posit_posit = {
			.posit8_function = posit8_csch,
			.posit16_function = posit16_csch,
			.posit32_function = posit32_csch,
			.posit64_function = posit64_csch,
			.posit_log8_function = posit_log8_csch,
			.posit_log16_function = posit_log16_csch,
			.posit_log32_function = posit_log32_csch,
			.posit_log64_function = posit_log64_csch,
		},
	},
	{
		.identifier = "exp",
		.type = OPERATOR_TYPE_POSIT_POSIT,
		.implementation.posit_posit = {
			.posit8_function = posit8_exp,
			.posit16_function = posit16_exp,
			.posit32_function = posit32_exp,
			.posit64_function = posit64_exp,
			.posit_log8_function = posit_log8_exp,
			.posit_log16_function = posit_log16_exp,
			.posit_log32_function = posit_log32_exp,
			.posit_log64_function = posit_log64_exp,
		},
	},
	{
		.identifier = "exp_minus_1",
		.type = OPERATOR_TYPE_POSIT_POSIT,
		.implementation.posit_posit = {
			.posit8_function = posit8_exp_minus_1,
			.posit16_function = posit16_exp_minus_1,
			.posit32_function = posit32_exp_minus_1,
			.posit64_function = posit64_exp_minus_1,
			.posit_log8_function = posit_log8_exp_minus_1,
			.posit_log16_function = posit_log16_exp_minus_1,
			.posit_log32_function = posit_log32_exp_minus_1,
			.posit_log64_function = posit_log64_exp_minus_1,
		},
	},
	{
		.identifier = "hypotenuse",
		.type = OPERATOR_TYPE_POSIT_POSIT_POSIT,
		.implementation.posit_posit_posit = {
			.posit8_function = posit8_hypotenuse,
			.posit16_function = posit16_hypotenuse,
			.posit32_function = posit32_hypotenuse,
			.posit64_function = posit64_hypotenuse,
			.posit_log8_function = posit_log8_hypotenuse,
			.posit_log16_function = posit_log16_hypotenuse,
			.posit_log32_function = posit_log32_hypotenuse,
			.posit_log64_function = posit_log64_hypotenuse,
		},
	},
	{
		.identifier = "root",
		.type = OPERATOR_TYPE_POSIT_INT64_POSIT,
		.implementation.posit_int64_posit = {
			.posit8_function = posit8_root,
			.posit16_function = posit16_root,
			.posit32_function = posit32_root,
			.posit64_function = posit64_root,
			.posit_log8_function = posit_log8_root,
			.posit_log16_function = posit_log16_root,
			.posit_log32_function = posit_log32_root,
			.posit_log64_function = posit_log64_root,
		},
	},
	{
		.identifier = "inv",
		.type = OPERATOR_TYPE_POSIT_POSIT,
		.implementation.posit_posit = {
			.posit8_function = posit8_inversion,
			.posit16_function = posit16_inversion,
			.posit32_function = posit32_inversion,
			.posit64_function = posit64_inversion,
			.posit_log8_function = posit_log8_inversion,
			.posit_log16_function = posit_log16_inversion,
			.posit_log32_function = posit_log32_inversion,
			.posit_log64_function = posit_log64_inversion,
		},
	},
	{
		.identifier = "lb",
		.type = OPERATOR_TYPE_POSIT_POSIT,
		.implementation.posit_posit = {
			.posit8_function = posit8_lb,
			.posit16_function = posit16_lb,
			.posit32_function = posit32_lb,
			.posit64_function = posit64_lb,
			.posit_log8_function = posit_log8_lb,
			.posit_log16_function = posit_log16_lb,
			.posit_log32_function = posit_log32_lb,
			.posit_log64_function = posit_log64_lb,
		},
	},
	{
		.identifier = "lb_1_plus",
		.type = OPERATOR_TYPE_POSIT_POSIT,
		.implementation.posit_posit = {
			.posit8_function = posit8_lb_1_plus,
			.posit16_function = posit16_lb_1_plus,
			.posit32_function = posit32_lb_1_plus,
			.posit64_function = posit64_lb_1_plus,
			.posit_log8_function = posit_log8_lb_1_plus,
			.posit_log16_function = posit_log16_lb_1_plus,
			.posit_log32_function = posit_log32_lb_1_plus,
			.posit_log64_function = posit_log64_lb_1_plus,
		},
	},
	{
		.identifier = "lg",
		.type = OPERATOR_TYPE_POSIT_POSIT,
		.implementation.posit_posit = {
			.posit8_function = posit8_lg,
			.posit16_function = posit16_lg,
			.posit32_function = posit32_lg,
			.posit64_function = posit64_lg,
			.posit_log8_function = posit_log8_lg,
			.posit_log16_function = posit_log16_lg,
			.posit_log32_function = posit_log32_lg,
			.posit_log64_function = posit_log64_lg,
		},
	},
	{
		.identifier = "lg_1_plus",
		.type = OPERATOR_TYPE_POSIT_POSIT,
		.implementation.posit_posit = {
			.posit8_function = posit8_lg_1_plus,
			.posit16_function = posit16_lg_1_plus,
			.posit32_function = posit32_lg_1_plus,
			.posit64_function = posit64_lg_1_plus,
			.posit_log8_function = posit_log8_lg_1_plus,
			.posit_log16_function = posit_log16_lg_1_plus,
			.posit_log32_function = posit_log32_lg_1_plus,
			.posit_log64_function = posit_log64_lg_1_plus,
		},
	},
	{
		.identifier = "ln",
		.type = OPERATOR_TYPE_POSIT_POSIT,
		.implementation.posit_posit = {
			.posit8_function = posit8_ln,
			.posit16_function = posit16_ln,
			.posit32_function = posit32_ln,
			.posit64_function = posit64_ln,
			.posit_log8_function = posit_log8_ln,
			.posit_log16_function = posit_log16_ln,
			.posit_log32_function = posit_log32_ln,
			.posit_log64_function = posit_log64_ln,
		},
	},
	{
		.identifier = "ln_1_plus",
		.type = OPERATOR_TYPE_POSIT_POSIT,
		.implementation.posit_posit = {
			.posit8_function = posit8_ln_1_plus,
			.posit16_function = posit16_ln_1_plus,
			.posit32_function = posit32_ln_1_plus,
			.posit64_function = posit64_ln_1_plus,
			.posit_log8_function = posit_log8_ln_1_plus,
			.posit_log16_function = posit_log16_ln_1_plus,
			.posit_log32_function = posit_log32_ln_1_plus,
			.posit_log64_function = posit_log64_ln_1_plus,
		},
	},
	{
		.identifier = "precision",
		.type = OPERATOR_TYPE_PRECISION,
	},
	{
		.identifier = "sec",
		.type = OPERATOR_TYPE_POSIT_POSIT,
		.implementation.posit_posit = {
			.posit8_function = posit8_sec,
			.posit16_function = posit16_sec,
			.posit32_function = posit32_sec,
			.posit64_function = posit64_sec,
			.posit_log8_function = posit_log8_sec,
			.posit_log16_function = posit_log16_sec,
			.posit_log32_function = posit_log32_sec,
			.posit_log64_function = posit_log64_sec,
		},
	},
	{
		.identifier = "sec_pi_times",
		.type = OPERATOR_TYPE_POSIT_POSIT,
		.implementation.posit_posit = {
			.posit8_function = posit8_sec_pi_times,
			.posit16_function = posit16_sec_pi_times,
			.posit32_function = posit32_sec_pi_times,
			.posit64_function = posit64_sec_pi_times,
			.posit_log8_function = posit_log8_sec_pi_times,
			.posit_log16_function = posit_log16_sec_pi_times,
			.posit_log32_function = posit_log32_sec_pi_times,
			.posit_log64_function = posit_log64_sec_pi_times,
		},
	},
	{
		.identifier = "sech",
		.type = OPERATOR_TYPE_POSIT_POSIT,
		.implementation.posit_posit = {
			.posit8_function = posit8_sech,
			.posit16_function = posit16_sech,
			.posit32_function = posit32_sech,
			.posit64_function = posit64_sech,
			.posit_log8_function = posit_log8_sech,
			.posit_log16_function = posit_log16_sech,
			.posit_log32_function = posit_log32_sech,
			.posit_log64_function = posit_log64_sech,
		},
	},
	{
		.identifier = "sign",
		.type = OPERATOR_TYPE_POSIT_POSIT,
		.implementation.posit_posit = {
			.posit8_function = posit8_sign,
			.posit16_function = posit16_sign,
			.posit32_function = posit32_sign,
			.posit64_function = posit64_sign,
			.posit_log8_function = posit_log8_sign,
			.posit_log16_function = posit_log16_sign,
			.posit_log32_function = posit_log32_sign,
			.posit_log64_function = posit_log64_sign,
		},
	},
	{
		.identifier = "sin",
		.type = OPERATOR_TYPE_POSIT_POSIT,
		.implementation.posit_posit = {
			.posit8_function = posit8_sin,
			.posit16_function = posit16_sin,
			.posit32_function = posit32_sin,
			.posit64_function = posit64_sin,
			.posit_log8_function = posit_log8_sin,
			.posit_log16_function = posit_log16_sin,
			.posit_log32_function = posit_log32_sin,
			.posit_log64_function = posit_log64_sin,
		},
	},
	{
		.identifier = "sin_pi_times",
		.type = OPERATOR_TYPE_POSIT_POSIT,
		.implementation.posit_posit = {
			.posit8_function = posit8_sin_pi_times,
			.posit16_function = posit16_sin_pi_times,
			.posit32_function = posit32_sin_pi_times,
			.posit64_function = posit64_sin_pi_times,
			.posit_log8_function = posit_log8_sin_pi_times,
			.posit_log16_function = posit_log16_sin_pi_times,
			.posit_log32_function = posit_log32_sin_pi_times,
			.posit_log64_function = posit_log64_sin_pi_times,
		},
	},
	{
		.identifier = "sinh",
		.type = OPERATOR_TYPE_POSIT_POSIT,
		.implementation.posit_posit = {
			.posit8_function = posit8_sinh,
			.posit16_function = posit16_sinh,
			.posit32_function = posit32_sinh,
			.posit64_function = posit64_sinh,
			.posit_log8_function = posit_log8_sinh,
			.posit_log16_function = posit_log16_sinh,
			.posit_log32_function = posit_log32_sinh,
			.posit_log64_function = posit_log64_sinh,
		},
	},
	{
		.identifier = "sqrt",
		.type = OPERATOR_TYPE_POSIT_POSIT,
		.implementation.posit_posit = {
			.posit8_function = posit8_square_root,
			.posit16_function = posit16_square_root,
			.posit32_function = posit32_square_root,
			.posit64_function = posit64_square_root,
			.posit_log8_function = posit_log8_square_root,
			.posit_log16_function = posit_log16_square_root,
			.posit_log32_function = posit_log32_square_root,
			.posit_log64_function = posit_log64_square_root,
		},
	},
	{
		.identifier = "posit8",
		.type = OPERATOR_TYPE_SWITCH_POSIT_TYPE,
		.implementation.switch_posit_type = {
			.type = POSIT_TYPE_POSIT8,
		},
	},
	{
		.identifier = "posit16",
		.type = OPERATOR_TYPE_SWITCH_POSIT_TYPE,
		.implementation.switch_posit_type = {
			.type = POSIT_TYPE_POSIT16,
		},
	},
	{
		.identifier = "posit32",
		.type = OPERATOR_TYPE_SWITCH_POSIT_TYPE,
		.implementation.switch_posit_type = {
			.type = POSIT_TYPE_POSIT32,
		},
	},
	{
		.identifier = "posit64",
		.type = OPERATOR_TYPE_SWITCH_POSIT_TYPE,
		.implementation.switch_posit_type = {
			.type = POSIT_TYPE_POSIT64,
		},
	},
	{
		.identifier = "posit_log8",
		.type = OPERATOR_TYPE_SWITCH_POSIT_TYPE,
		.implementation.switch_posit_type = {
			.type = POSIT_TYPE_POSIT_LOG8,
		},
	},
	{
		.identifier = "posit_log16",
		.type = OPERATOR_TYPE_SWITCH_POSIT_TYPE,
		.implementation.switch_posit_type = {
			.type = POSIT_TYPE_POSIT_LOG16,
		},
	},
	{
		.identifier = "posit_log32",
		.type = OPERATOR_TYPE_SWITCH_POSIT_TYPE,
		.implementation.switch_posit_type = {
			.type = POSIT_TYPE_POSIT_LOG32,
		},
	},
	{
		.identifier = "posit_log64",
		.type = OPERATOR_TYPE_SWITCH_POSIT_TYPE,
		.implementation.switch_posit_type = {
			.type = POSIT_TYPE_POSIT_LOG64,
		},
	},
	{
		.identifier = "tan",
		.type = OPERATOR_TYPE_POSIT_POSIT,
		.implementation.posit_posit = {
			.posit8_function = posit8_tan,
			.posit16_function = posit16_tan,
			.posit32_function = posit32_tan,
			.posit64_function = posit64_tan,
			.posit_log8_function = posit_log8_tan,
			.posit_log16_function = posit_log16_tan,
			.posit_log32_function = posit_log32_tan,
			.posit_log64_function = posit_log64_tan,
		},
	},
	{
		.identifier = "tan_pi_times",
		.type = OPERATOR_TYPE_POSIT_POSIT,
		.implementation.posit_posit = {
			.posit8_function = posit8_tan_pi_times,
			.posit16_function = posit16_tan_pi_times,
			.posit32_function = posit32_tan_pi_times,
			.posit64_function = posit64_tan_pi_times,
			.posit_log8_function = posit_log8_tan_pi_times,
			.posit_log16_function = posit_log16_tan_pi_times,
			.posit_log32_function = posit_log32_tan_pi_times,
			.posit_log64_function = posit_log64_tan_pi_times,
		},
	},
	{
		.identifier = "tanh",
		.type = OPERATOR_TYPE_POSIT_POSIT,
		.implementation.posit_posit = {
			.posit8_function = posit8_tanh,
			.posit16_function = posit16_tanh,
			.posit32_function = posit32_tanh,
			.posit64_function = posit64_tanh,
			.posit_log8_function = posit_log8_tanh,
			.posit_log16_function = posit_log16_tanh,
			.posit_log32_function = posit_log32_tanh,
			.posit_log64_function = posit_log64_tanh,
		},
	},
};

static int
process_token(const char *token, struct stack *stack,
              enum posit_type *posit_type, const struct number *results)
{
	size_t i;
	struct number *a = NULL, *b = NULL, result;

	/*
	 * First check if the token is a single lowercase letter, which
	 * means we just want to push the specified result on the stack.
	 */
	if (strlen(token) == 1 && token[0] >= 'a' && token[0] <= 'z') {
		if (stack_push(stack, &(results[token[0] - 'a']))) {
			return 1;
		}

		return 0;
	}

	/* next try matching the token against the defined operators */
	for (i = 0; i < LEN(operators); i++) {
		size_t j;
		bool first_iteration;

		/* try matching the token against the operator identifier */
		if (strcmp(token, operators[i].identifier)) {
			continue;
		}

		/* we matched an operator! */
		switch (operators[i].type) {
		case OPERATOR_TYPE_HELP:
			printf("This is an RPN (reverse polish notation) "
			       "calculator. Thus you would not write "
			       "'1 + 1' but '1 1 +', for example. Each "
			       "result is stored in registers 'a' to 'z', "
			       "which can be used in subsequent expressions."
			       "\n\nYou can switch between the different posit "
			       "types used for calculations using the "
			       "respective operators ");
			for (j = 0, first_iteration = true; j < LEN(operators);
			     j++) {
				if (operators[j].type !=
				    OPERATOR_TYPE_SWITCH_POSIT_TYPE) {
					continue;
				}
				if (!first_iteration) {
					printf(", ");
				} else {
					first_iteration = false;
				}
				printf("%s", operators[j].identifier);
			}
			printf(". Registers retain their respective "
			       "precisions, but behave as if they were "
			       "casted to the respective posit type.\n\n"
			       "The following operators are implemented: ");
			for (j = 0, first_iteration = true; j < LEN(operators);
			     j++) {
				if (operators[j].type ==
				    OPERATOR_TYPE_SWITCH_POSIT_TYPE) {
					/*
					 * Skip the type switcher operators,
					 * as they are listed separately
					 */
					continue;
				}
				if (!first_iteration) {
					printf(", ");
				} else {
					first_iteration = false;
				}
				printf("%s", operators[j].identifier);
			}
			printf("\n\nPress Ctrl+D to exit.\n");

			/* return 1 to abort further line processing */
			return 1;

			break;
		case OPERATOR_TYPE_POWER:
			if (stack_pop(stack, &b) || stack_pop(stack, &a)) {
				return 1;
			}

			result.posit_type = *posit_type;
			result.integer_value = INT64_MAX;

			/* Call integer_power or power depending on if b is
			 * integral or not */
			if (b->integer_value == INT64_MAX) {
				switch (*posit_type) {
				case POSIT_TYPE_POSIT8:
					number_from_posit8(
						posit8_power(a->posit8_value,
					                     b->posit8_value),
						&result);
					break;
				case POSIT_TYPE_POSIT16:
					number_from_posit16(
						posit16_power(a->posit16_value,
					                      b->posit16_value),
						&result);
					break;
				case POSIT_TYPE_POSIT32:
					number_from_posit32(
						posit32_power(a->posit32_value,
					                      b->posit32_value),
						&result);
					break;
				case POSIT_TYPE_POSIT64:
					number_from_posit64(
						posit64_power(a->posit64_value,
					                      b->posit64_value),
						&result);
					break;
				case POSIT_TYPE_POSIT_LOG8:
					number_from_posit_log8(
						posit_log8_power(
							a->posit_log8_value,
							b->posit_log8_value),
						&result);
					break;
				case POSIT_TYPE_POSIT_LOG16:
					number_from_posit_log16(
						posit_log16_power(
							a->posit_log16_value,
							b->posit_log16_value),
						&result);
					break;
				case POSIT_TYPE_POSIT_LOG32:
					number_from_posit_log32(
						posit_log32_power(
							a->posit_log32_value,
							b->posit_log32_value),
						&result);
					break;
				case POSIT_TYPE_POSIT_LOG64:
					number_from_posit_log64(
						posit_log64_power(
							a->posit_log64_value,
							b->posit_log64_value),
						&result);
					break;
				}
			} else {
				switch (*posit_type) {
				case POSIT_TYPE_POSIT8:
					number_from_posit8(
						posit8_integer_power(
							a->posit8_value,
							b->integer_value),
						&result);
					break;
				case POSIT_TYPE_POSIT16:
					number_from_posit16(
						posit16_integer_power(
							a->posit16_value,
							b->integer_value),
						&result);
					break;
				case POSIT_TYPE_POSIT32:
					number_from_posit32(
						posit32_integer_power(
							a->posit32_value,
							b->integer_value),
						&result);
					break;
				case POSIT_TYPE_POSIT64:
					number_from_posit64(
						posit64_integer_power(
							a->posit64_value,
							b->integer_value),
						&result);
					break;
				case POSIT_TYPE_POSIT_LOG8:
					number_from_posit_log8(
						posit_log8_integer_power(
							a->posit_log8_value,
							b->integer_value),
						&result);
					break;
				case POSIT_TYPE_POSIT_LOG16:
					number_from_posit_log16(
						posit_log16_integer_power(
							a->posit_log16_value,
							b->integer_value),
						&result);
					break;
				case POSIT_TYPE_POSIT_LOG32:
					number_from_posit_log32(
						posit_log32_integer_power(
							a->posit_log32_value,
							b->integer_value),
						&result);
					break;
				case POSIT_TYPE_POSIT_LOG64:
					number_from_posit_log64(
						posit_log64_integer_power(
							a->posit_log64_value,
							b->integer_value),
						&result);
					break;
				}
			}

			if (stack_push(stack, &result)) {
				return 1;
			}

			break;
		case OPERATOR_TYPE_PRECISION:
			if (stack_pop(stack, &a)) {
				return 1;
			}

			result.posit_type = *posit_type;

			switch (*posit_type) {
			case POSIT_TYPE_POSIT8:
				result.integer_value =
					posit8_precision(a->posit8_value);
				number_from_posit8(
					posit8_from_extended_float(
						(long double)
							result.integer_value),
					&result);
				break;
			case POSIT_TYPE_POSIT16:
				result.integer_value =
					posit16_precision(a->posit16_value);
				number_from_posit16(
					posit16_from_extended_float(
						(long double)
							result.integer_value),
					&result);
				break;
			case POSIT_TYPE_POSIT32:
				result.integer_value =
					posit32_precision(a->posit32_value);
				number_from_posit32(
					posit32_from_extended_float(
						(long double)
							result.integer_value),
					&result);
				break;
			case POSIT_TYPE_POSIT64:
				result.integer_value =
					posit64_precision(a->posit64_value);
				number_from_posit64(
					posit64_from_extended_float(
						(long double)
							result.integer_value),
					&result);
				break;
			case POSIT_TYPE_POSIT_LOG8:
				result.integer_value = posit_log8_precision(
					a->posit_log8_value);
				number_from_posit_log8(
					posit_log8_from_extended_float(
						(long double)
							result.integer_value),
					&result);
				break;
			case POSIT_TYPE_POSIT_LOG16:
				result.integer_value = posit_log16_precision(
					a->posit_log16_value);
				number_from_posit_log16(
					posit_log16_from_extended_float(
						(long double)
							result.integer_value),
					&result);
				break;
			case POSIT_TYPE_POSIT_LOG32:
				result.integer_value = posit_log32_precision(
					a->posit_log32_value);
				number_from_posit_log32(
					posit_log32_from_extended_float(
						(long double)
							result.integer_value),
					&result);
				break;
			case POSIT_TYPE_POSIT_LOG64:
				result.integer_value = posit_log64_precision(
					a->posit_log64_value);
				number_from_posit_log64(
					posit_log64_from_extended_float(
						(long double)
							result.integer_value),
					&result);
				break;
			}

			if (stack_push(stack, &result)) {
				return 1;
			}

			break;
		case OPERATOR_TYPE_SWITCH_POSIT_TYPE:
			*posit_type =
				operators[i]
					.implementation.switch_posit_type.type;

			/* return 1 to abort further line processing */
			return 1;

			break;
		case OPERATOR_TYPE_POSIT_INT64_POSIT:
			if (stack_pop(stack, &b) || stack_pop(stack, &a) ||
			    b->integer_value == INT64_MAX) {
				return 1;
			}

			result.posit_type = *posit_type;
			result.integer_value = INT64_MAX;

			switch (*posit_type) {
			case POSIT_TYPE_POSIT8:
				number_from_posit8(
					operators[i]
						.implementation
						.posit_int64_posit
						.posit8_function(
							a->posit8_value,
							b->integer_value),
					&result);
				break;
			case POSIT_TYPE_POSIT16:
				number_from_posit16(
					operators[i]
						.implementation
						.posit_int64_posit
						.posit16_function(
							a->posit16_value,
							b->integer_value),
					&result);
				break;
			case POSIT_TYPE_POSIT32:
				number_from_posit32(
					operators[i]
						.implementation
						.posit_int64_posit
						.posit32_function(
							a->posit32_value,
							b->integer_value),
					&result);
				break;
			case POSIT_TYPE_POSIT64:
				number_from_posit64(
					operators[i]
						.implementation
						.posit_int64_posit
						.posit64_function(
							a->posit64_value,
							b->integer_value),
					&result);
				break;
			case POSIT_TYPE_POSIT_LOG8:
				number_from_posit_log8(
					operators[i]
						.implementation
						.posit_int64_posit
						.posit_log8_function(
							a->posit_log8_value,
							b->integer_value),
					&result);
				break;
			case POSIT_TYPE_POSIT_LOG16:
				number_from_posit_log16(
					operators[i]
						.implementation
						.posit_int64_posit
						.posit_log16_function(
							a->posit_log16_value,
							b->integer_value),
					&result);
				break;
			case POSIT_TYPE_POSIT_LOG32:
				number_from_posit_log32(
					operators[i]
						.implementation
						.posit_int64_posit
						.posit_log32_function(
							a->posit_log32_value,
							b->integer_value),
					&result);
				break;
			case POSIT_TYPE_POSIT_LOG64:
				number_from_posit_log64(
					operators[i]
						.implementation
						.posit_int64_posit
						.posit_log64_function(
							a->posit_log64_value,
							b->integer_value),
					&result);
				break;
			}

			if (stack_push(stack, &result)) {
				return 1;
			}

			break;
		case OPERATOR_TYPE_POSIT_POSIT:
			if (stack_pop(stack, &a)) {
				return 1;
			}

			result.posit_type = *posit_type;
			result.integer_value = INT64_MAX;

			switch (*posit_type) {
			case POSIT_TYPE_POSIT8:
				number_from_posit8(
					operators[i]
						.implementation.posit_posit
						.posit8_function(
							a->posit8_value),
					&result);
				break;
			case POSIT_TYPE_POSIT16:
				number_from_posit16(
					operators[i]
						.implementation.posit_posit
						.posit16_function(
							a->posit16_value),
					&result);
				break;
			case POSIT_TYPE_POSIT32:
				number_from_posit32(
					operators[i]
						.implementation.posit_posit
						.posit32_function(
							a->posit32_value),
					&result);
				break;
			case POSIT_TYPE_POSIT64:
				number_from_posit64(
					operators[i]
						.implementation.posit_posit
						.posit64_function(
							a->posit64_value),
					&result);
				break;
			case POSIT_TYPE_POSIT_LOG8:
				number_from_posit_log8(
					operators[i]
						.implementation.posit_posit
						.posit_log8_function(
							a->posit_log8_value),
					&result);
				break;
			case POSIT_TYPE_POSIT_LOG16:
				number_from_posit_log16(
					operators[i]
						.implementation.posit_posit
						.posit_log16_function(
							a->posit_log16_value),
					&result);
				break;
			case POSIT_TYPE_POSIT_LOG32:
				number_from_posit_log32(
					operators[i]
						.implementation.posit_posit
						.posit_log32_function(
							a->posit_log32_value),
					&result);
				break;
			case POSIT_TYPE_POSIT_LOG64:
				number_from_posit_log64(
					operators[i]
						.implementation.posit_posit
						.posit_log64_function(
							a->posit_log64_value),
					&result);
				break;
			}

			if (stack_push(stack, &result)) {
				return 1;
			}

			break;
		case OPERATOR_TYPE_POSIT_POSIT_POSIT:
			if (stack_pop(stack, &b) || stack_pop(stack, &a)) {
				return 1;
			}

			result.posit_type = *posit_type;
			result.integer_value = INT64_MAX;

			switch (*posit_type) {
			case POSIT_TYPE_POSIT8:
				number_from_posit8(
					operators[i]
						.implementation
						.posit_posit_posit
						.posit8_function(
							a->posit8_value,
							b->posit8_value),
					&result);
				break;
			case POSIT_TYPE_POSIT16:
				number_from_posit16(
					operators[i]
						.implementation
						.posit_posit_posit
						.posit16_function(
							a->posit16_value,
							b->posit16_value),
					&result);
				break;
			case POSIT_TYPE_POSIT32:
				number_from_posit32(
					operators[i]
						.implementation
						.posit_posit_posit
						.posit32_function(
							a->posit32_value,
							b->posit32_value),
					&result);
				break;
			case POSIT_TYPE_POSIT64:
				number_from_posit64(
					operators[i]
						.implementation
						.posit_posit_posit
						.posit64_function(
							a->posit64_value,
							b->posit64_value),
					&result);
				break;
			case POSIT_TYPE_POSIT_LOG8:
				number_from_posit_log8(
					operators[i]
						.implementation
						.posit_posit_posit
						.posit_log8_function(
							a->posit_log8_value,
							b->posit_log8_value),
					&result);
				break;
			case POSIT_TYPE_POSIT_LOG16:
				number_from_posit_log16(
					operators[i]
						.implementation
						.posit_posit_posit
						.posit_log16_function(
							a->posit_log16_value,
							b->posit_log16_value),
					&result);
				break;
			case POSIT_TYPE_POSIT_LOG32:
				number_from_posit_log32(
					operators[i]
						.implementation
						.posit_posit_posit
						.posit_log32_function(
							a->posit_log32_value,
							b->posit_log32_value),
					&result);
				break;
			case POSIT_TYPE_POSIT_LOG64:
				number_from_posit_log64(
					operators[i]
						.implementation
						.posit_posit_posit
						.posit_log64_function(
							a->posit_log64_value,
							b->posit_log64_value),
					&result);
				break;
			}

			if (stack_push(stack, &result)) {
				return 1;
			}

			break;
		}

		/* we break out of the loop given we matched an operator */
		break;
	}

	if (i == LEN(operators)) {
		/* we matched no operator, so this must be a number */
		return number_from_string(token, *posit_type, &result) ||
		       stack_push(stack, &result);
	}

	return 0;
}

int
main(void)
{
	enum posit_type posit_type = POSIT_TYPE_POSIT64;
	struct stack stack;
	struct number results['z' - 'a' + 1] = { 0 };
	char *line = NULL;
	size_t result_offset, line_capacity = 0;

	/* print REPL symbol */
	printf("type '?' for help\n> ");

	/* initialise stack */
	stack_init(&stack);

	/* we start off with result 'a' */
	result_offset = 0;

	/* continuously read input lines */
	while (getline(&line, &line_capacity, stdin) != -1) {
		/* clear the stack but do not deallocate */
		stack.size = 0;

		/* tokenise the string by spaces */
		char *token = strtok(line, " \n");
		while (token != NULL) {
			if (process_token(token, &stack, &posit_type,
			                  results)) {
				break;
			}

			/* get next token */
			token = strtok(NULL, " \n");

			if (token == NULL) {
				/*
				 * End of line, check if stack has
				 * exactly one element and print it
				 */
				if (stack.size != 1) {
					fprintf(stderr,
					        "invalid expression, final "
					        "stack size is not one\n");
				} else {
					struct number *number;

					/* get the single number on the stack */
					stack_pop(&stack, &number);

					/* output the number */
					printf("%c ← ",
					       'a' + (char)result_offset);
					number_print(number);

					/*
					 * put it in a corresponding result slot
					 */
					memcpy(&(results[result_offset]),
					       number, sizeof(*number));

					/*
					 * increment the result offset, but
					 * wrap around properly
					 */
					result_offset = (result_offset + 1) %
					                LEN(results);
				}

				/* We are done with this line */
				break;
			}
		}

		/* print REPL symbol */
		printf("> ");
	}

	/* cleanup */
	free(line);
	stack_free(&stack);

	return 0;
}

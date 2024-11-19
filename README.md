# libposit

This ISO C99 library is an implementation of
[posit arithmetic](https://posithub.org/docs/posit_standard-2.pdf), a new tapered
precision machine number format.

Eight data types are defined, namely `posit8`, `posit16`, `posit32`,
`posit64` for the floating-point posits, and `posit_log8`,`posit_log16`,
`posit_log32` and `posit_log64` for the (logarithmic) posits, a
logarithmic number system.

A wide range of functions is implemented, including a full set of
trigonometric functions and a selection of constants. Please refer to
libposit(7) for an overview.

Using this package one is able to evaluate posits for real-world applications
in terms of precision. Given it is a software implementation the performance
is overall worse than the respective usual IEEE 754 floating-point hardware
implementations, but it is sufficient to evaluate the formats for reasonably
sized numerical benchmarks.

## Getting started

You can automatically configure and install libposit (including manuals)
via

```sh
./configure
make -j install
```

The `-j` flag is optional and enables the parallel processing of the make
rules, yielding a significant speedup. You can also specify it as `-j N`
(where N is, for example, the number of CPU threads) for more fine-grained
control.

The suite of unit tests is run with

```sh
make -j test
```

The manual pages are accessed via man(1). Every function is fully
documented.

```sh
man libposit
man posit16_from_float64
man posit_log32_csch
```

The library also comes with examples. One example is a full-fledged
multi-precision RPN calculator which is run via

```sh
make -j example
./example/calculator
```

## Example

As follows a simple example is given:

```C
#include <stdio.h>
#include <posit.h>

int
main(void)
{
	posit16 a, b;

	a = posit16_from_float64(4.5);
	b = posit16_from_float64(6.5);

	printf("4.5 + 6.5 = %f\n",
	       posit16_to_float64(posit16_addition(a, b)));

	return 0;
}
```

The example is compiled and run with

```sh
cc -o example example.c -lposit
./example
```

## Author and License

libposit is developed by Laslo Hunhold and licensed under the ISC
license. See LICENSE for copyright and license details.

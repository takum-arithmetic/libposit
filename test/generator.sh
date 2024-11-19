#!/bin/sh

cat << EOF > $1.c
/* See LICENSE file for copyright and license details. */
#include "../posit.h"
#include "util.h"

#include <math.h>

long double
${1}_reference(long double a)
{
	return ;
}

static const struct unit_test_block ${1}_utb = {
	.type = UNIT_TEST_BLOCK_TYPE_POSIT_POSIT,
	.function_name = "${1}",
	.data.posit_posit = {
		.reference_function = ${1}_reference,
		.posit_log8_function    = posit_log8_${1},
		.posit_log16_function   = posit_log16_${1},
		.posit_log32_function   = posit_log32_${1},
		.posit_log64_function   = posit_log64_${1},
	},
};

EOF

if [ -z "$2" ]; then
#############################################
cat << EOF >> $1.c
int
main(int argc, char *argv[])
{
	(void)argc;
	argv0 = argv[0];

	return run_unit_test_block(&${1}_utb);
}
EOF
##############################################
else
#############################################
cat << EOF >> $1.c
long double
${1}_${2}_reference(long double a)
{
	return ;
}

static const struct unit_test_block ${1}_${2}_utb = {
	.type = UNIT_TEST_BLOCK_TYPE_POSIT_POSIT,
	.function_name = "${1}_${2}",
	.data.posit_posit = {
		.reference_function = ${1}_${2}_reference,
		.posit_log8_function    = posit_log8_${1}_${2},
		.posit_log16_function   = posit_log16_${1}_${2},
		.posit_log32_function   = posit_log32_${1}_${2},
		.posit_log64_function   = posit_log64_${1}_${2},
	},
};

int
main(int argc, char *argv[])
{
	(void)argc;
	argv0 = argv[0];

	return run_unit_test_block(&${1}_utb) +
	       run_unit_test_block(&${1}_${2}_utb);
}
EOF
#############################################
fi


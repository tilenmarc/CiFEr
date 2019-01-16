/* *
 * Copyright (C) 2018 XLAB d.o.o.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of either:
 *
 *     * the GNU Lesser General Public License as published by the Free
 *     Software Foundation; either version 3 of the License, or (at your
 *     option) any later version.
 *
 * or
 *
 *     * the GNU General Public License as published by the Free Software
 *     Foundation; either version 2 of the License, or (at your option) any
 *     later version.
 *
 * or both in parallel, as here.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#include "munit.h"
#include <stdbool.h>
#include <stdio.h>
#include <sample/uniform.h>

#include "abe/policy.h"

MunitResult test_boolean_to_msp(const MunitParameter params[], void *data) {
    char bool_exp[] = "(1 OR 2) AND 3";
    cfe_msp msp;
    boolean_to_msp(&msp, bool_exp, false);
    cfe_mat_print(msp.mat);
    for (size_t i = 0; i<msp.mat->rows; i++) {
        printf("%d \n", msp.row_to_attrib[i]);
    };
//    munit_assert(1==1);
    char s[] = "1 AND 2 ";
    char *sub_s = substring(s, 0, 2);
    printf("%s \n", sub_s);

    char *s_trimmed = remove_spaces(s);
    printf("%s \n", s_trimmed);
    return MUNIT_OK;
}

MunitResult test_gaussian_elimination(const MunitParameter params[], void *data) {
    mpz_t p;
    mpz_init_set_ui(p, 17);
    cfe_mat mat;
    cfe_mat_init(&mat, 100, 50);
    cfe_uniform_sample_mat(&mat, p);
    cfe_vec x_test;
    cfe_vec_init(&x_test, 50);
    cfe_uniform_sample_vec(&x_test, p);
    cfe_vec x;
    cfe_vec_init(&x, 50);

    cfe_vec vec;
    cfe_vec_init(&vec, 100);

    cfe_mat_mul_vec(&vec, &mat, &x_test);
    cfe_vec_mod(&vec, &vec, p);


    gaussian_elimination(&x, &mat, &vec, p);

    // check if the result is correct
    for (size_t i = 0; i < x.size; i++) {
        munit_assert(mpz_cmp(x.vec[i], x_test.vec[i]) == 0);
    }

    return MUNIT_OK;
}

MunitTest policy_tests[] = {
        {(char *) "/test-boolean_to_msp",       test_boolean_to_msp,       NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL},
        {(char *) "/test-gaussian-elimination", test_gaussian_elimination, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL},
        {NULL,                                  NULL,                      NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL}
};

MunitSuite policy_suite = {
        (char *) "/abe/policy", policy_tests, NULL, 1, MUNIT_SUITE_OPTION_NONE
};

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

#include "abe/policy.h"

MunitResult test_boolean_to_msp(const MunitParameter params[], void *data) {
    char bool_exp[] = "(1 OR 2) AND 3";
    cfe_msp msp;
    boolean_to_msp(&msp, bool_exp, false);
//    munit_assert(1==1);
    char s[] = "foo bar";
    char *sub_s = substring(s, 2, 5);
    gmp_printf("%s\n", sub_s);
    return MUNIT_OK;
}

MunitTest policy_tests[] = {
        {(char *) "/test-boolean_to_msp", test_boolean_to_msp,   NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL},
        {NULL,                            NULL,                  NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL}
};

MunitSuite policy_suite = {
        (char *) "/abe/policy", policy_tests, NULL, 1, MUNIT_SUITE_OPTION_NONE
};
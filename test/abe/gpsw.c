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

#include <gmp.h>
#include <internal/big.h>
#include <ecp_BN254.h>
#include <pair_BN254.h>
#include "test.h"

#include "abe/gpsw.h"
#include "abe/policy.h"
#include "sample/uniform.h"

MunitResult test_gpsw_end_to_end(const MunitParameter *params, void *data) {

    cfe_gpsw gpsw;
    cfe_gpsw_init(&gpsw, 10);

    cfe_gpsw_pub_key pk;
    cfe_vec sk;
    generate_master_keys(&gpsw, &pk, &sk);

    return MUNIT_OK;

}


MunitResult test_amcl(const MunitParameter *params, void *data) {

    // check if e(g1 + g1, g2) = e(g1, g2 + g2)
    ECP_BN254 G1, G1sum;
    ECP_BN254_generator(&G1);
    ECP_BN254_generator(&G1sum);
    ECP_BN254_add(&G1sum, &G1);


    ECP2_BN254 G2, G2sum;
    ECP2_BN254_generator(&G2);
    ECP2_BN254_generator(&G2sum);
    ECP2_BN254_add(&G2sum, &G2);


    FP12_BN254 GTsum1, GTsum2;

    PAIR_BN254_ate(&GTsum1, &G2, &G1sum);
    PAIR_BN254_fexp(&GTsum1);
    PAIR_BN254_ate(&GTsum2, &G2sum, &G1);
    PAIR_BN254_fexp(&GTsum2);

    int check = FP12_BN254_equals(&GTsum1, &GTsum2);
    munit_assert(check);

    // check if g * CURVE_Order = identity
    ECP_BN254 H, H_prime;
    ECP_BN254_generator(&H);
    ECP_BN254_generator(&H_prime);
    BIG_256_56 zero;
    BIG_256_56_zero(zero);
    ECP_BN254_mul(&H, CURVE_Order_BN254);
    ECP_BN254_mul(&H_prime, zero);
    check = ECP_BN254_equals(&H, &H_prime);
    munit_assert(check);

    // check if transformations of integers work
    BIG_256_56 x;
    mpz_t y, y_check;
    mpz_inits(y, y_check, NULL);
    mpz_set_str(y, "72057594037927936", 10);
    BIG_256_56_from_mpz(x, y);
    mpz_from_BIG_256_56(y_check, x);
    munit_assert(mpz_cmp(y, y_check) == 0);

    return MUNIT_OK;
}

MunitTest gpsw_tests[] = {
        {(char *) "/end-to-end", test_gpsw_end_to_end, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL},
        {(char *) "/test-amcl",  test_amcl,            NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL},
        {NULL, NULL,                                   NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL}
};

MunitSuite gpsw_suite = {
        (char *) "/abe/gpsw", gpsw_tests, NULL, 1, MUNIT_SUITE_OPTION_NONE
};

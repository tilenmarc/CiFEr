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
#include <internal/common.h>
#include "test.h"

#include "abe/gpsw.h"
#include "abe/policy.h"
#include "sample/uniform.h"

MunitResult test_gpsw_end_to_end(const MunitParameter *params, void *data) {

    cfe_gpsw gpsw;
    cfe_gpsw_init(&gpsw, 10);

//    gmp_printf("%Zd %d\n", gpsw.p, gpsw.l);

    cfe_gpsw_pub_key pk;
    cfe_vec sk;
    generate_master_keys(&gpsw, &pk, &sk);

//    cfe_vec_print(&sk);

    FP12_BN254 msg;
    FP12_BN254_one(&msg);

    int *gamma= (int *) cfe_malloc(7 * sizeof(int));
    gamma[0] = 1;
    gamma[1] = 2;
    gamma[2] = 3;
    gamma[3] = 4;
    gamma[4] = 5;
    gamma[5] = 6;
    gamma[6] = 7;

    cfe_gpsw_cipher cipher;
    gpsw_encrypt(&cipher, &gpsw, &msg, gamma, 6, &pk);

    // define a boolean expression and make a corresponding msp structure
    char bool_exp[] = "(5 OR 3) AND ((2 OR 4) OR (1 AND 6))";
    cfe_msp msp;
    boolean_to_msp(&msp, bool_exp, true);

    cfe_mat_print(msp.mat);


    cfe_vec_G1 policy_keys;
    generate_policy_keys(&policy_keys, &gpsw, &msp, &sk);

    int *owned_atrib= (int *) cfe_malloc(3 * sizeof(int));
    owned_atrib[0] = 1;
    owned_atrib[1] = 3;
    owned_atrib[2] = 6;

    cfe_gpsw_keys keys;
    delegate_keys(&keys, &policy_keys, &msp, owned_atrib, 3);

    cfe_mat_print(&(keys.mat));


    FP12_BN254 decryption;
    int check = gpsw_decrypt(decryption, &cipher, &keys, &gpsw);
    gmp_printf("check %d\n", check);

//    FP12_BN254_reduce(&decryption);
    FP12_BN254_output(&decryption);
    FP12_BN254_output(&msg);

    munit_assert(FP12_BN254_equals(&msg, &decryption) == 0);
// TODO check negative in FP12
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


    // check if e(g1 + g1, g2) = e(g1, g2)^2
    FP12_BN254 GT_squared;
    PAIR_BN254_ate(&GT_squared, &G2, &G1);
    PAIR_BN254_fexp(&GT_squared);
    BIG_256_56 two;
    BIG_256_56_one(two);
    BIG_256_56_imul(two, two, 2);
    FP12_BN254_pow(&GT_squared, &GT_squared, two);
    check = FP12_BN254_equals(&GT_squared, &GTsum1);
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

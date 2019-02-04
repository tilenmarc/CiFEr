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

#include <stdlib.h>
#include <string.h>
#include <internal/common.h>
#include <internal/big.h>
#include <pair_BN254.h>
#include <big_256_56.h>
#include <fp12_BN254.h>

#include "sample/uniform.h"
#include "abe/policy.h"
#include "abe/gpsw.h"
#include "data/vec_curve.h"



void cfe_gpsw_init(cfe_gpsw *gpsw, size_t l) {
    gpsw->l = l;

    mpz_init_set_ui(gpsw->p, 0);
    mpz_from_BIG_256_56(gpsw->p, CURVE_Order_BN254);
}

void generate_master_keys(cfe_gpsw *gpsw, cfe_gpsw_pub_key *pk, cfe_vec *sk) {
    pk->t = (cfe_vec_G2 *) cfe_malloc(sizeof(cfe_vec_G2));
    pk->y = (FP12_BN254 *) cfe_malloc(sizeof(cfe_vec_G2));

    cfe_vec_init(sk, gpsw->l + 1);
    cfe_uniform_sample_vec(sk, gpsw->p);
    cfe_vec sub_sk;
    cfe_vec_init(&sub_sk, gpsw->l);
    cfe_vec_extract(&sub_sk, sk, 0, gpsw->l);

    cfe_vec_mul_G2(pk->t, &sub_sk);

    ECP_BN254 g1;
    ECP2_BN254 g2;
    FP12_BN254 gT;
    ECP_BN254_generator(&g1);
    ECP2_BN254_generator(&g2);
    PAIR_BN254_ate(&gT, &g2, &g1);
    PAIR_BN254_fexp(&gT);

    BIG_256_56 x;
    BIG_256_56_from_mpz(x, sk->vec[gpsw->l]);
    FP12_BN254_pow(pk->y, &gT, x);
}

























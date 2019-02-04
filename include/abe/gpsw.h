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

#ifndef CIFER_GPSW_H
#define CIFER_GPSW_H

#include <gmp.h>
#include <data/vec_curve.h>
#include <fp12_BN254.h>

#include "data/vec.h"

 /**
 * \file
 * \ingroup abe
 * \brief This is a key policy (KP) attribute based (ABE) scheme based
 * on Goyal, Pandey, Sahai, Waters: "Attribute-Based Encryption for
 * Fine-Grained Access Control of Encrypted Data"
 * We abbreviated it GPSW scheme to honor the authors. This scheme
 * enables distribution of keys based on a boolean expression determining
 * which attributes are needed for an entity to be able to decrypt. Each
 * key is connected to some attribute, such that only a set of keys
 * whose attributes are sufficient can decrypt the massage. This scheme
 * is a PUBLIC-KEY scheme - no master secret key is needed to encrypt
 * the messages.
 */

/**
 * cfe_gpsw represents the GPSW scheme.
 */
typedef struct cfe_gpsw {
    size_t l;
    mpz_t p;
} cfe_gpsw;

/**
 * cfe_gpsw_pub_key the public key for the GPSW scheme.
 */
typedef struct cfe_gpsw_pub_key {
    cfe_vec_G2 *t;
    FP12_BN254 *y;
} cfe_gpsw_pub_key;

/**
 * Configures a new instance of the scheme.
 *
 * @param gpsw A pointer to an uninitialized struct representing the scheme
 * @param l The number of attributes that can be used in the scheme.
 */
void cfe_gpsw_init(cfe_gpsw *gpsw, size_t l);

/**
 * Generates master secret and public key.
 *
 * @param gpsw A pointer to an initialized struct representing the scheme
 * @param pk A pointer to an uninitialized struct representing the public key
 * @param sk A pointer to an uninitialized vector representing the secret key
 */
void generate_master_keys(cfe_gpsw *gpsw, cfe_gpsw_pub_key *pk, cfe_vec *sk);


#endif

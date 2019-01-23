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

#include <stdbool.h>
#include <gmp.h>
#include <pair_BN254.h>
#include <big_256_56.h>

#include "data/mat.h"
#include "data/vec.h"

 /**
 * \file
 * \ingroup fullysec
 * \brief Damgard scheme.
 */

/**
 * cfe_damgard represents a scheme instantiated from the DDH assumption.
 */
typedef struct cfe_gpsw {
    size_t l;
    mpz_t p;
} cfe_gpsw;

/**
 * Configures a new instance of the scheme.
 *
 * @param s A pointer to an uninitialized struct representing the scheme
 * @param l The length of input vectors
 * @param n The security parameter of the scheme
 * @param bound_x The bound by which coordinates of the encrypted vectors are bounded
 * @param bound_y The bound by which coordinates of the inner product
 * vectors are bounded
 * @return Error code
 */
void cfe_gpsw_init(cfe_gpsw *gpsw, size_t l);


#endif

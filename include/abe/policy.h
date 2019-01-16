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

//#ifndef CIFER_POLICY_H
//#define CIFER_POLICY_H

#include <stdbool.h>
#include <gmp.h>

#include "data/mat.h"
#include "data/vec.h"

/**
 * \file
 * \ingroup data
 * \brief Vector struct and operations.
 *
 * As in GMP library, all functions except initialization functions presume that
 * all of the parameters are properly initialized.
 *
 * All functions (unless othewise specified) store their results (either a GMP
 * integer or a vector) to a parameter and do not modify the original vector.
 * Thus, the "result" passed as a parameter must also be properly initialized.
 */


/**
 * Vector of arbitrary precision (GMP) integers.
 */
typedef struct cfe_msp {
    cfe_mat *mat; /** A pointer to the first integer */
    int *row_to_attrib; /** The size of the vector */
} cfe_msp;

/**
 * Initializes a vector.
 *
 * @param v A pointer to an uninitialized vector
 * @param size The size of the vector
 */
void boolean_to_msp(cfe_msp *msp, char *bool_exp, bool convert_to_ones);

size_t boolean_to_msp_iterative(cfe_msp *msp, char *bool_exp, cfe_vec *vec, size_t c);

void make_and_vecs(cfe_vec *vec1, cfe_vec *vec2, cfe_vec *vec, size_t c);

char *substring(char *s, size_t start, size_t stop);

char *remove_spaces(char* source);

void gaussian_elimination(cfe_vec *res, cfe_mat *mat, cfe_vec *vec, mpz_t p);

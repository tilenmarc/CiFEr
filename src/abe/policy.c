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
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <internal/common.h>

#include "abe/policy.h"

void msp_init(cfe_msp *msp) {
    gmp_printf("uuu");
}

void boolean_to_msp(cfe_msp *msp, char *bool_exp, bool convert_to_ones) {
    cfe_vec vec;
    cfe_vec_init(&vec, 1);
    mpz_t one;
    mpz_init_set_ui(one, 1);
    boolean_to_msp_iterative(msp, bool_exp, &vec, 1);
}

size_t boolean_to_msp_iterative(cfe_msp *msp, char *bool_exp, cfe_vec *vec, size_t c) {
    // todo trim spaces in bool_exp
    size_t num_brc = 0;
    char *bool_exp1;
    char *bool_exp2;
    size_t c1;
    size_t c_out;
    cfe_msp msp1;
    cfe_msp msp2;
    bool found = false;
    for (size_t i=0; i<strlen(bool_exp); i++) {
//        gmp_printf("aa\n");
        if (bool_exp[i] == '(') {
            num_brc++;
            continue;
        }
        if (bool_exp[i] == ')') {
            num_brc--;
            continue;
        }
        if (num_brc == 0 && i < strlen(bool_exp) - 3 && bool_exp[i] == 'A' &&
                bool_exp[i+1] == 'N' && bool_exp[i+2] == 'D') {
            bool_exp1 = substring(bool_exp, 0, i);
            bool_exp2 = substring(bool_exp, i + 3, strlen(bool_exp));
            gmp_printf(bool_exp1);
            gmp_printf(bool_exp2);
            cfe_vec vec1, vec2;
            make_and_vecs(&vec1, &vec2, vec, c + 1);
            c1 = boolean_to_msp_iterative(&msp1, bool_exp1, &vec1, c + 1);
            c_out = boolean_to_msp_iterative(&msp2, bool_exp2, &vec2, c1);
            found = true;
        }
    }

    if (found == false) {
        if (bool_exp[0] == '(' && bool_exp[strlen(bool_exp) - 1] == ')') {
            bool_exp = substring(bool_exp, 1, strlen(bool_exp) - 1);
            return boolean_to_msp_iterative(msp, bool_exp, vec, c);
        }

        int attrib = atoi(bool_exp); // todo: error handling change to strtol

        msp->mat = (cfe_mat*) cfe_malloc(sizeof(cfe_mat));
        cfe_mat_init(msp->mat, 1, c);
        mpz_t zero;
        mpz_init_set_ui(zero, 0);
        for (size_t i = 0; i< c; i++) {
            if (i < vec->size) {
                cfe_mat_set(msp->mat, vec->vec[i], 0, i);
            } else {
                cfe_mat_set(msp->mat, zero, 0, i);
            }
        }

        msp->row_to_attrib = (int*) cfe_malloc(sizeof(int) * (1 + 1));
        msp->row_to_attrib[0] = attrib;
        msp->row_to_attrib[1] = '\0';
        return c;
    } else {
        msp->mat = (cfe_mat*) cfe_malloc(sizeof(cfe_mat));
        cfe_mat_init(msp->mat, msp1.mat->rows + msp2.mat->rows, c_out);

    }
}

void make_and_vecs(cfe_vec *vec1, cfe_vec *vec2, cfe_vec *vec, size_t c) {
    mpz_t zero;
    mpz_init_set_ui(zero, 0);
    cfe_vec_constant(vec1, c + 1, zero);
    cfe_vec_constant(vec2, c + 1, zero);
    for (size_t i = 0; i < vec->size; i++) {
        cfe_vec_set(vec2, vec->vec[i], i);
    }
    mpz_set_si(vec1->vec[c], -1);
    mpz_set_si(vec2->vec[c], 1);
}


char *substring(char *s, size_t start, size_t stop) {
    char *sub = cfe_malloc(sizeof(char)*(stop - start + 1));
    strncpy(sub, s+start, stop-start);
    sub[start - stop] = '\0';
    return sub;
}

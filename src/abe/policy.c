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
#include <stdbool.h>
#include <string.h>
#include "abe/policy.h"

void msp_init(cfe_msp *msp) {
    gmp_printf("uuu");
}

void boolean_to_msp(cfe_msp *msp, char *bool_exp, bool convert_to_ones) {
    cfe_vec vec;
    cfe_vec_init(&vec, 1);
    mpz_t one;
    mpz_init_set_ui(one, 1);
    boolean_to_msp_iterative(msp, bool_exp, vec, 1);
}

void boolean_to_msp_iterative(cfe_msp *msp, char *bool_exp, cfe_vec vec, size_t c) {
    // todo trim spaces in bool_exp
    size_t num_brc = 0;
    char *bool_exp1;
    char *bool_exp2;
    size_t c1;
    size_t cOut;
    cfe_msp msp1;
    cfe_msp msp2;
    bool found = false;
    for (size_t i=0; i<strlen(bool_exp); i++) {
        gmp_printf("aa\n");
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
        }
    }


    gmp_printf("hhdsf\n");
}

void make_and_vecs(cfe_vec *vec1, cfe_vec *vec2, cfe_vec *vec, size_t c) {
    return;

}


char *substring(char *s, size_t start, size_t stop) {
    char *sub = malloc(sizeof(char)*(stop - start + 1));
    strncpy(sub, s+start, stop-start);
    sub[start - stop] = '\0';
    return sub;
}

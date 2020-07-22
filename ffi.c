#include "ffi.h"
#include <gmp.h>
#include "cifer/test.h"

#include "cifer/innerprod/fullysec/damgard.h"
#include "cifer/sample/uniform.h"

int add(int a, int b) {
    size_t l = 100;
    mpz_t bound, bound_neg, key1, key2, xy_check, xy;
    mpz_inits(bound, bound_neg, key1, key2, xy_check, xy, NULL);
    mpz_set_ui(bound, 2);
    mpz_pow_ui(bound, bound, 10);
    mpz_neg(bound_neg, bound);
    cfe_damgard s, encryptor, decryptor;
    cfe_error err;

    size_t modulus_len;
    // modulus_len defines the security of the scheme, the higher the better
    modulus_len = 2048;
    cfe_damgard_precomp_init(&s, l, modulus_len, bound);


    cfe_vec mpk, ciphertext, x, y;
    cfe_vec_inits(l, &x, &y, NULL);
    cfe_uniform_sample_range_vec(&x, bound_neg, bound);
    cfe_uniform_sample_range_vec(&y, bound_neg, bound);
    cfe_vec_dot(xy_check, &x, &y);

    cfe_damgard_sec_key msk;

    cfe_damgard_sec_key_init(&msk, &s);
    cfe_damgard_pub_key_init(&mpk, &s);
    cfe_damgard_generate_master_keys(&msk, &mpk, &s);

    cfe_damgard_fe_key key;
    cfe_damgard_fe_key_init(&key);
    err = cfe_damgard_derive_fe_key(&key, &s, &msk, &y);
//    munit_assert(err == 0);

    cfe_damgard_copy(&encryptor, &s);
    cfe_damgard_ciphertext_init(&ciphertext, &encryptor);
    err = cfe_damgard_encrypt(&ciphertext, &encryptor, &x, &mpk);
//    munit_assert(err == 0);

    cfe_damgard_copy(&decryptor, &s);
    err = cfe_damgard_decrypt(xy, &decryptor, &ciphertext, &key, &y);
//    gmp_printf("%Zd, \n", xy);
//    munit_assert(err == 0);

//    munit_assert(mpz_cmp(xy, xy_check) == 0);

    mpz_clears(bound, bound_neg, key1, key2, xy_check, xy, NULL);
    cfe_vec_frees(&x, &y, &mpk, &ciphertext, NULL);

    cfe_damgard_sec_key_free(&msk);
    cfe_damgard_fe_key_free(&key);
    cfe_damgard_free(&s);
    cfe_damgard_free(&encryptor);
    cfe_damgard_free(&decryptor);

    return a + b;
}

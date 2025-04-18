/*
 * Copyright (c) 2025, Altomani Gianluca <altomanigianluca@gmail.com>
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#pragma once

extern "C" {
typedef struct engine_st ENGINE;
typedef struct bignum_st BIGNUM;
typedef struct evp_md_st EVP_MD;
typedef struct evp_md_ctx_st EVP_MD_CTX;
typedef struct evp_pkey_st EVP_PKEY;
typedef struct evp_pkey_ctx_st EVP_PKEY_CTX;
typedef struct evp_kdf_st EVP_KDF;
typedef struct evp_kdf_ctx_st EVP_KDF_CTX;
typedef struct evp_mac_st EVP_MAC;
typedef struct evp_mac_ctx_st EVP_MAC_CTX;
typedef struct evp_cipher_st EVP_CIPHER;
typedef struct evp_cipher_ctx_st EVP_CIPHER_CTX;

void ERR_print_errors_cb(int (*cb)(char const* str, size_t len, void* u), void* u);

EVP_MD_CTX* EVP_MD_CTX_new();
void EVP_MD_CTX_free(EVP_MD_CTX*);
int EVP_DigestUpdate(EVP_MD_CTX*, void const*, size_t);
int EVP_DigestInit_ex(EVP_MD_CTX*, const EVP_MD*, ENGINE*);
int EVP_DigestFinal_ex(EVP_MD_CTX*, unsigned char*, unsigned int*);
int EVP_MD_CTX_copy_ex(EVP_MD_CTX*, EVP_MD_CTX const*);

void EVP_CIPHER_CTX_free(EVP_CIPHER_CTX*);
void EVP_PKEY_CTX_free(EVP_PKEY_CTX*);
void EVP_PKEY_free(EVP_PKEY*);
void EVP_KDF_CTX_free(EVP_KDF_CTX* ctx);
void EVP_KDF_free(EVP_KDF* kdf);
void BN_free(BIGNUM*);
}

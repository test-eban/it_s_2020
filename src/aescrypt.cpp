#include "aescrypt.h"
#include <openssl/aes.h>
#include <openssl/evp.h>
#include "cstring"

QByteArray*AesCrypt::encrypt(QByteArray* clear)
{
    EVP_CIPHER_CTX *ctx;
    int len = 0;
    int cipherText_len = 0;
    int clearText_len = clear->size();

    const unsigned char* clearText = utility.toUnsignedChar(clear);
    unsigned char* cryptText = new unsigned char[clearText_len + EVP_MAX_BLOCK_LENGTH];

    /* Create and initialise the context */
    if(!(ctx = EVP_CIPHER_CTX_new()))
        printErrorAndAbort();

    if(1 != EVP_EncryptInit_ex(ctx, EVP_aes_256_cbc(), nullptr, utility.toConstUnsignedChar(m_key1), utility.toConstUnsignedChar(m_iv)))
        printErrorAndAbort();

    /* Execute and finalize */
    if(1 != EVP_EncryptUpdate(ctx, cryptText, &len, clearText, clearText_len))
        printErrorAndAbort();
    cipherText_len = len;

    if(1 != EVP_EncryptFinal_ex(ctx, cryptText+len, &len))
        printErrorAndAbort();
    cipherText_len += len;

    /* Clean up */
    EVP_CIPHER_CTX_free(ctx);

    return new QByteArray(utility.toConstChar(cryptText));
}

QByteArray* AesCrypt::decrypt(QByteArray* crypt)
{
    EVP_CIPHER_CTX *ctx;

    unsigned char* crypttext = utility.toUnsignedChar(crypt);
    int crypttext_len = std::strlen(utility.toConstChar(crypttext));
    unsigned char* cleartext = new unsigned char[crypttext_len + EVP_MAX_BLOCK_LENGTH];

    int len = 0;
    int cleartext_len = 0;

    /* Create and initialise the context */
    if(!(ctx = EVP_CIPHER_CTX_new()))
        printErrorAndAbort();

    if(1 != EVP_DecryptInit_ex(ctx, EVP_aes_256_cbc(), nullptr, utility.toConstUnsignedChar(m_key1), utility.toConstUnsignedChar(m_iv)))
        printErrorAndAbort();

    /* Execute and finalize */
    if(1 != EVP_DecryptUpdate(ctx, cleartext, &len, crypttext, crypttext_len))
        printErrorAndAbort();
    cleartext_len = len;

    if(1 != EVP_DecryptFinal_ex(ctx, cleartext + len, &len))
        printErrorAndAbort();
    cleartext_len += len;

    /* Clean up */
    EVP_CIPHER_CTX_free(ctx);

    return new QByteArray(utility.toConstChar(cleartext));
}

void AesCrypt::setKey1(QByteArray *key)
{
    if (key->length() != 32)
    {
        throw "The length of the aes key must be exactly 32 bytes (256 bit)";
    }
    m_key1 = key;
}

void AesCrypt::setIv(QByteArray *iv)
{
    if (iv->length() != 0 && iv->length() != 16)
    {
        throw "The length of the initialization vector key must be exactly 16 bytes (128 bit)";
    }
    m_iv = iv;
}

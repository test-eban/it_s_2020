#include "aescrypt.h"

QByteArray*AesCrypt::encrypt(QByteArray* clear)
{
    EVP_CIPHER_CTX *ctx;
    int len = 0;
    int cipherText_len = 0;
    int clearText_len = clear->size();

    const unsigned char* clearText = Utility::toUnsignedChar(clear);
    unsigned char* cryptText = new unsigned char[clearText_len + EVP_MAX_BLOCK_LENGTH];

    /* Create and initialise the context */
    if(!(ctx = EVP_CIPHER_CTX_new()))
    {
        BIO *bio = BIO_new(BIO_s_mem());
        ERR_print_errors(bio);
        BIO_free(bio);
        throw "Error creating EVP Cipher Context";
    }
    if(1 != EVP_EncryptInit_ex(ctx, EVP_aes_256_cbc(), nullptr, Utility::toConstUnsignedChar(m_key1), Utility::toConstUnsignedChar(m_iv)))
    {
        BIO *bio = BIO_new(BIO_s_mem());
        ERR_print_errors(bio);
        BIO_free(bio);
        throw "Error Initializing EVP Encryption";
    }
    /* Execute and finalize */
    if(1 != EVP_EncryptUpdate(ctx, cryptText, &len, clearText, clearText_len))
    {
        BIO *bio = BIO_new(BIO_s_mem());
        ERR_print_errors(bio);
        BIO_free(bio);
        throw "Error while encrypting the plain text.";
    }
    cipherText_len = len;
    if(1 != EVP_EncryptFinal_ex(ctx, cryptText+len, &len))
    {
        BIO *bio = BIO_new(BIO_s_mem());
        ERR_print_errors(bio);
        BIO_free(bio);
        throw "Error finalizing encryption.";
    }
    cipherText_len += len;

    /* Clean up */
    EVP_CIPHER_CTX_free(ctx);

    return new QByteArray(Utility::toConstChar(cryptText));

//    EVP_CIPHER_CTX *ctx;

//    unsigned char* plaintext = Utility::toUnsignedChar(clear);

//    unsigned char* ciphertext = new unsigned char[std::strlen(Utility::toConstChar(plaintext)) + EVP_MAX_BLOCK_LENGTH];

//    int len;

//    int ciphertext_len;

//    int plaintext_len = std::strlen(Utility::toConstChar(plaintext));

//    const unsigned char* _iv = Utility::toConstUnsignedChar(m_iv);

//    /* Create and initialise the context */
//    if(!(ctx = EVP_CIPHER_CTX_new()))
//        ERR_print_errors_fp(stderr);

//    /*
//     * Initialise the encryption operation. IMPORTANT - ensure you use a key
//     * and IV size appropriate for your cipher
//     * In this example we are using 256 bit AES (i.e. a 256 bit key). The
//     * IV size for *most* modes is the same as the block size. For AES this
//     * is 128 bits
//     */
//    if(1 != EVP_EncryptInit_ex(ctx, EVP_aes_256_cbc(), nullptr, Utility::toConstUnsignedChar(m_key1), _iv))
//        ERR_print_errors_fp(stderr);

//    /*
//     * Provide the message to be encrypted, and obtain the encrypted output.
//     * EVP_EncryptUpdate can be called multiple times if necessary
//     */
//    if(1 != EVP_EncryptUpdate(ctx, ciphertext, &len, plaintext, plaintext_len))
//        ERR_print_errors_fp(stderr);
//    ciphertext_len = len;

//    /*
//     * Finalise the encryption. Further ciphertext bytes may be written at
//     * this stage.
//     */
//    if(1 != EVP_EncryptFinal_ex(ctx, ciphertext + len, &len))
//        ERR_print_errors_fp(stderr);
//    ciphertext_len += len;

//    /* Clean up */
//    EVP_CIPHER_CTX_free(ctx);

//    return new QByteArray(Utility::toConstChar(ciphertext));
}

QByteArray* AesCrypt::decrypt(QByteArray* crypt)
{
//    EVP_CIPHER_CTX *ctx;
//    int len = 0;
//    int clearText_len = 0;
//    int cryptText_len = crypt->length();

//    unsigned char* clearText = new unsigned char[cryptText_len + EVP_MAX_BLOCK_LENGTH];
//    unsigned char* cryptText = Utility::toUnsignedChar(crypt);

//    /* Create and initialise the context */
//    if(!(ctx = EVP_CIPHER_CTX_new()))
//    {
//        BIO *bio = BIO_new(BIO_s_mem());
//        ERR_print_errors(bio);
//        BIO_free(bio);
//        throw "Error creating EVP Cipher Context";
//    }
//    if(1 != EVP_DecryptInit_ex(ctx, EVP_aes_256_cbc(), nullptr, Utility::toConstUnsignedChar(m_key1), Utility::toConstUnsignedChar(m_iv)))
//    {
//        BIO *bio = BIO_new(BIO_s_mem());
//        ERR_print_errors(bio);
//        BIO_free(bio);
//        throw "Error Initializing EVP Decryption";
//    }
//    /* Execute and finalize */
//    if(1 != EVP_DecryptUpdate(ctx, clearText, &len, cryptText, cryptText_len))
//    {
//        BIO *bio = BIO_new(BIO_s_mem());
//        ERR_print_errors(bio);
//        BIO_free(bio);
//        throw "Error while decrypting the plain text.";
//    }
//    clearText_len = len;
//    if(1 != EVP_DecryptFinal_ex(ctx, (clearText), &len))
//    {
////        BIO *bio = BIO_new(BIO_s_mem());
////        ERR_print_errors(bio);
////        BIO_free(bio);

////        BIO *bio = BIO_new(BIO_s_mem());
////        ERR_print_errors(bio);
////        char *buf;
////        size_t len = BIO_get_mem_data(bio, &buf);
////        std::string ret(buf, len);
////        BIO_free(bio);

//        ERR_print_errors_fp(stderr);

//        throw "Error finalizing decryption.";
//    }

//    clearText_len = len;

//    /* Clean up */
//    EVP_CIPHER_CTX_free(ctx);

//    return new QByteArray(Utility::toConstChar(clearText), clearText_len);

    EVP_CIPHER_CTX *ctx;

    unsigned char* ciphertext = Utility::toUnsignedChar(crypt);
    int ciphertext_len = std::strlen(Utility::toConstChar(ciphertext));

    unsigned char* plaintext = new unsigned char[ciphertext_len + EVP_MAX_BLOCK_LENGTH];

    int len = 0;

    int plaintext_len = 0;

    /* Create and initialise the context */
    if(!(ctx = EVP_CIPHER_CTX_new()))
        ERR_print_errors_fp(stderr);

    /*
     * Initialise the decryption operation. IMPORTANT - ensure you use a key
     * and IV size appropriate for your cipher
     * In this example we are using 256 bit AES (i.e. a 256 bit key). The
     * IV size for *most* modes is the same as the block size. For AES this
     * is 128 bits
     */
    if(1 != EVP_DecryptInit_ex(ctx, EVP_aes_256_cbc(), nullptr, Utility::toConstUnsignedChar(m_key1), Utility::toConstUnsignedChar(m_iv)))
        ERR_print_errors_fp(stderr);

    /*
     * Provide the message to be decrypted, and obtain the plaintext output.
     * EVP_DecryptUpdate can be called multiple times if necessary.
     */
    if(1 != EVP_DecryptUpdate(ctx, plaintext, &len, ciphertext, ciphertext_len))
        ERR_print_errors_fp(stderr);
    plaintext_len = len;

    /*
     * Finalise the decryption. Further plaintext bytes may be written at
     * this stage.
     */
    if(1 != EVP_DecryptFinal_ex(ctx, plaintext + len, &len))
        ERR_print_errors_fp(stderr);
    plaintext_len += len;

    /* Clean up */
    EVP_CIPHER_CTX_free(ctx);

    return new QByteArray(Utility::toConstChar(plaintext));
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

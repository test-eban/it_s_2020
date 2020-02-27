#include "aescrypt.h"

AesCrypt::AesCrypt()
{
    qDebug("AesCrypt::AesCrypt()");
}

QByteArray*AesCrypt::encrypt(QByteArray* clear)
{
//    qDebug(OpenSSL_version(1));

    EVP_CIPHER_CTX *ctx;
    int len = 0;
    int cipherText_len = 0;
    int clearText_len = clear->length();

    unsigned char* clearText = Utility::QByteArrayToUChar(clear);
    unsigned char* cryptText = new unsigned char[clearText_len + EVP_MAX_BLOCK_LENGTH];

    /* Create and initialise the context */
    if(!(ctx = EVP_CIPHER_CTX_new()))
    {
        throw "Error creating EVP Cipher Context";
    }
    if(1 != EVP_EncryptInit_ex(ctx, EVP_aes_256_cbc(), nullptr, Utility::QByteArrayToConstUChar(m_key), Utility::QByteArrayToConstUChar(m_iv)))
    {
        throw "Error Initializing EVP Encryption";
    }
    if(1 != EVP_EncryptUpdate(ctx, cryptText, &len, clearText, clearText_len))
    {
        throw "Error while encrypting the plain text.";
    }
    cipherText_len = len;

    if(1 != EVP_EncryptFinal_ex(ctx, cryptText+len, &len))
    {
        throw "Error finalizing encryption.";
    }
    cipherText_len += len;

//    *_len = ciphertext_len;

    /* Clean up */
    EVP_CIPHER_CTX_free(ctx);

    return new QByteArray(Utility::toConstChar(cryptText));
}

QByteArray* AesCrypt::decrypt(QByteArray* crypt)
{
    EVP_CIPHER_CTX *ctx;
    int len = 0;
    unsigned int clearText_len = 0;
    unsigned int cryptText_len = crypt->length();

    unsigned char* clearText = new unsigned char[cryptText_len + EVP_MAX_BLOCK_LENGTH];
    unsigned char* cryptText = Utility::QByteArrayToUChar(crypt);

    if(!(ctx = EVP_CIPHER_CTX_new()))
    {
        throw "Error creating EVP Cipher Context";
    }

    if(1 != EVP_DecryptInit_ex(ctx, EVP_aes_256_cbc(), nullptr, Utility::QByteArrayToConstUChar(m_key), Utility::QByteArrayToConstUChar(m_iv)))
    {
        throw "Error Initializing EVP Decryption";
    }

    if(1 != EVP_DecryptUpdate(ctx, clearText, &len, cryptText, cryptText_len))
    {
        throw "Error while decrypting the plain text.";
    }

    clearText_len = len;

//    std::cout << "plaintext BEFORE decryptFinal: " << plaintext << std::endl; // todo currently serves debug purposes, remove before shipping

    if(1 != EVP_DecryptFinal_ex(ctx, (clearText), &len))
    {
        // TODO Remove -- Currently serves debug purposes
        BIO *bio = BIO_new(BIO_s_mem());
        ERR_print_errors(bio);
        char *buf;
        size_t len = BIO_get_mem_data(bio, &buf);
        std::string ret(buf, len);
        BIO_free(bio);

//        std::cout << ret << std::endl;

        throw "Error finalizing decryption.";
    }

    clearText_len += len;
//    *_len = plaintext_len;

    EVP_CIPHER_CTX_free(ctx);

    return new QByteArray(Utility::toConstChar(clearText));
}

void AesCrypt::setKey(QByteArray *key)
{
    this->m_key = key;
}

void AesCrypt::setIv(QByteArray *iv)
{
    m_iv = iv;
}

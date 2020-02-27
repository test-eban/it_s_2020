#include "utility.h"

Utility::Utility()
{}

// https://www.openssl.org/docs/man1.0.2/man3/SHA512.html
unsigned char* Utility::Sha512(const unsigned char* toHash, unsigned int len)
{
//    const EVP_MD* md = EVP_sha512();
//    EVP_MD_CTX* mdctx = EVP_MD_CTX_new();

    unsigned char* out = new unsigned char[SHA512_DIGEST_LENGTH];
    SHA512(toHash, len, out);

    return out;

//    EVP_DigestInit_ex(mdctx, md, nullptr);
//    EVP_DigestUpdate()
//    EVP_MD_
}

const unsigned char* Utility::QByteArrayToConstUChar(const QByteArray* arr)
{
    const char* chr = arr->data();
    const unsigned char* cuchr =  reinterpret_cast<const unsigned char* > (chr);

    return cuchr;
}

unsigned char* Utility::QByteArrayToUChar(const QByteArray *arr)
{
    const char* chr = arr->data();
    unsigned char* uchr = new unsigned char[arr->size()];
    std::memcpy(uchr, chr, arr->size()+1);

    return uchr;
}

const char* Utility::toConstChar(char* cchr)
{
    return reinterpret_cast<const char*>(cchr);
}

const char* Utility::toConstChar(const unsigned char* cuchr)
{
    return reinterpret_cast<const char*>(cuchr);
}

const char* Utility::toConstChar(unsigned char* uchr)
{
    return reinterpret_cast<const char*>(uchr);
}

const unsigned char* Utility::toConstUnsignedChar(char* chr)
{
    return reinterpret_cast<const unsigned char*>(chr);
}

const unsigned char* Utility::toConstUnsignedChar(const char* cchr)
{
    return reinterpret_cast<const unsigned char*>(cchr);
}

const unsigned char* Utility::toConstUnsignedChar(unsigned char* cuchr)
{
    return reinterpret_cast<const unsigned char*>(cuchr);
}


//QByteArray* Utility::toHex(const QByteArray *arr)
//{
//    QByteArray* result = new QByteArray();
//}

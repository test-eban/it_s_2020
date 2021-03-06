#include "utility.h"
#include "cstring"
#include "openssl/sha.h"
#include "openssl/err.h"

QByteArray* Utility::sha512(QByteArray* input, unsigned int inputLen)
{
    const unsigned char* in = toConstUnsignedChar(input);
    unsigned char* out = new unsigned char[SHA512_DIGEST_LENGTH];
    try
    {
        SHA512(in, inputLen, out);
    } catch (const char* e)
    {
        ERR_print_errors_fp(stderr);
        abort();
    }

    return new QByteArray(toConstChar(out), SHA512_DIGEST_LENGTH);
}

const char* Utility::toConstChar(char* chr)
{
    return reinterpret_cast<const char*>(chr);
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

const unsigned char* Utility::toConstUnsignedChar(unsigned char* uchr)
{
    return reinterpret_cast<const unsigned char*>(uchr);
}

const unsigned char* Utility::toConstUnsignedChar(const QByteArray* arr)
{
    char *chr = new char[arr->size() + 1];
    strcpy(chr, arr->data());
    const unsigned char* cuchr =  toConstUnsignedChar(chr);

    return cuchr;
}

unsigned char* Utility::toUnsignedChar(const QByteArray *arr)
{
    char* chr= new char[arr->size() + 1];
    strcpy(chr, arr->data());

    unsigned char* uchr = new unsigned char[arr->size() + 1];
    std::memcpy(uchr, chr, arr->size()+1);

    return uchr;
}

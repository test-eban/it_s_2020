#include "blowfishcrypt.h"
#include <openssl/blowfish.h>
#include "cstring"

QByteArray* BlowfishCrypt::encrypt(QByteArray* clear)
{
    if (m_key1 == nullptr)
    {
        throw "You first must run BlowfishCrypt::setKey1(QByteArray* newKey)!";
    }
    if (m_iv == nullptr)
    {
        throw "You first must run BlowfishCrypt::setIv(QByteArray* iv)!";
    }

    unsigned char* tmp = new unsigned char[clear->length()*8];
    try
    {
        BF_cbc_encrypt(utility.toConstUnsignedChar(clear), tmp, clear->length(), &m_bfKey, utility.toUnsignedChar(m_iv), BF_ENCRYPT);
    }
    catch (const char* e)
    {
        printErrorAndAbort();
    }
    const char* out = utility.toConstChar(tmp);

    return new QByteArray(out, std::strlen(out));
}

QByteArray* BlowfishCrypt::decrypt(QByteArray* crypt)
{
    if (m_key1 == nullptr)
    {
        throw "You first must run BlowfishCrypt::setKey1(QByteArray* newKey)!";
    }
    if (m_iv == nullptr)
    {
        throw "You first must run BlowfishCrypt::setIv(QByteArray* iv)!";
    }

    unsigned char* tmp = new unsigned char[crypt->length()+8];
    try
    {
        BF_cbc_encrypt(utility.toConstUnsignedChar(crypt), tmp, crypt->length(), &m_bfKey, utility.toUnsignedChar(m_iv), BF_DECRYPT);
    }
    catch (const char* e)
    {
        printErrorAndAbort();
    }
    const char* out = utility.toConstChar(tmp);

    return new QByteArray(out, std::strlen(out));
}

void BlowfishCrypt::setKey1(QByteArray* key)
{
    if (!isWithinBounds(key, 4, 56))
    {
        throw "Key must not be null and have a length between 4 and 56 Bytes";
    }

    m_key1 = key;
    try
    {
        BF_set_key(&m_bfKey, key->length(), utility.toConstUnsignedChar(m_key1));
    }
    catch (const char* e)
    {
        printErrorAndAbort();
    }
}

void BlowfishCrypt::setIv(QByteArray *iv)
{
    if (!isWithinBounds(iv, 8, 8))
    {
        throw "Initialization vector must not be null and should be exactly 8 bytes long!";
    }

    m_iv = new QByteArray(*iv);
}

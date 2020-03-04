#include "tripledescrypt.h"
#include "openssl/des.h"
#include "cstring"

TripleDesCrypt::~TripleDesCrypt()
{
    m_iv->fill('0');
    m_key1->fill('0');
    m_key2->fill('0');
    m_key3->fill('0');
}

QByteArray* TripleDesCrypt::encrypt(QByteArray* clear)
{
    if (m_key1 == nullptr)
    {
        throw "You first must run BlowfishCrypt::setKey1(QByteArray* newKey)!";
    }
    if (m_key2 == nullptr)
    {
        throw "You first must run BlowfishCrypt::setKey2(QByteArray* newKey)!";
    }
    if (m_key3 == nullptr)
    {
        throw "You first must run BlowfishCrypt::setKey3(QByteArray* newKey)!";
    }
    if (m_iv == nullptr)
    {
        throw "You first must run BlowfishCrypt::setIv(QByteArray* iv)!";
    }

    /* preparing fields */
    const unsigned char* clearText = utility.toConstUnsignedChar(clear);
    unsigned char* cryptText = new unsigned char[std::strlen(utility.toConstChar(clearText))];

    /* preparing cipher specific fields */
    unsigned char* uKey1 = utility.toUnsignedChar(m_key1);
    unsigned char* uKey2 = utility.toUnsignedChar(m_key2);
    unsigned char* uKey3 = utility.toUnsignedChar(m_key3);
    unsigned char* uIv  = utility.toUnsignedChar(m_iv);

    DES_cblock key1 = { uKey1[0], uKey1[1], uKey1[2], uKey1[3], uKey1[4], uKey1[5], uKey1[6], uKey1[7] };
    DES_cblock key2 = { uKey2[0], uKey2[1], uKey2[2], uKey2[3], uKey2[4], uKey2[5], uKey2[6], uKey2[7] };
    DES_cblock key3 = { uKey3[0], uKey3[1], uKey3[2], uKey3[3], uKey3[4], uKey3[5], uKey3[6], uKey3[7] };
    DES_cblock iv = { uIv[0], uIv[1], uIv[2], uIv[3], uIv[4], uIv[5], uIv[6], uIv[7] };
    DES_key_schedule schKey1,schKey2,schKey3;

    DES_set_odd_parity(&iv);

    if (-2 == DES_set_key_checked(&key1, &schKey1) || -2 == DES_set_key_checked(&key2, &schKey2) || -2 == DES_set_key_checked(&key3, &schKey3))
    {
        throw "One of the keys used poses a weak key.";
    }

    /* execute */
    try
    {
        DES_ede3_cbc_encrypt(clearText, cryptText, std::strlen(utility.toConstChar(clearText)), &schKey1, &schKey2, &schKey3, &iv, DES_ENCRYPT);
    } catch (const char* e)
    {
        printErrorAndAbort();
    }

    return new QByteArray(utility.toConstChar(cryptText));
}

QByteArray* TripleDesCrypt::decrypt(QByteArray* crypt)
{
    if (m_key1 == nullptr)
    {
        throw "You first must run BlowfishCrypt::setKey1(QByteArray* newKey)!";
    }
    if (m_key2 == nullptr)
    {
        throw "You first must run BlowfishCrypt::setKey2(QByteArray* newKey)!";
    }
    if (m_key3 == nullptr)
    {
        throw "You first must run BlowfishCrypt::setKey3(QByteArray* newKey)!";
    }
    if (m_iv == nullptr)
    {
        throw "You first must run BlowfishCrypt::setIv(QByteArray* iv)!";
    }

    /* preparing fields */
    const unsigned char* cryptText = utility.toConstUnsignedChar(crypt);
    unsigned char* clearText = new unsigned char[std::strlen(utility.toConstChar(cryptText))];

    /* preparing cipher specific fields */
    unsigned char* uKey1 = utility.toUnsignedChar(m_key1);
    unsigned char* uKey2 = utility.toUnsignedChar(m_key2);
    unsigned char* uKey3 = utility.toUnsignedChar(m_key3);
    unsigned char* uIv  = utility.toUnsignedChar(m_iv);

    DES_cblock key1 = { uKey1[0], uKey1[1], uKey1[2], uKey1[3], uKey1[4], uKey1[5], uKey1[6], uKey1[7] };
    DES_cblock key2 = { uKey2[0], uKey2[1], uKey2[2], uKey2[3], uKey2[4], uKey2[5], uKey2[6], uKey2[7] };
    DES_cblock key3 = { uKey3[0], uKey3[1], uKey3[2], uKey3[3], uKey3[4], uKey3[5], uKey3[6], uKey3[7] };
    DES_cblock iv = { uIv[0], uIv[1], uIv[2], uIv[3], uIv[4], uIv[5], uIv[6], uIv[7] };
    DES_key_schedule schKey1,schKey2,schKey3;

    DES_set_odd_parity(&iv);

    if (-2 == DES_set_key_checked(&key1, &schKey1) || -2 == DES_set_key_checked(&key2, &schKey2) || -2 == DES_set_key_checked(&key3, &schKey3))
    {
        throw "One of the keys used poses a weak key.";
    }

    /* execute */
    try
    {
        DES_ede3_cbc_encrypt(cryptText, clearText, std::strlen(utility.toConstChar(cryptText)), &schKey1, &schKey2, &schKey3, &iv, DES_DECRYPT);
    } catch (const char* e)
    {
        printErrorAndAbort();
    }

    return new QByteArray(utility.toConstChar(clearText));
}

void TripleDesCrypt::setKey1(QByteArray* key)
{
    if (!isWithinBounds(key, 8, 8))
    {
        throw "Key must not be null or empty and exactly 8 bytes long!";
    }
    m_key1 = new QByteArray(*key);
}

void TripleDesCrypt::setKey2(QByteArray* key)
{
    if (!isWithinBounds(key, 8, 8))
    {
        throw "Key must not be null or empty and exactly 8 bytes long!";
    }
    m_key2 = new QByteArray(*key);
}

void TripleDesCrypt::setKey3(QByteArray* key)
{
    if (!isWithinBounds(key, 8, 8))
    {
        throw "Key must not be null or empty and exactly 8 bytes long!";
    }
    m_key3 = new QByteArray(*key);
}

void TripleDesCrypt::setIv(QByteArray *iv)
{
    if (!isWithinBounds(iv, 8, 8))
    {
        throw "Iv must not be null or empty and exactly 8 bytes long!";
    }

    m_iv = iv;
}

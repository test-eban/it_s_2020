#include "tripledescrypt.h"

QByteArray* TripleDesCrypt::encrypt(QByteArray* clear)
{
    /* preparing fields */
    const unsigned char* clearText = Utility::toConstUnsignedChar(clear);
    unsigned char* cryptText = new unsigned char[std::strlen(Utility::toConstChar(clearText))];

    /* preparing cipher specific fields */
    unsigned char* uKey1 = Utility::toUnsignedChar(m_key1);
    unsigned char* uKey2 = Utility::toUnsignedChar(m_key2);
    unsigned char* uKey3 = Utility::toUnsignedChar(m_key3);
    unsigned char* uIv  = Utility::toUnsignedChar(m_iv);

    DES_cblock key1 = { uKey1[0], uKey1[1], uKey1[2], uKey1[3], uKey1[4], uKey1[5], uKey1[6], uKey1[7] };
    DES_cblock key2 = { uKey2[0], uKey2[1], uKey2[2], uKey2[3], uKey2[4], uKey2[5], uKey2[6], uKey2[7] };
    DES_cblock key3 = { uKey3[0], uKey3[1], uKey3[2], uKey3[3], uKey3[4], uKey3[5], uKey3[6], uKey3[7] };
    DES_cblock iv = { uIv[0], uIv[1], uIv[2], uIv[3], uIv[4], uIv[5], uIv[6], uIv[7] };
    DES_key_schedule schKey1,schKey2,schKey3;

//    fillDesCBlocks(&key1, &key2, &key3, &iv);
    DES_set_odd_parity(&iv);

    if (-2 == DES_set_key_checked(&key1, &schKey1) || -2 == DES_set_key_checked(&key2, &schKey2) || -2 == DES_set_key_checked(&key3, &schKey3))
    {
        printf(" Weak key ....\n");
        throw "mimimi";
    }

    /* execute */
    DES_ede3_cbc_encrypt(clearText, cryptText, std::strlen(Utility::toConstChar(clearText)), &schKey1, &schKey2, &schKey3, &iv, DES_ENCRYPT);

    return new QByteArray(Utility::toConstChar(cryptText));
}

QByteArray* TripleDesCrypt::decrypt(QByteArray* crypt)
{
    /* preparing fields */
    const unsigned char* cryptText = Utility::toConstUnsignedChar(crypt);
    unsigned char* clearText = new unsigned char[std::strlen(Utility::toConstChar(cryptText))];

    /* preparing cipher specific fields */
    unsigned char* uKey1 = Utility::toUnsignedChar(m_key1);
    unsigned char* uKey2 = Utility::toUnsignedChar(m_key2);
    unsigned char* uKey3 = Utility::toUnsignedChar(m_key3);
    unsigned char* uIv  = Utility::toUnsignedChar(m_iv);

    DES_cblock key1 = { uKey1[0], uKey1[1], uKey1[2], uKey1[3], uKey1[4], uKey1[5], uKey1[6], uKey1[7] };
    DES_cblock key2 = { uKey2[0], uKey2[1], uKey2[2], uKey2[3], uKey2[4], uKey2[5], uKey2[6], uKey2[7] };
    DES_cblock key3 = { uKey3[0], uKey3[1], uKey3[2], uKey3[3], uKey3[4], uKey3[5], uKey3[6], uKey3[7] };
    DES_cblock iv = { uIv[0], uIv[1], uIv[2], uIv[3], uIv[4], uIv[5], uIv[6], uIv[7] };
    DES_key_schedule schKey1,schKey2,schKey3;

    DES_set_odd_parity(&iv);

    if (-2 == DES_set_key_checked(&key1, &schKey1) || -2 == DES_set_key_checked(&key2, &schKey2) || -2 == DES_set_key_checked(&key3, &schKey3))
    {
        printf(" Weak key ....\n");
        throw "mimimi";
    }

    /* execute */
    DES_ede3_cbc_encrypt(cryptText, clearText, std::strlen(Utility::toConstChar(cryptText)), &schKey1, &schKey2, &schKey3, &iv, DES_DECRYPT);

    return new QByteArray(Utility::toConstChar(clearText));
}

void TripleDesCrypt::fillDesCBlocks(DES_cblock* key1, DES_cblock* key2, DES_cblock* key3, DES_cblock* iv)
{
    unsigned char* uKey1 = Utility::toUnsignedChar(m_key1);
    unsigned char* uKey2 = Utility::toUnsignedChar(m_key2);
    unsigned char* uKey3 = Utility::toUnsignedChar(m_key3);
    unsigned char* uIv  = Utility::toUnsignedChar(m_iv);

    DES_cblock _key1 = { uKey1[0], uKey1[1], uKey1[2], uKey1[3], uKey1[4], uKey1[5], uKey1[6], uKey1[7] };
    DES_cblock _key2 = { uKey2[0], uKey2[1], uKey2[2], uKey2[3], uKey2[4], uKey2[5], uKey2[6], uKey2[7] };
    DES_cblock _key3 = { uKey3[0], uKey3[1], uKey3[2], uKey3[3], uKey3[4], uKey3[5], uKey3[6], uKey3[7] };
    DES_cblock _iv = { uIv[0], uIv[1], uIv[2], uIv[3], uIv[4], uIv[5], uIv[6], uIv[7] };

    key1 = &_key1;
    key2 = &_key2;
    key3 = &_key3;
    iv = &_iv;
}

void TripleDesCrypt::setKey(QByteArray* key, QByteArray* m_key)
{
    if (!isWithinBounds(key, 7, 9))
    {
        throw "Key must not be null or empty and exactly 8 bytes long!";
    }
    m_key = new QByteArray(*key);
}

void TripleDesCrypt::setKey1(QByteArray* key)
{
    if (!isWithinBounds(key, 7, 9))
    {
        throw "Key must not be null or empty and exactly 8 bytes long!";
    }
    m_key1 = new QByteArray(*key);
}

void TripleDesCrypt::setKey2(QByteArray* key)
{
    if (!isWithinBounds(key, 7, 9))
    {
        throw "Key must not be null or empty and exactly 8 bytes long!";
    }
    m_key2 = new QByteArray(*key);
}

void TripleDesCrypt::setKey3(QByteArray* key)
{
    if (!isWithinBounds(key, 7, 9))
    {
        throw "Key must not be null or empty and exactly 8 bytes long!";
    }
    m_key3 = new QByteArray(*key);
}

void TripleDesCrypt::setIv(QByteArray *iv)
{
    if (!isWithinBounds(iv, 7, 9))
    {
        throw "Iv must not be null or empty and exactly 8 bytes long!";
    }

    m_iv = iv;
}

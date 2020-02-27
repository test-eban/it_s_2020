#include "blowfishcrypt.h"

BlowfishCrypt::BlowfishCrypt()
{
    qDebug("Blowfish::Blowfish()");
}

QByteArray* BlowfishCrypt::encrypt(QByteArray* clear)
{
    if (m_key == nullptr)
    {
        throw "You first must run BlowfishCrypt::setKey(QByteArray* newKey)!";
    }
    if (m_iv == nullptr)
    {
        throw "You first must run BlowfishCrypt::setIv(QByteArray* iv)!";
    }

    ///////////////////////////////////////////////// encrypt
    unsigned char* out = new unsigned char[1024*1024];
//    std::cout << "message: " << clear->toStdString() << "\nout: " << out << "\nm_iv: " << m_iv->toStdString() << std::endl << std::endl;
    BF_cbc_encrypt(Utility::QByteArrayToConstUChar(clear), out, clear->length(), &m_bfKey, Utility::QByteArrayToUChar(m_iv), BF_ENCRYPT);
    std::cout << "message: " << clear->toStdString() << "\nout: " << out << "\nm_iv: " << m_iv->toStdString() << std::endl << std::endl;



//    ///////////////////////////////////////////////// decrypt
//    int strLength = strlen((char*)out1);
//    std::cout << "strlen out1: " << strLength << std::endl;
//    BF_cbc_encrypt(out1, out2, strLength, &m_bfKey, Utility::QByteArrayToUChar(m_iv), BF_DECRYPT);
//    std::cout << "message: " << message->toStdString() << "\nout1: " << out1 << "\nout2: " << out2 << "\nm_iv: " << m_iv->toStdString() << std::endl << std::endl;
    char* tmp = reinterpret_cast<char*> (out);

    return new QByteArray(tmp, std::strlen(tmp));
}

QByteArray* BlowfishCrypt::decrypt(QByteArray* crypt)
{
    ///////////////////////////////////////////////// decrypt
    int strLength = crypt->length();
    unsigned char* out = new unsigned char[1024*1024];
    std::cout << "strlen out: " << strLength << std::endl;
    BF_cbc_encrypt(Utility::QByteArrayToConstUChar(crypt), out, strLength, &m_bfKey, Utility::QByteArrayToUChar(m_iv), BF_DECRYPT);
    std::cout << "message: " << crypt->toStdString() << "\nout: " << out << "\nm_iv: " << m_iv->toStdString() << std::endl << std::endl;

    char* tmp = reinterpret_cast<char*> (out);

    return new QByteArray(tmp, std::strlen(tmp));
}

void BlowfishCrypt::setKey(QByteArray* newKey)
{
    if (newKey != nullptr)
    {
        if (newKey->length() > maxKeyLengthInBytes)
        {
            throw "mimimi";
        }
        if (newKey->length() < /*minKeyLengthInBytes*/ 4)
        {
            throw "mimimi";
        }

        int len = newKey->length();
        m_key = newKey;
        BF_set_key(&m_bfKey, len, Utility::QByteArrayToConstUChar(m_key));
    }
}

void BlowfishCrypt::setIv(QByteArray *iv)
{
    if (iv->length() <= 4)
    {
        throw "Initialization vector must be exactly 8 byte long!";
    }
    m_iv = new QByteArray(*iv);
}

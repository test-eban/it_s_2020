#include "cryptclassbase.h"
#include "limits.h"
#include "openssl/err.h"

CryptClassBase::~CryptClassBase()
{
    m_iv->fill('0');
    m_key1->fill('0');
}

void CryptClassBase::setKey1(QByteArray* key)
{
    if(key == nullptr || key->length() == 0)
    {
        throw "Key must not be null or empty!";
    }
    m_key1 = key;
}

void CryptClassBase::setIv(QByteArray* iv)
{
    if(iv == nullptr)
    {
        throw "Iv must not be null!";
    }
    m_iv = iv;
}

QByteArray* CryptClassBase::getKey1()
{
    return m_key1;
}

QByteArray* CryptClassBase::getIv()
{
    return m_iv;
}

bool CryptClassBase::isWithinBounds(QByteArray* arr, int lowerBound, int upperBound)
{
    bool result = true;
    if(arr == nullptr || arr->length() == 0)
    {
        result = false;
    }
    else if(arr->length() < lowerBound)
    {
        result = false;
    }
    else if(arr->length() > upperBound)
    {
        result = false;
    }

    return result;
}

void CryptClassBase::printErrorAndAbort()
{
    ERR_print_errors_fp(stderr);
    abort();
}

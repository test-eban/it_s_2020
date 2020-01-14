#include "cryptclassbase.h"

CryptClassBase::CryptClassBase()
{
    qDebug("CryptClassBase::CryptClassBase()");
}

QByteArray* CryptClassBase::getKey()
{
    return key;
}

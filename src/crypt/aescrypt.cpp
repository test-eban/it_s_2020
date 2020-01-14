#include "aescrypt.h"

AesCrypt::AesCrypt()
{
    qDebug("AesCrypt::AesCrypt()");
}

QByteArray*AesCrypt::encrypt(QByteArray* clear)
{
    qDebug(OpenSSL_version(1));
}

QByteArray* AesCrypt::decrypt(QByteArray* crypt)
{

}

void AesCrypt::setKey(QByteArray *key)
{

}

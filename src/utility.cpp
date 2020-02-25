#include "utility.h"

Utility::Utility()
{
}

QString Utility::Sha512(const QString* toHash)
{
//    sha
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

//QByteArray* Utility::toHex(const QByteArray *arr)
//{
//    QByteArray* result = new QByteArray();
//}

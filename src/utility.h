#ifndef UTILITY_H
#define UTILITY_H

#include <QString>
#include <QByteArray>
#include "cstring"
#include "openssl/evp.h"
#include "openssl/sha.h"

class Utility
{
private:
    Utility();

public:
    static unsigned char* Sha512(const unsigned char* toHash, unsigned int len);
    static const unsigned char* QByteArrayToConstUChar(const QByteArray* arr);
    static unsigned char* QByteArrayToUChar(const QByteArray* arr);
//    static QByteArray* toHex(const QByteArray* arr);

    static const char* toConstChar(char* cchr);
    static const char* toConstChar(const unsigned char* cuchr);
    static const char* toConstChar(unsigned char* uchr);

    static const unsigned char* toConstUnsignedChar(char* chr);
    static const unsigned char* toConstUnsignedChar(const char* cchr);
    static const unsigned char* toConstUnsignedChar(unsigned char* uchr);
};

#endif // UTILITY_H

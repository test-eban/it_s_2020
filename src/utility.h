#ifndef UTILITY_H
#define UTILITY_H

#include <QString>
#include <QByteArray>
#include "cstring"

class Utility
{
private:
    Utility();

public:
    static QString Sha256(const QString* toHash);
    static const unsigned char* QByteArrayToConstUChar(const QByteArray* arr);
    static unsigned char* QByteArrayToUChar(const QByteArray* arr);
//    static QByteArray* toHex(const QByteArray* arr);
};

#endif // UTILITY_H

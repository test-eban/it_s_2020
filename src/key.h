#ifndef KEY_H
#define KEY_H

#include <QByteArray>
#include <iostream>

#include <fcntl.h>
#include <unistd.h>

#include "utility"

class Key
{
public:
    Key();

    static QByteArray* passwordToKey(QByteArray* password);
    static QByteArray* passwordToKey(QString* password);
    static QByteArray* passwordToKey(const char* password);

    static unsigned char* randomKey(unsigned int length);
//    QByteArray* qRandomKey(unsigned int length);
};

#endif // KEY_H

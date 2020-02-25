#ifndef KEY_H
#define KEY_H

#include <QByteArray>

class Key
{
public:
    Key();

    QByteArray* passwordToKey(QByteArray* password);
    QByteArray* passwordToKey(QString* password);
    QByteArray* passwordToKey(const char* password);

    QByteArray* randomKey();
};

#endif // KEY_H

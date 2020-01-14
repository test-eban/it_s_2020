#ifndef CRYPTCLASSBASE_H
#define CRYPTCLASSBASE_H

#include <QString>
#include <QByteArray>

class CryptClassBase
{
public:
    CryptClassBase();
    //virtual ~CryptClassBase();

    virtual QByteArray* encrypt(QByteArray* clear) = 0;
    virtual QByteArray* decrypt(QByteArray* crypt) = 0;
    virtual void setKey(QByteArray* key) = 0;
    virtual QByteArray* getKey();

protected:
    QByteArray* key;
};

#endif // CRYPTCLASSBASE_H

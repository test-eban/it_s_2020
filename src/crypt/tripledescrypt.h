#ifndef TRIPLEDES_H
#define TRIPLEDES_H

#include "cryptclassbase.h"

class TripleDesCrypt : public CryptClassBase
{
public:
    TripleDesCrypt();

    QByteArray* encrypt(QByteArray* clear) override;
    QByteArray* decrypt(QByteArray* crypt) override;
    void setKey(QByteArray *m_key) override;
};

#endif // TRIPLEDES_H

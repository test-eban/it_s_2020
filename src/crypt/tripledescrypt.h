#ifndef TRIPLEDES_H
#define TRIPLEDES_H

#include "cryptclassbase.h"
#include "../utility.h"

#include "openssl/des.h"

class TripleDesCrypt : public CryptClassBase
{
public:
    TripleDesCrypt() = default;

    QByteArray* encrypt(QByteArray* clear) override;
    QByteArray* decrypt(QByteArray* crypt) override;

    void setKey1(QByteArray *key) override;
    void setKey2(QByteArray *key);
    void setKey3(QByteArray *key);

    void setIv(QByteArray *iv) override;

    QByteArray* getKey2() { return m_key2; }
    QByteArray* getKey3() { return m_key3; }

private:
    void setKey(QByteArray* key, QByteArray* m_key);
    void fillDesCBlocks(DES_cblock* key1, DES_cblock* key2, DES_cblock* key3, DES_cblock* iv);

    QByteArray* m_key2;
    QByteArray* m_key3;
};

#endif // TRIPLEDES_H

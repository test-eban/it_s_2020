#ifndef AES_H
#define AES_H

#include "cryptclassbase.h"
#include <openssl/aes.h>
#include <openssl/evp.h>

class AesCrypt : public CryptClassBase
{
public:
    AesCrypt();

    QByteArray* encrypt(QByteArray* clear) override;
    QByteArray* decrypt(QByteArray* crypt) override;
    void setKey(QByteArray *key) override;
};

#endif // AES_H

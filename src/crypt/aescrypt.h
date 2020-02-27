#ifndef AES_H
#define AES_H

#include "cryptclassbase.h"
#include "../utility.h"

#include <openssl/aes.h>
#include <openssl/evp.h>
#include <openssl/err.h>

class AesCrypt : public CryptClassBase
{
public:
    AesCrypt();

    QByteArray* encrypt(QByteArray* clear) override;
    QByteArray* decrypt(QByteArray* crypt) override;
    void setKey(QByteArray* key) override;
    void setIv(QByteArray* iv);

private:
    QByteArray* m_iv;
};

#endif // AES_H

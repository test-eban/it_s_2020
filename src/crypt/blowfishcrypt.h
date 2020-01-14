#ifndef BLOWFISH_H
#define BLOWFISH_H

#include "cryptclassbase.h"
#include "../utility.h"
#include <openssl/blowfish.h>
#include <iostream>

class BlowfishCrypt : public CryptClassBase
{
public:
    BlowfishCrypt();

    QByteArray* encrypt(QByteArray* clear) override;
    QByteArray* decrypt(QByteArray* crypt) override;
    void setKey(QByteArray *key) override;
    void setIv (QByteArray *IV);

private:
    BF_KEY m_bfKey;
    QByteArray* m_iv;
    int maxKeyLengthInBytes = 56;
};

#endif // BLOWFISH_H

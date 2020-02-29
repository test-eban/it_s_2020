#ifndef BLOWFISH_H
#define BLOWFISH_H

#include "cryptclassbase.h"
#include "../utility.h"
#include <openssl/blowfish.h>

/**
 * @brief   This class provides everything that is necessary to encrypt/decrypt the contents of a given QByteArray with the Blowfish cipher.
 *          The Blowfish cipher is a symmetric-key block cipher.
 * @extends CryptClassBase
 * @author S. Laddach
 */
class BlowfishCrypt: public CryptClassBase
{
public:
    /**
      * @brief default constructor.
      */
    BlowfishCrypt() = default;

    /**
     * @brief This method is used to encrypt the contents of the given QByteArray with the Blowfish cipher.
     * @param clear QByteArray that contains the content that is going to be encrypted.
     * @return a QByteArray containing the encrypted content
     */
    QByteArray* encrypt(QByteArray* clear) override;
    /**
     * @brief This method is used to decrypt the contents of the given QByteArray with the Blowfish cipher.
     * @param crypt QByteArray that contains the content that is going to be decrypted.
     * @return a QByteArray containing the encrypted content
     */
    QByteArray* decrypt(QByteArray* crypt) override;

    /**
     * @brief setter for m_key1. Overwrites the baseclass setter because more logic is necessary.
     * @param new value for m_key1
     */
    void setKey1(QByteArray *key) override;
    /**
     * @brief setter for iv. Overwrites the baseclass setter because more logic is necessary.
     * @param new value for iv
     */
    void setIv (QByteArray *iv) override;

private:
    /**
     * @brief Blowfish (openssl) specific key-object.
     */
    BF_KEY m_bfKey;
};

#endif // BLOWFISH_H

#ifndef AES_H
#define AES_H

#include "cryptclassbase.h"
#include "utility.h"

/**
 * @brief   This class provides everything that is necessary to encrypt/decrypt the contents of a given QByteArray with the AES cipher.
 *          The AES cipher is a symmetric-key algorithm.
 * @extends CryptClassBase
 * @see https://en.wikipedia.org/wiki/Advanced_Encryption_Standard
 * @see https://wiki.openssl.org/index.php/AES
 * @see https://www.openssl.org/docs/manmaster/man3/EVP_aes_256_cbc.html
 * @author S. Laddach
 */
class SYMMETRICCIPHERS_EXPORT AesCrypt: public CryptClassBase
{
public:
    /**
      * @brief default constructor.
      */
    AesCrypt() = default;

    /**
     * @brief This method is used to encrypt the contents of the given QByteArray with the AES cipher.
     * @param clear QByteArray that contains the content that is going to be encrypted.
     * @return a QByteArray containing the encrypted content
     */
    QByteArray* encrypt(QByteArray* clear) override;
    /**
     * @brief This method is used to decrypt the contents of the given QByteArray with the AES cipher.
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
    void setIv(QByteArray *iv) override;
};

#endif // AES_H

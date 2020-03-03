#ifndef TRIPLEDES_H
#define TRIPLEDES_H

#include "cryptclassbase.h"
#include "utility.h"

/**
 * @brief   This class provides everything that is necessary to encrypt/decrypt the contents of a given QByteArray with the 3DES (Triple Key DES) cipher.
 *          Instead of just one key this cipher works using 3 keys. Therefore this class extends on the key1-object by adding two more keys.
 * @extends CryptClassBase
 * @see https://en.wikipedia.org/wiki/Triple_DES
 * @see https://wiki.openssl.org/index.php/3DES
 * @see https://www.openssl.org/docs/man1.1.0/man3/DES_ede3_cbc_encrypt.html
 * @author S. Laddach
 */
class SYMMETRICCIPHERS_EXPORT TripleDesCrypt : public CryptClassBase
{
public:
    /**
      * @brief default constructor
      */
    TripleDesCrypt() = default;

    /**
     * @brief This method is used to encrypt the contents of the given QByteArray with the 3DES cipher.
     * @param clear QByteArray that contains the content that is going to be encrypted.
     * @return a QByteArray containing the encrypted content
     */
    QByteArray* encrypt(QByteArray* clear) override;
    /**
     * @brief This method is used to decrypt the contents of the given QByteArray with the 3DES cipher.
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
     * @brief setter for m_key2.
     * @param new value for m_key2
     */
    void setKey2(QByteArray *key);
    /**
     * @brief setter for m_key3.
     * @param new value for m_key3
     */
    void setKey3(QByteArray *key);
    /**
     * @brief setter for iv. Overwrites the baseclass setter because more logic is necessary.
     * @param new value for iv
     */
    void setIv(QByteArray *iv) override;

    /**
     * @brief getter for key2
     * @return m_key2
     */
    QByteArray* getKey2() { return m_key2; }
    /**
     * @brief getter for key3
     * @return m_key3
     */
    QByteArray* getKey3() { return m_key3; }

private:
    /** QByteArray that holds the key2 */
    QByteArray* m_key2;
    /** QByteArray that holds the key3 */
    QByteArray* m_key3;
};

#endif // TRIPLEDES_H

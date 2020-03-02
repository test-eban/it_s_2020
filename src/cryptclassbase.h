#ifndef CRYPTCLASSBASE_H
#define CRYPTCLASSBASE_H

#include "SymmetricCiphers_global.h"
#include "utility.h"
#include <QByteArray>
/**
 * @brief   This class serves as a base class for all crypt-classes, meaning AesCrypt, BlowfishCrypt, TripleDesCrypt.
 *          Provides basic setter and getter for m_key1 and iv that can be overwritten. Also provides isWithinBounds for QByteArray's.
 * @author S. Laddach
 */
class SYMMETRICCIPHERS_EXPORT CryptClassBase
{
public:
    /**
      * @brief default constructor.
      */
    CryptClassBase() = default;
    /**
      * @brief default destructor.
      */
    virtual ~CryptClassBase() = default;

    /**
     * @brief This class provides the method signature that all deriving crypt classes are using.
     * @param clear QByteArray that contains the content that is going to be encrypted.
     * @return a QByteArray containing the encrypted content
     */
    virtual QByteArray* encrypt(QByteArray* clear) = 0;
    /**
     * @brief This class provides the method signature that all deriving crypt classes are using.
     * @param crypt
     * @return a QByteArray containing the encrypted content
     */
    virtual QByteArray* decrypt(QByteArray* crypt) = 0;

    /**
     * @brief setter for m_key1
     * @param new value for m_key1
     */
    virtual void setKey1(QByteArray* key);
    /**
     * @brief setter for iv
     * @param new value for iv
     */
    virtual void setIv(QByteArray* iv);
    /**
     * @brief getter for key1
     * @return m_key1
     */
    virtual QByteArray* getKey1();
    /**
     * @brief getter for iv
     * @return m_iv
     */
    virtual QByteArray* getIv();

protected:
    /**
     * @brief This method checks if the given array-length is within the provided bounds.
     * @param array which length has to be within the provided bounds
     * @param lowerBound defines the minimal length (arr-length must be higher)
     * @param upperBound defines the maximal length (arr-length must be lower)
     * @return  true - if the arr is within bounds
     *          false - if the arr is not within bounds
     */
    static bool isWithinBounds(QByteArray* arr, int lowerBound, int upperBound);

    /**
     * @brief This method makes use of
     */
    [[noreturn]] static void printErrorAndAbort();

    /** QByteArray that holds the key1 */
    QByteArray* m_key1;
    /** QByteArray that holds the initialization vector */
    QByteArray* m_iv;
    /** Utility object */
    Utility utility;
};

#endif // CRYPTCLASSBASE_H

#ifndef KEY_H
#define KEY_H

#include "utility.h"
/**
 * @brief   This class provides all necessary methods to generate a random key and to generate a key from a given password.
 *          To use this class in a shared library the methods can't be static.
 * @author S. Laddach
 */
class SYMMETRICCIPHERS_EXPORT Key
{
public:
    /**
     * @brief default constructor.
     */
    Key() = default;

    /**
     * @brief This method generates a key from a given password. The max. length of the generated key is 64 Bytes.
     * @param password source password from which the key is generated.
     * @param keyLength length of the resulting key. Must be between 0 and 64.
     * @return the resulting key
     */
    QByteArray* passwordToKey(QByteArray* password, int keyLength);

    /**
     * @brief This class generates a random key using /dev/urandom. urandom is more stable than random.
     * @param length defines the length of the output
     * @param printProgress defines if the progress of the keygeneration will be printed
     * @return the resulting random key having the length length
     */
    QByteArray* randomKey(unsigned int length, bool printProgress = false);

private:
    /** Utlity object */
    Utility utility;
};

#endif // KEY_H

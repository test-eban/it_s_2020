#ifndef KEY_H
#define KEY_H

#include <QByteArray>
#include <iostream>

#include <fcntl.h>
#include <unistd.h>

#include "utility.h"
/**
 * @brief   This class provides all necessary methods to generate a random key and to generate a key from a given password.
 *          All methods are static, the constructor is private.
 * @author S. Laddach
 */
class Key
{
public:
    /**
     * @brief This method generates a key from a given password. The max. length of the generated key is 64 Bytes.
     * @param password source password from which the key is generated.
     * @param keyLength length of the resulting key. Must be between 0 and 64.
     * @return the resulting key
     */
    static QByteArray* passwordToKey(QByteArray* password, int keyLength);

    /**
     * @brief This class generates a random key using /dev/urandom. urandom is more stable than random.
     * @param length defines the length of the output
     * @return the resulting random key having the length length
     */
    static QByteArray* randomKey(unsigned int length);

private:
    /**
     * @brief default constructor. private, utility class.
     */
    Key() = default;
};

#endif // KEY_H

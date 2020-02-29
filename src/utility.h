#ifndef UTILITY_H
#define UTILITY_H

#include <iostream>
#include <QByteArray>
#include "cstring"
#include "openssl/sha.h"

/**
 * @brief   This class serves as an utility-class, as the name suggests.
 *          Its main-use is the Sha512-method, which is used by the Key-class.
 *          Due to the repeated use of some of the ways to handle certain data-types
 *          or specific behaviour I defined said ways with methods. This ensures we can
 *          change a repeatedly used behaviour by only changing the associated method.
 * @author S. Laddach
 */
class Utility
{
public:
    /**
     * @brief This method uses openssl to hash the input with the sha-512-algorithm
     * @param input input content
     * @param inputLen length of the input
     * @return the hashed input
     * @see https://www.openssl.org/docs/man1.0.2/man3/SHA512.html
     */
    static QByteArray* Sha512(QByteArray* input, unsigned int inputLen);
    /**
     * @brief converts the given char* into const char*
     * @param chr input
     * @return input as const char*
     */
    static const char* toConstChar(char* chr);
    /**
     * @brief converts the given const unsigned char* into const char*
     * @param chr input
     * @return input as const char*
     */
    static const char* toConstChar(const unsigned char* cuchr);
    /**
     * @brief converts the given unsigned char* into const char*
     * @param chr input
     * @return input as const char*
     */
    static const char* toConstChar(unsigned char* uchr);

    /**
     * @brief converts the given char* into const unsigned char*
     * @param chr input
     * @return input as const unsigned char*
     */
    static const unsigned char* toConstUnsignedChar(char* chr);
    /**
     * @brief converts the given const char* into const unsigned char*
     * @param chr input
     * @return input as const unsigned char*
     */
    static const unsigned char* toConstUnsignedChar(const char* cchr);
    /**
     * @brief converts the given unsigned char* into const unsigned char*
     * @param chr input
     * @return input as const unsigned char*
     */
    static const unsigned char* toConstUnsignedChar(unsigned char* uchr);
    /**
     * @brief converts the given QByteArray* into const unsigned char*
     * @param arr input
     * @return input as const unsigned char*
     */
    static const unsigned char* toConstUnsignedChar(const QByteArray* arr);

    /**
     * @brief converts the given QByteArray* into unsigned char*
     * @param arr input
     * @return input as unsigned char*
     */
    static unsigned char* toUnsignedChar(const QByteArray* arr);

private:
    Utility() = default;
};

#endif // UTILITY_H

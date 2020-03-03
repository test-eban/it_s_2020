#include <QByteArray>
#include <iostream>
#include "blowfishcrypt.h"
#include "aescrypt.h"
#include "tripledescrypt.h"
#include "key.h"

/**
 * @brief Creates an instance of BlowfishCrypt and encrypts a cleartext, decrypts the resulting crypttext and compares the results.
 * @return  true if the results are equal
 *          false if not
 */
bool blowfishTest()
{
    std::cout << "========= Start blowfishTest() =========" << std::endl;
    QByteArray* clear = new QByteArray("The quick brown fox jumps over the lazy dog");

    BlowfishCrypt* blowfish = new BlowfishCrypt(); // new instance
    blowfish->setKey1(new QByteArray("12345678")); // set key
    blowfish->setIv(new QByteArray("12345678")); // set iv

    QByteArray* crypt = blowfish->encrypt(clear); // encrypt
    QByteArray* clearAgain = blowfish->decrypt(crypt); // decrypt

    std::cout << "crypt(hex): " << crypt->toHex().toStdString() << std::endl;
    std::cout << "clear:      " << clear->toStdString() << std::endl;
    std::cout << "clearAgain: " << clearAgain->toStdString() << std::endl;
    blowfish->~BlowfishCrypt();
    std::cout << "=========  end blowfishTest() =========" << std::endl << std::endl;
    return clearAgain->compare(*clear, Qt::CaseSensitive) == 0;
}

/**
 * @brief Creates an instance of AesCrypt and encrypts a cleartext, decrypts the resulting crypttext and compares the results.
 * @return  true if the results are equal
 *          false if not
 */
bool aesTest()
{
    std::cout << "========= Start aesTest() =========" << std::endl;
    QByteArray* clear= new QByteArray("The quick brown fox jumps over the lazy dog");

    AesCrypt* aes = new AesCrypt(); // new instance
    aes->setKey1(new QByteArray("12345678901234567890123456789012")); // set key
    aes->setIv(new QByteArray("1234567890123456")); // set iv

    QByteArray* crypt = aes->encrypt(clear); // encrypt
    QByteArray* clearAgain = aes->decrypt(crypt); // decrypt

    std::cout << "crypt(hex): " << crypt->toHex().toStdString() << std::endl;
    std::cout << "clear:      " << clear->toStdString() << std::endl;
    std::cout << "clearAgain: " << clearAgain->toStdString() << std::endl;
    aes->~AesCrypt();
    std::cout << "=========  End aesTest() =========" << std::endl << std::endl;
    return clearAgain->compare(*clear, Qt::CaseSensitive) == 0;
}

/**
 * @brief Creates an instance of TripleDesCrypt and encrypts a cleartext, decrypts the resulting crypttext and compares the results.
 * @return  true if the results are equal
 *          false if not
 */
bool tripleDesTest()
{
    std::cout << "========= Start tripleDesTest() =========" << std::endl;
    QByteArray* clear = new QByteArray("The quick brown fox jumps over the lazy dog");

    TripleDesCrypt* tdes = new TripleDesCrypt(); // new instance
    tdes->setKey1(new QByteArray("12345678")); // set key 1
    tdes->setKey2(new QByteArray("23456789")); // set key 2
    tdes->setKey3(new QByteArray("34567890")); // set key 3
    tdes->setIv(new QByteArray("87654321")); // set iv

    QByteArray* crypt = tdes->encrypt(clear); // encrypt
    QByteArray* clearAgain = tdes->decrypt(crypt); // decrypt

    std::cout << "crypt(hex): " << crypt->toHex().toStdString() << std::endl;
    std::cout << "clear:      " << clear->toStdString() << std::endl;
    std::cout << "clearAgain: " << clearAgain->toStdString() << std::endl;
    tdes->~TripleDesCrypt();
    std::cout << "=========  End tripleDesTest() =========" << std::endl << std::endl;
    return clearAgain->compare(*clear, Qt::CaseSensitive) == 0;
}

/**
 * @brief Hashes the specified phrase "MeinGeheimesPasswort" and compares it to the expected result
 * @return  true if the result and the expected result are equel
 *          false if not
 */
bool passwordToKeyTest()
{
    std::cout << "========= Start passwordToKeyTest() =========" << std::endl;
    Key key;
    QByteArray* in = new QByteArray("MeinGeheimesPasswort"); // input
    QByteArray* out = key.passwordToKey(in, 64); // output / execute Key::passwordToKey()
    std::cout << "Key(hex) :" << out->toHex().toStdString() << std::endl;
    std::cout << "=========  End passwordToKeyTest() =========" << std::endl << std::endl;
    return out->toHex().compare("D5C1923948A607A116E705AEB3F5E22226BBCFC5AC53A16D52CFF91A7C83BA682416EFE6E90A8D2FE738A3BEDADF1C6F3BDA1FBACE346E69AF97E3E79C04F966", Qt::CaseSensitive);
}

/**
 * @brief checks if the randomKey has the desired length of 64
 * @return  true if the resulting key has a length of 64
 *          false if not
 */
bool randomKeyTest()
{
    std::cout << "========= Start randomKeyTest() =========" << std::endl;
    Key key; // new Key-instance
    QByteArray* rkey = key.randomKey(64); // execute Key::randomKey(int) to get a random key
    std::cout << "random key: " << rkey->toStdString() << std::endl;
    std::cout << "random key(hex): " << rkey->toHex().toStdString() << std::endl;
    std::cout << "=========  End randomKeyTest() =========" << std::endl << std::endl;
    return rkey->size() == 64;
}

bool executeTest()
{
    if (blowfishTest() == false)
    {
        throw "Something seems to be wrong with the blowfish-class.";
    }
    if (aesTest() == false)
    {
        throw "Something seems to be wrong with the aes-class";
    }
    if (tripleDesTest() == false)
    {
        throw "Something seems to be wrong with the tripleDes-class";
    }
    if (passwordToKeyTest() == false)
    {
        throw "Something seems to be wrong with Key::passwordToKey(QByteArray*, unsigned int)";
    }
    if (randomKeyTest() == false)
    {
        throw "Something seems to be wrong with the Key::randomKey(int)";
    }

    std::cout << "Everything seems to be working normally..." << std::endl << std::endl;
    return true;
}

#include <QCoreApplication>

#include "src/cryptclassbase.h"
#include "src/aescrypt.h"
#include "src/blowfishcrypt.h"
#include "src/tripledescrypt.h"
#include "src/key.h"
#include "iostream"

int main(int argc, char *argv[])
{
    Utility utility;
    Key key;

//////////////////////////////////////////////////// crypt blowfish
    QByteArray* inputKey0 = new QByteArray("12345678");
    QByteArray* inputIv0 = new QByteArray("12345678");
    QByteArray* msg0 = new QByteArray("Klartext1111Klartext2222Klartext3333Klartext4444Klartext5555Klartext6666Klartext7777Klartext8888Klartext9999Klartext0000");

    BlowfishCrypt* blowfish = new BlowfishCrypt();
    blowfish->setKey1(inputKey0);
    blowfish->setIv(inputIv0);

    QByteArray* crypt0 = blowfish->encrypt(msg0);
    QByteArray* clear0 = blowfish->decrypt(crypt0);

    std::cout << "crypt(hex): " << crypt0->toHex().toStdString() << "\nclear: " << clear0->toStdString() << std::endl;
//////////////////////////////////////////////////// crypt blowfish


//////////////////////////////////////////////////// crypt aes
    QByteArray* inputKey1 = new QByteArray("12345678901234567890123456789012");
    QByteArray* inputIv1 = new QByteArray("1234567890123456");
    QByteArray* msg1 = new QByteArray("Klartext1111klartext2222Klartext3333Klartext4444Klartext5555Klartext6666Klartext7777Klartext8888Klartext9999Klartext0000");
//    QByteArray* msg = new QByteArray("The quick brown fox jumps over the lazy dog");

    AesCrypt* aes = new AesCrypt();
    try {
        aes->setKey1(inputKey1);
        aes->setIv(inputIv1);

    } catch (const char* e) {
        std::cerr << e;
    }

    QByteArray* crypt1 = aes->encrypt(msg1);
    QByteArray* clear1 = aes->decrypt(crypt1);

    std::cout << "crypt(hex): " << crypt1->toHex().toStdString() << "\nclear: " << clear1->toStdString() << std::endl;
//////////////////////////////////////////////////// crypt aes


//////////////////////////////////////////////////// crypt 3DES
    QByteArray* msg = new QByteArray("Klartext12345678");

    TripleDesCrypt* tdes = new TripleDesCrypt();
    tdes->setKey1(new QByteArray("12345678"));
    tdes->setKey2(new QByteArray("23456789"));
    tdes->setKey3(new QByteArray("34567890"));

    tdes->setIv(new QByteArray("87654321"));

    QByteArray* crypt = tdes->encrypt(msg);
    QByteArray* clear = tdes->decrypt(crypt);

    std::cout << "crypt(hex): " << crypt->toHex().toStdString() << std::endl << "clear: " << clear->toStdString() << std::endl;
//////////////////////////////////////////////////// crypt 3DES


//////////////////////////////////////////////////// sha512
    QByteArray* toHash = new QByteArray("Wahrheit ist tut weh, neh?!");
    QByteArray* out = utility.Sha512(toHash, toHash->length());
    std::cout << "SHA512: " <<std::endl << out->toStdString() << std::endl;
    std::cout << out->toHex().toStdString() << std::endl;
//////////////////////////////////////////////////// sha512


//////////////////////////////////////////////////// passwordToKey
    QByteArray* in = new QByteArray("Franz jagt im komplett verwahrlosten Taxi quer durch Bayern");
    std::cout << "Key :" << key.passwordToKey(in, 64)->toHex().toStdString() << std::endl;
//////////////////////////////////////////////////// key


//////////////////////////////////////////////////// randomKey
    QByteArray* rkey = key.randomKey(64);
    std::cout << rkey->toStdString() << std::endl;
    std::cout << rkey->size() << std::endl;
    std::cout << rkey->toHex().toStdString() << std::endl;
    std::cout << rkey->toHex().size() << std::endl;
//////////////////////////////////////////////////// randomKey

    //    return a.exec();

    return 0;
}



// 17436963d8bf7c9b0d4bdf8369a463a7

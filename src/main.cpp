#include <QCoreApplication>

#include "crypt/cryptclassbase.h"
#include "crypt/aescrypt.h"
#include "crypt/blowfishcrypt.h"
#include "crypt/tripledescrypt.h"

#include "key.h"

int main(int argc, char *argv[])
{
//    QCoreApplication a(argc, argv);

//////////////////////////////////////////////////// crypt blowfish
//    QByteArray* inputKey = new QByteArray("12345678");
//    QByteArray* inputIv = new QByteArray("12345678");
//    QByteArray* msg = new QByteArray("Klartext1111Klartext2222Klartext3333Klartext4444Klartext5555Klartext6666Klartext7777Klartext8888Klartext9999Klartext0000");

//    BlowfishCrypt* blowfish = new BlowfishCrypt();
//    blowfish->setKey1(inputKey);
//    blowfish->setIv(inputIv);

//    QByteArray* crypt = blowfish->encrypt(msg);
//    QByteArray* clear = blowfish->decrypt(crypt);

//    std::cout << "crypt(hex): " << crypt->toHex().toStdString() << "\nclear: " << clear->toStdString() << std::endl;
//////////////////////////////////////////////////// crypt blowfish


//////////////////////////////////////////////////// crypt aes
//    QByteArray* inputKey = new QByteArray("12345678901234567890123456789012");
//    QByteArray* inputIv = new QByteArray("1234567890123456");
//    QByteArray* msg = new QByteArray("Klartext1111klartext2222Klartext3333Klartext4444Klartext5555Klartext6666Klartext7777Klartext8888Klartext9999Klartext0000");
////    QByteArray* msg = new QByteArray("The quick brown fox jumps over the lazy dog");

//    AesCrypt* aes = new AesCrypt();
//    try {
//        aes->setKey1(inputKey);
//        aes->setIv(inputIv);

//    } catch (const char* e) {
//        std::cerr << e;
//    }

//    QByteArray* crypt = aes->encrypt(msg);
//    QByteArray* clear = aes->decrypt(crypt);

//    std::cout << "crypt(hex): " << crypt->toHex().toStdString() << "\nclear: " << clear->toStdString() << std::endl;
//////////////////////////////////////////////////// crypt aes


//////////////////////////////////////////////////// crypt 3DES
//    QByteArray* msg = new QByteArray("Klartext12345678");

//    TripleDesCrypt* tdes = new TripleDesCrypt();
//    tdes->setKey1(new QByteArray("12345678"));
//    tdes->setKey2(new QByteArray("23456789"));
//    tdes->setKey3(new QByteArray("34567890"));

//    tdes->setIv(new QByteArray("87654321"));

//    QByteArray* crypt = tdes->encrypt(msg);
//    QByteArray* clear = tdes->decrypt(crypt);

//    std::cout << "crypt(hex): " << crypt->toHex().toStdString() << std::endl << "clear: " << clear->toStdString() << std::endl;
//////////////////////////////////////////////////// crypt 3DES


//////////////////////////////////////////////////// sha512
//    QByteArray* toHash = new QByteArray("Wahrheit ist tut weh, neh?!");
//    QByteArray* out = Utility::Sha512(toHash, toHash->length());
//    std::cout << "SHA512: " <<std::endl << out->toStdString() << std::endl;
//    std::cout << out->toHex().toStdString() << std::endl;
//////////////////////////////////////////////////// sha512


//////////////////////////////////////////////////// passwordToKey
//    QByteArray* in = new QByteArray("Franz jagt im komplett verwahrlosten Taxi quer durch Bayern");
//    std::cout << "Key :" << Key::passwordToKey(in, 64)->toHex().toStdString() << std::endl;
//////////////////////////////////////////////////// key


//////////////////////////////////////////////////// randomKey
    QByteArray* key = Key::randomKey(64);
    std::cout << key->toStdString() << std::endl;
    std::cout << key->size() << std::endl;
    std::cout << key->toHex().toStdString() << std::endl;
    std::cout << key->toHex().size() << std::endl;
//////////////////////////////////////////////////// randomKey

    //    return a.exec();

    return 0;
}



// 17436963d8bf7c9b0d4bdf8369a463a7

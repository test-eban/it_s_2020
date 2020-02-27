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
//    QByteArray* inputKey = new QByteArray("1234567890123456");
//    QByteArray* inputIv = new QByteArray("\n\n\n\n\n");
//    QByteArray* msg = new QByteArray("Klartext1234");

//    BlowfishCrypt* blowfish = new BlowfishCrypt();
//    blowfish->setKey(inputKey);
//    blowfish->setIv(inputIv);

//    QByteArray* crypt = blowfish->encrypt(msg);
//    QByteArray* clear = blowfish->decrypt(crypt);

//    std::cout << "crypt(hex): " << crypt->toHex().toStdString() << "\nclear: " << clear->toStdString() << std::endl;
//////////////////////////////////////////////////// crypt blowfish


//////////////////////////////////////////////////// crypt aes
//    QByteArray* inputKey = new QByteArray("1234567890123456");
    QByteArray* inputKey = new QByteArray("12345678901234567890123456789012");
//    QByteArray* inputIv = new QByteArray("12345678");
    QByteArray* inputIv = new QByteArray("1234567890123456");
    QByteArray* msg = new QByteArray("Klartext1234");

    AesCrypt* aes = new AesCrypt();
    aes->setKey(inputKey);
    aes->setIv(inputIv);

    QByteArray* crypt = aes->encrypt(msg);
    QByteArray* clear = aes->decrypt(crypt);

    std::cout << "crypt(hex): " << crypt->toHex().toStdString() << "\nclear: " << clear->toStdString() << std::endl;
//////////////////////////////////////////////////// crypt aes


//////////////////////////////////////////////////// rand key
//    const unsigned char* key = Key::randomKey(8);
//    std::cout << "12345678" << std::endl;
//    std::cout << key << std::endl;
//    std::cout << sizeof(key) << std::endl;
//////////////////////////////////////////////////// rand key


//////////////////////////////////////////////////// sha512
//    QByteArray* toHash = new QByteArray("Wahrheit ist tut weh, neh?!");
//    const unsigned char* in = Utility::QByteArrayToConstUChar(toHash);
//    unsigned char* out = Utility::Sha512(in, toHash->length());
//    std::cout << "SHA512: " <<std::endl << out << std::endl << Utility::toConstChar(out) << std::endl;
//    toHash->setRawData(Utility::toConstChar(out), SHA512_DIGEST_LENGTH);
//    std::cout << toHash->toHex().toStdString() << std::endl;
//////////////////////////////////////////////////// sha512
    //    return a.exec();

    return 0;
}



// 17436963d8bf7c9b0d4bdf8369a463a7

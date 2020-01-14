#include <QCoreApplication>

#include "crypt/cryptclassbase.h"
#include "crypt/aescrypt.h"
#include "crypt/blowfishcrypt.h"
#include "crypt/tripledescrypt.h"

int main(int argc, char *argv[])
{
//    QCoreApplication a(argc, argv);

    QByteArray* inputKey = new QByteArray("1234567890123456");
    QByteArray* inputIv = new QByteArray("");
    QByteArray* msg = new QByteArray("Klartext1234567");

    BlowfishCrypt* blowfish = new BlowfishCrypt();
    blowfish->setKey(inputKey);
    blowfish->setIv(inputIv);

    QByteArray* crypt = blowfish->encrypt(msg);
    QByteArray* clear = blowfish->decrypt(crypt);

    std::cout << "crypt(hex): " << crypt->toHex().toStdString() << "\nclear: " << clear->toStdString() << std::endl;

//    return a.exec();
    return 0;
}



// 17436963d8bf7c9b0d4bdf8369a463a7

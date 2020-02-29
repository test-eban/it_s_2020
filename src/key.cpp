#include "key.h"

QByteArray* Key::passwordToKey(QByteArray* password, int keyLength)
{
    QByteArray* result = Utility::Sha512(password, password->length());
    result->resize(keyLength);
    return result;
}

QByteArray* Key::randomKey(unsigned int length)
{
    int randomData = open("/dev/urandom", O_RDONLY);
    if (randomData < 0)
    {
        throw "/dev/urandom could not be opened";
    }
    else
    {
        unsigned char * myRandomData = new unsigned char [length+1];
        ssize_t result = read(randomData, myRandomData, length);

        if (result < 0)
        {
            throw "could not read from /dev/urandom";
        }

        return new QByteArray(Utility::toConstChar(myRandomData));
    }
}

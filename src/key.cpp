#include "key.h"

Key::Key()
{

}

QByteArray* Key::passwordToKey(QByteArray* password)
{
    return new QByteArray();
}

QByteArray* Key::passwordToKey(QString* password)
{
    return new QByteArray();
}

QByteArray* Key::passwordToKey(const char* password)
{
    return new QByteArray();
}

unsigned char* Key::randomKey(unsigned int length)
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

        return myRandomData;
    }
}

//QByteArray* Key::qRandomKey(unsigned int length)
//{
//    unsigned char* randomKey = randomKey(length);

//    QByteArray* qRandomKey = new QByteArray();
//    qRandomKey->fromRawData(randomKey);
//}

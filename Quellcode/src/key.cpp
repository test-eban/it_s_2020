#include "key.h"
#include <fcntl.h>
#include <unistd.h>
#include "cstring"

#include <iostream>

QByteArray* Key::passwordToKey(QByteArray* password, int keyLength)
{
    if (keyLength < 0 || keyLength > 64)
    {
        throw "keyLength must be between 0 and 64";
    }
    QByteArray* result = utility.sha512(password, password->length());
    result->resize(keyLength);
    return result;
}

QByteArray* Key::randomKey(unsigned int length, bool printProgress)
{
    int randomDataFd = open("/dev/random", O_RDONLY); // open file
    if (randomDataFd < 0)
    {
        throw "/dev/random could not be opened";
    }

    unsigned char * randomData = new unsigned char [length];
    size_t randomDataLen = 0;
    while (randomDataLen < length)
    {
        ssize_t result = read(randomDataFd, randomData + randomDataLen, length - randomDataLen); // fill n bytes of the buffer

        if (result < 0)
        {
            throw "could not read from /dev/urandom";
        }
        randomDataLen += result;

        if (printProgress)
        {
            std::cout << "Progress: " << randomDataLen << "/" << length << std::endl;
            std::cout << "Key: " << randomData << std::endl;
        }
        // repeat if the buffer is not yet completely filled
    }
    close(randomDataFd); // close file

    return new QByteArray(utility.toConstChar(randomData), length);
}

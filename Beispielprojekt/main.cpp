#include <QCoreApplication>
#include "test.h"

int main(int argc, char *argv[])
{
    try
    {
        executeTest();
    }
    catch (const char* e)
    {
        std::cerr << e << std::endl;
    }

    return 0;
}

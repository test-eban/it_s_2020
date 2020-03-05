#include <QCoreApplication>
#include "test.h"

int main(int argc, char *argv[])
{
    const int N = 10; // defines the amount of runs
    int errorCount = 0;

    for (int i = 0; i < N; i++)
    {
        std::cout << ">>Run: " << i << std::endl;
        try
        {
            executeTest();
        }
        catch (const char* e)
        {
            std::cerr << e <<std::endl;
            errorCount += 1;
        }
    }

    std::cout << "runs: " << N << std::endl;
    std::cout << "errors: " << errorCount << std::endl;

    return 0;
}

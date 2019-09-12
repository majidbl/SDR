#include <iostream>
#include "sdr.h"
#include <vector>

int main()
{
    std::cout << "Hello World!" << std::endl;

    SDR* sdrobj = new SDR();
    std::vector<std::vector<std::string>> foutDataF;
    std::vector<std::vector<double>> foutDataFD;

    //foutDataF = sdrobj->getDataString("./test.txt");
    foutDataFD = sdrobj->getDataDoublePath("./test2.txt");

    std::cout << foutDataFD.size() << std::endl;
    sdrobj->printSDR(foutDataFD);
    return 0;
}

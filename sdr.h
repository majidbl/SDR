#ifndef SDR_H
#define SDR_H

#include <iostream>
#include <vector>

class SDR
{
public:
    SDR();
    bool wasInteger(const std::string &num);
    std::vector<std::vector<std::string>> getDataString(std::string path);
    std::vector<std::vector<double>> getDataDoubleV(std::vector<std::vector<std::string>> foutDataS);
    std::vector<std::vector<double>> getDataDoublePath(std::string path);
    void printSDR(std::vector<std::vector<double>> foutDataFD);
    
};

#endif // SDR_H

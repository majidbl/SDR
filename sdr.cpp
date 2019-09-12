#include "sdr.h"
#include <vector>
#include <fstream>
#include <regex>

SDR::SDR()
{

}

// check the string has non-integer ele or not
bool SDR::wasInteger(const std::string &num){
        return regex_match(num, std::regex("([+-]?[0-9]+[.]*[0-9]*)"));
}

//return data from file as string vetcor
std::vector<std::vector<std::string>> SDR::getDataString(std::string path)
{
    std::vector<std::vector<std::string>> outDataF;
    std::string::iterator it;
    std::fstream myfile(path);
    std::string line;
    if(myfile.is_open())
    {
        //std::cout << "file opened !!!!!!" << std::endl;
        std::vector<char> temp;
        std::vector<std::string> tempS;
        while(!myfile.eof())
        {
            std::getline(myfile,line);
            //cout << line << endl;
            for (it = line.begin(); it < line.end(); it++)
            {
                if((*it != ' ') && (*it != '\t'))
                {
                    temp.push_back(*it);
                }
                if((*it == ' ') || (it == line.end()-1) || (*it == '\t'))
                {
                    if(temp.empty() == 0)
                    {
                        std::string out;
                        for (std::vector<char>::iterator itc = temp.begin() ; itc != temp.end(); itc++ )
                        {
                            out = out + *itc;
                        }
                        tempS.push_back(out);
                        out = " ";
                        temp.clear();
                    }
                }
            }
            outDataF.push_back(tempS);
            tempS.clear();
        }
        myfile.close();
    }
    else
    {
        std::cout << "file note opened" << std::endl;
    }
    return outDataF;
}

//return data from file as double vetcor from string vector
std::vector<std::vector<double>> SDR::getDataDoubleV(std::vector<std::vector<std::string>> foutDataS)
{
    std::vector<double> filteredtemp;
    std::vector<std::vector<double>> filtered;
    double tempf;
    for (size_t i = 0; i < foutDataS.size(); i++)
    {
        for (size_t its = 0 ; its < foutDataS[i].size(); its++ )
        {
            if(wasInteger(foutDataS[i][its]) == 1)
            {
                tempf = atof(foutDataS[i][its].c_str());
                filteredtemp.push_back(tempf);
            }
        }
        if(!filteredtemp.empty())
            filtered.push_back(filteredtemp);
        filteredtemp.clear();
    }
    return filtered;
}

//return data from file as double vector directly by path of file
std::vector<std::vector<double>> SDR::getDataDoublePath(std::string path)
{
    std::vector<std::vector<std::string>> foutDataS;
    foutDataS = getDataString(path);
    std::vector<double> filteredtemp;
    std::vector<std::vector<double>> filtered;
    double tempf;
    for (size_t i = 0; i < foutDataS.size(); i++)
    {
        for (size_t its = 0 ; its < foutDataS[i].size(); its++ )
        {
            if(wasInteger(foutDataS[i][its]) == 1)
            {
                tempf = atof(foutDataS[i][its].c_str());
                filteredtemp.push_back(tempf);
            }
        }
        if(!filteredtemp.empty())
            filtered.push_back(filteredtemp);
        filteredtemp.clear();
    }
    return filtered;
}

void SDR::printSDR(std::vector<std::vector<double>> foutDataFD)
{
    for (size_t i = 0; i < foutDataFD.size(); i++)
    {
        for (size_t d = 0; d < foutDataFD[i].size(); d++)
        {
            std::cout << foutDataFD[i][d] << "      ";
        }
        std::cout << std::endl;
        
    }
    return;
}
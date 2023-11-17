#include <iostream>
#include "Pwelch.h"
#include <fstream>


template <typename T>
void writeBinary(string fileName, T* x, long  len)
{
    try
    {
        std::ofstream signal_base_band_online(fileName, std::ofstream::binary | std::ofstream::app);
        signal_base_band_online.write((char*)x, len * sizeof(T));
    }
    catch (...)
    {
    }

}

template <typename T>
void readBinary(string fileName, T* x, long  len)
{
    try
    {
        std::ifstream signal_base_band_online(fileName, std::ofstream::binary);
        signal_base_band_online.read((char*)x, len * sizeof(T));
    }
    catch (...)
    {
    }

}

int main()
{
    vector<doubleC> inp(8192);
    readBinary("C:\\Users\\Hosein\\Desktop\\rand.bin", inp.data(), inp.size());
    Pwelch pwelch;
    vector<double> pxx = pwelch.Pwelch_Process(inp, 512, 256, 1024, WindowType::hamming);
}


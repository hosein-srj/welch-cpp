#ifndef FFTW3_CLASS_H
#define FFTW3_CLASS_H

#include <vector>
#include <complex>
#include "defines.h"
#include "fftw3.h"
using namespace std;

class FFTW3_Class
{
public:
    FFTW3_Class(){}

    vector<doubleC>  Fft_C2C(const vector<doubleC>& input, const int& nfft);
    vector<doubleC> iFft_C2C(const vector<doubleC>& input, const int& nfft);
    vector<doubleC>  Fft_R2C(const vector<double>  & input, const int& nfft);
};

#endif // FFTW3_CLASS_H

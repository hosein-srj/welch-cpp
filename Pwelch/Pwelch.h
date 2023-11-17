#pragma once


#include "FFTW3_Class.h"
#include "defines.h"
using namespace std;

enum WindowType {
	hamming,
	hanning
};

class Pwelch
{
public:
	vector<double> Pwelch_Process(vector<doubleC>& in, int w, int overlap, int nfft, WindowType type);
private:
	FFTW3_Class FFT_Obj;
};


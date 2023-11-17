#include "Pwelch.h"

vector<double> Pwelch::Pwelch_Process(vector<doubleC>& in, int w, int overlap, int nfft, WindowType type)
{
	vector<double> pxx(nfft);
	vector<doubleC> window(w);
	if (type == WindowType::hamming) {
		for (int i = 0;i < w;i++)
			window[i] = 0.54 - 0.46 * std::cos(2 * M_PI * i / (w - 1));
	}
	else if (type == WindowType::hanning) {
		for (int i = 0;i < w;i++)
			window[i] = 0.5 * ( 1 - std::cos(2 * M_PI * i / (w - 1)));
	}
	double overlap_ratio = (double)overlap / (double)w;
	int i = 0;
	int count = 0;
	while (i + w <= in.size()) {
		vector<doubleC> block(w);
		memcpy(block.data(), in.data() + i, w * sizeof(doubleC));
		for (int j = 0;j < w;j++)
			block[j] = block[j] * window[j];
		vector<doubleC> fftResult = FFT_Obj.Fft_C2C(block, nfft);
		for (int j = 0;j < nfft;j++)
			pxx[j] = pxx[j] + std::pow(std::abs(fftResult[j]), 2);
		i += overlap;
		count++;
	}
	for (int j = 0;j < nfft;j++)
		pxx[j] = pxx[j] / (double)(count);
	return pxx;
}
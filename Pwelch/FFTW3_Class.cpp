#include "FFTW3_Class.h"


vector<doubleC> FFTW3_Class::Fft_C2C(const vector<doubleC>& input, const int& nfft) {
    vector<doubleC> input_sig(nfft);
    vector<doubleC> output_sig(nfft);
    std::copy(input.begin(), input.begin() + input.size(), input_sig.begin());

    fftw_plan plan = fftw_plan_dft_1d(nfft, reinterpret_cast<fftw_complex*>(input_sig.data()), reinterpret_cast<fftw_complex*>(output_sig.data()), FFTW_FORWARD, FFTW_ESTIMATE);

    fftw_execute(plan);
    fftw_destroy_plan(plan);
    return output_sig;
}

vector<doubleC> FFTW3_Class::iFft_C2C(const vector<doubleC>& input, const int& nfft) {
    vector<doubleC> input_sig(nfft);
    vector<doubleC> output_sig(nfft);

    std::copy(input.begin(), input.end(), input_sig.begin());

    fftw_plan plan = fftw_plan_dft_1d(nfft, reinterpret_cast<fftw_complex*>(input_sig.data()), reinterpret_cast<fftw_complex*>(output_sig.data()), FFTW_BACKWARD, FFTW_ESTIMATE);

    fftw_execute(plan);
    fftw_destroy_plan(plan);
    return output_sig;
}

vector<doubleC> FFTW3_Class::Fft_R2C(const vector<double>& input, const int& nfft) {
    vector<doubleC> input_comp(nfft);
    for (int i{}; i < (int)input_comp.size(); ++i) {
        if (i < (int)input.size())
            input_comp[i].real(input[i]);
    }

    std::vector<doubleC> output_sig(nfft);

    fftw_plan plan = fftw_plan_dft_1d(nfft, reinterpret_cast<fftw_complex*>(input_comp.data()),
                                          reinterpret_cast<fftw_complex*>(output_sig.data()),
                                          FFTW_FORWARD, FFTW_ESTIMATE);

    fftw_execute(plan);
    fftw_destroy_plan(plan);
    return output_sig;
}

# Pwelch C++ Implementation

## Overview

This repository contains a C++ implementation of the Welch Power Spectral Density (PSD) estimation using the FFTW3 library. 

## Dependencies
Make sure you have the FFTW3 library installed. You can find more information about FFTW3 [here](https://fftw.org).

## Usage
### Pwelch Class
The Pwelch class is the core of this implementation. It includes a function Pwelch_process with the following parameters:

- input: The input signal represented as std::complex<double>.
- 
- w: the size of window
- 
- overlap: Number of overlapping samples between segments.
- 
- nfft: Number of points for the FFT.
- 
- windowtype: Type of window function to be applied (hamming or hanning).
- 

### Example

<pre>```c++
#include <iostream>
#include "Pwelch.h"
  
int main()
{
    vector<doubleC> inp(8192);
    readBinary("C:\\Users\\Hosein\\Desktop\\rand.bin", inp.data(), inp.size());
    Pwelch pwelch;
    vector<double> pxx = pwelch.Pwelch_Process(inp, 512, 256, 1024, WindowType::hamming);
    int X = 2;
}```
</pre>


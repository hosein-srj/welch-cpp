# Pwelch C++ Implementation

## Overview

This repository contains a C++ implementation of the Welch Power Spectral Density (PSD) estimation using the FFTW3 library. 

## Dependencies
Make sure you have the FFTW3 library installed. You can find more information about FFTW3 [here](https://fftw.org).

## Usage
### Pwelch Class
The Pwelch class is the core of this implementation. It includes a function Pwelch_process with the following parameters:

input: The input signal represented as std::complex<double>.
w: the size of window
nfft: Number of points for the FFT.
overlap: Number of overlapping samples between segments.
windowtype: Type of window function to be applied (hamming or hanning).

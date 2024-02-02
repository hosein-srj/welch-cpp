# Pwelch C++ Implementation

## Overview

This repository contains a C++ implementation of the Welch Power Spectral Density (PSD) estimation using the FFTW3 library.

## Dependencies
Make sure you have the FFTW3 library installed. You can find more information about FFTW3 [here](https://fftw.org).

Download fftw from website and place in  Pwelch folder.

## Usage
### Pwelch Class
The Pwelch class is the core of this implementation. It includes a function Pwelch_process with the following parameters:

- input: The input signal represented as std::complex<double>.
  
- w: the size of window
  
- overlap: Number of overlapping samples between segments.
  
- nfft: Number of points for the FFT.
  
- windowtype: Type of window function to be applied (hamming or hanning).


### Example

```c++
#include <iostream>
#include "Pwelch.h"
  
int main()
{
     //Load your input
    vector<doubleC> inp(8192);
    int w = 512;
    int overlap = 256;
    int nfft = 1024;
    Pwelch pwelch;
    vector<double> pxx = pwelch.Pwelch_Process(inp, w, overlap, nfft, WindowType::hamming);
    
}
```

## Building
1. Open the project in Visual Studio.
2. Configure the project settings if needed.
3. Build the project using the "Build" menu or by pressing `Ctrl + Shift + B`.
4. Run the executable generated in the output directory or run in Visual Studio.
5. make sure that libfftw3-3.dll is in project directory

## Contributing
Feel free to contribute to this project by submitting issues or pull requests. Your feedback and contributions are highly appreciated.

## License

This project is licensed under the GNU General Public License v3.0 - see the [LICENSE](LICENSE) file for details.


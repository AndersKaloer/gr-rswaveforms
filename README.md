# gr-rswaveforms
GNURadio sink that creates Rohde & Schwarz SMU waveform files (.wv) for R&S signal generators (e.g. SMU, SMBV).

See `examples/cosine.grc` for a simple example.

## Installation:
```
mkdir build
cd build
cmake ..
make
sudo make install
sudo ldconfig
```

You must have `LD_LIBRARY_PATH` set to include the directory under which the
module is installed (in many cases `/usr/local/lib`).

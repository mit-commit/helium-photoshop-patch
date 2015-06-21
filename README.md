This repository contains the code necessary to build the patch DLL used for in situ replacement of Photoshop filters with [Helium](https://github.com/CharithYMendis/Helium)-lifted replacements, as described in section 6.5 of the [Helium PLDI 2015 paper](http://groups.csail.mit.edu/commit/papers/2015/mendis-pldi15-helium.pdf).

To build, run `./configure.py > Makefile`, then run `nmake`.  After Photoshop finishes initializing, inject combineddll.dll (with a tool such as [Process Hacker](http://processhacker.sourceforge.net/)).  Then use the Photoshop filters as normal -- the patch will redirect execution to the Helium-lifted implementations.

The Helium outputs in photoshop_*.cpp have been pretty-printed and scheduled using an autotuner, as described in the paper.

The Add Noise patch does not work, due to a problem with the patch code and/or a problem with Helium (see [Helium #10](https://github.com/CharithYMendis/Helium/issues/10)).

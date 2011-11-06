Nabaztag Tools
==============

This is a copy of the Nabaztag tools that has been patched to compile under Mac OS X along with the source to the standard Nabaztag firmware.

Compiling
=========

To compile the mtl compiler go into the `compiler` directory and type

    make

Once the mtl compiler has been compiled it is then possible to compile the Nabaztag firmware using the scripts provided in the `bc-nominal/nominal_splitted` directory.

    test_compile.sh

This will produce a file called `bootcode.bin` which should then be able to be used with a Nabaztag rabbit.



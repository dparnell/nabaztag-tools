Nabaztag Tools
==============

This is a copy of the Nabaztag tools that has been patched to compile under Mac OS X along with the source to the standard Nabaztag firmware.
I have also updated the simulator to have the start of a UI that shows the state of the LEDs on the rabbit.

![The Simulator](http://blog.danielparnell.com/wp-content/uploads/20120329114317_image.jpg)

Compiling
=========

To compile the mtl compiler go into the `compiler` directory and type

    make

Once the mtl compiler has been compiled it is then possible to compile the Nabaztag firmware using the scripts provided in the `bc-nominal/nominal_splitted` directory.

    test_compile.sh

This will produce a file called `bootcode.bin` which should then be able to be used with a Nabaztag rabbit.

Running the simulator
=====================

The simulator can be run using the `test_sim.sh` script in the `bc-nominal/nominal_splitted` directory.
You will also need to copy the `conf.bin` file from the `compiler` directory the `bc-nominal/nominal_splitted` and edit it with a hex editor to point to your Nabaztag server.
Running the script invokes the compiler, then you will need press enter a couple of times to skip past the information it spits out.  You should then see your firmware running in the simulator :)


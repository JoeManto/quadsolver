## Source Directory for Quadsolver.

This directory includes the following C and header files:

### getInput.c
This file is responsible for reading user input and tokenizing it into the proper buffers.
The input will also be checked for flags for things like help, logging, and exiting the program.
The floating point values entered by the user will also be checked for INFs, NaNs, and other bad input values.

### getInput.h
The header file that contains function declarations for getInput.c.

### quadsolver.c
The driver file for the program.
This file will print getting started information to the user.
This file will then solve the quadratic according to specifications provided by J.K.K consulting.

### quadsolver.h
The header file that contains function declarations for quadsolver.c.

README for Quadsolver for CS 4900
------------------------Authors---------------------------
Jared Teller - jared.e.teller@wmich.edu
Joe Manto - joe.m.manto@wmich.edu
__________________________________________________________

------------------------Client----------------------------
J.K.K. Consulting.
__________________________________________________________

---------------------Specifications-----------------------
This program will take in user input as follows:
"a b c" where a,b, and c are floating point numbers. The
quadratic equation (-b +- sqrt(b*b-4ac)) / 2a will be
computed and output to the user. Proper warnings will be
given for bad input.
__________________________________________________________

-------------Compile and Run Instructions-----------------
To run the core program use "make quad" which will run the
executable ./quadsolver and start prompting for user
input. To create the executable run "make".
__________________________________________________________

---------------------Version Control----------------------
Git was used for version control of the program and 
allowed for effective pair programming. All tests must 
pass before any change is made to the program.
__________________________________________________________

-------------------------Standards------------------------
We decided to use the C11 standard for gcc. 
The program will be run with Make instructions like -Wall 
-pedantic.
__________________________________________________________

-----------------------Testing----------------------------
See readme.txt in the testing directory for more
information.
__________________________________________________________

-----------------------License----------------------------
Licensed under GNU General Public License. See LICENSE.txt
for more information.
__________________________________________________________
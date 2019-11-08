## Quadsolver v1 for CS 4900
### Authors
Jared Teller - jared.e.teller@wmich.edu
Joe Manto - joe.m.manto@wmich.edu
__________________________________________________________

### Client
J.K.K. Consulting. - john.kapenga@wmich.edu
__________________________________________________________

### Specifications
This program will take in user input as follows:
"a b c" where a,b, and c are floating point numbers. The
quadratic equation (-b +- sqrt(b*b-4ac)) / 2a will be
computed and output to the user. Proper warnings will be
given for bad input.
__________________________________________________________

### Compile and Run Instructions
To run the core program use "make quad" which will run the
executable ./quadsolver and start prompting for user
input. To create the executable run "make".
__________________________________________________________

### Automation

We used a make file for Automation to create a consistent compiling and linking experience.
Our make file handles all the of the following
-   compiling and linking the correct object files for quadsolver
-   compiling and assembling all the spikes
-   compiling,linking,and assembling all unit tests
-   compiling,linking, and assembling all the system tests
__________________________________________________________

### Version Control
Git was used for version control of the program and 
allowed for effective pair programming. All tests must 
pass before any change is made to the program.

Git Commands:
    - `git add -A`
    - `git commit -m "message"`
    - `git push <remote> master`
__________________________________________________________

### Standards
We decided to use the C11 standard for gcc. 
The program will be run with Make instructions like `-Wall 
-pedantic`.
__________________________________________________________

### Testing
To run all unit tests do:
- `make unit`

- `./unit all  or make test-unit`
    
To run all system tests do:
    make system
- `./system  or make test-system`

See readme in the testing directory for more
information.
__________________________________________________________

### License
Licensed under GNU General Public License. See LICENSE.txt
for more information.
__________________________________________________________
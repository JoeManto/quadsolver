### Testing Standards
Tests will be automated using **Make**.
All tests will need to pass before any push is made in version control.

##### Running Tests
To run all unit tests at once:
-   `make unit`
-   `./unit all`

To run system test:
-   `make system`
-   `./system  or make test-system`

Unit tests were created for every function with input and output in the project.

Testing directory contains the following sub directories:

- Unit:
        unitTests.c - Runs test functions on quadsolver.c and getInput.c
        linkerQuadSolver - Helps link some functions from quadsolver to our testing C files

-   System:
        systemTests.c - Runs test functions on the overall system (solving the quadratic)


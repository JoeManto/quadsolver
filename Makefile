#build quadsolver exc
all:
	gcc -Wall -Wpedantic -std=c11 src/*.c -g -o quadsolver

#run quadsolver exc
quad:
	./quadsolver

#build spikes 
spikeCreate:
	gcc -Wall -Wpedantic -std=c11 spikes/*.c -g -o spike

#run spike exc
spike:
	./spike

#build unit tests exc
unit:
	gcc -Wall -Wpedantic -std=c11 testing/linkerQuadSolver.c testing/unit/*.c src/getInput.c -g -o unit 

#run unit tests
test-unit:
	./unit all

#build system tests exc
system:
	gcc -Wall -Wpedantic -std=c11 testing/linkerQuadSolver.c testing/system/*.c src/getInput.c -g -o system

#run system tests
test-system:
	./system

#clean all object and exc files
clean:
	rm -f src/*.o spikes/*.o all quadsolver spike system unit
	rm -rf *.dSYM

export:
	tar -czvf quadsolverv1.tar.gz .

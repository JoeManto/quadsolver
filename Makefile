all:
	gcc -Wall -Wpedantic -std=c11 src/*.c -g -o quadsolver

quad:
	./quadsolver

clean:
	rm -f src/*.o all quadsolverexc

all:
	gcc -Wall -Wpedantic -std=c11 src/*.c -g -o quadsolver

quad:
	./quadsolver

spikeCreate:
	gcc -Wall -Wpedantic -std=c11 spikes/*.c -g -o spike

spike:
	./spike

clean:
	rm -f src/*.o spikes/*.o all quadsolver spike

all:
	cc -Wall lista.c -o lista

.PHONY run:
run:
	./main

.PHONY clean:
clean:
	rm -f main
	clear
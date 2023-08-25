all:
	cc -Wall lista.c -o lista

.PHONY run:
run:
	./lista

.PHONY clean:
clean:
	rm -f lista
	clear
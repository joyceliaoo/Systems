all: main.o sieve.o
	gcc -g main.o sieve.o -lm

main.o: main.c sieve.h
	gcc -c -g main.c

sieve.o: sieve.c sieve.h
	gcc -c -g sieve.c

run:
	./a.out

clean:
	rm -rf *.o


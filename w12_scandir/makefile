all: main.o scanner.o
	gcc main.o scanner.o

main.o: main.c scanner.h
	gcc -c main.c

scanner.o: scanner.c scanner.h
	gcc -c scanner.c

run: all
	./a.out

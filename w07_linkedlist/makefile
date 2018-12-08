all: main.o linkedlist.o
	gcc linkedlist.o main.o

main.o: main.c linkedlist.h
	gcc -c main.c

linkedlist.o: linkedlist.c linkedlist.h
	gcc -c linkedlist.c

run:
	./a.out

clean:
	rm -rf main.o linkedlist.o


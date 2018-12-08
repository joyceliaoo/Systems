all: song.o library.o main.o
	gcc -o music song.o library.o main.o

main.o: main.c library.h song.h
	gcc -c main.c

song.o: song.c song.h
	gcc -c song.c

library.o: library.c library.h song.h
	gcc -c library.c

run:
	./music

clean:
	rm -rf *.o

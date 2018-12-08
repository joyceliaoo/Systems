all: strfun.o mainstr.o
	gcc strfun.o mainstr.o

strfun.o: strfun.c strfun.h
	gcc -c strfun.c

mainstr.o: mainstr.c strfun.h
	gcc -c mainstr.c

run:
	./a.out

clean:
	rm -rf strfun.o mainstr.o


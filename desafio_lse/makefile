# Makefile, para run, comando: make
all: main

main: main.o
	gcc main.o -o prog.exe

main.o: main.c lse.h
	gcc -c main.c -o main.o

clean:
	rm -f *.o *.exe
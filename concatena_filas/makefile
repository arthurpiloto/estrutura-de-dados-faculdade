# Makefile, para run, comando: make
all: main

main: main.o
	gcc main.o -o prog.exe

main.o: main.c fila_estatica.h
	gcc -c main.c -o main.o

# main.o: main.c fila_dinamica.h
# 	gcc -c main.c -o main.o

clean:
	rm -f *.o *.exe
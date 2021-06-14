#This is makefile yeaah
CC=clang
CFLAGS=-I.
truc: main.c 
	$(CC) -o truc  -Wall -static  main.c
	
truc_o: main.o 
	$(CC) -o truc  -Wall -static  main.c

clean:
	rm -f truc main.o 


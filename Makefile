CFLAGS=-g3 -Og 
main: hashtable.o conjunto.o main.c 

clean: 
	rm *.o main

run:
	./main

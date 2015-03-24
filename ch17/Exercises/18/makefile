inventory: inventory.o readline.o
	gcc -o inventory.out inventory.o readline.o

inventory.o: inventory.c readline.h
	gcc -c inventory.c

readline.o: readline.c readline.h
	gcc -c readline.c

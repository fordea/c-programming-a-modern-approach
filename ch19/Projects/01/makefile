stackclient: stackclient.o stack.o
	gcc -o stackclient.out stackclient.o stack.o

stackclient.o: stackclient.c stack.h
	gcc -c stackclient.c

stack.o: stack.c stack.h
	gcc -c stack.c

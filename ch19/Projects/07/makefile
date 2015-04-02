queueclient: queueclient.o queueADT.o
	gcc -o queueclient.out queueclient.o queueADT.o

queueclient.o: queueclient.c queue.h
	gcc -c queueclient.c

queueADT.o: queueADT.c queue.h
	gcc -c queueADT.c

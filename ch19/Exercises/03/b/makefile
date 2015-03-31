queueclient: queueclient.o queue.o
	gcc -o queueclient.out queueclient.o queue.o

queueclient.o: queueclient.c queue.h
	gcc -c queueclient.c

queue.o: queue.c queue.h
	gcc -c queue.c

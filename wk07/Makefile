CC=gcc
CFLAGS=-g

q6: q6.o graph.o
	$(CC) q6.o graph.o -o q6

q6.o: q6.c graph.h
	$(CC) $(CFLAGS) q6.c -o q6.o -c

graph.o: graph.c graph.h
	$(CC) $(CFLAGS) graph.c -o graph.o -c
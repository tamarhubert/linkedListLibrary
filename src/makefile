CC=gcc
CFLAGS=-I .
DEPS = LinkedList.h

%.o: %.c $(DEPS)
	$(CC) -c -o ../obj/$@ $< $(CFLAGS)

make: LinkedList.o

CC=gcc
CFLAGS=-I.
DEPS = LinkedList.h

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

make: LinkedList.o

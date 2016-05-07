CC=gcc
CFLAGS=-I.
DEPS = LinkedList.h

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

make: LinkedListTests.o
	cd .. && $(MAKE)
	$(CC) -o LinkedListTests LinkedListTests.o

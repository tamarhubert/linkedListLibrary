CC=gcc
CFLAGS=-I.
DEPS = ../src/LinkedList.h

%.o: %.c $(DEPS)
	$(CC) -c -o ../obj/$@ $< $(CFLAGS)

make: LinkedListTests.o
	cd ../src && $(MAKE)
	$(CC) -o ../obj/LinkedListTests ../obj/LinkedListTests.o ../obj/LinkedList.o

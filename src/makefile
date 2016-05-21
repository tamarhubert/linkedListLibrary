CC=gcc
CFLAGS=-I . -g
DEPS = linkedList.h

%.o: %.c $(DEPS)
	$(CC) -c -fPIC -o ../obj/$@ $< $(CFLAGS)

make: linkedList.o

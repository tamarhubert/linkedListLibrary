CC=gcc
CFLAGS=-I . -g
DEPS = linkedList.h

OBJ=../obj
LIB=../lib

%.o: %.c $(DEPS)
	$(CC) -c -fPIC -o $(OBJ)/$@ $< $(CFLAGS)

make: linkedList.o $(LIB)/threadingProcessingLibrary/obj/threadingProcessingLibrary.o

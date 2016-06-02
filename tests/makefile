CC=gcc
CFLAGS=-I. -g
DEPS = ../src/linkedList.h

LIB=../lib

%.o: %.c $(DEPS)
	$(CC) -c -o ../obj/$@ $< $(CFLAGS)

make: linkedListTests.o
	cd ../src && $(MAKE)
	$(CC) -o ../obj/linkedListTests \
	../obj/linkedListTests.o ../obj/linkedList.o \
	$(LIB)/threadingProcessingLibrary/obj/threadingProcessingLibrary.o \
	-lpthread

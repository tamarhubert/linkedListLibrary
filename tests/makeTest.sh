cd ..
gcc -Wall -c LinkedList.c
cd tests
gcc -Wall -c LinkedListTests.c
gcc -Wall -o LinkedListTests LinkedListTests.o ../LinkedList.o
./LinkedListTests

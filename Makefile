tests: test-stack.out test-queue.out list.o btree.o
#### libs ####
stack.o: stack.c stack.h
	gcc -c -o stack.o stack.c
queue.o:
	gcc -c -o queue.o queue.c
list.o:
	gcc -c -o list.o list.c
btree.o:
	gcc -c -o btree.o btree.c

#### tests ####	
test-stack.out: stack.o test-stack.c
	gcc -o test-stack.out test-stack.c stack.o
test-queue.out: queue.o test-queue.c
	gcc -o test-queue.out test-queue.c queue.o

#### misc ####
clean:
	rm -f *.o *.out
check:
	valgrind ./test-stack.out
	valgrind ./test-queue.out

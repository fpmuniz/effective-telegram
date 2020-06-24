tests: test-stack.out queue.o list.o btree.o
test-stack.out: stack.o test-stack.c
	gcc -o test-stack.out test-stack.c stack.o
stack.o: stack.c stack.h
	gcc -c -o stack.o stack.c
queue.o:
	gcc -c -o queue.o queue.c
list.o:
	gcc -c -o list.o list.c
btree.o:
	gcc -c -o btree.o btree.c
clean:
	rm -f *.o *.out
check:
	valgrind ./test-stack.out

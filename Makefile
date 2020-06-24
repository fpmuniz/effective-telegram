tests: test-stack.out test-queue.out test-list.out test-btree.out

#### libs ####
slcell.o: slcell.h slcell.c
	gcc -c -o slcell.o slcell.c
dlcell.o: dlcell.h dlcell.c
	gcc -c -o dlcell.o dlcell.c
bnode.o: bnode.h bnode.c
	gcc -c -o bnode.o bnode.c
stack.o: stack.c stack.h
	gcc -c -o stack.o stack.c
queue.o: queue.c queue.h
	gcc -c -o queue.o queue.c
list.o: list.c list.h
	gcc -c -o list.o list.c
btree.o: btree.c btree.h
	gcc -c -g -o btree.o btree.c

#### tests ####	
test-stack.out: stack.o test-stack.c slcell.o
	gcc -o test-stack.out test-stack.c stack.o slcell.o
test-queue.out: queue.o test-queue.c slcell.o
	gcc -o test-queue.out test-queue.c queue.o slcell.o
test-list.out: list.o test-list.c dlcell.o
	gcc -o test-list.out test-list.c list.o dlcell.o
test-btree.out: btree.o test-btree.c bnode.o
	gcc -g -o test-btree.out test-btree.c btree.o bnode.o

#### misc ####
clean:
	rm -f *.o *.out vgcore.*
check:
	valgrind ./test-stack.out
	valgrind ./test-queue.out
	valgrind ./test-list.out
	valgrind ./test-btree.out
	./test-btree.out | diff - test-btree.txt

main: main.c sum.o sub.o
	gcc main.c sum.o sub.o -o main
sum.o: sum.c sum.h
	gcc -c sum.c
sub.o: sub.c sub.h
	gcc -c sub.c
clean:
	rm *.o main
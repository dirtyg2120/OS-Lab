all: main.c findsubstr.o readline.o
	gcc main.c findsubstr.o readline.o -o mygrep
findsubstr.o: findsubstr.c findsubstr.h
	gcc -c findsubstr.c
readline.o: readline.c readline.h
	gcc -c readline.c
clean:
	rm *.o mygrep

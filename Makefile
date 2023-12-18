COMPILER=clang
OPTIONS=-pedantic -Wall -Werror
COMPILE=$(COMPILER) $(OPTIONS)

all: program

program: main.c arrays.o rk45.o
	$(COMPILE) main.c arrays.o rk45.o -o program

numVector.o: arrays.c arrays.h
	$(COMPILE) -c arrays.c -o arrays.o

runge.o: rk45.c rk45.h
	$(COMPILE) -c rk45.c -o rk45.o

clean:
	rm -f *.o program



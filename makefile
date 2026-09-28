#modify this makefile so that it will work for this new assignment
CC = g++

all: a.out

a.out: main.o loanCalc.o
	$(CC) -std=c++11 main.o loanCalc.o -o a.out

main.o: main.cpp loanCalc.h
	$(CC) -std=c++11 -c main.cpp

loanCalc.o: loanCalc.cpp loanCalc.h
	$(CC) -std=c++11 -c loanCalc.cpp

clean:
	rm -f *.o a.out

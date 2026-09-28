#modify this makefile so that it will work for this new assignment
CC = g++

all: 14

14: loanCalc.cpp
	$(CC) -std=c++11 loan.cpp -o 14

clean:
	rm -f 14 *.o

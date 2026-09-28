#modify this makefile so that it will work for this new assignment
CC = g++

all: loan

loan: loan.o main.o
	$(CC) -std=c++11 loan.o main.o -o a.out

loan.o: loan.cpp
	$(CC) -std=c++11 -c loan.cpp

main.o: main.cpp
	$(CC) -std=c++11 -c main.cpp

clean:
	rm -f *.o a.out

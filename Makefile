CC=g++
CFLAGS=-Wall -g

all: main main.o TicTacToe.o
	
main: main.o TicTacToe.o
	$(CC) $(CFLAGS) main.o TicTacToe.o -o main

main.o: main.cpp TicTacToe.cpp
	$(CC) $(CFLAGS) -c main.cpp

TicTacToe.o: TicTacToe.cpp
	$(CC) $(CFLAGS) -c TicTacToe.cpp

clean:
	rm -f *o main

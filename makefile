all: Minesweeper.cpp main.cpp
	g++ -g Minesweeper.o main.o -o Minesweeper

Minesweeper: Minesweeper.cpp
	g++ -g -c Minesweeper.cpp

main: main.cpp
	g++ -g -c main.cpp

clean:
	rm -f Minesweeper
	rm -f *.o
	rm -f *~
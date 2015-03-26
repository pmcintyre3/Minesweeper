all: Minesweeper.o main.o
	g++ -g Minesweeper.o main.o -o Minesweeper

Minesweeper.o: Minesweeper.cpp
	g++ -g -c Minesweeper.cpp

main.o: main.cpp
	g++ -g -c main.cpp

clean:
	rm -f Minesweeper
	rm -f *.o
	rm -f *~
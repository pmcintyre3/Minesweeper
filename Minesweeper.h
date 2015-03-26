#ifndef MINESWEEPER_H
#define MINESWEEPER_H

#include <vector>

class Minesweeper {
 private:
  int row, col, numMines;
  int isNoFogOn;
  std::vector< std::vector<char> > gameBoard;
  std::vector< std::vector<int> > mineBoard;
  std::vector< std::pair<int, int> > nF;
 public:
  Minesweeper(int, int, int, std::vector<std::vector <int > >);

  void noFog();

  int getNumRows();
  int getNumCols();
  int getNumMines();
  char getNumAdjMines(int, int, int);

  void setNumRows(int);
  void setNumCols(int);
  void setNumMines(int);
  
  std::string prompt();
  
  int isInBounds(int, int);
  void display();
  void mark(int, int);
  void guess(int, int);
  void reveal(int, int);
  int numTilesLeft();
  void run();
}; //Minesweeper

#endif

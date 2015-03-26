#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>

//#include <stdio>

#include "Minesweeper.h"

using namespace std;

int main(int argc, char* argv[]) {
  
  //check number of arguments
  if(argc > 2 || argc < 2)
    {
      cout << "Incorrect number of arguments" << endl;
      exit(-1);
    } //if
  
  //get mine coordinates
  vector<pair <int, int> > mineCoords;

  string line;
  int row, col;
  int numMines;

  unsigned int i = 0, j = 0, k = 0;
  
  //get seed file
  ifstream seed;
  seed.open(argv[1]);


  if(seed.is_open()){
    while(getline(seed, line)) {      
      istringstream t (line);  
      
      int a = 0, b = 0;
      
      ++j;
      if(j == 1) {
	if(t >> row >> col)
	  continue;
	else {
	  cout << "Cannot create game with " << argv[1] << " because it is not formatted correctly" << endl;
	  exit(0);
	}
      } //if
      else if(j == 2) {
	if(t >> numMines)
	  continue;
	else{
	  cout << "Cannot create game with " << argv[1] << " because it is not formatted correctly" << endl;
	  exit(0);
	}

      } //else if
      else if(j < (numMines + 3)) {
	if(t >> a >> b)	
	  mineCoords.push_back(make_pair(a,b));
	else {
	  cout << "Cannot create game with " << argv[1] << " because it is not formatted correctly" << endl;
	  exit(0);
	}
      } //else if
      else if(j > (numMines + 3)){
	cout << "Cannot create game with " << argv[1] << " because it is not formatted correctly" << endl;
	exit(0);
      } //else if
      else
	break;
    } //while
  } //if

  seed.close();


  //Create the mine board
  vector< vector<int> > mines (row, vector<int> (col, 0));
  k = 0;
  for(i = 0; i < (row); i++) {
    for(j = 0; j < (col); j++) {
      if(i == mineCoords[k].first) {
	if(j == mineCoords[k].second) {
	  mines[i][j] = 1;
	  k++;
	} //if
	else{
	  mines[i][j] = 0;
	}
      } //if
    } //for
  } //for

  cout << "        _" << endl;
  cout << "  /\\/\\ (_)_ __   ___  _____      _____  ___ _ __   ___ _ __ " << endl;
  cout << " /    \\| | '_ \\ / _ \\/ __\\ \\ /\\ / / _ \\/ _ \\ '_ \\ / _ \\ '__| " << endl;
  cout << "/ /\\/\\ \\ | | | |  __/\\__ \\  V  V /  __/  __/ |_) |  __/ |" << endl;
  cout << "\\/    \\/_|_| |_|\\___||___/ \\_/\\_/ \\___|\\___| .__/ \\___|_|" << endl;
  cout << "                                 RECURSIVE |_| EDITION" << endl;

  if(row > 10 || col > 10){
    cout << "ಠ_ಠ says, \"Cannot create a minefield with that many rows and/or columns!\" " << endl;
    exit(0);
  }
  // create game board
  Minesweeper game(row, col, numMines, mines);

  //run it
  game.run();

  //hope this works!
  return EXIT_SUCCESS;

} //main

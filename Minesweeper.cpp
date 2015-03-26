#include <cstdlib>
#include <iostream>
#include <vector>
#include <sstream>
#include "Minesweeper.h"

using namespace std;

Minesweeper::Minesweeper(int r, int c, int nm, vector< vector<int> > mines) : row(r), col(c), numMines(nm), gameBoard(row, vector<char>(col, ' ')), mineBoard(mines){
  
  isNoFogOn = 0;

  for(int l = 0; l < row; l++){
    for(int m = 0; m < col; m++){
      if(mineBoard[l][m] == 1)
	nF.push_back(make_pair(l,m));
    } 
  }

} //Minesweeper

void Minesweeper::noFog() {
  if(isNoFogOn == 0)
    isNoFogOn = 1;
  else
    isNoFogOn = 0;
} //noFog

int Minesweeper::getNumRows(){
  return row;
} //getNumRows

int Minesweeper::getNumCols(){
  return col;
} //getNumCols

int Minesweeper::getNumMines(){
  return numMines;
} //getNumMines

char Minesweeper::getNumAdjMines(int a, int b, int numCheckedLeft){
  int x, y;
  int i, j;

  int coordInBounds = 0;
  int offsetInBounds = 0;
  int dispInBounds = 0;
  char count = '0';

  coordInBounds = isInBounds(a,b);

  if(coordInBounds == 1) {
    if(numCheckedLeft == 9){
      x = (a-1);
      y = (b-1);      
      for(i = (x - 1); i <= (x + 1); i++) {
	for(j = (y - 1); j <= (y + 1); j++){
	  offsetInBounds = isInBounds(i,j);
	  if(offsetInBounds == 1){
	    if(mineBoard[i][j] == 1){
	      count++;
	    } //if mineBoard
	    else
	      continue;
	  } //if isInBounds
	  else
	    continue;
	} //for
      } //for
      dispInBounds = isInBounds(x,y);
      if(dispInBounds == 1)
	gameBoard[x][y] = count;
    } //if

    if(numCheckedLeft == 8){
      x = (a-1);
      y = (b);      
      for(i = (x - 1); i <= (x + 1); i++) {
	for(j = (y - 1); j <= (y + 1); j++){
	  offsetInBounds = isInBounds(i,j);
	  if(offsetInBounds == 1){
	    if(mineBoard[i][j] == 1){
	      count++;
	    } //if mineBoard
	    else
	      continue;
	  } //if isInBounds
	  else
	    continue;
	} //for
      } //for
      dispInBounds = isInBounds(x,y);
      if(dispInBounds == 1)
      gameBoard[x][y] = count;
    } //if

    if(numCheckedLeft == 7){
      x = (a-1);
      y = (b+1);      
      for(i = (x - 1); i <= (x + 1); i++) {
	for(j = (y - 1); j <= (y + 1); j++){
	  offsetInBounds = isInBounds(i,j);
	  if(offsetInBounds == 1){
	    if(mineBoard[i][j] == 1){
	      count++;
	    } //if mineBoard
	    else
	      continue;
	  } //if isInBounds
	  else
	    continue;
	} //for
      } //for
      dispInBounds = isInBounds(x,y);
      if(dispInBounds == 1)
      gameBoard[x][y] = count;
    } //if
    if(numCheckedLeft == 6){
      x = (a);
      y = (b-1);      
      for(i = (x - 1); i <= (x + 1); i++) {
	for(j = (y - 1); j <= (y + 1); j++){
	  offsetInBounds = isInBounds(i,j);
	  if(offsetInBounds == 1){
	    if(mineBoard[i][j] == 1){
	      count++;
	    } //if mineBoard
	    else
	      continue;
	  } //if isInBounds
	  else
	    continue;
	} //for
      } //for
      dispInBounds = isInBounds(x,y);
      if(dispInBounds == 1)
      gameBoard[x][y] = count;
    } //if
    if(numCheckedLeft == 5){
      x = (a);
      y = (b+1);      
      for(i = (x - 1); i <= (x + 1); i++) {
	for(j = (y - 1); j <= (y + 1); j++){
	  offsetInBounds = isInBounds(i,j);
	  if(offsetInBounds == 1){
	    if(mineBoard[i][j] == 1){
	      count++;
	    } //if mineBoard
	    else
	      continue;
	  } //if isInBounds
	  else
	    continue;
	} //for
      } //for
      dispInBounds = isInBounds(x,y);
      if(dispInBounds == 1)
      gameBoard[x][y] = count;
    } //if
    if(numCheckedLeft == 4){
      x = (a+1);
      y = (b-1);      
      for(i = (x - 1); i <= (x + 1); i++) {
	for(j = (y - 1); j <= (y + 1); j++){
	  offsetInBounds = isInBounds(i,j);
	  if(offsetInBounds == 1){
	    if(mineBoard[i][j] == 1){
	      count++;
	    } //if mineBoard
	    else
	      continue;
	  } //if isInBounds
	  else
	    continue;
	} //for
      } //for
      dispInBounds = isInBounds(x,y);
      if(dispInBounds == 1)
	gameBoard[x][y] = count;
    } //if
    if(numCheckedLeft == 3){
      x = (a+1);
      y = (b);      
      for(i = (x - 1); i <= (x + 1); i++) {
	for(j = (y - 1); j <= (y + 1); j++){
	  offsetInBounds = isInBounds(i,j);
	  if(offsetInBounds == 1){
	    if(mineBoard[i][j] == 1){
	      count++;
	    } //if mineBoard
	    else
	      continue;
	  } //if isInBounds
	  else
	    continue;
	} //for
      } //for
      dispInBounds = isInBounds(x,y);
      if(dispInBounds == 1)
	gameBoard[x][y] = count;
    } //if
    if(numCheckedLeft == 2){
      x = (a+1);
      y = (b+1);      
      for(i = (x - 1); i <= (x + 1); i++) {
	for(j = (y - 1); j <= (y + 1); j++){
	  offsetInBounds = isInBounds(i,j);
	  if(offsetInBounds == 1){
	    if(mineBoard[i][j] == 1){
	      count++;
	    } //if mineBoard
	    else
	      continue;
	  } //if isInBounds
	  else
	    continue;
	} //for
      } //for
      dispInBounds = isInBounds(x,y);
      if(dispInBounds == 1)
	gameBoard[x][y] = count;
    } //if
    if(numCheckedLeft > 1){
      return getNumAdjMines(a, b, (numCheckedLeft-1));
    } //if
    if(numCheckedLeft == 1){
      x = (a);
      y = (b);      
      for(i = (x - 1); i <= (x + 1); i++) {
	for(j = (y - 1); j <= (y + 1); j++){
	  offsetInBounds = isInBounds(i,j);
	  if(offsetInBounds == 1){
	    if(mineBoard[i][j] == 1){
	      count++;
	    } //if mineBoard
	    else
	      continue;
	  } //if isInBounds
	  else
	    continue;
	} //for
      } //for
      dispInBounds = isInBounds(x,y);
      if(dispInBounds == 1)
	return gameBoard[x][y] = count;
      else
	return -1; //shouldn't happen
    } //if
  } //if coordsInBounds
  else
    return -1; //shouldn't happen
} //getNumAdjMines

void Minesweeper::setNumRows(int a){
  row = a;
} //setNumRows

void Minesweeper::setNumCols(int a){
  col = a;
} //setNumCols

void Minesweeper::setNumMines(int a) {
  numMines = a;
} //setNumMines

int Minesweeper::isInBounds(int a, int b){
  int inBounds;

  if(a < 0 || b < 0 || a >= row || b >= col) {
    inBounds = 0;
  }
  else{
    inBounds = 1;
  }
  return inBounds;
} //isInBounds

void Minesweeper::display(){

  unsigned int i, j, k = 0;
  
  //print colums and rows w/ row numbers
  for(i = 0; i < (row); i++) {
    cout << i << " |";
    for(j = 0; j < (col); j++) {
      if(isNoFogOn == 0)
	cout << " "<< gameBoard[i][j] << " |";
      else if(i == nF[k].first && j == nF[k].second){
	cout << "<" << gameBoard[i][j] << ">|";
	k++;
	//	continue;
      }
      else
	cout << " "<< gameBoard[i][j] << " |";
    
    } //for
    cout << endl;
  } //for
  
  //initial indent for bottom row
  cout << "   ";
  //print column numbers
  for(k = 0; k < col; k++){
    cout << " " << k << "  ";
  }
  cout << endl << endl;
} //display

string Minesweeper::prompt() {
  string input;
    
  cout << "minesweeper$ ";
  getline(cin, input);

  return input;    
} //prompt
  
void Minesweeper::mark(int a, int b) {
  if(gameBoard[a][b] != 'F')
    gameBoard[a][b] = 'F';
  else
    gameBoard[a][b] = ' ';
} //mark

void Minesweeper::guess(int a, int b){
  if(gameBoard[a][b] != '?')
    gameBoard[a][b] = '?';
  else
    gameBoard[a][b] = ' ';
} //guess

void Minesweeper::reveal(int a, int b) {

  int inBounds;
  int numToCheck;
  inBounds = isInBounds(a,b);

  if(inBounds == 1) {
    if(mineBoard[a][b] == 1){
      gameBoard[a][b] = 'X';
      
      cout << "Oh no... You revealed a mine!" << endl;
      cout << "  __ _  __ _ _ __ ___   ___    _____   _____ _ __ " << endl;
      cout << " / _` |/ _` | '_ ` _ \\ / _ \\  / _ \\ \\ / / _ \\ '__| " << endl;
      cout << "| (_| | (_| | | | | | |  __/ | (_) \\ V /  __/ |    " << endl;
      cout << " \\__, |\\__,_|_| |_| |_|\\___|  \\___/ \\_/ \\___|_|    " << endl;
      cout << " |___/                                             " << endl;
      cout << endl;
      exit(0);
    }

  else if(mineBoard[a][b] == 0)
    {
      int coordInBounds;
      numToCheck = 1;
      gameBoard[a][b] = getNumAdjMines(a,b,numToCheck);
      
      if(gameBoard[a][b] == '0') {

	numToCheck = 9;
	gameBoard[a][b] = getNumAdjMines(a,b,numToCheck);

      } //if
    } //else if
  }//if inBounds
  else
    cout << "ಠ_ಠ  says,\"Incorrect Input!\" " << endl;
} //reveal

//get numoftilesleft without a mark or revealed to 0 to win
int Minesweeper::numTilesLeft() {
  int count = 0;

  for(int i = 0; i < row; i++) {
    for(int j = 0; j < col; j++) {
      if(gameBoard[i][j] == ' ' || gameBoard[i][j] == '?') {
	count++;
      } //if
      else if(gameBoard[i][j] == 'F'){
	if(mineBoard[i][j] == 1){
	  continue;
	} //if
	else{
	  count++;
	}//else
      }//else if
      else
	continue;
    } //for j
  } //for i
  return count;
} //isWon

void Minesweeper::run(){

  int isRunning = 1;
  static int numRounds = 0;

  while(isRunning == 1){
    string s = " ";
    string cmd = " ";
    int l = 0, m = 0;
    int a = 0, b = 0, inBounds;
    int isWon;

    cout << endl << "Rounds Completed: " << numRounds << endl << endl;

    display();

    s = prompt();
    istringstream iss(s);
    
    if(iss >> cmd){ 

      //      a = l;
      //      b = m;

      //bounds check
      
      
      //reveal
      if(cmd == "r" || cmd == "reveal") {
	if(iss >> a >> b){
	  inBounds = isInBounds(a,b);	
	  if(inBounds != 0){
	    reveal(a,b);	    
	  } //if
	} //if a >> b
	else{
	  cout << "ಠ_ಠ  says,\"Incorrect Input!\" " << endl << endl;
	}
      } //if
      
      //mark
      else if(cmd == "m" || cmd == "mark") {
	if(iss >> a >> b){
	  if(inBounds =! 0) {
	    mark(a,b);
	  } //if
	} //if a >> b
	else {
	  cout << "ಠ_ಠ  says,\"Incorrect Input!\" " << endl << endl;
	} //else
      } //else if
      
      //guess
      else if (cmd == "g" || cmd == "guess"){
	if(iss >> a >> b){
	  if(inBounds =! 0){
	    guess(a,b);
	  } //if
	} //if a >> b
	else {
	  cout << "ಠ_ಠ says: Incorrect Input!" << endl;
	} //else
      } //else if
      
      //help
      else if(cmd == "h" | cmd == "help"){
	numRounds--;
	cout << "Commands Available..." << endl;
	cout << "\t- Reveal: " << "\t r/reveal" << "\t row\t col" << endl;
	cout << "\t- Mark: " << "\t m/mark" << "\t row\t col" << endl;
	cout << "\t- Guess: " << "\t g/guess" << "\t row\t col" << endl;
	cout << "\t- Help: " << "\t h/help"<< endl;
	cout << "\t- Quit: " << "\t q/quit" << endl;
	cout << endl;
      } //else if
      
      //quit
      else if(cmd == "q" || cmd == "quit"){
	cout << " \n ლ(ಠ_ಠლ) \n Y U NO PLAY MORE? \n Bye! "  << endl;
	isRunning = 0;
      } //else if
      else if(cmd == "nofog"){
	noFog();
      }
      //default
      else {
	cout << "ಠ_ಠ  says,\"Incorrect Input!\" " << endl << endl;
      } //else if
    }//if iss >> cmd

    else
      cout << "ಠ_ಠ  says,\"Incorrect Input!\" " << endl << endl;

    numRounds++;
    
      isWon = numTilesLeft();
      if(isWon == 0){

	int score = (row * col) - numMines - numRounds;

	cout << endl;
	cout << " ░░░░░░░░░▄░░░░░░░░░░░░░░▄░░░░ \"So Doge\" " << endl;
	cout << " ░░░░░░░░▌▒█░░░░░░░░░░░▄▀▒▌░░░ " << endl;
	cout << " ░░░░░░░░▌▒▒█░░░░░░░░▄▀▒▒▒▐░░░ \"Such Score\" " << endl;
	cout << " ░░░░░░░▐▄▀▒▒▀▀▀▀▄▄▄▀▒▒▒▒▒▐░░░ " << endl;
	cout << " ░░░░░▄▄▀▒░▒▒▒▒▒▒▒▒▒█▒▒▄█▒▐░░░ \"Much Minesweeping\" " << endl;
	cout << " ░░░▄▀▒▒▒░░░▒▒▒░░░▒▒▒▀██▀▒▌░░░ " << endl;
	cout << " ░░▐▒▒▒▄▄▒▒▒▒░░░▒▒▒▒▒▒▒▀▄▒▒▌░░ \"Wow\" " << endl;
	cout << " ░░▌░░▌█▀▒▒▒▒▒▄▀█▄▒▒▒▒▒▒▒█▒▐░░ " << endl;
	cout << " ░▐░░░▒▒▒▒▒▒▒▒▌██▀▒▒░░░▒▒▒▀▄▌░ " << endl;
	cout << " ░▌░▒▄██▄▒▒▒▒▒▒▒▒▒░░░░░░▒▒▒▒▌░ " << endl;
	cout << " ▀▒▀▐▄█▄█▌▄░▀▒▒░░░░░░░░░░▒▒▒▐░ " << endl;
	cout << " ▐▒▒▐▀▐▀▒░▄▄▒▄▒▒▒▒▒▒░▒░▒░▒▒▒▒▌ " << endl;
	cout << " ▐▒▒▒▀▀▄▄▒▒▒▄▒▒▒▒▒▒▒▒░▒░▒░▒▒▐░ " << endl;
	cout << " ░▌▒▒▒▒▒▒▀▀▀▒▒▒▒▒▒░▒░▒░▒░▒▒▒▌░ " << endl;
	cout << " ░▐▒▒▒▒▒▒▒▒▒▒▒▒▒▒░▒░▒░▒▒▄▒▒▐░░ " << endl;
	cout << " ░░▀▄▒▒▒▒▒▒▒▒▒▒▒░▒░▒░▒▄▒▒▒▒▌░░ " << endl;
	cout << " ░░░░▀▄▒▒▒▒▒▒▒▒▒▒▄▄▄▀▒▒▒▒▄▀░░░ CONGRATULATIONS! " << endl;
	cout << " ░░░░░░▀▄▄▄▄▄▄▀▀▀▒▒▒▒▒▄▄▀░░░░░ YOU HAVE WON! " << endl;
	cout << " ░░░░░░░░░▒▒▒▒▒▒▒▒▒▒▀▀░░░░░░░░ SCORE: " << score << endl << endl;
      
	exit(0);
    
      } //isWon
      //    } //else if
  } //while
  exit(0);
} //run


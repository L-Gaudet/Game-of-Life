/*
Implementation of GameBoard class.
*/
using namespace std;
#include <iostream>
#include <fstream>
#include <random>
#include "GameBoard.h"

/* 
GameBoard
Default constructor for GameBoard class, creates a game board.
@param none
@return none
*/ 
GameBoard::GameBoard(){
    while(true){
        cout << "Select an option for creating the starting grid:\n 1. Provide a map file\n 2. Generate a random assignment\n Enter 1 or 2: ";
        cin >> userChoice;
        if(userChoice == 1){
            createUserGeneratedBoard();
            break;
        }
        else if(userChoice == 2){
            createRandomGeneratedBoard();
            break;
        }
        else{
            continue;
        }
    }
}

/* 
GameBoard
Copy constructor for GameBoard class, creates a game board exactly matching a given game board.
@param boardToCopy: game board that will be copied.
@return none
*/ 
GameBoard::GameBoard(const GameBoard &boardToCopy){
    rows = boardToCopy.rows;
    columns = boardToCopy.columns;

    board = new char* [rows];
    for(int i = 0; i < rows; ++i){
        board[i] = new char[columns];
    }

    for(int i=0;i<rows;i++){
        for(int j=0;j<columns;j++){
            board[i][j] = boardToCopy.board[i][j];
        }
    }
}

/* 
~GameBoard
Destructor for GameBoard class, deallocates all dynamic memory.
@param none
@return none
*/ 
GameBoard::~GameBoard(){
    for(int i=0; i < rows; i++){
        delete[] board[i];
    }
    delete[] board;
}

/* 
createRandomGenBoard
generates a random assignment for the game board.
@param none
@return void
*/ 
void GameBoard::createRandomGeneratedBoard(){
    float initialPopulationDensity = 0;
    char currentChar;
    rows = 0;
    columns = 0;

    while(!(rows > 0 && columns > 0)){
        cout << "Enter number of rows for the game board: ";
        cin >> rows;
        cout << "Enter number of columns for the game board: ";
        cin >> columns;
    }

    while(!(initialPopulationDensity > 0 && initialPopulationDensity <= 1)){
        cout << "Enter a decimal to represent the initial population density. "
                << "\n(must be greater than 0 and less than or equal to 1): ";
        cin >> initialPopulationDensity;
    }

    // create board
    board = new char* [rows];
    for(int i = 0; i < rows; ++i){
        board[i] = new char[columns];
    }

    // fill board
    srand((unsigned)time(NULL));
    for(int i=0;i<rows;i++){
        for(int j=0;j<columns;j++){
            board[i][j] = getNextSpace(initialPopulationDensity);
        }
    }
}

/* 
getNextSpace
takes a population density variable and returns a life or empty space character for the board.
@param initPopDensity: decimal representing population density 
@return returnChar: char representing either life or empty space for the game.
*/ 
char GameBoard::getNextSpace(float initPopDensity){
    char returnChar;
    float randomLifeValue = (float) (rand()%101)/100.0;

    if(randomLifeValue <= initPopDensity)
        returnChar = 'x';
    else
        returnChar = '-';
    return returnChar;
}

/* 
createUserGeneratedBoard
Imports a user created board from a file.
@param none
@return void
*/ 
void GameBoard::createUserGeneratedBoard(){
    string inputFile;
    cout << "Enter the name of the map file you would like to load: ";
    cin >> inputFile;

    processFile(inputFile);

}

/* 
processFile
takes a specified file and parses it creating the map of our game board.
@param inputFile: name of file containing a map of a board.
@return void
*/
void GameBoard::processFile(string inputFile){
    ifstream in_file;
    in_file.open(inputFile);

    in_file >> rows;
    in_file >> columns;

    // create board
    board = new char* [rows];
    for(int i = 0; i < rows; ++i){
        board[i] = new char[columns];
    }

    // fill board
    srand((unsigned)time(NULL));
    for(int i=0;i<rows;i++){
        for(int j=0;j<columns;j++){
            in_file >> board[i][j];
        }
    }

    in_file.close();
}

/* 
printBoard
prints the game board to standard io.
@param none
@return void
*/ 
void GameBoard::printBoard(){
    for(int i=0;i<rows;i++){
        for(int j=0;j<columns;j++){
            cout << board[i][j];
        }
        cout << endl;
    }
}

/* 
getCell
returns the character that occupies a specified cell.
@param row, column: specific row and column to find the cell.
@return cell: specified cell
*/
char GameBoard::getCell(int row, int column){
    char cell = board[row][column];
    return cell;
}

/* 
setCell
sets the character to occupy a specified cell.
@param row, column: specific row and column to find the cell.
@return void
*/
void GameBoard::setCell(int row, int column, char charToPlace){
    board[row][column] = charToPlace;
}

/* 
getRows
returns the value stored in the rows variable.
@param none.
@return rows
*/
int GameBoard::getRows(){
    return rows;
}

/* 
getColumns
returns the value stored in the columns variable.
@param none.
@return rows
*/
int GameBoard::getColumns(){
    return columns;
}
/*
Implementation of GameBase class.
*/
using namespace std;
#include <iostream>
#include <string>
#include "GameBase.h"

/* 
GameBase
Default constructor for GameBase class.
@param none
@return none
*/ 
GameBase::GameBase(){
    currentGen = new GameBoard();
    nextGen = new GameBoard(*currentGen);
    generationNumber = 0;
}

/* 
~GameBase
Destructor for GameBase class. Deallocates all dynamic memory.
@param none
@return none
*/ 
GameBase::~GameBase(){
    delete currentGen;
    delete nextGen;
}

/* 
processCurrentGen
Goes thru the current generation and examines the neighbors of each space.
@param none
@return none
*/ 
void GameBase::processCurrentGen(){
    for(int row = 0; row < currentGen->getRows(); row++){
        for(int column = 0; column < currentGen->getColumns(); column++){
            char charToPlace;
            switch (getNeighborCountForCell(row, column)){
            case 0:
            case 1:
                charToPlace = '-';
                nextGen->setCell(row, column, charToPlace);
                break;
            case 2:
                charToPlace = currentGen->getCell(row, column);
                nextGen->setCell(row, column, charToPlace);
                break;
            case 3:
                charToPlace = 'x';
                nextGen->setCell(row, column, charToPlace);
                break;
            default:
                charToPlace = '-';
                nextGen->setCell(row, column, charToPlace);
                break;
            }
        }
    }
    generationNumber++;
    swapBoardReferences();
}

/* 
getNeighborsForCell
returns the number of occupied neighbors a cell has.
@param row, column: specifies a cell in the board.
@return neighborCount: number of occupied cells around a specified cell.
*/ 
int GameBase::getNeighborCountForCell(int row, int column){
    int neighborCount = 0;
    if(row == 0){ // first row
        if(column == 0)
            neighborCount += topLeftCorner(row, column);
        else if(column == currentGen->getColumns()-1)
            neighborCount += topRightCorner(row, column);
        else
            neighborCount += topEdgeNotCorner(row, column);
    }
    else if (row == currentGen->getRows()-1){ // last row
        if(column == 0)
            neighborCount += bottomLeftCorner(row, column);
        else if(column == currentGen->getColumns()-1)
            neighborCount += bottomRightCorner(row, column);
        else
            neighborCount += bottomEdgeNotCorner(row, column);
    }
    else if(column == 0){ // left edge
        neighborCount += leftEdgeNotCorner(row, column);
    }
    else if(column == currentGen->getColumns()-1){ // right edge
        neighborCount += rightEdgeNotCorner(row, column);
    }
    else{
        neighborCount += getNeighborCountForCellNoEdgeCases(row, column);
    }
    return neighborCount;
}

/* 
getNeighborCountForCellNoEdgeCases
returns the number of occupied neighbors a cell has, does not account for edge cases.
@param row, column: specifies a cell in the board.
@return neighborCount: number of occupied cells around a specified cell.
*/ 
int GameBase::getNeighborCountForCellNoEdgeCases(int row, int column){
    int neighborCount = 0;
    neighborCount += isCellFilled(row-1, column-1);
    neighborCount += isCellFilled(row-1, column);
    neighborCount += isCellFilled(row-1, column+1);
    neighborCount += isCellFilled(row, column-1);
    neighborCount += isCellFilled(row, column+1);
    neighborCount += isCellFilled(row+1, column-1);
    neighborCount += isCellFilled(row+1, column);
    neighborCount += isCellFilled(row+1, column+1);
    return neighborCount;
}

/*
isCellFilled
returns if the top specified cell contains an x.
@param row, column: specifies a cell in the board.
@return 1 if cell is occupied, 0 if cell is empty.
*/
int GameBase::isCellFilled(int row, int column){
    if(currentGen->getCell(row, column) == 'x')
        return 1;
    return 0;
}

/* 
printCurrentGen
prints the current gen board to standard output
@param none.
@return void.
*/ 
void GameBase::printCurrentGen(){
    cout << "Generation: " << generationNumber << endl;
    currentGen->printBoard();
    cout << endl;
}

/* 
printNextGen
prints the next gen board to standard output
@param none.
@return void.
*/ 
void GameBase::printNextGen(){
    nextGen->printBoard();
}

/* 
isBoardStable
checks if current gen is the same as next gen.
@param none.
@return void.
*/ 
bool GameBase::isBoardStable(){
    for(int i=0; i < currentGen->getRows(); i++){
        for(int j=0;j < currentGen->getColumns();j++){
            if(!(currentGen->getCell(i, j) == nextGen->getCell(i, j)))
                return false;
        }
    }
    return true;
}

/* 
isBoardEmpty
checks to see if the board has any live cells.
@param none.
@return true if board has no live cells.
*/ 
bool GameBase::isBoardEmpty(){
    for(int i=0; i < nextGen->getRows(); i++){
        for(int j=0;j < nextGen->getColumns();j++){
            if(!(nextGen->getCell(i, j) == '-')){
                return false;
            }
        }
    }
    return true;
}

/* 
swapBoardReferences
changes currentGen to point to nextGen, and vice versa.
@param none.
@return true if board has no live cells.
*/ 
void GameBase::swapBoardReferences(){
    // fix by creating copy function
    //GameBoard* temp = new GameBoard(*currentGen);
    GameBoard* temp = currentGen;
    currentGen = nextGen;
    nextGen = temp;
    //delete currentGen;
    //currentGen = new GameBoard(*nextGen);
   // delete nextGen;
    //*nextGen = *temp;
}

/* 
stopAndWaitForEnterPress
waits for the user to press enter to exit the simulation.
@param none.
@return void.
*/ 
void GameBase::stopAndWaitForEnterPress(){
    //cin.ignore()
	string myString = "";
    while(true){
        getline(cin, myString);
        break;
    }
}

/* 
getGenerationNumber
returns the current generation number.
@param none.
@return generationNumber
*/ 
int GameBase::getGenerationNumber(){
    return generationNumber;
}

/* 
getRows
returns the number of rows in the grid.
@param none.
@return number of rows.
*/ 
int GameBase::getRows(){
    return currentGen->getRows();
}

/* 
getGenerationNumber
returns the number of columns in the grid
@param none.
@return number of columns.
*/ 
int GameBase::getColumns(){
    return currentGen->getColumns();
}

/* 
getSpecificCell
returns the character in specified cell.
@param none.
@return character of specified cell.
*/ 
char GameBase::getSpecificCell(int row, int column){
    return currentGen->getCell(row, column);
}
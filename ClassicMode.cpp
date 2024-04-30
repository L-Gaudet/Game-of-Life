/*
implementation class for ClassicMode
*/
using namespace std;
#include "ClassicMode.h"

/* 
ClassicMode
Default constructor for ClassicMode class.
@param none
@return none
*/ 
ClassicMode::ClassicMode(){}

/* 
~ClassicMode
Destructor for ClassicMode class. Deallocates all dynamic memory.
@param none
@return none
*/ 
ClassicMode::~ClassicMode(){}

/* 
topLeftCorner
top left corner boundary case for Classic Mode.
@param row, column: specifies a cell in the board.
@return neighborCount: number of live neighbors surrounding the cell
*/ 
int ClassicMode::topLeftCorner(int row, int column){
    int neighborCount = 0;
    neighborCount += isCellFilled(row, column+1);
    neighborCount += isCellFilled(row+1, column);
    neighborCount += isCellFilled(row+1, column+1);
    return neighborCount;
}

/* 
topRightCorner
top right corner boundary case for Classic Mode.
@param row, column: specifies a cell in the board.
@return neighborCount: number of live neighbors surrounding the cell
*/ 
int ClassicMode::topRightCorner(int row, int column){
    int neighborCount = 0;
    neighborCount += isCellFilled(row, column-1);
    neighborCount += isCellFilled(row+1, column-1);
    neighborCount += isCellFilled(row+1, column);
    return neighborCount;
}

/* 
bottomLeftCorner
bottom left corner boundary case for Classic Mode.
@param row, column: specifies a cell in the board.
@return neighborCount: number of live neighbors surrounding the cell
*/ 
int ClassicMode::bottomLeftCorner(int row, int column){
    int neighborCount = 0;
    neighborCount += isCellFilled(row-1, column);
    neighborCount += isCellFilled(row-1, column+1);
    neighborCount += isCellFilled(row, column+1);
    return neighborCount;
}

/* 
bottomRightCorner
bottom left corner boundary case for Classic Mode.
@param row, column: specifies a cell in the board.
@return neighborCount: number of live neighbors surrounding the cell
*/ 
int ClassicMode::bottomRightCorner(int row, int column){
    int neighborCount = 0;
    neighborCount += isCellFilled(row-1, column);
    neighborCount += isCellFilled(row-1, column-1);
    neighborCount += isCellFilled(row, column-1);
    return neighborCount;
}

/* 
topEdgeNotCorner
top edge boundary case for Classic Mode.
@param row, column: specifies a cell in the board.
@return neighborCount: number of live neighbors surrounding the cell
*/ 
int ClassicMode::topEdgeNotCorner(int row, int column){
    int neighborCount = 0;
    neighborCount += isCellFilled(row, column-1);
    neighborCount += isCellFilled(row, column+1);
    neighborCount += isCellFilled(row+1, column-1);
    neighborCount += isCellFilled(row+1, column);
    neighborCount += isCellFilled(row+1, column+1);
    return neighborCount;
}

/* 
leftEdgeNotCorner
left edge boundary case for Classic Mode.
@param row, column: specifies a cell in the board.
@return neighborCount: number of live neighbors surrounding the cell
*/ 
int ClassicMode::leftEdgeNotCorner(int row, int column){
    int neighborCount = 0;
    neighborCount += isCellFilled(row-1, column);
    neighborCount += isCellFilled(row-1, column+1);
    neighborCount += isCellFilled(row, column+1);
    neighborCount += isCellFilled(row+1, column);
    neighborCount += isCellFilled(row+1, column+1);
    return neighborCount;
}

/* 
rightEdgeNotCorner
right edge boundary case for Classic Mode.
@param row, column: specifies a cell in the board.
@return neighborCount: number of live neighbors surrounding the cell
*/ 
int ClassicMode::rightEdgeNotCorner(int row, int column){
    int neighborCount = 0;
    neighborCount += isCellFilled(row-1, column-1);
    neighborCount += isCellFilled(row-1, column);
    neighborCount += isCellFilled(row, column-1);
    neighborCount += isCellFilled(row+1, column-1);
    neighborCount += isCellFilled(row+1, column);
    return neighborCount;
}

/* 
bottomEdgeNotCorner
bottom edge boundary case for Classic Mode.
@param row, column: specifies a cell in the board.
@return neighborCount: number of live neighbors surrounding the cell
*/ 
int ClassicMode::bottomEdgeNotCorner(int row, int column){
    int neighborCount = 0;
    neighborCount += isCellFilled(row-1, column-1);
    neighborCount += isCellFilled(row-1, column);
    neighborCount += isCellFilled(row-1, column+1);
    neighborCount += isCellFilled(row, column-1);
    neighborCount += isCellFilled(row, column+1);
    return neighborCount;
}
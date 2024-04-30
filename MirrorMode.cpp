/*
implementation class for MirrorMode
*/
using namespace std;
#include "MirrorMode.h"

/* 
MirrorMode
Default constructor for MirrorMode class.
@param none
@return none
*/ 
MirrorMode::MirrorMode(){}

/* 
~MirrorMode
Destructor for MirrorMode class. Deallocates all dynamic memory.
@param none
@return none
*/ 
MirrorMode::~MirrorMode(){}

/* 
topLeftCorner
top left corner boundary case for MirrorMode.
@param row, column: specifies a cell in the board.
@return neighborCount: number of live neighbors surrounding the cell
*/ 
int MirrorMode::topLeftCorner(int row, int column){
    int neighborCount = 0;
    if(currentGen->getCell(row, column) == 'x')
        neighborCount += 3;
    neighborCount += 2 * isCellFilled(row, column+1);
    neighborCount += isCellFilled(row+1, column+1);
    neighborCount += 2 * isCellFilled(row+1, column);
    return neighborCount;
} 

/* 
topRightCorner
top right corner boundary case for MirrorMode.
@param row, column: specifies a cell in the board.
@return neighborCount: number of live neighbors surrounding the cell
*/ 
int MirrorMode::topRightCorner(int row, int column){
    int neighborCount = 0;
    if(currentGen->getCell(row, column) == 'x') 
        neighborCount += 3;
    neighborCount += 2 * isCellFilled(row, column-1);
    neighborCount += isCellFilled(row+1, column-1);
    neighborCount += 2 * isCellFilled(row+1, column);
    return neighborCount;
}

/* 
bottomLeftCorner
bottom left corner boundary case for MirrorMode.
@param row, column: specifies a cell in the board.
@return neighborCount: number of live neighbors surrounding the cell
*/ 
int MirrorMode::bottomLeftCorner(int row, int column){
    int neighborCount = 0;
    if(currentGen->getCell(row, column) == 'x') 
        neighborCount += 3;
    neighborCount += 2 * isCellFilled(row, column+1);
    neighborCount += isCellFilled(row-1, column+1);
    neighborCount += 2 * isCellFilled(row-1, column);
    return neighborCount;
} 

/* 
bottomRightCorner
bottom left corner boundary case for MirrorMode.
@param row, column: specifies a cell in the board.
@return neighborCount: number of live neighbors surrounding the cell
*/ 
int MirrorMode::bottomRightCorner(int row, int column){
    int neighborCount = 0;
    if(currentGen->getCell(row, column) == 'x') 
        neighborCount += 3;
    neighborCount += 2 * isCellFilled(row, column-1);
    neighborCount += isCellFilled(row-1, column-1);
    neighborCount += 2 * isCellFilled(row-1, column);
    return neighborCount;
}

/* 
topEdgeNotCorner
top edge boundary case for MirrorMode.
@param row, column: specifies a cell in the board.
@return neighborCount: number of live neighbors surrounding the cell
*/ 
int MirrorMode::topEdgeNotCorner(int row, int column){
    int neighborCount = 0;
    neighborCount += isCellFilled(row, column);
    neighborCount += 2 * isCellFilled(row, column+1);
    neighborCount += 2 * isCellFilled(row, column-1);
    neighborCount += isCellFilled(row+1, column-1);
    neighborCount += isCellFilled(row+1, column);
    neighborCount += isCellFilled(row+1, column+1);
    return neighborCount;
} 

/* 
leftEdgeNotCorner
left edge boundary case for MirrorMode.
@param row, column: specifies a cell in the board.
@return neighborCount: number of live neighbors surrounding the cell
*/ 
int MirrorMode::leftEdgeNotCorner(int row, int column){
    int neighborCount = 0;
    neighborCount += isCellFilled(row, column);
    neighborCount += 2 * isCellFilled(row-1, column);
    neighborCount += 2 * isCellFilled(row+1, column);
    neighborCount += isCellFilled(row-1, column+1);
    neighborCount += isCellFilled(row, column+1);
    neighborCount += isCellFilled(row+1, column+1);
    return neighborCount;
}

/* 
rightEdgeNotCorner
right edge boundary case for MirrorMode.
@param row, column: specifies a cell in the board.
@return neighborCount: number of live neighbors surrounding the cell
*/ 
int MirrorMode::rightEdgeNotCorner(int row, int column){
    int neighborCount = 0;
    neighborCount += isCellFilled(row, column);
    neighborCount += 2 * isCellFilled(row-1, column);
    neighborCount += 2 * isCellFilled(row+1, column);
    neighborCount += isCellFilled(row-1, column-1);
    neighborCount += isCellFilled(row, column-1);
    neighborCount += isCellFilled(row+1, column-1);
    return neighborCount;
} 

/* 
bottomEdgeNotCorner
bottom edge boundary case for MirrorMode.
@param row, column: specifies a cell in the board.
@return neighborCount: number of live neighbors surrounding the cell
*/ 
int MirrorMode::bottomEdgeNotCorner(int row, int column){
    int neighborCount = 0;
    neighborCount += isCellFilled(row, column);
    neighborCount += 2 * isCellFilled(row, column+1);
    neighborCount += 2 * isCellFilled(row, column-1);
    neighborCount += isCellFilled(row-1, column-1);
    neighborCount += isCellFilled(row-1, column);
    neighborCount += isCellFilled(row-1, column+1);
    return neighborCount;
}
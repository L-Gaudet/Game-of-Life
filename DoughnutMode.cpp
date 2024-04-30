/*
implementation class for DoughnutMode
*/
using namespace std;
#include "DoughnutMode.h"

/* 
DoughnutMode
Default constructor for DoughnutMode class.
@param none
@return none
*/ 
DoughnutMode::DoughnutMode(){}

/* 
~DoughnutMode
Destructor for DoughnutMode class. Deallocates all dynamic memory.
@param none
@return none
*/ 
DoughnutMode::~DoughnutMode(){}

/* 
topLeftCorner
top left corner boundary case for Doughnut Mode.
@param row, column: specifies a cell in the board.
@return neighborCount: number of live neighbors surrounding the cell
*/ 
int DoughnutMode::topLeftCorner(int row, int column){
    int neighborCount = 0;
    if(currentGen->getCell(currentGen->getRows()-1, currentGen->getColumns()-1) == 'x') // corner edge wrap diagonal
        neighborCount++;
    neighborCount += isTopEdgeNeighborFilled(row, column);
    neighborCount += isTopEdgeNeighborFilled(row, column+1);
    neighborCount += isLeftEdgeNeightborFilled(row, column);
    neighborCount += isLeftEdgeNeightborFilled(row+1, column);
    neighborCount += isCellFilled(row, column+1);
    neighborCount += isCellFilled(row+1, column+1);
    neighborCount += isCellFilled(row+1, column);
    return neighborCount;
} 

/* 
topRightCorner
top right corner boundary case for Doughnut Mode.
@param row, column: specifies a cell in the board.
@return neighborCount: number of live neighbors surrounding the cell
*/ 
int DoughnutMode::topRightCorner(int row, int column){
    int neighborCount = 0;
    if(currentGen->getCell(currentGen->getRows()-1, 0) == 'x') // corner edge wrap diagonal
        neighborCount++;
    neighborCount += isTopEdgeNeighborFilled(row, column);
    neighborCount += isTopEdgeNeighborFilled(row, column-1);
    neighborCount += isRightEdgeNeighborFilled(row, column);
    neighborCount += isRightEdgeNeighborFilled(row+1, column);
    neighborCount += isCellFilled(row, column-1);
    neighborCount += isCellFilled(row+1, column-1);
    neighborCount += isCellFilled(row+1, column);
    return neighborCount;
} 

/* 
bottomLeftCorner
bottom left corner boundary case for Doughnut Mode.
@param row, column: specifies a cell in the board.
@return neighborCount: number of live neighbors surrounding the cell
*/ 
int DoughnutMode::bottomLeftCorner(int row, int column){
    int neighborCount = 0;
    if(currentGen->getCell(0, currentGen->getColumns()-1) == 'x') // corner edge wrap diagonal
        neighborCount++;
    neighborCount += isRightEdgeNeighborFilled(row, column);
    neighborCount += isRightEdgeNeighborFilled(row-1, column);
    neighborCount += isBottomEdgeNeighborFilled(row, column+1);
    neighborCount += isBottomEdgeNeighborFilled(row, column);
    neighborCount += isCellFilled(row-1, column);
    neighborCount += isCellFilled(row-1, column+1);
    neighborCount += isCellFilled(row, column+1);
    return neighborCount;
} 

/* 
bottomRightCorner
bottom left corner boundary case for Doughnut Mode.
@param row, column: specifies a cell in the board.
@return neighborCount: number of live neighbors surrounding the cell
*/ 
int DoughnutMode::bottomRightCorner(int row, int column){
    int neighborCount = 0;
    if(currentGen->getCell(0, 0) == 'x') // corner edge wrap diagonal
        neighborCount++;
    neighborCount += isBottomEdgeNeighborFilled(row, column);
    neighborCount += isBottomEdgeNeighborFilled(row, column-1);
    neighborCount += isRightEdgeNeighborFilled(row-1, column);
    neighborCount += isRightEdgeNeighborFilled(row, column);
    neighborCount += isCellFilled(row, column-1);
    neighborCount += isCellFilled(row-1, column-1);
    neighborCount += isCellFilled(row-1, column);
    return neighborCount;
}

/* 
topEdgeNotCorner
top edge boundary case for Doughnut Mode.
@param row, column: specifies a cell in the board.
@return neighborCount: number of live neighbors surrounding the cell
*/ 
int DoughnutMode::topEdgeNotCorner(int row, int column){
    int neighborCount = 0;
    neighborCount += isTopEdgeNeighborFilled(row, column-1);
    neighborCount += isTopEdgeNeighborFilled(row, column);
    neighborCount += isTopEdgeNeighborFilled(row, column+1);
    neighborCount += isCellFilled(row, column+1);
    neighborCount += isCellFilled(row, column-1);
    neighborCount += isCellFilled(row+1, column-1);
    neighborCount += isCellFilled(row+1, column);
    neighborCount += isCellFilled(row+1, column+1);
    return neighborCount;
} 

/* 
leftEdgeNotCorner
left edge boundary case for Doughnut Mode.
@param row, column: specifies a cell in the board.
@return neighborCount: number of live neighbors surrounding the cell
*/ 
int DoughnutMode::leftEdgeNotCorner(int row, int column){
    int neighborCount = 0;
    neighborCount += isLeftEdgeNeightborFilled(row-1, column);
    neighborCount += isLeftEdgeNeightborFilled(row, column);
    neighborCount += isLeftEdgeNeightborFilled(row+1, column);
    neighborCount += isCellFilled(row-1, column);
    neighborCount += isCellFilled(row-1, column+1);
    neighborCount += isCellFilled(row, column+1);
    neighborCount += isCellFilled(row+1, column);
    neighborCount += isCellFilled(row+1, column+1);
    return neighborCount;
}

/* 
rightEdgeNotCorner
right edge boundary case for Doughnut Mode.
@param row, column: specifies a cell in the board.
@return neighborCount: number of live neighbors surrounding the cell
*/ 
int DoughnutMode::rightEdgeNotCorner(int row, int column){
    int neighborCount = 0;
    neighborCount += isRightEdgeNeighborFilled(row-1, column);
    neighborCount += isRightEdgeNeighborFilled(row, column);
    neighborCount += isRightEdgeNeighborFilled(row+1, column);
    neighborCount += isCellFilled(row-1, column);
    neighborCount += isCellFilled(row-1, column-1);
    neighborCount += isCellFilled(row, column-1);
    neighborCount += isCellFilled(row+1, column);
    neighborCount += isCellFilled(row+1, column-1);
    return neighborCount;
} 

/* 
bottomEdgeNotCorner
bottom edge boundary case for Doughnut Mode.
@param row, column: specifies a cell in the board.
@return neighborCount: number of live neighbors surrounding the cell
*/ 
int DoughnutMode::bottomEdgeNotCorner(int row, int column){
    int neighborCount = 0;
    neighborCount += isBottomEdgeNeighborFilled(row, column-1);
    neighborCount += isBottomEdgeNeighborFilled(row, column);
    neighborCount += isBottomEdgeNeighborFilled(row, column+1);
    neighborCount += isCellFilled(row-1, column-1);
    neighborCount += isCellFilled(row-1, column);
    neighborCount += isCellFilled(row-1, column+1);
    neighborCount += isCellFilled(row, column-1);
    neighborCount += isCellFilled(row, column+1);
    return neighborCount;
}

/* 
isNeighborTopEdgeFilled
returns 1 if the cell in the bottom of the specified column is filled.
@param row, column: specifies a cell in the board.
@return 1 if cell is occupied, 0 if cell is empty.
*/ 
int DoughnutMode::isTopEdgeNeighborFilled(int row, int column){
    if(currentGen->getCell(currentGen->getRows()-1, column) == 'x') 
        return 1;
    return 0;
}

/* 
isLeftEdgeNeightborFilled
returns 1 if the cell in the last column of the specified row is filled.
@param row, column: specifies a cell in the board.
@return 1 if cell is occupied, 0 if cell is empty.
*/ 
int DoughnutMode::isLeftEdgeNeightborFilled(int row, int column){
    if(currentGen->getCell(row, currentGen->getColumns()-1) == 'x') 
        return 1;
    return 0;
}

/* 
isRightEdgeNeighborFilled
returns 1 if the cell in the first column of the specified row is filled.
@param row, column: specifies a cell in the board.
@return 1 if cell is occupied, 0 if cell is empty.
*/ 
int DoughnutMode::isRightEdgeNeighborFilled(int row, int column){
    if(currentGen->getCell(row, 0) == 'x') 
        return 1;
    return 0;
}

/* 
isBottomEdgeNeighborFilled
returns 1 if the cell in the first column of the specified row is filled.
@param row, column: specifies a cell in the board.
@return 1 if cell is occupied, 0 if cell is empty.
*/ 
int DoughnutMode::isBottomEdgeNeighborFilled(int row, int column){
    if(currentGen->getCell(0, column) == 'x') 
        return 1;
    return 0;
}
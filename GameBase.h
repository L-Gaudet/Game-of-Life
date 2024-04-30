/*
Header file for GameBase class.
*/
#if !defined(GAMEBOARD_H)
#define GAMEBOARD_H
using namespace std;
#include "GameBoard.h"

class GameBase{
    protected:
        GameBoard* currentGen;
        GameBoard* nextGen;
        int generationNumber;

        int getNeighborCountForCellNoEdgeCases(int row, int column);
        //int getNeighborCountForCell(int row, int column);

        int isCellFilled(int row, int column);
        // bool checkForStability();
        // bool isBoardEmpty();
        // void stopAndWaitForEnterPress();
        // void swapBoardReferences();

        // functions for getting neighbor counts on edge cases
        virtual int topLeftCorner(int row, int column) = 0; // define in each subclass
        virtual int topRightCorner(int row, int column) = 0; // define in each subclass
        virtual int bottomLeftCorner(int row, int column) = 0; // define in each subclass
        virtual int bottomRightCorner(int row, int column) = 0; // define in each subclass
        virtual int topEdgeNotCorner(int row, int column) = 0;  // define in each subclass
        virtual int leftEdgeNotCorner(int row, int column) = 0; // define in each subclass
        virtual int rightEdgeNotCorner(int row, int column) = 0; // define in each subclass
        virtual int bottomEdgeNotCorner(int row, int column) = 0; // define in each subclass

    public:
        GameBase();
        ~GameBase();
        void processCurrentGen();
        int getNeighborCountForCell(int row, int column);
        void printCurrentGen();
        void printNextGen();
        void stopAndWaitForEnterPress();
        void swapBoardReferences();
        bool isBoardEmpty();
        bool isBoardStable();
        int getGenerationNumber();
        int getRows();
        int getColumns();
        char getSpecificCell(int row, int column);
};
#endif
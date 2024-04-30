/*
Header file for GameBoard class.
Represents a game board at any given state. Creates a board by importing
a user board or creating a random board. Contains methods to get and set 
cells in the board, and return the number of rows and columns.
*/
using namespace std;
#include <string>

class GameBoard{
    private:
        char **  board;
        int rows;
        int columns;
        int userChoice;

        char getNextSpace(float initPopDensity);
        void createRandomGeneratedBoard();
        void createUserGeneratedBoard();
        void processFile(string inputFile);

    public:
        GameBoard();
        GameBoard(const GameBoard &boardToCopy);
        ~GameBoard();
        void printBoard();
        char getCell(int row, int column);
        void setCell(int row, int column, char charToPlace);
        int getRows();
        int getColumns();
};
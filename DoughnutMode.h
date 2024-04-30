/*
Header file for DoughnutMode class.
*/
using namespace std;
#include "GameBase.h"

class DoughnutMode : public GameBase {
    private:
        int isTopEdgeNeighborFilled(int row, int column); // add 1 to column for topright minus 1 for topleft
        int isLeftEdgeNeightborFilled(int row, int column); // minus 1 to row for topleft add 1 for bottomleft 
        int isRightEdgeNeighborFilled(int row, int column); // minus 1 to row for topright add 1 for bottomright
        int isBottomEdgeNeighborFilled(int row, int column); // add 1 to column for bottomright minus 1 for bottomleft
    protected:
        int topLeftCorner(int row, int column); 
        int topRightCorner(int row, int column); 
        int bottomLeftCorner(int row, int column); 
        int bottomRightCorner(int row, int column); 
        int topEdgeNotCorner(int row, int column);  
        int leftEdgeNotCorner(int row, int column); 
        int rightEdgeNotCorner(int row, int column); 
        int bottomEdgeNotCorner(int row, int column);

    public:
        DoughnutMode();
        ~DoughnutMode();

};
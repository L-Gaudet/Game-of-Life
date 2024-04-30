/*
Header file for DoughnutMode class.
*/
using namespace std;
#include "GameBase.h"

class MirrorMode : public GameBase {
    protected:
        int topLeftCorner(int row, int column); 
        int topRightCorner(int row, int column); 
        int bottomLeftCorner(int row, int column); 
        int bottomRightCorner(int row, int column); 
        int topEdgeNotCorner(int row, int column);  
        int leftEdgeNotCorner(int row, int column); 
        int rightEdgeNotCorner(int row, int column); 
        int bottomEdgeNotCorner(int row, int column);

        // add functions specific for indexing doughnut edge cases

    public:
        MirrorMode();
        ~MirrorMode();

};
/*
Header file for Simulation class.
*/
#if !defined(SIMULATION_H)
#define SIMULATION_H
using namespace std;
#include "ClassicMode.h"
#include "DoughnutMode.h"
#include "MirrorMode.h"
#include <unistd.h>
#include <iostream>
#include <string>
#include <fstream>


class Simulation{
    private:
        GameBase* gameObject;
        string gameMode;
        int simType;

    public:
        Simulation();
        ~Simulation();
        void runSimulation();
        void pauseAndContinueSim();
        void pressEnterSim();
        void outputToFileSim();
        void isGridEmptyOrStable();
        //void printBoardToFile(ofstream out_file);
        
    
};
#endif
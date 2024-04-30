/*
Implementation of Simulation class.
*/
#include "Simulation.h"

/* 
Simulation
Default constructor for GameBase class.
@param none
@return none
*/ 
Simulation::Simulation(){
    cout << "Which mode would you like to run in?" << endl;
	cout << "Classic mode runs the simulation without any regard for boxes outside of the grid." << endl;
	cout << "Doughnut mode wraps the grid around so one grid unit off to the left will be the respective unit on the right side." << endl;
	cout << "Mirror mode reflects the unit off the board back onto the corresponding unit next to it." << endl;
	cout << "Type the name of the mode you wish to run the simulation in: ";
	cin >> gameMode;
	while ((gameMode != "Classic") && (gameMode != "Doughnut") && (gameMode != "Mirror")) {
		cout << "Please enter one of the options:" << endl;
		cout << "Classic          Doughnut          Mirror" << endl;
		cin >> gameMode;
    }

    if(gameMode == "Classic")
        gameObject = new ClassicMode();
    else if (gameMode == "Doughnut")
        gameObject = new DoughnutMode();
    else if (gameMode == "Mirror")
        gameObject = new MirrorMode();


    cout << endl;
	cout << "Would you like the simulation pause briefly between generations, require input before continuing to the next\ngeneration, or just output the simulation to a seperate text file" << endl;
	cout << "Enter 1 for delay, 2 for pause, or 3 for file output" << endl;
	cin >> simType;
    while(simType != 1 && simType != 2 && simType != 3){
        cout << "Enter 1 for delay, 2 for pause, or 3 for file output" << endl;
	    cin >> simType;
    }
}

/* 
~Simulation
Destructor for Simulation class. Deallocates all dynamic memory.
@param none
@return none
*/ 
Simulation::~Simulation(){
    delete gameObject;
}

/* 
runSimulation
runs thru the specified simulation type.
@param none
@return none
*/ 
void Simulation::runSimulation(){
    if(simType == 1){
        pauseAndContinueSim();
    }
    else if(simType == 2){
        pressEnterSim();
    }
    else if(simType == 3){
        outputToFileSim();
    }
}

/* 
pauseAndContinueSim
carries out a simulation with brief pauses between generations.
@param none
@return none
*/ 
void Simulation::pauseAndContinueSim(){
    gameObject->printCurrentGen();
    usleep(1000000);
    do{
        gameObject->processCurrentGen();
        gameObject->printCurrentGen();
        usleep(1000000);
    }
    while(!(gameObject->isBoardStable()));
    isGridEmptyOrStable();
    cout << "Press Enter to exit simulation: ";
    cin.ignore();
    gameObject->stopAndWaitForEnterPress();
}

/* 
pressEnterSim
carries out a simulation that requires user input before processing generations.
@param none
@return none
*/ 
void Simulation::pressEnterSim(){
    gameObject->printCurrentGen();
    cout << "press enter to iterate to next generation: ";
    cin.ignore();
    gameObject->stopAndWaitForEnterPress();
    do{
        gameObject->processCurrentGen();
        gameObject->printCurrentGen();
        gameObject->stopAndWaitForEnterPress();
    }
    while(!(gameObject->isBoardStable()));
    isGridEmptyOrStable();
    cout << "Press Enter to exit simulation: ";
    gameObject->stopAndWaitForEnterPress();
}

void Simulation::outputToFileSim(){
    string outputFile = "";
    ofstream out_file;
    cout << "Enter a file name to output results to (should end with .txt): ";
    cin >> outputFile;
    out_file.open(outputFile);

    out_file << "Generation: " << gameObject->getGenerationNumber() << endl;
    for(int i=0; i < gameObject->getRows(); i++){
        for(int j=0; j < gameObject->getColumns(); j++){
            out_file << gameObject->getSpecificCell(i, j);
        }               
        out_file << endl;
    }
    do{
        gameObject->processCurrentGen();
        out_file << "Generation: " << gameObject->getGenerationNumber() << endl;
        for(int i=0; i < gameObject->getRows(); i++){
            for(int j=0; j < gameObject->getColumns(); j++){
                out_file << gameObject->getSpecificCell(i, j);
            }               
        out_file << endl;
        }
    }
    while(!(gameObject->isBoardStable()));
    isGridEmptyOrStable();
    cout << "Press Enter to exit simulation: ";
    cin.ignore();
    gameObject->stopAndWaitForEnterPress();

    out_file.close();
}

void Simulation::isGridEmptyOrStable(){
    if(gameObject->isBoardEmpty())
        cout << "Grid is empty" << endl;
    else
        cout << "Grid has stabilized" << endl;
}

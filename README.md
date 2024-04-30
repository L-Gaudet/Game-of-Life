### Game of Life

An implementation of John Conway's "Game of Life" in C++. I completed this project at the start of 2022. 

Code files: 
   
- GameBoard.h
- GameBoard.cpp
- GameBase.h
- GameBase.cpp
- ClassicMode.h
- ClassicMode.cpp
- DoughnutMode.h
- DoughnutMode.cpp
- MirrorMode.h
- MirrorMode.cpp
- Simulation.h
- Simulation.cpp
- mainprogram.cpp

Issues:

 - Implicitly defined namespace of 'std' generates warnings. (Was not following the proper practice of namespace usage when I did this project)

Instructions to run:

- Use lowercase x for testing.
- Open a terminal window
- Make sure you are in a folder with the necessary files
- Type the following and hit enter:

        g++ -std=c++11 *.cpp -o out && ./out

- Follow the in-terminal instructions
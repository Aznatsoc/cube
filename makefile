%.out:	%.cpp
	g++ -g -std=c++0x -Wall $*.cpp -o $*.out

all:
	g++ -c -std=c++0x game.cpp
	g++ -std=c++0x -Wall testGame.cpp -o testGame.out game.o
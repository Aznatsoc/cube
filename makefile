%.out:	%.cpp
	g++ -g -std=c++0x -Wall $*.cpp -o $*.out

all:
	g++ -c -std=c++0x Rooms/room.cpp
	g++ -c -std=c++0x Rooms/fire_room.cpp
	g++ -c -std=c++0x game.cpp

	g++ -std=c++0x -Wall testGame.cpp -o testGame.out game.o fire_room.o room.o
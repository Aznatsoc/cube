all: test

test: room.o fire_room.o character.o game.o
	 g++ -std=c++11 -Wall testGame.cpp -o testGame.out directions.h room.o fire_room.o character.o game.o

room.o: room.cpp
    g++ -c -std=c++11 patch.h room.cpp 

fire_room.o: fire_room.cpp
	g++ -c -std=c++11 fire_room.cpp

character.o: character.cpp
	g++ -c -std=c++11 character.cpp
    
game.o: game.cpp
	g++ -c -std=c++11 game.cpp

clean:
	rm -rf *o test
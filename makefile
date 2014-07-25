FLAGS = -std=c++11 -Wall
CC = g++

all: test

test: room.o normal_room.o fire_room.o earth_room.o air_room.o water_room.o character.o item.o game.o
	${CC} ${FLAGS} testGame.cpp -o testGame.out room.o normal_room.o fire_room.o earth_room.o air_room.o water_room.o character.o item.o game.o

room.o: room.cpp
	${CC} -c ${FLAGS} room.cpp

normal_room.o: normal_room.cpp
	${CC} -c ${FLAGS} normal_room.cpp

fire_room.o: fire_room.cpp
	${CC} -c ${FLAGS} fire_room.cpp

earth_room.o: earth_room.cpp
	${CC} -c ${FLAGS} earth_room.cpp

air_room.o: air_room.cpp
	${CC} -c ${FLAGS} air_room.cpp

water_room.o: water_room.cpp
	${CC} -c ${FLAGS} water_room.cpp

character.o: character.cpp
	${CC} -c ${FLAGS} character.cpp

item.o: item.cpp
	${CC} -c ${FLAGS} item.cpp


game.o: directions.h game.cpp
	${CC} -c ${FLAGS} game.cpp

clean:
	rm -rf *o test
FLAGS = -std=c++11 -Wall
CC = g++

all: test

test: room.o normal_room.o fire_room.o earth_room.o air_room.o water_room.o character.o human.o air_human.o animal.o item.o game.o
	${CC} ${FLAGS} testGame.cpp -o testGame.out room.o normal_room.o fire_room.o earth_room.o air_room.o water_room.o character.o human.o air_human.o animal.o item.o game.o

room.o: Rooms/room.cpp
	${CC} -c ${FLAGS} Rooms/room.cpp

normal_room.o: Rooms/normal_room.cpp
	${CC} -c ${FLAGS} Rooms/normal_room.cpp

fire_room.o: Rooms/fire_room.cpp
	${CC} -c ${FLAGS} Rooms/fire_room.cpp

earth_room.o: Rooms/earth_room.cpp
	${CC} -c ${FLAGS} Rooms/earth_room.cpp

air_room.o: Rooms/air_room.cpp
	${CC} -c ${FLAGS} Rooms/air_room.cpp

water_room.o: Rooms/water_room.cpp
	${CC} -c ${FLAGS} Rooms/water_room.cpp

character.o: Characters/character.cpp
	${CC} -c ${FLAGS} Characters/character.cpp

human.o: Characters/human.cpp
	${CC} -c ${FLAGS} Characters/human.cpp

air_human.o: Characters/air_human.cpp
	${CC} -c ${FLAGS} Characters/air_human.cpp

animal.o: Characters/animal.cpp
	${CC} -c ${FLAGS} Characters/animal.cpp

item.o: item.cpp
	${CC} -c ${FLAGS} item.cpp


game.o: directions.h game.cpp
	${CC} -c ${FLAGS} game.cpp

clean:
	rm -rf *o test
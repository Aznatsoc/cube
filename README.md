cube
====

The Cube is a highly addictive text-based game. Collect tokens and diamonds and create gems to unleash the fifth element.
The games goal is a single player game were the player move around in the cube by writing actions to the command line.

====
The cube is build on 4 earth rooms, 4 fire rooms, 4 air rooms, 4 water rooms. The remaining 11 rooms are ordinary rooms.
Each rooms has the same neighbours through out the game. However, the doors of the room can be rotated so outher rooms can be accessed. 
Each sub-room has different properties and different amount of doors.

-rooms.cpp
--fire_room.cpp
--earth_room.cpp
--air_room.cpp
--water_room.cpp
--ordinary_room.cpp

====
Characters

====
Items

====
Actions available

- rotate -- rotates the doors of the room in a specified direction.
- go -- moves the player in a specified direction, and changing room if allowed.
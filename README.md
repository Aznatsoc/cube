cube
====

The Cube is a highly addictive text-based game. Collect tokens and diamonds and create gems to unleash the fifth element.
The games goal is a single player game were the player move around in the cube by writing actions to the command line.

====
The cube is build on 4 earth rooms, 4 fire rooms, 4 air rooms, 4 water rooms. The remaining 11 rooms are ordinary rooms.
Each rooms has the same neighbours through out the game. However, the doors of the room can be rotated so outher rooms can be accessed. 
Each sub-room has different properties and different amount of doors.

	-rooms.cpp:
		
		--fire_room.cpp

		--earth_room.cpp

		--air_room.cpp

		--water_room.cpp

		--ordinary_room.cpp

====
Characters

Characters that will be available soon:
	
	- fire-characters:
		- fire-eaters

	- earth-characters:
		- neanderthals

	- air-characters:
		- aviators

	-water-characters:
		- mermaids
	
	-animals:
		- fireflies
		- snakes
		- birds
		- piranhas


====
Items

Items that will be available soon:
	
	- fire_items:
		- matches
	
	- earth_items:
		- seeds
	
	- air_items:
		- feather
	
	-water_items:
		- bubbles

====
Actions available:

	- rotate -- rotates the doors of the room in a specified direction.
	
	- go -- moves the player in a specified direction, and changing room if allowed.

Actions that will be available soon:
	
	- pickup -- pickup an item from the current room and store in your backpack
	
	- drop -- drops an item from your backpack into the current room
	
	- use -- Use an item...
	
	- talk -- Talk spells or something you have learned to create and merge items
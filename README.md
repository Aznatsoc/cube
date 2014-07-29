cube
====

The Cube is a highly addictive text-based game. Collect tokens and diamonds and create gems to unleash the fifth element.
It is a single player game in which the player moves around in the cube by writing actions in the command line.

====
The cube is made up of four earth rooms, four fire rooms, four air rooms and four water rooms. The remaining eleven rooms are ordinary rooms.
Each room has the same neighbours throughout the game. However, the doors of the room can be rotated so other rooms can be accessed. 
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
		- diamonds
	
	- earth_items:
		- seeds
			-evolves to:
				- tree
				- diamonds
				- dust
				- bubbles
		- tree
	
	- air_items:
		- feather
		- dust
	
	-water_items:
		- bubbles

====
Actions available:

	- rotate -- rotates the doors of the room in a specified direction.
	
	- go -- moves the player in a specified direction, and changing current room if allowed.

	- pickup -- pickup an item from the current room and store in your backpack
	
	- drop -- drops an item from your backpack into the current room

Actions that will be available soon:
	
	- use -- Use an item...

	- blow
	
	- talk -- Talk spells or something you have learned to create and merge items
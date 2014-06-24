#ifndef ROOM_H_
#define ROOM_H_



#include "../Character/character.h"
#include "../Item/item.h"
#include <iostream>
#include <vector>
#include <map>

namespace cube
{
	class Room{
	protected:
	    std::string m_description;
	    std::map<std::string, Character*> m_characters;
	    std::map<std::string, Item*> m_items;
	    std::map<int, Room*> m_neighbours;
	    std::vector<int> m_directions;

	public:
		~Room(){};
		std::vector<int> directions();
		Room* neighbour(int direction);
		
		std::string description();

		bool enter(Character* c);
		bool leave(Character* c);

		bool pick_up(std::string item);
		bool drop(Item& it);
	};
}
#endif
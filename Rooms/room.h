#ifndef ROOM_H_
#define ROOM_H_

class Character;
#include "../Character/character.h"

#include <iostream>
#include <vector>
#include <map>


using namespace std;
namespace cube
{
	class Room{
	protected:
	    string m_description;
	    map<string, Character*> m_characters;
	    map<string, Item*> m_items;
	    map<unsigned int, Room*> m_neighbours;
	    vector<unsigned int> m_directions;
        vector<unsigned int> m_doors;

	public:
        Room();
		~Room(){};
		string description();

		vector<unsigned int> directions();
		Room* neighbour(unsigned int direction);
		void add_neighbour(unsigned int direction, Room* r);
		
        bool enter(Character* c);
		bool leave(Character* c);

		bool pick_up(string item);
		bool drop(Item& it);

		void rotate();
	};
}
#endif
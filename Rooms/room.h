#ifndef ROOM_H_
#define ROOM_H_



#include "../Character/character.h"
#include "../Item/item.h"
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

	public:
        Room();
		~Room(){};
		string description();

		vector<unsigned int> directions();
		Room* neighbour(unsigned int direction);
		void add_neighbour(unsigned int direction, Room* r);
        //TODO remove
        void get_neighbours();
		
        bool enter(Character* c);
		bool leave(Character* c);

		bool pick_up(string item);
		bool drop(Item& it);

		//virtual void rotate() = 0;
	};
}
#endif
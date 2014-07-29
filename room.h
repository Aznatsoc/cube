#ifndef ROOM_H_
#define ROOM_H_

#include "character.h"
#include "directions.h"
#include "item.h"
#include <iostream>
#include <vector>
#include <map>
#include <sstream>
#include <string>


using namespace std;
namespace cube
{
    class Character;
    //class Item;
	class Room{
	protected:
	    string m_description;
	    map<string, Character*> m_characters;
        map<string, Item*> m_items;
	    map<int, Room*> m_neighbours;
        std::vector<int> m_room_neighbour_id;
        vector<int> m_doors;
        static const string direction_description[];

	public:
        Room();
		~Room(){};
		string description();

		vector<int> room_neighbour_id();
		Room* neighbour(int direction);
		void add_neighbour(int direction, Room* r);
        const vector<int> doors() const;
		
        bool enter(Character* c);
		bool leave(Character* c);

        bool add_item(Item* item);
		Item* remove_item(string item);

		void rotate(int direction);
        virtual void action(Character* c) = 0;
	};
}
#endif
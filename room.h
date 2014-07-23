#ifndef ROOM_H_
#define ROOM_H_

#include "character.h"
#include "directions.h"
//#include "item.h"
#include <iostream>
#include <vector>
#include <map>
#include <sstream>
#include <string>


using namespace std;
namespace cube
{
    class Character;
	class Room{
	protected:
	    string m_description;
	    map<string, Character*> m_characters;
	    //map<string, Item*> m_items;
	    map<unsigned int, Room*> m_neighbours;
	    vector<unsigned int> m_room_neighbour_id;
        vector<unsigned int> m_doors;
        std::string direction_description[8] = {"RIGHT", "BACK", "LEFT", "FORWARD", "DUMMY2", "DUMMY3", "UP", "DOWN"};

	public:
        Room();
		~Room(){};
		string description();

		vector<unsigned int> room_neighbour_id();
		Room* neighbour(unsigned int direction);
		void add_neighbour(unsigned int direction, Room* r);
        const vector<unsigned int> doors() const;
		
        bool enter(Character* c);
		bool leave(Character* c);

	/*	bool pick_up(string item);
		bool drop(Item& it);*/

		void rotate(unsigned int direction);
	};
}
#endif
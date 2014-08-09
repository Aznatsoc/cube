#ifndef ROOM_H_
#define ROOM_H_

#include "../Characters/character.h"
#include "../directions.h"
#include "../item.h"
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
        string type_of_room;

	public:
        Room();
		~Room(){};
		string description();

		vector<int> room_neighbour_id();
		Room* neighbour(int direction);
		void add_neighbour(int direction, Room* r);
        const vector<int> doors() const;
		
        virtual bool enter(Character* c) = 0;
		bool leave(Character* c);

        virtual bool add_item(Item* item) = 0;
		Item* remove_item(string item);
        bool contains_item(string item);
        Character* get_character(string name); //this should be a reference, but might need to change the characters life and such

		virtual void rotate() = 0;
        virtual void item_impact(string item) = 0;
        
        string type();
	};
}
#endif
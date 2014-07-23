#ifndef CHARACTER_H_
#define CHARACTER_H_

#include <string>
#include <map>
#include <iostream>
#include <math.h>        // std::abs not fucking working
#include "room.h"
#include <vector>
#include <algorithm>
//#include "item.h"


using namespace std;
namespace cube
{
    class Room;
	class Character{
        private:
            void change_room(Room *next_room);
		protected: //private?
			string m_name;
			int m_item_capacity;
		//	map<string, Item*> m_item_container;
			int m_life;
			string m_type;
			Room* m_current_room;

		public:
            Character();
            Character(string name, Room *current_room);
			~Character(){};
			string name() const;
			unsigned int life() const;
            Room* current_room();
			int container_size() const;
			int container_capacity() const;
//            
//            bool pick_up(Item& item);
//			bool drop(Item& item);
			bool go(int direction);

			//virtual bool action() = 0; //aktörens tur att agera
	};
}	
#endif
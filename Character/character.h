#ifndef CHARACTER_H_
#define CHARACTER_H_

class Room;
#include <string>
#include <map>
#include <iostream>
#include "../Item/item.h"
#include "../Rooms/room.h"

using namespace std;
namespace cube
{
	class Character{
        private:
            //void change_room(Place *location);
		protected: //private?
			string m_name;
			int m_item_capacity;
			map<string, Item*> m_item_container;
			unsigned int m_life;
			string m_type;
			Room* m_current_room;

		public:
        Character();
			~Character(){};
			string name() const;
			unsigned int life() const;
            Room* current_room();
			int container_size() const;
			int container_capacity() const;
			
            bool pick_up(Item& item);
			bool drop(Item& item);
			bool go(int direction);

			virtual bool action() = 0; //aktörens tur att agera
	};
}	
#endif
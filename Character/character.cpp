#include "character.h"

using namespace std;

namespace cube
{
    Character::Character(string name, Room* current_room){
        m_name = name;
        m_current_room = current_room;
    }
	string Character::name() const{
		return m_name;
	}
    
    unsigned int Character::life() const{
		return m_life;
	};
    
    Room* Character::current_room(){
    	return m_current_room;
    }

	int Character::container_size() const{
		return m_item_container.size();
	};

	int Character::container_capacity() const{
		return m_item_capacity;
	};
	
	bool Character::pick_up(Item& item){
		if(container_size() < container_capacity()){
			m_item_container.insert(pair<string, Item*>(item.name(), &item));
			return true;
		}
		return false;
	};
	
	bool Character::drop(Item& item){
		//Remove from container
		return false;
	};



	bool Character::go(int direction){
//		Room* current_room = this->current_room();
//		Room* next_room = current_room->neighbour(direction);
//
//		if(current_room != next_room){
//			printf("WE CHANGED ROOM\n");
//			if(next_room->enter(this) && current_room->leave(this)){
//				this->change_location(next_room);
//				return true;
//			}
//		}
		return false;
	};
}
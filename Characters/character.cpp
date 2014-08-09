#include "character.h"

using namespace std;

namespace cube
{
    
	string Character::name() const{
		return m_name;
	}
    
    int Character::life() const{
		return m_life;
	};
    
    void Character::life(int change){
        
        m_life = m_life+change;
    }
    
    Room* Character::current_room(){
    	return m_current_room;
    }

	int Character::container_size() const{
		return m_item_container.size();
	};

	int Character::container_capacity() const{
        return m_item_capacity;
	};
    
    string Character::type(){
        return m_type;
    }
    string Character::backpack_description(){
        std::string items = "\nThe Items in your backpack are: ";
        std::map<string,Item*>::iterator it = m_item_container.begin();
        for (it=m_item_container.begin(); it!=m_item_container.end(); ++it){
            items += it->first + ", ";
        }
        return items;
    }
    
	bool Character::add_item(Item* item){
		if(container_size() < container_capacity()){
            pair<std::map<string,Item*>::iterator,bool> ret;
			ret = m_item_container.insert(pair<string, Item*>(item->name(), item));
			return ret.second;
		}
		return false;
	};
	
	Item* Character::remove_item(string item){
        std::map<string, Item*>::iterator it = m_item_container.find(item);
        if(it != m_item_container.end()){
            Item* return_value = it->second;
            m_item_container.erase(it);
            return return_value;
        }else{
            return NULL;
        }
        
	};

    void Character::change_room(Room *next_room){
        m_current_room = next_room;
    };
    

	bool Character::go(int exit){
        //check that exit is in valid doors
        const vector<int> valid_doors = this->current_room()->doors();
        if(std::find(valid_doors.begin(), valid_doors.end(), exit) != valid_doors.end()) {
            //If next_room is not a neighbour return can't go ???? really
            const vector<int> valid_neighbours = this->current_room()->room_neighbour_id();
            if(std::find(valid_neighbours.begin(), valid_neighbours.end(), exit) != valid_neighbours.end()) {
                //retrieve next_room to where exit points to.
                Room* next_room = this->current_room()->neighbour(exit);
                vector<int> next_rooms_doors = next_room->doors();
                for(int i = 0; i < (int)next_rooms_doors.size(); ++i){
                   // cout << "APAN: nextRoomsDoors: " << next_rooms_doors[i] << ", exit: " << exit << ", abs " << abs((int)next_rooms_doors[i]-(int)exit) << endl;
                    if(abs((int)next_rooms_doors[i]-(int)exit) == 3){
                        bool entered = next_room->enter(this);
                        bool left = this->current_room()->leave(this);
                        if(entered && left){
                            this->change_room(next_room);
                            return true;
                        }else{
                           std::cout << "SOMETHING WENT WRONG TODO" << endl;
                        }
                    }
                }
                //If next_room does not have a door points to current_room, return can't go
                std::cout << "Sorry this door points to a neighbor that does not have a door pointing to you! try another room by rotating this room!" << endl;
            }else{
                std::cout << "Sorry this door goes to void, try rotate the room!" << endl;
            }
        }else{
             std::cout << "This is not a valid door" << endl;
        }

        
		return false;
	};
    
    bool Character::contains_item(string item){
        std::map<string, Item*>::iterator it = m_item_container.find(item);
        return it != m_item_container.end();
    }
}
#include "character.h"

using namespace std;

namespace cube
{
    
    Character::Character(string name, Room *current_room){
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
		//return m_item_container.size();
        return -1;
	};

	int Character::container_capacity() const{
		//return m_item_capacity;
        return -1;
	};
	
	/*bool Character::pick_up(Item& item){
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
*/
    void Character::change_room(Room *next_room){
        m_current_room = next_room;
    };
    

	bool Character::go(int exit){
        //check that exit is in valid doors
        const vector<unsigned int> valid_doors = this->current_room()->doors();
        if(std::find(valid_doors.begin(), valid_doors.end(), exit) != valid_doors.end()) {
            //If next_room is not a neighbour return can't go ???? really
            const vector<unsigned int> valid_neighbours = this->current_room()->room_neighbour_id();
            if(std::find(valid_neighbours.begin(), valid_neighbours.end(), exit) != valid_neighbours.end()) {
                //retrieve next_room to where exit points to.
                Room* next_room = this->current_room()->neighbour(exit);
                vector<unsigned int> next_rooms_doors = next_room->doors();
                for(int i = 0; i < next_rooms_doors.size(); ++i){
                    cout << "ZEEEBRA next rooms door points to: " << next_rooms_doors[i] << ", this exit are: " << exit << ", "<< abs((int)next_rooms_doors[i]-(int)exit) << endl;
                    
                    if(abs((int)next_rooms_doors[i]-(int)exit) == 2){
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
}
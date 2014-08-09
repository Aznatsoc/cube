#include "room.h"

using namespace std;
namespace cube
{
    const std::string Room::direction_description[6] = {"RIGHT", "UP", "FORWARD", "LEFT", "DOWN", "BACK"};
    
    
    Room::Room(){}
    
	vector<int> Room::room_neighbour_id(){
		return m_room_neighbour_id;
	};

	Room* Room::neighbour(int direction){
        std::map<int, Room*>::iterator it;
        it=m_neighbours.find(direction); //Todo, what if end of map??
        return it->second;
	};
	
	void Room::add_neighbour(int direction, Room* r){
		m_neighbours[direction] = r;
        m_room_neighbour_id.push_back(direction);
	};
    
    //TODO clean up, neat up!
	string Room::description(){
        std::string doors = "\nThe exits in this room are: ";
        int m_doors_size = m_doors.size();
        for (int i = 0; i < m_doors_size-1; ++i) {
            doors += direction_description[m_doors[i]] + ", "; //lookup from enum map
        }
        doors +=  direction_description[m_doors[m_doors_size-1]];
        
        std::string items = "\nThe Items in this room are: ";
        std::map<string,Item*>::iterator it = m_items.begin();
        for (it=m_items.begin(); it!=m_items.end(); ++it){
            items += it->first + ", "; //todo trailing ,
        }
        
        std::string characters = "\nThe characters in this room are: ";
        std::map<string,Character*>::iterator char_it = m_characters.begin();
        for (char_it=m_characters.begin(); char_it!=m_characters.end(); ++char_it){
            //todo remove player of type human
            characters += char_it->first + ", "; //todo trailing ,
        }
        
        return m_description + doors + items + characters;
	};
    
    const vector<int> Room::doors() const{
        return m_doors;
    };
    
    string Room::type(){
        return type_of_room;
    }
    
    
	bool Room::leave(Character* c){
        m_characters.erase(c->name());
        //room action will happen on character or on room itself...
        //this->action(c);
		return true; //TODO check this
	};
    
    Item* Room::remove_item(string item){
        cout << "remove item " << item <<endl;
        std::map<string, Item*>::iterator it = m_items.find(item);
        //Todo remove if found
        Item* return_value = it->second;
        m_items.erase(it);
        return return_value;
    }

    bool Room::contains_item(string item){
        std::map<string, Item*>::iterator it = m_items.find(item);
        return it != m_items.end();
    }
    
    Character* Room::get_character(string name){
        std::map<string, Character*>::iterator it = m_characters.find(name);
        Character* return_value = it->second;
        return return_value;

    }
}
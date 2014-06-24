#include "room.h"

using namespace std;
namespace cube
{
    Room::Room(){
        
    }
    
	vector<unsigned int> Room::directions(){
		return m_directions;
	};

	Room* Room::neighbour(unsigned int direction){
		return NULL;
	};
	
	void Room::add_neighbour(unsigned int direction, Room* r){
		m_neighbours[direction] = r;
        m_directions.push_back(direction);
	};

    void Room::get_neighbours(){
        std::map<unsigned int,Room*>::iterator it = m_neighbours.begin();
        for (it=m_neighbours.begin(); it!=m_neighbours.end(); ++it)
            std::cout << it->first << '\n';

    };
    
	string Room::description(){
		return m_description;
	};

	bool Room::enter(Character* c){
		return false;
	};
	bool Room::leave(Character* c){
		return false;
	};

	bool Room::pick_up(std::string item){
		return false;
	};
	bool Room::drop(Item& it){
		return false;
	};
}
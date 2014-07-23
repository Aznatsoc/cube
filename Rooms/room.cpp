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
		return m_neighbours[direction];
	};
	
	void Room::add_neighbour(unsigned int direction, Room* r){
		m_neighbours[direction] = r;
        m_directions.push_back(direction);
	};
    
	string Room::description(){
        string doors = "";
        for (int i = 0; i < m_doors.size(); ++i) {
            doors += to_string(m_doors[i]) + ", ";
        }
		return m_description + doors;
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
    
    void Room::rotate(){
        for(int i = 0; i < m_doors.size(); ++i){
            m_doors[i] = (m_doors[i]+1)%6;
        }
    };
}
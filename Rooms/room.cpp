#include "room.h"

using namespace std;

namespace cube
{
	vector<int> Room::directions(){
		return m_directions;
	};

	Room* Room::neighbour(int direction){
		return NULL;
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
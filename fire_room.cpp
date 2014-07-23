#include "fire_room.h"

using namespace std;

namespace cube
{
	FireRoom::FireRoom(){
		m_description = "Fire room";
        m_doors = {BACK,LEFT};
	};
    FireRoom::FireRoom(string name){
		m_description = "Fire room " + name;
        m_doors = {BACK,LEFT};
	};
}
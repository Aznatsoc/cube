#include "fire_room.h"

using namespace std;

namespace cube
{
	FireRoom::FireRoom(){
		m_description = "Fire room";
        m_doors = {BACK,LEFT, UP};
	};
    FireRoom::FireRoom(string name){
		m_description = "Fire room " + name;
        m_doors = {BACK,LEFT, UP};
	};
    
    void FireRoom::action(Character* c){
        cout << "FireRoom room made an action" << endl;
    };
}
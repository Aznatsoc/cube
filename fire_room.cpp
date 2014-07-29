#include "fire_room.h"

using namespace std;

namespace cube
{
	FireRoom::FireRoom(){
		m_description = "Fire room";
        m_doors = {BACK,LEFT, UP};
        type_of_room = "fire";
	};
    FireRoom::FireRoom(string name){
		m_description = "Fire room " + name;
        m_doors = {BACK,LEFT, UP};
        type_of_room = "fire";
	};
    
    void FireRoom::action(Character* c){
        cout << "FireRoom room made an action" << endl;
    };
    void FireRoom::item_impact(string item){
    };
}
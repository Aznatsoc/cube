//
//  earth_room.cpp
//  
//
//  Created by Lovisa Skeppe on 7/24/14.
//
//

#include "earth_room.h"

using namespace std;

namespace cube
{
	EarthRoom::EarthRoom(){
		m_description = "Earth room";
        m_doors = {RIGHT, LEFT, DOWN};
        soil = 100;
        type_of_room = "earth";
	};
    EarthRoom::EarthRoom(string name){
		m_description = "Earth room " + name;
        m_doors = {RIGHT, LEFT, DOWN};
        soil = 100;
        type_of_room = "earth";
	};
    
    void EarthRoom::action(Character* c){
        cout << "EARTH room made an action" << endl;
    }
    
    void EarthRoom::item_impact(string item){
    }
}
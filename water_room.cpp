//
//  water_room.cpp
//  
//
//  Created by Lovisa Skeppe on 7/24/14.
//
//

#include "water_room.h"

using namespace std;

namespace cube
{
	WaterRoom::WaterRoom(){
		m_description = "Water room";
        m_doors = {RIGHT, LEFT, DOWN, UP};
	};
    WaterRoom::WaterRoom(string name){
		m_description = "Water room " + name;
        m_doors = {RIGHT, LEFT, DOWN, UP};
	};
    void WaterRoom::action(Character* c){
        cout << "WaterRoom room made an action" << endl;
    }
}
//
//  air_room.cpp
//  
//
//  Created by Lovisa Skeppe on 7/24/14.
//
//

#include "air_room.h"

using namespace std;

namespace cube
{
	AirRoom::AirRoom(){
		m_description = "Air room";
        m_doors = {RIGHT, LEFT, DOWN, UP, BACK, FORWARD};
	};
    AirRoom::AirRoom(string name){
		m_description = "Air room " + name;
        m_doors = {RIGHT, LEFT, DOWN, UP, BACK, FORWARD};
	};
    
    void AirRoom::action(Character* c){
        cout << "Air room made an action" << endl;
    }
}
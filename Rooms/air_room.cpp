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

    AirRoom::AirRoom(string name){
		m_description = "Air room " + name;
        m_doors = {RIGHT, LEFT, DOWN, UP, BACK, FORWARD};
        type_of_room = "air";
	};
    
    void AirRoom::change_wind(int wind){
        m_wind = m_wind + wind;
    }

    int AirRoom::wind(){
        return m_wind;
    }
    void AirRoom::rotate(){
        //this will only build up wind power
        change_wind(20);
    }

    bool AirRoom::add_item(Item* item){
        //cout << "add item" << endl;
        //If a special item is added, rooms internal structure changes...
        pair<std::map<string,Item*>::iterator,bool> ret;
        ret = m_items.insert(pair<string,Item*>(item->name(), item));
        return ret.second;
        //return false;
    };
    
    void AirRoom::item_impact(string item){
        //item impact
    };
    bool AirRoom::enter(Character* c){
        pair<std::map<string,Character*>::iterator,bool> ret;
        ret = m_characters.insert(pair<string,Character*>(c->name(), c));

//        //room action will happen, on character or and on room itself
        if(c->type() == "player"){
            cout << this->description() << endl;
            //this->action(c);
        }
        return ret.second;
    };
}
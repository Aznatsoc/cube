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
        m_doors = {RIGHT, LEFT, DOWN, UP}; //TODO remove up
        soil = 100;
        type_of_room = "earth";
	};
    
    void EarthRoom::rotate(){
        //todo keep a counter for rotate, so if rotated to often, jordskred happens, and the player is kicked out and this room seal their doors.
        cout << "ROTATE UP WEIRD" << endl;
        for(int i = 0; i < m_doors.size(); ++i){
            switch (m_doors[i]) {
                case RIGHT:
                    m_doors[i] = UP;
                    break;
                case LEFT:
                    m_doors[i] = DOWN;
                    break;
                case UP:
                    m_doors[i] = LEFT;
                    break;
                case DOWN:
                    m_doors[i] = RIGHT;
                    break;
                default:
                    break;
            }
        }

    }
    void EarthRoom::action(Character* c){
        cout << "EARTH room made an action" << endl;
    }
    
    bool EarthRoom::add_item(Item* item){
        //cout << "add item" << endl;
        //If a special item is added, rooms internal structure changes...
        pair<std::map<string,Item*>::iterator,bool> ret;
        ret = m_items.insert(pair<string,Item*>(item->name(), item));
        item_impact(item->name());
        return ret.second;
        //return false;
    };
    
    void EarthRoom::item_impact(string item_name){
        //React to some items
        if(item_name == "seeds"){
            soil = soil - 30;
        }
    };
    
    bool EarthRoom::enter(Character* c){
        //TODO! This insert can be made in super class
        pair<std::map<string,Character*>::iterator,bool> ret;
        ret = m_characters.insert(pair<string,Character*>(c->name(), c));
        
        if(c->type() == "player"){
            cout << c->name() << ", You have entered an earth room" << endl;
            cout << this->description() << endl;
            //this->action(c);
        }
        return ret.second;
    };
}
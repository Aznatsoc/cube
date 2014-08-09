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
    WaterRoom::WaterRoom(string name){
		m_description = "Water room " + name;
        m_doors = {RIGHT, LEFT, DOWN, UP};
        type_of_room = "water";
        waves = 100;
	};
    
    void WaterRoom::rotate(){
        waves += 10;
        cout << "Rotating a water room increases wave power to " << waves << endl; //todo move message??
        for(int i = 0; i < m_doors.size(); ++i){
            switch (m_doors[i]) {
                case BACK:
                    m_doors[i] = UP;
                    break;
                case FORWARD:
                    m_doors[i] = DOWN;
                    break;
                case UP:
                    m_doors[i] = FORWARD;
                    break;
                case DOWN:
                    m_doors[i] = BACK;
                    break;
                default:
                    break;
            }
        }
    };
    
    void WaterRoom::action(Character* c){
        cout << "WaterRoom room made an action" << endl;
    }
    
    bool WaterRoom::add_item(Item* item){
        //cout << "add item" << endl;
        //If a special item is added, rooms internal structure changes...
        pair<std::map<string,Item*>::iterator,bool> ret;
        ret = m_items.insert(pair<string,Item*>(item->name(), item));
        return ret.second;
        //return false;
    };
    
    void WaterRoom::item_impact(string item){
        //Item impact implementation
    };
    
    bool WaterRoom::enter(Character* c){
        //TODO! Instead of action, this can be virtual and all rooms respond differently!
        pair<std::map<string,Character*>::iterator,bool> ret;
        ret = m_characters.insert(pair<string,Character*>(c->name(), c));

        //room action will happen, on character or and on room itself
        if(c->type() == "player"){
            int life_change = 10;
            cout << c->name() << ", You have entered a water room\nIt is cooling and relaxing in here so your life is increasing with " << life_change << endl;
            c->life(life_change);

        }
        return ret.second;
    }
}
#include "fire_room.h"

using namespace std;

namespace cube
{    
    FireRoom::FireRoom(string name){
		m_description = "Fire room " + name;
        m_doors = {BACK,LEFT, UP};
        type_of_room = "fire";
	};
    
    void FireRoom::rotate(){
        cout << "ROTATE RIGHT" << endl;
        for(int i = 0; i < m_doors.size(); ++i){
            if (m_doors[i] < 4) {
                m_doors[i] = (m_doors[i]+1)%4;
            }
        }
    };
    
    void FireRoom::action(Character* c){
        cout << "FireRoom room made an action" << endl;
    };
    
    bool FireRoom::add_item(Item* item){
        //cout << "add item" << endl;
        //If a special item is added, rooms internal structure changes...
        if(item->name() == "tree"){
            delete item; //burn up tree
            item = new Item("fire");
        }
        pair<std::map<string,Item*>::iterator,bool> ret;
        ret = m_items.insert(pair<string,Item*>(item->name(), item));
        return ret.second;
        //return false;
    };
    
    void FireRoom::item_impact(string item){
    };
    
    bool FireRoom::enter(Character* c){
        pair<std::map<string,Character*>::iterator,bool> ret;
        ret = m_characters.insert(pair<string,Character*>(c->name(), c));
        
        if(c->type() == "player"){
            int life_change = -30;
            cout << c->name() << ", You have entered a fire room\nIt is hot in here so your life is decreasing with " << life_change << endl;
            c->life(life_change);
            cout << this->description() << endl;
            //this->action(c);
        }
        return ret.second;
    };
}
#include "normal_room.h"

using namespace std;

namespace cube
{
    NormalRoom::NormalRoom(string name){
        m_description = "Normal room " + name;
        m_doors = {BACK, LEFT, RIGHT, FORWARD, UP};
        type_of_room = "normal";
    };
    
    void NormalRoom::rotate(){
        cout << "ROTATE UP WEIRD" << endl;
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

    }
    void NormalRoom::action(Character* character){
        cout << "This is a normal room so I wont do you any good..." << endl;
    };
    
    bool NormalRoom::add_item(Item* item){
        //cout << "add item" << endl;
        //If a special item is added, rooms internal structure changes...
        pair<std::map<string,Item*>::iterator,bool> ret;
        ret = m_items.insert(pair<string,Item*>(item->name(), item)); //todo, should be able to have multiple items that is the same
        return ret.second;
        //return false;
    };
    
    void NormalRoom::item_impact(string item){
    };
    
    bool NormalRoom::enter(Character* c){
        //TODO! Instead of action, this can be virtual and all rooms respond differently!
        pair<std::map<string,Character*>::iterator,bool> ret;
        ret = m_characters.insert(pair<string,Character*>(c->name(), c));
        //room action will happen, on character or and on room itself
        if(c->type() == "player"){
            cout << this->description() << endl;
            //this->action(c);
        }
        return ret.second;
    };
    
}
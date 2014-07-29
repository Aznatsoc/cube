#include "normal_room.h"

using namespace std;

namespace cube
{
    NormalRoom::NormalRoom(){
        m_description = "Normal room";
        m_doors = {BACK, LEFT, RIGHT, FORWARD, UP};
        type_of_room = "normal";
    };
    NormalRoom::NormalRoom(string name){
        m_description = "Normal room " + name;
        m_doors = {BACK, LEFT, RIGHT, FORWARD, UP};
        type_of_room = "normal";
    };
    void NormalRoom::action(Character* character){
        cout << "This is a normal room so I wont do you any good..." << endl;
    };
    
    void NormalRoom::item_impact(string item){
    };
    
}
#ifndef AIR_HUMAN_H
#define AIR_HUMAN_H

#include <iostream>
#include "human.h"



using namespace std;
namespace cube
{
	class Air_human : public Human{
    
    public:
        Air_human(string name, Room *current_room, string human_type);
        string human_type();
        string communicate(Character* c);
        string talk(Character* c);
    };
}
#endif


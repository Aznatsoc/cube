//
//  water_room.h
//  
//
//  Created by Lovisa Skeppe on 7/24/14.
//
//

#ifndef WATER_ROOM_H_
#define WATER_ROOM_H_

#include "room.h"
#include <string>
#include <map>
#include <stdlib.h>     /* srand, rand */


using namespace std;
namespace cube
{
	class WaterRoom : public Room{
    private:
        int waves;
    public:
        WaterRoom(string name);
        
        void rotate();
        void action(Character* c);
        bool add_item(Item* item);
        void item_impact(string item);
        bool enter(Character* c);
	};
}

#endif
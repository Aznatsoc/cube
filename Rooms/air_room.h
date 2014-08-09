//
//  air_room.h
//  
//
//  Created by Lovisa Skeppe on 7/24/14.
//
//

#ifndef AIR_ROOM_H_
#define AIR_ROOM_H_

#include "room.h"
#include <string>
#include <map>
#include <stdlib.h>     /* srand, rand */


using namespace std;
namespace cube
{
	class AirRoom : public Room{
    private:
        int m_wind;
    public:
        AirRoom(string name);
        
        void rotate();
        bool add_item(Item* item);
        void item_impact(string item);
        bool enter(Character* c);
        
        int wind();
        void change_wind(int wind);
        
	};
}

#endif /* defined(AIR_ROOM_H_) */
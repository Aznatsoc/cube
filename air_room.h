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
        int oxygen;
    public:
        AirRoom();
        AirRoom(string name);
        //void rotate();
        void action(Character* c);
        void item_impact(string item);
	};
}

#endif /* defined(AIR_ROOM_H_) */
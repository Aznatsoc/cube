#ifndef FIRE_ROOM_H_
#define FIRE_ROOM_H_

#include "room.h"
#include <string>
#include <map>
#include <stdlib.h>     /* srand, rand */


using namespace std;
namespace cube
{
	class FireRoom : public Room{
		private:
			int heat;
		public:
            //default constr not implemented
            FireRoom(string name);
        
            void rotate();
            void action(Character* c);
            bool add_item(Item* item);
            void item_impact(string item);
            bool enter(Character* c);
	};
}
#endif
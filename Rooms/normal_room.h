#ifndef NORMAL_ROOM_H_
#define NORMAL_ROOM_H_

#include "room.h"
#include <string>
#include <map>
#include <stdlib.h>     /* srand, rand */


using namespace std;
namespace cube
{
	class NormalRoom : public Room{
        private:
            int oxygen;
        public:
            NormalRoom(string name);
        
            void rotate();
            void action(Character* character);
            bool add_item(Item* item);
            void item_impact(string item);
            bool enter(Character* c);
	};
}

#endif
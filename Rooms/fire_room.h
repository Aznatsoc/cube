#ifndef FIRE_ROOM_H_
#define FIRE_ROOM_H_

#include "room.h"
#include <string>
#include <map>
#include <stdlib.h>     /* srand, rand */


using namespace std;
namespace cube
{
	//class Ghost;
	class FireRoom : public Room{
		private:
			int heat;
		public:
			FireRoom();
	};
}
#endif
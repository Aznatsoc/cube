#ifndef GAME_H_
#define GAME_H_



#include "fire_room.h"
#include "earth_room.h"
#include "air_room.h"
#include "water_room.h"
#include "normal_room.h"
//#include "character.h"
#include "item.h"
#include <iostream>
#include <vector>
#include <string>
#include <map>

namespace cube
{
	class Game{
		void setup();
        void setup_cube_structure();
		bool finished();
        vector<string>  processCommand();
        vector<Room*> cube;
        Character* player;
        std::map<std::string, int> directions;

        
		public:
			Game();
			~Game();
			void play();
            vector<Room*> get_cube();
            Character* get_player();
	};
}
#endif
#ifndef GAME_H_
#define GAME_H_



#include "fire_room.h"
//#include "character.h"
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
		bool processCommand();
        vector<Room*> cube;
        Character* player;
        std::map<std::string, unsigned int> directions;

        
		public:
			Game();
			~Game();
			void play();
            vector<Room*> get_cube();
	};
}
#endif
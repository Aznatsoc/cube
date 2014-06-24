#ifndef GAME_H_
#define GAME_H_



#include "Rooms/fire_room.h"
#include <iostream>
#include <vector>
namespace cube
{
	class Game{
		void setup();
        void setup_cube_structure();
		bool finished();
		bool processCommand();
        vector<Room*> cube;
        
		public:
			Game();
			~Game();
			void play();
            vector<Room*> get_cube();
	};
}
#endif
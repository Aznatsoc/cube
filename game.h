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
        void setup_items();
		bool finished();

        vector<Room*> cube;
        Character* player;
        std::map<std::string, int> directions;
        
        typedef void (Game::*pfunc)(void);
        std::map<std::string, Game::pfunc> commands;
        
        bool is_finished;
        bool is_exit;
        std::vector<std::string> tokens;
        void processCommand();
        bool validate_if_next_argument();
        
        //commands
        void exit();
        void drop();
        void pickup();
        void rotate();
        void go();
        
		public:
			Game();
			~Game();
			void play();
            vector<Room*> get_cube(); //for testing
            Character* get_player(); //for testing
        
	};
}
#endif
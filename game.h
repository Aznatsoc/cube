#ifndef GAME_H_
#define GAME_H_



#include "Rooms/fire_room.h"
#include "Rooms/earth_room.h"
#include "Rooms/air_room.h"
#include "Rooms/water_room.h"
#include "Rooms/normal_room.h"
#include "Characters/air_human.h"
#include "Characters/animal.h"
#include "item.h"
#include <iostream>
#include <vector>
#include <string>
#include <map>

namespace cube
{
	class Game{
        //setup
		void setup();
        void setup_cube_structure();
        void setup_items();
        void setup_characters();
        void welcome_the_game();
        void setup_player();
        void setup_commands();
        
        //variables to be accessed in game
        vector<Room*> cube;
        Human* player;
        
        //finish
		bool finished();
        bool has_fifth_element;
        void create_fifth_element();
        
        //Command helpers
        void processCommand();
        void error_input_handler(string command);
        bool is_exit;
        std::vector<std::string> tokens;
        std::map<std::string, int> directions;
        
        //commands
        typedef void (Game::*pfunc)(void);
        std::map<std::string, Game::pfunc> commands;
        std::map<std::string, Game::pfunc> learnable_commands;
        
        typedef void (Game::*pfunc_args)(string);
        std::map<std::string, Game::pfunc_args> commands_with_arguments;
        //std::map<std::string, Game::pfunc_args> learnable_commands_with_arguments;
        
        void exit();
        void rotate();
        void health();
        
        void go(string direction);
        void use(string item_name);
        void talk(string character_name);
        void drop(string item_name);
        void pickup(string item_name);
        
        //Learnable commands
        void blow();
        
        //void whisper(string character_name);
        
		public:
			Game();
			~Game();
			void play();
            Character* get_player();
	};
}
#endif
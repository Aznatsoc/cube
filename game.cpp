#include "game.h"
#include "directions.h"

#include <string>
#include <climits>
#include <cmath>
#include <algorithm>    // std::random_shuffle
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sstream>


namespace cube
{
	Game::Game(){
        //todo, move this to directions to be accessed everywhere??
        directions["right"] = RIGHT;
        directions["back"] = BACK;
        directions["left"] = LEFT;
        directions["forward"] = FORWARD;
        directions["up"] = UP;
        directions["down"] = DOWN;
        
        setup();
        play();
	};
	
	Game::~Game(){
		//tear down all rooms, characters and items!
		//TODO remove the items in the vectors, otherwise memory leakage
       // delete [] cube;
       // delete player;
	};

	void Game::play(){
        Room* currentRoom = cube[0]; //start game in this room
        player = new Character("Bengan", currentRoom); // TODO ask name and stuff
        cout<< "before enter room" << endl;
        currentRoom->enter(player);
        
        bool finished = false;
        
        // pickup *item -> remove_item from room and put in backback
        // drop *item -> remove_item from backpack and put in current room
        while(finished != true){
            Room* tmp_room =player->current_room();
            string tmp_str = tmp_room->description();
            cout << "You are in room: " << tmp_str <<endl;
            vector<string> tokens = processCommand(); // Create vector to hold our words
        
            if (tokens.size() < 1) {
                continue;
            }
            if(tokens[0] == "rotate"){
                if (tokens.size() == 2) {
                    map<string, int>::iterator direction_it = directions.find(tokens[1]);
                    if(direction_it != directions.end()){
                        int dir = direction_it->second;
                        player->current_room()->rotate(dir);
                    }else{
                        cout << "The direction you are trying to rotate in does not exist, misspelled?" << endl;
                    }
                }else{
                    cout << "Rotate demands a direction too, please try again!" << endl;
                }
                
            }else if(tokens[0] == "exit"){
                finished = true;
            }else if(tokens[0] == "go"){
                if (tokens.size() == 2) {
                    //TODO looks awfully similar to 'rotate'
                    map<string, int>::iterator direction_it = directions.find(tokens[1]);
                    if(direction_it != directions.end()){
                        int dir = direction_it->second;
                        player->go(dir);
                    }else{
                        cout << "The direction you are trying to enter does not exist, misspelled?" << endl;
                    }
                }else{
                    cout << "go demands a direction too, please try again!" << endl;
                }
            }
        }
	};

	void Game::setup(){
        setup_cube_structure();
        //items
        //characters
    };
    
    void Game::setup_cube_structure(){
        //create cube of 4 fire_rooms...
        vector<Room*> rooms;
        int index = 0;
        for (int i = 0; i < 4; ++i) {
            Room *r = new FireRoom(" r" + to_string(index));
            rooms.push_back(r);
            ++index;
        }
        //..4 earth_rooms
        for (int i = 0; i < 4; ++i) {
            Room *r = new EarthRoom(" r" + to_string(index));
            rooms.push_back(r);
            ++index;
        }
        //..4 air_rooms
        for (int i = 0; i < 4; ++i) {
            Room *r = new AirRoom(" r" + to_string(index)); 
            rooms.push_back(r);
            ++index;
        }
        //..4 water_rooms
        for (int i = 0; i < 4; ++i) {
            Room *r = new WaterRoom(" r" + to_string(index));
            rooms.push_back(r);
            ++index;
        }
        //..4 normal_rooms
        for (int i = 0; i < 11; ++i) {
            Room *r = new NormalRoom(" r" + to_string(index));
            rooms.push_back(r);
            ++index;
        }
        //shuffle, but no seed! so allways the same!!
        std::random_shuffle ( rooms.begin(), rooms.end() );
    
        for (int i = 0; i < 3; ++i) {
            int lower_bound= i*9;
            int upper_bound = (i+1)*9;
            for (int n = lower_bound; n < upper_bound; ++n) {
                Room* r = rooms[n];
                if((n+1)%3 > 0 && n+1 < upper_bound) r->add_neighbour(RIGHT, rooms[n+1]);  //add right neigbour
                if((n-1)%3 != 2 && n-1 >= lower_bound) r->add_neighbour(LEFT, rooms[n-1]);  //add left neigbour
                if(n-3 >= lower_bound) r->add_neighbour(FORWARD, rooms[n-3]);  //add forward neigbour
                if(n+3 < upper_bound) r->add_neighbour(BACK, rooms[n+3]);  //add back neigbour
                if(n-9 >= 0) r->add_neighbour(UP, rooms[n-9]);  //add roof neigbour
                if(n+9 < 27) r->add_neighbour(DOWN, rooms[n+9]);  //add cellar neigbour
            }
        }
        cube = rooms;
        cout << "Before itemz"<< endl;
        Item *item = new Item("ax");
        cube[0]->add_item(item);
    }
    
    vector<Room*> Game::get_cube(){
        return cube;
    };
    
    Character* Game::get_player(){
        return player;
    }
	bool Game::finished(){
		return false;
	};
    
    vector<string>  Game::processCommand(){
         vector<string> tokens;
         std::string input;
         std::getline(std::cin, input);
         
         std::stringstream ss(input);
         std::string token;
         while(std::getline(ss, token, ' '))
         {
             tokens.push_back(token);
         }

		return tokens;
	};
}
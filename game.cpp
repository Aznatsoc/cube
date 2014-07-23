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
        directions["back"] =BACK;
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
	};

	void Game::play(){
        Room* currentRoom = cube[0];
        player = new Character("Bengan", currentRoom); // TODO ask name and stuff
        
        string command = "";
        bool finished = false;
        while(finished != true){
            cout << "You are in room: " << player->current_room()->description() << endl;
            vector<string> tokens; // Create vector to hold our words
            std::string input;
            std::getline(std::cin, input);
            
            std::stringstream ss(input);
            std::string token;
            while(std::getline(ss, token, ' '))
            {
                tokens.push_back(token);
            }
            
            if (tokens.size() < 1) {
                continue;
            }
            if(tokens[0] == "rotate"){
                if (tokens.size() == 2) {
                    //TODO check if there is a second token otherwise don't call function
                    map<string, unsigned int>::iterator direction_it = directions.find(tokens[1]);
                    if(direction_it != directions.end()){
                        unsigned int dir = direction_it->second;
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
                    map<string, unsigned int>::iterator direction_it = directions.find(tokens[1]);
                    if(direction_it != directions.end()){
                        unsigned int dir = direction_it->second;
                        bool went = player->go(dir);
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
        //create cube
        //four fire_rooms
        //four earth_rooms
        //four water_rooms
        //four air_rooms
        //eleven other rooms

            ///pluppipluu
        
        //create cube of 27 fire_rooms.
        vector<Room*> rooms;
        for (int i = 0; i < 27; ++i) {
            Room *r = new FireRoom(" r" + to_string(i)); //TODO should be const, only game can destroy this objects
            rooms.push_back(r);
        }
        
        //shuffle
        std::random_shuffle ( rooms.begin(), rooms.end() );

       // std::cout <<  rooms.size()  << std::endl;
        for (int i = 0; i < 3; ++i) {
            int lower_bound= i*9;
            int upper_bound = (i+1)*9;
            for (int n = lower_bound; n < upper_bound; ++n) {
                Room* r = rooms[n];
                if((n+1)%3 > 0 && n+1 < upper_bound) r->add_neighbour(RIGHT, rooms[n+1]);  //add right
                if((n-1)%3 != 2 && n-1 >= lower_bound) r->add_neighbour(LEFT, rooms[n-1]);  //add left
                if(n-3 >= lower_bound) r->add_neighbour(FORWARD, rooms[n-3]);  //add forward
                if(n+3 < upper_bound) r->add_neighbour(BACK, rooms[n+3]);  //add back
                if(n-9 >= 0) r->add_neighbour(UP, rooms[n-9]);  //add roof
                if(n+9 < 27) r->add_neighbour(DOWN, rooms[n+9]);  //add cellar
                //std::cout <<  r->description()  << std::endl;
            }
        }
        
        cube = rooms;


    }
    
    vector<Room*> Game::get_cube(){
        return cube;
    };
    
	bool Game::finished(){
		return false;
	};
	bool Game::processCommand(){
		return false;
	};
}
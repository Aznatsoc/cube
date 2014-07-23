#include "game.h"
#include <string>
#include <climits>
#include <cmath>
#include <algorithm>    // std::random_shuffle

namespace cube
{
	Game::Game(){
		setup();
	};
	
	Game::~Game(){
		//tear down all rooms, characters and items!
		//TODO remove the items in the vectors, otherwise memory leakage
	};

	void Game::play(){
        Room* currentRoom = cube[5];
        player = new Character("Bengan", currentRoom);
        
        cout << "You ARE in room: " << currentRoom->description() << endl;
        
        cout << "Player are in room: " << player->currentRoom()->description() << endl;
		
        string command = "";
        bool finished = false;
        while(finished != true){
            cin >> command;

            if(command == "rotate"){
                currentRoom->rotate();
            }else if(command == "exit"){
                finished = true;
            }
            cout << "You are in room: " << currentRoom->description() << endl;
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

        
        //create cube of 27 fire_rooms.
        vector<Room*> rooms;
        for (int i = 0; i < 27; ++i) {
            Room *r = new FireRoom(" r" + to_string(i));
            rooms.push_back(r);
        }
        
        //shuffle
        std::random_shuffle ( rooms.begin(), rooms.end() );

        std::cout <<  rooms.size()  << std::endl;
        for (int i = 0; i < 3; ++i) {
            int lower_bound= i*9;
            int upper_bound = (i+1)*9;
            for (int n = lower_bound; n < upper_bound; ++n) {
                Room* r = rooms[n];
                if((n+1)%3 > 0 && n+1 < upper_bound) r->add_neighbour(n+1, rooms[n+1]);  //add right
                if((n-1)%3 != 2 && n-1 >= lower_bound) r->add_neighbour(n-1, rooms[n-1]);  //add left
                if(n-3 >= lower_bound) r->add_neighbour(n-3, rooms[n-3]);  //add up
                if(n+3 < upper_bound) r->add_neighbour(n+3, rooms[n+3]);  //add down
                if(n-9 >= 0) r->add_neighbour(n-9, rooms[n-9]);  //add roof
                if(n+9 < 27) r->add_neighbour(n+9, rooms[n+9]);  //add cellar
                std::cout <<  r->description()  << std::endl;
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
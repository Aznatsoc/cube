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
        is_finished = false;
        is_exit = false;
        while(!is_finished || !is_exit){
            Room* tmp_room =player->current_room();
            string tmp_str = tmp_room->description();
            cout << "You are in room: " << tmp_str <<endl;
            
            processCommand(); // Create vector to hold our words
        
            if (tokens.size() < 1) {
                continue;
            }
            pfunc f = commands[tokens[0]]; //todo check that it is a valid command
            (this->*f)();
        }
	};
    
    void Game::exit(){
        cout << "exit function are called"<<endl;
        is_exit = true;
    }
    
    void Game::drop(){
        cout << "drop function are called"<<endl;
        if (validate_if_next_argument()) {
            Item* item = player->remove_item(tokens[1]);
            //todo check items not in backpack
            player->current_room()->add_item(item);
            cout << player->backpack_description()<<endl;
        }else{
            cout << "You need to specify what object to drop" << endl;
        }
    }
    
    void Game::pickup(){
        cout << "pickup function are called"<<endl;
        if (validate_if_next_argument()) {
            Item* item = player->current_room()->remove_item(tokens[1]);
            //todo pickup items not in room
            player->add_item(item);
            cout << player->backpack_description()<<endl;
        }else{
            cout << "You need to specify what object to pickup" << endl;
        }

    }
    
    void Game::rotate(){
        cout << "rotate function are called"<<endl;
        if (validate_if_next_argument()) {
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

    }
    
    void Game::go(){
        cout << "go function are called"<<endl;
        if (validate_if_next_argument()) {
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
    
    bool Game::validate_if_next_argument(){
        return (tokens.size() == 2);
    }

	void Game::setup(){
        setup_cube_structure();
        //items
        setup_items();
        //characters
        Room* currentRoom = cube[0]; //start game in this room
        player = new Character("Bengan", currentRoom); // TODO ask name and stuff
        cout<< "before enter room" << endl;
        currentRoom->enter(player);
        
        commands["exit"] = &Game::exit;
        commands["drop"] = &Game::drop;
        commands["pickup"] = &Game::pickup;
        commands["rotate"] = &Game::rotate;
        commands["go"] = &Game::go;

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
    }
    
    void Game::setup_items(){
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
    
    void Game::processCommand(){
         vector<string> tmp_tokens;
         std::string input;
         std::getline(std::cin, input);
         
         std::stringstream ss(input);
         std::string token;
         while(std::getline(ss, token, ' '))
         {
             tmp_tokens.push_back(token);
         }

		tokens = tmp_tokens;
	};
}
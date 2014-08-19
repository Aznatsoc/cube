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
#include "unistd.h"


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

    Character* Game::get_player(){
        return player;
    }
	void Game::play(){
        has_fifth_element = false;
        is_exit = false;
        look();
        cout << endl;

        while(!finished() && !is_exit){
        	cout << ">";
            processCommand(); // Create vector to hold our words
        
            cout << endl;

            if (tokens.size() < 1) {
                continue;
            }else if(tokens.size() == 2){ //there is a second argument specified
                std::map<string, Game::pfunc_args>::iterator command_arg_it =commands_with_arguments.find(tokens[0]);
                if(command_arg_it != commands_with_arguments.end()){
                    pfunc_args f = command_arg_it->second;
                    (this->*f)(tokens[1]);
                }
            }else{
                std::map<string, Game::pfunc>::iterator command_it = commands.find(tokens[0]);
                if(command_it != commands.end()){
                    pfunc f = command_it->second;
                    (this->*f)();
                }else{
                    error_input_handler(tokens[0]);
                }
            }

            cout << endl;

            
            if(!has_fifth_element){
                create_fifth_element(); //try to create fifth element
            }
        }
	};
    
    void Game::error_input_handler(string command){
        if(command == "use" || command == "drop" || command == "pickup"  ){
            cout << "You need to specify which item to "  << command<< endl;
        }else if(command == "go"){
            cout << "You need to specify in what direction to "  << command<< endl;
        }else{
            cout << "Sorry, did not recognize the command '" << command  << "'" << endl; //todo print all possible commands
            
        }
    }
    
    void Game::exit(){
        cout << "Thanks for playing!"<<endl;
        is_exit = true;
        //remove game??
    }

    void Game::help() {
    	std::string help_text = "\nSo you need help buddy?, the availible commands without arguments are: ";

        std::map<std::string, Game::pfunc>::iterator it = commands.begin();

        for (it=commands.begin(); it!=commands.end(); ++it){
            help_text += it->first + ", ";
        }
        
        std::map<std::string, Game::pfunc_args>::iterator it2 = commands_with_arguments.begin();
        
        help_text += "\nCommands with arguments are: ";

         for (it2=commands_with_arguments.begin(); it2!=commands_with_arguments.end(); ++it2){
            help_text += it2->first + ", ";
        }
        cout << help_text << endl;
    }

    void Game::inventory() {
    	cout << player->backpack_description()<<endl;
    }

    void Game::look() {
    	cout << player->current_room()->description() << endl;

    }
        
    void Game::rotate(){
        player->current_room()->rotate();
    }
    
    void Game::drop(string item_name){
        
        Item* item = player->remove_item(item_name); //todo how to see that the remove was correct?
        if(item != NULL){
            player->current_room()->add_item(item);
            
        }else{
            cout << item_name << " does not exist in your backpack!" << endl;
        }
        cout << player->backpack_description()<<endl;
    }

    
    void Game::pickup(string item_name){
        Item* item = player->current_room()->remove_item(item_name); //todo how to see that the remove was correct?
        player->add_item(item);
        cout << player->backpack_description()<<endl;
    }
    
    void Game::go(string direction){
        map<string, int>::iterator direction_it = directions.find(direction);
        if(direction_it != directions.end()){
            int dir = direction_it->second;
            player->go(dir);
        }else{
            cout << "This is not a direction, misspelled?" << endl;
        }
    }
    
    void Game::use(string item_name){
        Item* item = player->remove_item(item_name); //todo how to see that the remove was correct, aka error input handling?
           if(item != NULL){ //todo best practise to return null???
               if(item->name() == "fifth_element"){
                   has_fifth_element = true;
               }else{
                   try {
                       string evolve_name = item->evolve(player->current_room()->type());
                        Item* evolve_item = new Item(evolve_name);
                        player->current_room()->add_item(evolve_item);
                   }catch(string e){
                        cout << "why not here???"<<endl;
                        cout << e << endl;
                   }
               }
               delete item;
               
           }else{
               cout << "The item did not exists" << endl;
           }
            //todo check if null, aka the item did not exist in the container
           
           
            //todo
            //impact character

           
            //stuff should happen
    }
    
    void Game::blow(){
        cout << "You are blowing!" << endl;
        if(player->current_room()->type() == "air"){
            AirRoom* air_room = (AirRoom*) player->current_room();
           air_room->change_wind(100);
            cout << "The wind in this room is up to " << air_room->wind()<<" m/s"<<endl;
        }else if(player->current_room()->type() == "fire"){
            //increase fire and make it dangerous
        }else{
            cout << "But nothing happens..." <<endl;
        }
    }
    
    void Game::health(){
        cout << "You current health is at astonishing: " <<  player->life()<< endl;
    }
    
    void Game::talk(string character_name){
            Character* character = player->current_room()->get_character(character_name); //todo read only for type so to access talk
            //TODO if character does not exist...

            if(character == nullptr) {		// Error handling if character does not exist in the room
            	cout << "The character " << character_name << " does not exist in this room, what are you? Blind?" << endl;
            	return;
            }

            string learnable_command = character->communicate(player);; // and not allways do you learn commands!!
            
            //TODO TODO
            if(learnable_command == "blow"){
                cout << "You have learned to make air!! You can increase wind power!" << endl;
                std::map<string, Game::pfunc>::iterator learn_it = learnable_commands.find(learnable_command);
                if(learn_it != learnable_commands.end()){
                    commands[learnable_command] = learn_it->second;//todo move learned function from learnable<#statements#>_commands map to commands
                }
            }else{
                cout << learnable_command << endl;
            }
    }
    
    void Game::create_fifth_element(){
        Room* current_room = player->current_room();
        if(current_room->type() == "air"){
            AirRoom* air_room = (AirRoom*) current_room; //Todo, only want to cast
            if(air_room->wind() >= 500 && current_room->contains_item("fire") && current_room->contains_item("bubbles") && current_room->contains_item("dust")){
                cout << "You have creted the fifth element!!" << endl;
                Item* fifth_element = new Item("fifth_element");
                player->add_item(fifth_element);
            }
        }
    }

	void Game::setup(){
        setup_cube_structure();
        setup_items();
        setup_characters();
        //welcome_the_game();
        setup_player();
        setup_commands();
    };
    
    void Game::setup_commands(){
        commands["exit"] = &Game::exit;
        commands["rotate"] = &Game::rotate;
        commands["health"] = &Game::health;
        commands["help"] = &Game::help;
        commands["inventory"] = &Game::inventory;
        commands["look"] = &Game::look;
        
        commands_with_arguments["go"] = &Game::go;
        commands_with_arguments["use"] = &Game::use;
        commands_with_arguments["talk"] = &Game::talk;
        commands_with_arguments["drop"] = &Game::drop;
        commands_with_arguments["pickup"] = &Game::pickup;
        
        learnable_commands["blow"] = &Game::blow;
        
        //learnable_commands_with_arguments["whisper"] = &Game::whisper;
    }
    
    void Game::welcome_the_game(){
        cout <<"Welcome to the cube!"<<endl;
        cout <<"We will begin your body upload in..."<<endl;
        for (int i=5; i > 0; --i)
        {
            sleep(1);
            printf("%d...", i);
            fflush(stdout);
        }
        sleep(1);
        printf("\n");
        cout << "* °' *°'~ *~"<<endl;
        sleep(1);

    }
    
    void Game::setup_player(){
        //cout <<"What is your name, body?"<<endl;
        //processCommand();
        Room* currentRoom = cube[0]; //start game in this room
        string name = "lovisa";//tokens[0];
        player = new Air_human(name, currentRoom, "player"); // TODO ask name and stuff
        currentRoom->enter(player);
    }
    
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
        Item *seeds = new Item("seeds");
        Item *seeds2 = new Item("seeds");
        cube[0]->add_item(seeds);
        cube[1]->add_item(seeds2);
        
        Item *bubbles = new Item("bubbles");
        cube[0]->add_item(bubbles);
    }
    
    void Game::setup_characters(){
        cout << "Before characters" << endl;
        Human *wright = new Air_human("Wright", cube[0], "aviator");
        cube[0]->enter(wright);
        
        Animal *bo = new Animal("Bo", cube[0], "snake");
        cube[0]->enter(bo);
    }

	bool Game::finished(){
        if(player->current_room()->type() == "normal" && has_fifth_element){
            cout << "You won the game!!!" << endl;
            return true;
        }else if(player->life() <= 0){
            cout << "You died with 90% burns" << endl;
            return true;
        }
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


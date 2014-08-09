//
//  human.cpp
//
//
//  Created by Lovisa Skeppe on 8/5/14.
//
//

#include "animal.h"
using namespace std;

namespace cube
{
    Animal::Animal(string name, Room *current_room, string animal_type){
        m_name = name;
        m_current_room = current_room;
        m_item_capacity = 1;
        m_type = "animal";
        m_animal_type = animal_type;
        m_life = 200;
    }
    
    string Animal::communicate(Character* c){
        return whisper(c);
    }
    
    string Animal::whisper(Character* c){
        //todo this should be virtual, so all types of characters responds differently, and impact player differently depending on how they communicate.
        //if(type() == "aviator"){
        cout << "I am an animal, do you wanna hear something?" << endl;
        std::string input;
        bool answered = false;
        while(!answered){
            std::getline(std::cin, input);
            if(input == "yes"){
                answered = true; //todo remove??
                return "story";
            }else if(input == "no"){
                answered = true; //todo remove?
                return "Ok, fair enough! Find me later if you change your mind!";
            }else{
                cout << "you have to choose yes or no!"<<endl;
            }
        }
        return "Error";
    };
    
    string Animal::animal_type(){
        return m_animal_type;
    }
    
}
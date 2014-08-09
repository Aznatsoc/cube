#include "air_human.h"
using namespace std;

namespace cube
{
    Air_human::Air_human(string name, Room *current_room, string human_type){
        m_name = name;
        m_current_room = current_room;
        m_item_capacity = 5;
        m_type = "human";
        m_human_type = human_type;
        m_life = 100;
    }
    
    string Air_human::communicate(Character* c){
        return talk(c);
    }
    string Air_human::talk(Character* c){
        //todo this should be virtual, so all types of characters responds differently, and impact player differently depending on how they communicate.
        //if(type() == "aviator"){
        cout << "I am an aviator, do you wanna learn something? .. you learned to blow" << endl;
        std::string input;
        bool answered = false;
        while(!answered){
            std::getline(std::cin, input);
            if(input == "yes"){
                answered = true; //todo remove??
                return "blow";
            }else if(input == "no"){
                answered = true; //todo remove?
                cout << "Ok, fair enough! Find me later if you change your mind!"<<endl;
                return "humbug";
            }else{
                cout << "you have to choose yes or no!"<<endl;
            }
        }
        return "Error";
    };
    
    string Air_human::human_type(){
        return m_human_type;
    }
    
    
    
}
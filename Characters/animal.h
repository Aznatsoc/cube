//
//  human.h
//
//
//  Created by Lovisa Skeppe on 8/5/14.
//
//

#ifndef ANIMAL_H_
#define ANIMAL_H_

#include "character.h"



using namespace std;
namespace cube
{
	class Animal : public Character{
        string m_animal_type;
        string whisper(Character* c);
        
    public:
        Animal(string name, Room *current_room, string animal_type);
        string animal_type();
        string communicate(Character* c);
    };
}
#endif
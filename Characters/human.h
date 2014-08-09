//
//  human.h
//  
//
//  Created by Lovisa Skeppe on 8/5/14.
//
//

#ifndef HUMAN_H_
#define HUMAN_H_

#include "character.h"



using namespace std;
namespace cube
{
	class Human : public Character{
        
    protected:
        string m_human_type;
        
    public:
        string human_type();
        virtual string communicate(Character* c) = 0;
        virtual string talk(Character* c) = 0;
    };
}
#endif
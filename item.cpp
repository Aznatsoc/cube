//
//  item.cpp
//  
//
//  Created by Lovisa Skeppe on 7/24/14.
//
//

#include "item.h"

using namespace std;
namespace cube
{
    Item::Item(){};
    Item::Item(string name){
        m_name = name;
    };
    Item::~Item(){};
    
    string Item::name() const{
        return m_name;
    };
    
    string Item::evolve(string element){
        if(m_name == "seeds"){
            if(element == "earth"){
                return "tree";
            }else if(element == "air"){
                return "dust";
            }else if(element == "fire"){
                return "ash";
            }else if(element == "water"){
                return "bubbles";
            }
        }
        //todo long long list
        throw "Evolve item not implemented";
    }
}

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
}

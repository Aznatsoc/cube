#ifndef ITEM_H_
#define ITEM_H_

#include <iostream>
#include <string>

using namespace std;
namespace cube
{
	class Item{
        protected:
            string m_name;

        public:
            Item();
            Item(string name);
            ~Item();
            string name() const;
		
    };
}
#endif
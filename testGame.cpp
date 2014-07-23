#include "game.h"

#include <vector>
#include <string.h>
#include <iostream>
#include <assert.h>

using namespace std;
using namespace cube;

bool assert_vector(vector<unsigned int> realDeal, vector<unsigned int> created){
    for (unsigned int i = 0; i < realDeal.size(); ++i) {
        if ((unsigned)realDeal[i] != (unsigned)created[i]) {
            cout << realDeal[i] << ": " << created[i]<< endl;
            return false;
        }
    }
    return true;
}
int main(){


	Game g;
    
    vector<Room*> cube = g.get_cube();
    cout << "TESTGAME::" << endl;
    cout << cube.size() << endl;

    vector<unsigned int> test_vector = {1, 3, 9};
    if(assert_vector(cube[0]->directions(), test_vector)) cout << "Cell 0 ok"<<endl;
    test_vector = {2, 0, 4, 10};
    if(assert_vector(cube[1]->directions(), test_vector)) cout << "Cell 1 ok"<<endl;
    test_vector = {1, 5, 11};
    if(assert_vector(cube[2]->directions(), test_vector)) cout << "Cell 2 ok"<<endl;
    //cell 3
    //cell 4
    //cell 5
    //cell 6
    //cell 7
    //cell 8
    //cell 9
    //cell 10
    //cell 11
    //cell 12
    //cell 13
    test_vector = {14, 12, 10, 16, 4, 22};
    if(assert_vector(cube[13]->directions(), test_vector)) cout << "Cell 13 ok"<<endl;
    //cell 14
    //cell 15
    //cell 16
    //cell 17
    //cell 18
    //cell 19
    //cell 20
    //cell 21
    //cell 22
    //cell 23
    //cell 24
    //cell 25
    //cell 26
    test_vector = {25, 23, 17};
    if(assert_vector(cube[26]->directions(), test_vector)) cout << "Cell 26 ok"<<endl;
	return 0;
}
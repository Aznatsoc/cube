#include "room.h"
#include "directions.h"

using namespace std;
namespace cube
{
    Room::Room(){
    }
    
	vector<unsigned int> Room::room_neighbour_id(){
		return m_room_neighbour_id;
	};

	Room* Room::neighbour(unsigned int direction){
        std::map<unsigned int, Room*>::iterator it;
        it=m_neighbours.find(direction);
		//return m_neighbours[direction];
        return it->second;
	};
	
	void Room::add_neighbour(unsigned int direction, Room* r){
		m_neighbours[direction] = r;
        m_room_neighbour_id.push_back(direction);
	};
    
	string Room::description(){
        std::string doors = " The exits you've got are: ";
        int m_doors_size = m_doors.size();
        for (unsigned int i = 0; i < m_doors_size-1; ++i) {
            
            doors += direction_description[m_doors[i]] + ", "; //lookup from enum map
            //oss << ; //std::to_string does not work!!!
        }
        doors +=  direction_description[m_doors[m_doors_size-1]];
        return m_description + doors;
	};
    
    const vector<unsigned int> Room::doors() const{
        return m_doors;
    };
    
	bool Room::enter(Character* c){
        pair<std::map<string,Character*>::iterator,bool> ret;
        ret = m_characters.insert(pair<string,Character*>(c->name(), c));
		return ret.second; //??? todo
	};
	bool Room::leave(Character* c){
        m_characters.erase(c->name());
		return true; //TODO check this
	};

//	bool Room::pick_up(std::string item){
//		return false;
//	};
//	bool Room::drop(Item& it){
//		return false;
//	};
    
    void Room::rotate(unsigned int direction){
        switch(direction){
                cout << "ROTATE DIRECTION " << direction<<endl;
            case RIGHT :
                cout << "ROTATE RIGHT" << endl;
                for(unsigned int i = 0; i < m_doors.size(); ++i){
                    if (m_doors[i] < 4) {
                        m_doors[i] = (m_doors[i]+1)%4;
                    }
                }
                break;
            case LEFT :
                cout << "ROTATE LEFT" << endl;
                for(unsigned int i = 0; i < m_doors.size(); ++i){
                    if (m_doors[i] < 4) {
                        m_doors[i] = (m_doors[i]-1)%4;
                    }
                }
                break;
            case UP :
                cout << "ROTATE UP WEIRD" << endl;
                for(unsigned int i = 0; i < m_doors.size(); ++i){
                    switch (m_doors[i]) {
                        case RIGHT:
                            m_doors[i] = UP;
                            break;
                        case LEFT:
                            m_doors[i] = DOWN;
                            break;
                        case UP:
                            m_doors[i] = LEFT;
                            break;
                        case DOWN:
                            m_doors[i] = RIGHT;
                            break;
                        default:
                            break;
                    }
                }
                break;
            case DOWN :
                cout << "ROTATE UP WEIRD" << endl;
                for(unsigned int i = 0; i < m_doors.size(); ++i){
                    switch (m_doors[i]) {
                        case BACK:
                            m_doors[i] = UP;
                            break;
                        case FORWARD:
                            m_doors[i] = DOWN;
                            break;
                        case UP:
                            m_doors[i] = FORWARD;
                            break;
                        case DOWN:
                            m_doors[i] = BACK;
                            break;
                        default:
                            break;
                    }
                }
                break;
            default :
                cout << "No such direction!" << endl;
        }
    };
}
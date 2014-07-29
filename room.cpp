#include "room.h"

using namespace std;
namespace cube
{
    const std::string Room::direction_description[6] = {"RIGHT", "UP", "FORWARD", "LEFT", "DOWN", "BACK"};
    
    
    Room::Room(){}
    
	vector<int> Room::room_neighbour_id(){
		return m_room_neighbour_id;
	};

	Room* Room::neighbour(int direction){
        std::map<int, Room*>::iterator it;
        it=m_neighbours.find(direction); //Todo, what if end of map??
        return it->second;
	};
	
	void Room::add_neighbour(int direction, Room* r){
		m_neighbours[direction] = r;
        m_room_neighbour_id.push_back(direction);
	};
    
	string Room::description(){
        std::string doors = "\nThe exits you've got are: ";
        int m_doors_size = m_doors.size();
        for (int i = 0; i < m_doors_size-1; ++i) {
            doors += direction_description[m_doors[i]] + ", "; //lookup from enum map
        }
        doors +=  direction_description[m_doors[m_doors_size-1]];
        
        std::string items = "\nThe Items you've got are: ";
        std::map<string,Item*>::iterator it = m_items.begin();
        for (it=m_items.begin(); it!=m_items.end(); ++it){
            items += it->first + ", ";
        }
        return m_description + doors + items;
	};
    
    const vector<int> Room::doors() const{
        return m_doors;
    };
    
	bool Room::enter(Character* c){
        
        //TODO! Instead of action, this can be virtual and all rooms respond differently!
        pair<std::map<string,Character*>::iterator,bool> ret;
        ret = m_characters.insert(pair<string,Character*>(c->name(), c));
        
        //room action will happen, and
        cout << "Greetings " << c->name() << ", ";
        this->action(c);
		return ret.second; //??? true if inserted, false if already existed or
	};
	bool Room::leave(Character* c){
        m_characters.erase(c->name());
        //room action will happen
        this->action(c);
		return true; //TODO check this
	};

    bool Room::add_item(Item* item){
        //cout << "add item" << endl;
        pair<std::map<string,Item*>::iterator,bool> ret;
        ret = m_items.insert(pair<string,Item*>(item->name(), item));
        return ret.second;
        //return false;
    };
    
    Item* Room::remove_item(string item){
        cout << "remove item " << item <<endl;
        std::map<string, Item*>::iterator it = m_items.find(item);
        Item* return_value = it->second;
        m_items.erase(it);
        return return_value;
    }

    void Room::rotate(int direction){
        //TODO, each room will rotate differently to give maximum confusion
        switch(direction){
                cout << "ROTATE DIRECTION " << direction<<endl;
            case RIGHT :
                cout << "ROTATE RIGHT" << endl;
                for(int i = 0; i < m_doors.size(); ++i){
                    if (m_doors[i] < 4) {
                        m_doors[i] = (m_doors[i]+1)%4;
                    }
                }
                break;
            case LEFT :
                cout << "ROTATE LEFT" << endl;
                for(int i = 0; i < m_doors.size(); ++i){
                    if (m_doors[i] < 4) {
                        m_doors[i] = (m_doors[i]-1)%4;
                    }
                }
                break;
            case UP :
                cout << "ROTATE UP WEIRD" << endl;
                for(int i = 0; i < m_doors.size(); ++i){
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
                for(int i = 0; i < m_doors.size(); ++i){
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
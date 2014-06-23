#include "game.h"
#include <string>
#include <climits>
#include <cmath>
namespace cube
{
	Game::Game(){
		setup();
	};
	
	Game::~Game(){
		//tear down all rooms, characters and items!
		//TODO remove the items in the vectors, otherwise memory leakage
	};

	void Game::play(){
		std::cout << "YOU ARE PLAYING";
	};

	void Game::setup(){

	};
	bool Game::finished(){
		return false;
	};
	bool Game::processCommand(){
		return false;
	};
}
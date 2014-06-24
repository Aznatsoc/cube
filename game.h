#ifndef GAME_H_
#define GAME_H_



#include "Rooms/fire.h"
#include <iostream>
#include <vector>
namespace cube
{
	class Game{
		void setup();
		bool finished();
		bool processCommand();

		public:
			Game();
			~Game();

			void play();
	};
}
#endif

// -------------------------------------------	//
//	Project : TetOris							//
//	Name : main.cpp								//
//	Written by : Ram (Hyunsoo Park)				//
//	Generated Date : Feb 05, 2025				//
//	Latest Modify : Mar 06, 2025				//
// -------------------------------------------  //

// DESC :

// RULES : DO NOT USE namespace, it possibly collided to the sfml library namespaces in the worst case.
//		   Using std::cout for debuging is okay, do not nessersary make the console window for the debuging.
//		   Make sure the SFML-3.0 .dll files in the project, need non debuging .dll files w/o -d once it need to be released. 

#include <iostream>
#include "Timer.h"
#include "WindowScreen.h"

int main()
{
	//init Game engine 
	WindowScreen gamestate;
	/*sf::Event event;*/
	Timer time;
	//Timer Starts 
	while (gamestate.bRunning())
	{
		// Update 
		gamestate.update();

		// Render 
		gamestate.render();
	}

	// End of application.
}

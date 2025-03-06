
// -------------------------------------------	//
//	Project : TetOris							//
//	Name : main.cpp								//
//	Written by : Ram (Hyunsoo Park)				//
//	Generated Date : Feb 05, 2025				//
//	Latest Modify : 							//
// -------------------------------------------  //

// DESC :  

#include <iostream>
#include "Timer.h"
#include "GameState.h"

int main()
{	
	//Timer Starts 
	// 
	//init Game engine 
	GameState gamestate;
	/*sf::Event event;*/
	Timer time; 


	while (gamestate.bRunning())
	{
		// Update 
		gamestate.update();

		// Render 
		gamestate.render(); 
	

		
	
	}
	
	// End of application.
}

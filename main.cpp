/* 

Used SFML 3.0 
Fan game of the Tetoris, 
Copyright is reserved t
Made by Ram. 
*/
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

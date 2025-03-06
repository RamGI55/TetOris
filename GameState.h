
// -------------------------------------------	//
//	Project : TetOris							//
//	Name : GameState.h							//
//	Written by : Ram (Hyunsoo Park)				//
//	Generated Date : Feb 05, 2025				//
//	Latest Modify : 							//
// -------------------------------------------  //

// DESC : 


#pragma once

#include "Header.h"

class Tetrisbox; 
class GameState
{
private:
	// Variables
	// Window 
	unsigned int Width = 1920;
	unsigned int Height = 1080; 
	sf::RenderWindow* window;
	sf::VideoMode videomode;
	Tetrisbox* tbox;
	/*sf::Event event;*/


	//Private Functions 
	void InitalizeVariables(); 
	void IntiWindow(); 
public: 


	//Constructors/ Destructors/ 
	GameState();
	virtual ~GameState();
	//Accessors 
	const bool bRunning() const; 


	//Function 
	void pollEvents();
	void update();
	// Render must be refactored to other class -> if you'd like to make a menu. 
	void render(); 
};

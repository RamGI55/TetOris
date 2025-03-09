
// -------------------------------------------	//
//	Project : TetOris							//
//	Name : WindowScreen.h						//
//	Written by : Ram (Hyunsoo Park)				//
//	Generated Date : Feb 05, 2025				//
//	Latest Modify : 							//
// -------------------------------------------  //

// DESC : Manages rendering using SFML.


#pragma once

#include "Header.h"

class Tetrisbox; 
class WindowScreen
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
	WindowScreen();
	virtual ~WindowScreen();
	//Accessors 
	const bool bRunning() const; 


	//Function 
	void pollEvents();
	void update();
	// Render must be refactored to other class -> if you'd like to make a menu. 
	void render();
};

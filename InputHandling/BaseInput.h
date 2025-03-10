
// -------------------------------------------	//
//	Project : TetOris							//
//	Name : BaseInput.h							//
//	Written by : Ram (Hyunsoo Park)				//
//	Generated Date : Feb 05, 2025				//
//	Latest Modify : 							//
// -------------------------------------------  //

// DESC : 

#pragma once

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "../GameLogic/Tetrisbox.h"

class BaseInput
{
private:
	
public: 
	bool bGamepadConnected();
	int getVerticalMovement();
	int getHorizontalMovement(); 
	bool bPressSpacebar(); 
	bool bRightSwitch();
	bool bLeftSwitch();
	Tetrisbox* Tetrisbox;


};


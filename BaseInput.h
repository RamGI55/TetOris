
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

class BaseInput
{
private:
	
public: 
	bool bGamepadConnected();
	int MoveUp();
	int MoveRight(); 
	bool bPressSpacebar(); 
	bool bPressSwitch();


};


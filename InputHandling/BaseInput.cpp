
// -------------------------------------------	//
//	Project : TetOris							//
//	Name : BaseInput.cpp					    //
//	Written by : Ram (Hyunsoo Park)				//
//	Generated Date : Feb 05, 2025				//
//	Latest Modify : 							//
// -------------------------------------------  //

// DESC : 



#include "BaseInput.h"

#include <iostream>

#include "../GameLogic/Tetrisbox.h"
#include "../GameLogic/Tetromino.h"

bool BaseInput::bGamepadConnected()
{
	return sf::Joystick::isConnected(0); 
}

int BaseInput::getVerticalMovement()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
	{
		std::cout << "Moving Up" << std::endl;
		return 1;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
	{
		std::cout << "Moving Down" << std::endl;
		return -1;
	}
	return 0; 
}
int BaseInput::getHorizontalMovement()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
	{
		std::cout << "Moving Right" << std::endl;
		return 1;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
	{
		std::cout << "Moving Left" << std::endl;
		return -1;
	}
	return 0; 
}

bool BaseInput::bPressSpacebar()
{
	return sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space);
}

bool BaseInput::bRightSwitch()
{
	return sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Z);
}

bool BaseInput::bLeftSwitch()
{
	return sf::Keyboard::isKeyPressed(sf::Keyboard::Key::C);
}




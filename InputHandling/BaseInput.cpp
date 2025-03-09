
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
	if (sf::Joystick::isConnected(0)) // this index count works as how many people connected.
	{
		std::cout << "GamePad Connected" << std::endl;
		return true; 
	}
	return false;
}

int BaseInput::MoveUp()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
	{
		std::cout << "Moving Up" << std::endl;
		return 1;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
	{
		std::cout << "Moving Down" << std::endl;
		return -1;
	}
}
int BaseInput::MoveRight()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
	{
		std::cout << "Moving Right" << std::endl;
		return 1;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
	{
		std::cout << "Moving Left" << std::endl;
		return -1;
	}

}

bool BaseInput::bPressSpacebar()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space))
	{
		std::cout << "Pressing Spacebar" << std::endl;
		return true; 
	}
	return false;
}

bool BaseInput::bPressSwitch()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::RShift))
	{
		std::cout << "Pressing Switch" << std::endl;
		return true; 
	}
	return false; 
}




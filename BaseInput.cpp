
// -------------------------------------------	//
//	Project : TetOris							//
//	Name : BaseInput.cpp					    //
//	Written by : Ram (Hyunsoo Park)				//
//	Generated Date : Feb 05, 2025				//
//	Latest Modify : 							//
// -------------------------------------------  //

// DESC : 



#include "BaseInput.h"

bool BaseInput::bGamepadConnected()
{
	if (sf::Joystick::isConnected(0)) // this index count works as how many people connected.
	{
		return true; 
	}
	return false;
}

int BaseInput::MoveUp()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
	{
		return 1;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
	{
		return -1;
	}
}
int BaseInput::MoveRight()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
	{
		return 1;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
	{
		return -1;
	}

}

bool BaseInput::bPressSpacebar()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space))
	{
		return true; 
	}
	return false;
}

bool BaseInput::bPressSwitch()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::RShift))
	{
		return true; 
	}
	return false; 
}



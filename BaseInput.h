#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

// using wasd or keyboard movement 
// filp and drop 
// keyboard or mouse 
// menu - 
// -- 
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


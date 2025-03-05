#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class TetorisMatrix
{
private: 

	sf::RenderWindow& window; // Add this line to declare window as a non-static data member

public: 

	
	void GetRetangles(); 
};

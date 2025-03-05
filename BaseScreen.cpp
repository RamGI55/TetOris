#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream> 
#include "BaseScreen.h"


unsigned int BaseScreen::ScreenWidth = 1920; // or any default value
unsigned int BaseScreen::ScreenHeight = 1080; // or any default value
BaseScreen::BaseScreen()
{

}

BaseScreen::~BaseScreen()
{
}

unsigned int BaseScreen::SetWidth(unsigned int screenwidth)
{
	this->ScreenWidth = screenwidth;
	return ScreenWidth;
}

unsigned int BaseScreen::SetHeight(unsigned int screenheight)
{
	this->ScreenHeight = screenheight; 
	return ScreenHeight;
}

void BaseScreen::ScreenPop()
{
	sf::RenderWindow window(sf::VideoMode({ ScreenWidth, ScreenHeight }), "TETORIS");
	sf::WindowHandle handle = window.getNativeHandle();

	window.setVerticalSyncEnabled(true);
	// This is the Game loop (should refactoring to the gamestates) 
	while (window.isOpen())
	{

		// This will be the game screen 
		sf::RectangleShape cell(sf::Vector2f((CellSize * Multiplier) - 3, (CellSize*Multiplier) - 3));
		cell.setFillColor(sf::Color(255, 255, 255));

		while (const std::optional event = window.pollEvent())
		{
			if (event->is<sf::Event::Closed>())
				window.close();
		}
		// window rendering - must clear the window 
		window.clear();

	for (unsigned char a = 0; a < Columns; a++)
	{
		for (unsigned char b = 0; b < Rows; b++)
		{
            cell.setPosition(sf::Vector2f((CellSize * Multiplier) * a, (CellSize * Multiplier) * b));
			window.draw(cell);
		}
	}
		// must display after. 
		window.display();

	}
}



// -------------------------------------------	//
//	Project : TetOris							//
//	Name : WindowScreen.cpp						//
//	Written by : Ram (Hyunsoo Park)				//
//	Generated Date : Feb 05, 2025				//
//	Latest Modify : 							//
// -------------------------------------------  //

// DESC : 

#include "WindowScreen.h"
#include "../GameLogic/Tetrisbox.h"
#include <chrono> 
#include <iostream>
//Private 
void WindowScreen::InitalizeVariables()
{
	this->window = nullptr; 
	this->tbox = nullptr; 
}

void WindowScreen::IntiWindow()
{
	this->videomode.size = {Width, Height};
	this->window = new sf::RenderWindow(sf::VideoMode(this->videomode.size), "T E T O R I S", sf::Style::Titlebar | sf::Style::Close);
	this->tbox = new Tetrisbox(this->window); 
}

// Constructors 
WindowScreen::WindowScreen()
{
	this->InitalizeVariables();
	this->IntiWindow();

}
// Deconstructors
WindowScreen::~WindowScreen()
{
	delete this->window;
	delete this->tbox;
}
const bool WindowScreen::bRunning() const
{
	return this->window->isOpen(); 
}
//Accessors 

//Function 

void WindowScreen::pollEvents()
{
	while (const std::optional event = window->pollEvent())
	{
		if (event->is<sf::Event::Closed>())
		{
			this->window->close();
		}
		else if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>())
		{
			if (keyPressed->scancode == sf::Keyboard::Scancode::Escape)
				this->window->close();
		}
	}
}

void WindowScreen::update()
{
	this->pollEvents();
}

void WindowScreen::render()
{
	/*
	* clear oldframe 
	* render objects 
	* display frame in window. 
	Renders the game object.
	*/
	const sf::Texture texture("Teto.png");
	sf::Sprite TetoSprite(texture);
	//sprite.setPosition({ Width/2, Height/2 }); // need narrowing conversion 
	TetoSprite.setPosition({ 950.f, 350.f });
	this->window->clear(sf::Color(255, 217, 85, 255)); // (R, G, B, Alpha) 
	
	//Draw the Teto
	this->window->draw(TetoSprite);

	tbox->GetTetrisBox(); // nullptr error 

	//Draw game objects 
	this->window->display();
}



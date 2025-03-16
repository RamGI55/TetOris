
// -------------------------------------------	//
//	Project : TetOris							//
//	Name : WindowScreen.cpp						//
//	Written by : Ram (Hyunsoo Park)				//
//	Generated Date : Feb 05, 2025				//
//	Latest Modify : 							//
// -------------------------------------------  //

// DESC : I am so stupid I put delete tetobox function on the windowscreen. 

#include "WindowScreen.h"
#include "../GameLogic/Tetrisbox.h"
#include <chrono> 
#include <iostream>
#include "../GameLogic/PlayerController.h"
//Private 
void WindowScreen::InitalizeVariables()
{
	
	this->videomode.size = {Width, Height};
	this->window = new sf::RenderWindow(sf::VideoMode(this->videomode.size), "T E T O R I S", sf::Style::Titlebar | sf::Style::Close);
}

// Constructors 
WindowScreen::WindowScreen()
{
	this->InitalizeVariables();
	tbox = new Tetrisbox(window);
}

// Deconstructors
WindowScreen::~WindowScreen()
{
	delete this->window;
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
	static const sf::Time FRAME_DURATION = sf::seconds(1.f /60.f); // 60 frame per second.
	// sfml 3.0 doesn't have any frameduration but need to set the frame rate manually.
	// Set the timer (it is very important)
	sf::Time deltatime = clock.restart();
	lag += deltatime;
	
	while (FRAME_DURATION <= lag)
	{
		lag -= FRAME_DURATION;
		// playercontroller->update(tetromino, tbox);
		
	}
}

void WindowScreen::render()
{
	/*
	* render objects 
	* display frame in window. 
	Renders the game object.
	*/

	// TODO: this will be in the teto class. 
	const sf::Texture texture("Teto.png");
	sf::Sprite TetoSprite(texture);
	//sprite.setPosition({ Width/2, Height/2 }); // need narrowing conversion 
	TetoSprite.setPosition({ 950.f, 350.f });
	this->window->clear(sf::Color(255, 217, 85, 255)); // (R, G, B, Alpha) 
	
	//Draw the Teto
	this->window->draw(TetoSprite);

	// Draw the Tetrisbox. 
	if (this->tbox == nullptr) {
		std::cerr << "Error: tbox is null in render." << std::endl;
	}
	else
	{
		tbox->GetTetrisBox(); // nullptr error
	}
	
	//Draw game objects 
	this->window->display();
}

sf::Clock WindowScreen::clock;
sf::Time WindowScreen::lag; 

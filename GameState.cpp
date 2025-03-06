

// -------------------------------------------	//
//	Project : TetOris							//
//	Name : GameState.cpp						//
//	Written by : Ram (Hyunsoo Park)				//
//	Generated Date : Feb 05, 2025				//
//	Latest Modify : 							//
// -------------------------------------------  //

// DESC : 

#include "GameState.h"
#include "Tetrisbox.h"
#include <iostream>
//Private 
void GameState::InitalizeVariables()
{
	this->window = nullptr; 
	this->tbox = nullptr; 
}

void GameState::IntiWindow()
{
	this->videomode.size = {Width, Height};
	this->window = new sf::RenderWindow(sf::VideoMode(this->videomode.size), "T E T O R I S", sf::Style::Titlebar | sf::Style::Close);
	this->tbox = new Tetrisbox(this->window); 
}

// Constructors 
GameState::GameState()
{
	this->InitalizeVariables();
	this->IntiWindow();

}
// Deconstructors
GameState::~GameState()
{
	delete this->window;
	delete this->tbox;
}
const bool GameState::bRunning() const
{
	return this->window->isOpen(); 
}
//Accessors 

//Function 

void GameState::pollEvents()
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

void GameState::update()
{
	this->pollEvents();
}

void GameState::render()
{
	/*
	* clear oldframe 
	* render objects 
	* display frame in window. 
	Renders the game object.
	*/
	const sf::Texture texture("Teto.png");
	sf::Sprite sprite(texture);
	//sprite.setPosition({ Width/2, Height/2 }); // need narrowing conversion 
	sprite.setPosition({ 950.f, 350.f });
	this->window->clear(sf::Color(255, 217, 85, 255)); // (R, G, B, Alpha) 
	
	//Draw the Teto
	this->window->draw(sprite);

	tbox->GetTetrisBox(); // nullptr error 

	//Draw game objects 
	this->window->display();
}

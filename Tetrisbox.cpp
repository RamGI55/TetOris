
// -------------------------------------------	//
//	Project : TetOris							//
//	Name : Tetrisbox.cpp						//
//	Written by : Ram (Hyunsoo Park)				//
//	Generated Date : Feb 05, 2025				//
//	Latest Modify : 							//
// -------------------------------------------  //

// DESC :



#include "Tetrisbox.h"
#include <iostream>

void Tetrisbox::InitVariables()
{
	this->tetrisboxes = nullptr; 
	this->window = nullptr;
}

void Tetrisbox::InitTetrisbox()
{
    this->tetrisboxes = new sf::RectangleShape(sf::Vector2f((BoxParameter * Multiplier) - 3, (BoxParameter * Multiplier) - 3));
}
// vecotr2f 

Tetrisbox::Tetrisbox(sf::RenderWindow* window)
{
	this->InitVariables();
	this->window = window;
	this->InitTetrisbox();
}

Tetrisbox::~Tetrisbox()
{
	delete tetrisboxes; 
}

const bool Tetrisbox::bTetrisBoxOpen() const
{
	if (this->tetrisboxes != nullptr)
	{
		return true;
	}
	return false;
}

float Tetrisbox::GetColumns() const
{
	return Columns;
}

float Tetrisbox::GetRows() const
{
	return Rows;
}

void Tetrisbox::GetTetrisBox()
{
	if (!window || !tetrisboxes)
	{
		 std::cout << "Unable to generate the tetrisbox." << std::endl; 
	}
	for (unsigned char a = 0; a < Columns; a++)
	{
		for (unsigned char b = 0; b < Rows; b++)
		{
			this->tetrisboxes->setPosition(sf::Vector2f(((BoxParameter* Multiplier) * a + 450), ((BoxParameter * Multiplier) * b+ 150)));


			this->window->draw(*tetrisboxes);
		}
	}
}

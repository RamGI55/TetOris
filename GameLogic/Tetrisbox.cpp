
// -------------------------------------------	//
//	Project : TetOris							//
//	Name : Tetrisbox.cpp						//
//	Written by : Ram (Hyunsoo Park)				//
//	Generated Date : Feb 05, 2025				//
//	Latest Modify : Mar 10, 2025				//
// -------------------------------------------  //

// DESC : 

#include "Tetrisbox.h"
#include <iostream>

void Tetrisbox::InitVariables()
{
	this->tetrisboxes = nullptr; 
	// this->window = nullptr;
}

void Tetrisbox::InitTetrisbox()
{
    this->tetrisboxes = new sf::RectangleShape(sf::Vector2f((BoxParameter * Multiplier) - 3, (BoxParameter * Multiplier) - 3));
}
// vecotr2f 

Tetrisbox::Tetrisbox(sf::RenderWindow* window)
	:window(window), tetrisboxes(nullptr), matrix(Columns, std::vector<unsigned char>(Rows, 0)), clearline (Rows, false)
{
	this->InitVariables();
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
			this->tetrisboxes->setPosition(sf::Vector2f(((BoxParameter* Multiplier) * a + 450), ((BoxParameter * Multiplier) * b + 150)));
			
			this->window->draw(*tetrisboxes);
		}
	}
}

unsigned char Tetrisbox::GetCell(unsigned char x, unsigned char y)
{
	return matrix[x][y];
}

void Tetrisbox::SetCell(unsigned char x, unsigned char y, unsigned char value)
{
	matrix[x][y] = value;
}

bool Tetrisbox::isClearLine(unsigned y) const
{
	return clearline[y];
}

void Tetrisbox::SetClearLine(unsigned y, bool value)
{
	clearline[y] = value;
}

void Tetrisbox::ClearLines()
{
	for (unsigned char a = 0; a < Rows; a++)
	{
		if (clearline[a])
		{
			for (unsigned char b = 0; b < Columns; b++)
			{
				matrix[b][a] = 0;
				for (unsigned char c = a; c > 0; c--)
				{
					matrix[b][c] = matrix[b][c - 1];
					matrix[b][c - 1] = 0;
				}
			}
			clearline[a] = false;
		}
	}
}

void Tetrisbox::Clear()
{
	for (auto& Column: matrix)
	{
		std::fill(Column.begin(), Column.end(), 0);
	}
	std::fill(clearline.begin(), clearline.end(), false);
}




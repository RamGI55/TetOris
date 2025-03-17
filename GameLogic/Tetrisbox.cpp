
// -------------------------------------------	//
//	Project : TetOris							//
//	Name : Tetrisbox.cpp						//
//	Written by : Ram (Hyunsoo Park)				//
//	Generated Date : Feb 05, 2025				//
//	Latest Modify : Mar 16, 2025				//
// -------------------------------------------  //

// DESC : 

#include "Tetrisbox.h"
#include <iostream>

void Tetrisbox::InitTetrisbox()
{
    this->tetrisboxes = new sf::RectangleShape(sf::Vector2f((BoxParameter * Multiplier) - 3, (BoxParameter * Multiplier) - 3));
	if (this->tetrisboxes == nullptr) {
		std::cerr << "Error: tetrisboxes is null after creation." << std::endl;
	} else {
		std::cout << "Tetrisboxes created successfully." << std::endl;
	}
}
// vecotr2f 

Tetrisbox::Tetrisbox(sf::RenderWindow* window)
	:window(window),
	tetrisboxes(nullptr),
	Columns (DEFAULT_COLUMNS), Rows(DEFAULT_ROWS),
	matrix(DEFAULT_COLUMNS, std::vector<unsigned char>(DEFAULT_ROWS, 0)),
	clearline (DEFAULT_ROWS, false),
	CellColors({
	sf::Color (36,36,85),
	sf::Color(0, 219, 255),
	sf::Color(0, 36,255),
	sf::Color (255, 146, 0),
	sf::Color (255, 291, 0 ),
	sf::Color( 0, 219, 0),
	sf::Color (146, 0 , 255),
	sf::Color(219,0,0),
	sf::Color (73,73,85)})
{ 
	this->InitTetrisbox();
	if (this->window == nullptr) {
		std::cerr << "Error: window is null in constructor." << std::endl;
	} else {
		std::cout << "Window initialized successfully." << std::endl;
	}
	
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

void Tetrisbox::SetColums(unsigned int iColumns)
{
	Columns = iColumns;
	matrix.resize(iColumns);
	for (auto& row : matrix)
	{
		row.resize(iColumns);
	}
	clearline.resize(iColumns);
}

void Tetrisbox::SetRows(unsigned int iRows)
{
	Rows = iRows;
	matrix.resize(iRows);
	for (auto& row : matrix)
	{
		row.resize(iRows);
	}
	clearline.resize(iRows);
}

const std::vector<sf::Color>& Tetrisbox::GetCellColours()
{
	return CellColors; 
}

void Tetrisbox::GetTetrisBox()
{
	if (!window) {
		std::cerr << "Error: window is null in GetTetrisBox." << std::endl;
	}
	if (!tetrisboxes) {
		std::cerr << "Error: tetrisboxes is null in GetTetrisBox." << std::endl;
	}
	// Cannot get the tetrisboxes. 
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




#include "TetorisMatrix.h"

TetorisMatrix::TetorisMatrix()
{
	
}

void TetorisMatrix::Retangleshape()
{
	sf::RectangleShape cell(sf::Vector2f(CellSize - 1, CellSize - 1));
	cell.setFillColor(sf::Color(255,0,0))
}

void TetorisMatrix::GetRetangles()
{
	for (unsigned char a = 0; a < Columns; a++)
	{
		for (unsigned char b = 0; b < Rows; b++)
		{
			cell.setPosition(CellSize * a, CellSize * b);
			window.draw(cell);
		}
	}
}


// -------------------------------------------	//
//	Project : TetOris							//
//	Name : Tetromino.cpp						//
//	Written by : Ram (Hyunsoo Park)				//
//	Generated Date : Feb 05, 2025				//
//	Latest Modify : 							//
// -------------------------------------------  //

// DESC : brought teterimono information from TetromioShapes.h 
//		print colour on the tetris box 
//		then drop it automatically in every tick (timeevent) 




#include "Tetromino.h"

Tetromino::Tetromino(unsigned char iShape, const std::vector<std::vector<unsigned char>>& iMatrix, Tetrisbox tetrisbox)
	:rotation(0), shape(iShape), minos(tetromioShapes(iShape, tetrisbox.GetColumns()/ 2, 1))
{

}

Tetromino::~Tetromino()
{

}

unsigned char Tetromino::GetShape()
{
	return shape;
}

void Tetromino::UpdateMatrix(std::vector<std::vector<unsigned char>>& iMatrix, Tetrisbox tetrisbox)
{
		for (Position& mino : minos)
		{
			if (0 > mino.y)
			{
				continue;
			}
			iMatrix[mino.x][mino.y] = 1 + shape;
		}
}

void Tetromino::FlipTetromino()
{

}

// you should think to bring delta time on the movement cause it would works varies by the speed of computer. 
// likewise old shitty dady computer will goes slow, mine goes fucking too fast. 
bool Tetromino::MoveDown(const std::vector<std::vector<unsigned char>>& iMatrix, Tetrisbox tetrisbox)
{
	 
	for (Position& mino : minos)
	{
		// hit the bottom
		if (tetrisbox.GetRows() == 1 + mino.y)
		{
			return 0;
		}

		// hit another tetriominum 
		if (0 < iMatrix[mino.x][1 + mino.y])
		{
			return 0;
		}
	}
	// then, you can go down to 
		for (Position& mino : minos)
		{
			mino.y++; 
		}

		return 1; 
	
}

void Tetromino::MoveLeft(const std::vector<std::vector<unsigned char>>& iMatrix, Tetrisbox tetrisbox)
{
	for (Position& mino : minos)
	{
		if (0 > mino.x - 1)
		{
			return; 
		}

		if (0 > mino.y)
		{
			continue; 
		}

		if (0 < iMatrix[mino.x][mino.y])
		{
			return;
		}
	}
	// continue to the left
	// 
	// until it hits to the far left part of the box.
	// or hits to the
	for (Position& mino : minos)
	{
		mino.x--;
	} 
}

void Tetromino::MoveRight(const std::vector<std::vector<unsigned char>>& iMatrix, Tetrisbox tetrisbox)
{
	for (Position& mino : minos)
	{
		if (tetrisbox.GetColumns() == 0)
		{
			return; 
		}
		if (0 > mino.x)
		{
			continue; 
		}
		if (0 < iMatrix[mino.x][mino.y])
		{
			return;
		}
	}
	for (Position& mino : minos)
	{
		mino.x++; 
	}
}

void Tetromino::Rotate(const std::vector<std::vector<unsigned char>>& iMatrix, Tetrisbox tetrisbox)
{
}


// print colour as the position of the gettetromino. 

//sf::Vector2f((BoxParameter * Multiplier) - 3, (BoxParameter * Multiplier) - 3) //  tetromino box size 
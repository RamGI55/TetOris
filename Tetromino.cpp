
// -------------------------------------------	//
//	Project : TetOris							//
//	Name : Tetromino.cpp						//
//	Written by : Ram (Hyunsoo Park)				//
//	Generated Date : Feb 05, 2025				//
//	Latest Modify : Mar 06, 2025				//
// -------------------------------------------  //

// DESC : brought teterimono information from TetromioShapes.h 
//		print colour on the tetris box 
//		then drop it automatically in every tick (timeevent) 

#include "Tetromino.h"
#include "Tetrisbox.h"
Tetromino::Tetromino(unsigned char iShape, const std::vector<std::vector<unsigned char>>& iMatrix, Tetrisbox* tetrisbox)
	: rotation(0), shape(iShape), minos(tetromioShapes(iShape, tetrisbox->GetColumns() / 2, 1))
{
}

Tetromino::~Tetromino()
{

}

unsigned char Tetromino::GetShape()
{
	return shape;
}

void Tetromino::UpdateMatrix(std::vector<std::vector<unsigned char>>& iMatrix)
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

std::vector<Position> Tetromino::GetGhostMinos(std::vector<std::vector<unsigned char>> iMatrix)
{
	bool KeepFailling = true;
	unsigned char TotalMovement = 0;
	std::vector<Position> GhostMinos = minos;
	while (KeepFailling)
	{
		TotalMovement ++;
		for (Position& mino : minos)
		{
			if (tetrisbox->GetRows() == TotalMovement + mino.y)
			{
				KeepFailling = false;
				break;  
			}
			if (0> TotalMovement + mino.y)
			{
				continue; 
			}
			else if (0< iMatrix [ mino.x][TotalMovement+mino.y])
			{
				KeepFailling = false;
				break; 
			}
		}
	}
	for (Position& mino : GhostMinos)
	{
		mino.y += TotalMovement - 1; 
	}
	return GhostMinos;
}

std::vector<Position> Tetromino::GetMinos()
{
	return minos; 
}

void Tetromino::FlipTetromino()
{

}

// you should think to bring delta time on the movement cause it would works varies by the speed of computer. 
// likewise old shitty dady computer will goes slow, in the based gaming computers the tetromino goes fucking too fast. 
bool Tetromino::MoveDown(const std::vector<std::vector<unsigned char>>& iMatrix)
{
	 
	for (Position& mino : minos)
	{
		// hit the bottom
		if (tetrisbox->GetRows() == 1 + mino.y)
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

void Tetromino::MoveLeft(const std::vector<std::vector<unsigned char>>& iMatrix)
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
	
	for (Position& mino : minos)
	{
		mino.x--;
	} 
}

void Tetromino::MoveRight(const std::vector<std::vector<unsigned char>>& iMatrix)
{
	for (Position& mino : minos)
	{
		if (tetrisbox->GetColumns() == 0)
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

void Tetromino::Rotate(bool Clockwise ,const std::vector<std::vector<unsigned char>>& iMatrix)
{
	// rotating the tetroris box.
	if (shape != 4) // if the shape isn't the 0 shape. 
	{
		unsigned char NextRotation;

		std::vector<Position> Minos;

		if (0 == Clockwise)
		{
			NextRotation = (3 + rotation) % 4;
		}
		else
		{
			NextRotation = (1 + rotation ) % 4;
		}
		// if the i shape
		if (shape == 0)
		{
			float CentreX = 0.5f * (minos[1].x + minos[2].x);
			float CentreY = 0.5f * (minos[1].y + minos[2].y);

			switch (rotation)
			{
			case 0:
				{
					CentreY += 0.5f;
					break;
				}
			case 1:
				{
					CentreX -= 0.5f;
					break;
				}
			case 2:
				{
					CentreY -= 0.5f;
					break;
				}
			case 3:
				{
					CentreX += 0.5f;
				}
			}
			for (Position& mino : minos)
			{
				float x = mino.x - CentreX;
				float y = mino.y - CentreY;

				if (0 == Clockwise)
				{
					mino.x = static_cast<char>(CentreX + y);
					mino.y = static_cast<char>(CentreY - x);
				}
				else
				{
					mino.x = static_cast<char>(CentreX - y);
					mino.y = static_cast<char>(CentreY + x);
				}
			}
		}
		else
		{
			for (unsigned char a = 1; a < minos.size(); a++)
			{
				char x = minos[a].x - minos[0].x;
				char y = minos[a].y - minos[0].y;

				if (0 == Clockwise)
				{
					minos[a].x = y + minos[0].x;
					minos[a].y = minos[0].y - x;
				}
				else
				{
					minos[a].x = minos[0].x - y;
					minos[a].y = x + minos[0].y;
				}
			}
		}
		// Wall kick, check the wall either side of the block, block the turne
		// if the wall was either side. 
	}
}

void Tetromino::HardDrop(const std::vector<std::vector<unsigned char>>& iMatrix)
{
	minos = GetGhostMinos(iMatrix);
}


// print colour as the position of the gettetromino. 

//sf::Vector2f((BoxParameter * Multiplier) - 3, (BoxParameter * Multiplier) - 3) //  tetromino box size 
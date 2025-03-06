
// -------------------------------------------	//
//	Project : TetOris							//
//	Name : TetrominoShapes.hpp					//
//	Written by : Ram (Hyunsoo Park)				//
//	Generated Date : Feb 05, 2025				//
//	Latest Modify : Mar 06, 2025				//
// -------------------------------------------  //

// DESC : brought teterimono shape information

#include <vector>
#include "Header.h"
#include "TetromioShapes.h"

// get vector2 variable for the vector. 

std::vector<Position> tetromioShapes(unsigned char iShape, unsigned char ix, unsigned char iy)
{
	std::vector<Position> gettetromino(4);
	// cause the tetrimono blocks get 4 blocks. 
	switch (iShape)
	{
		case 0: 
		{
			gettetromino[0] = { 1, -1 };
			gettetromino[1] = { 0, -1 };
			gettetromino[2] = { -1, -1 };
			gettetromino[3] = { -2, -1 };
			break; 
		}
		// I block 
		case 1:
		{
			gettetromino[0] = { 0, 0 };
			gettetromino[1] = { -1, 0};
			gettetromino[2] = { -1, -1};
			gettetromino[3] = { 1, 0 };
			break;
		}
		//J shape  
		case 2: 
		{
			gettetromino[0] = { 0, 0 };
			gettetromino[1] = { 0, -1 };
			gettetromino[2] = { -1, 0 };
			gettetromino[3] = { 1, 0 };
			break;

		}
		//middle finger 
		case 3:
		{
			gettetromino[0] = { 0, 0 };
			gettetromino[1] = { -1, 1 };
			gettetromino[2] = { 1, 0 };
			gettetromino[3] = { -1, 0 };
			break;
		}
		// L Shape 
		case 4:
		{
			gettetromino[0] = { 0, 0 };
			gettetromino[1] = { 1, -1 };
			gettetromino[2] = { 0, -1 };
			gettetromino[3] = { -1, 0 };
			break;
		}
		// O Shape 
		case 5:
		{
			gettetromino[0] = { 0, 0 };
			gettetromino[1] = { 0, -1 };
			gettetromino[2] = { 1, -1 };
			gettetromino[3] = { -1, 0 };
			break;
		}
		// S shape 

		case 6:
		{
			gettetromino[0] = { 0, 0 };
			gettetromino[1] = { 0, -1 };
			gettetromino[2] = { -1, -1 };
			gettetromino[3] = { 1, 0 };
			break;
		}
		// Z shape 
	
		
	}

	// print the tetrominos. 
	for (Position& mino : gettetromino)
	{
		mino.x = ix; 
		mino.y = iy; 
	}

	//vector2f 
	return gettetromino; 
}


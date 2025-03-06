
// -------------------------------------------	//
//	Project : TetOris							//
//	Name : Tetromino.h							//
//	Written by : Ram (Hyunsoo Park)				//
//	Generated Date : Feb 05, 2025				//
//	Latest Modify : Mar 06, 2025				//
// -------------------------------------------  //

// DESC : brought teterimono information from TetromioShapes.h 
//		print colour on the tetris box 
//		then drop it automatically in every tick (timeevent) 
// TODO :: MUST USE THE POINTER (*) / & DECLARE INSTEAD THE COPY CONSTRUCTOR for TETOBOX.

#pragma once
#include "GameState.h"
#include <vector>
#include "TetromioShapes.h"

class Tetrisbox; 
class Tetromino
{
private:
	// Variables
	unsigned char rotation;
	unsigned char shape;

	std::vector<Position> minos;
	
	// References
	
public: 
	// Constructors
	Tetromino(unsigned char iShape, const std::vector<std::vector<unsigned char>>& iMatrix , Tetrisbox tetrisbox); // can I set it as 2fVector? 

	// Destructors 
	~Tetromino(); 
	
	// Accessors
	unsigned char GetShape();
	void UpdateMatrix(std::vector<std::vector<unsigned char>>& iMatrix, Tetrisbox tetrisbox);

	// minos and ghost minos. 
	std::vector <Position> GetGhostMinos(std::vector<std::vector<unsigned char>> iMatrix, Tetrisbox tetrisbox);
	std::vector <Position> GetMinos(); 

	// Functions
	void FlipTetromino(); 
	bool Reset(unsigned char i_shape, const std::vector<std::vector<unsigned char>>& iMatrix);
	bool MoveDown(const std::vector<std::vector<unsigned char>> &iMatrix, Tetrisbox tetrisbox);
	void MoveLeft(const std::vector<std::vector<unsigned char>> &iMatrix, Tetrisbox tetrisbox);
	void MoveRight(const std::vector<std::vector<unsigned char>> &iMatrix, Tetrisbox tetrisbox);
	void Rotate(bool Clockwise, const std::vector<std::vector<unsigned char>> &iMatrix, Tetrisbox tetrisbox);
	void HardDrop(const std::vector<std::vector<unsigned char>> &iMatrix, Tetrisbox tetrisbox);
	
};

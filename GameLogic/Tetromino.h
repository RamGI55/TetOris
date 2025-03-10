
// -------------------------------------------	//
//	Project : TetOris							//
//	Name : Tetromino.h							//
//	Written by : Ram (Hyunsoo Park)				//
//	Generated Date : Feb 05, 2025				//
//	Latest Modify : Mar 06, 2025				//
// -------------------------------------------  //

// DESC : 

#pragma once
#include "../CoreGame/WindowScreen.h"
#include <vector>
#include "TetromioShapes.h"

class Tetrisbox; 
class Tetromino
{
private:
	// Variables
	Tetrisbox* tetrisbox;
	unsigned char rotation;
	unsigned char shape;

	std::vector<Position> minos;
	// References
	
public: 
	// Constructors
	Tetromino(unsigned char iShape, const std::vector<std::vector<unsigned char>>& iMatrix , Tetrisbox* tetrisbox);
	// Check the SF-003 Note. 

	// Destructors 
	~Tetromino(); 
	
	// Accessors
	unsigned char GetShape();
	void UpdateMatrix(std::vector<std::vector<unsigned char>>& iMatrix);

	// minos and ghost minos. 
	std::vector <Position> GetGhostMinos(std::vector<std::vector<unsigned char>> iMatrix);
	std::vector <Position> GetMinos(); 

	// Functions
	void FlipTetromino(); 
	bool Reset(unsigned char i_shape, const std::vector<std::vector<unsigned char>>& iMatrix);
	bool MoveDown(const std::vector<std::vector<unsigned char>> &iMatrix);
	void MoveLeft(const std::vector<std::vector<unsigned char>> &iMatrix);
	void MoveRight(const std::vector<std::vector<unsigned char>> &iMatrix);
	void Rotate(bool Clockwise, const std::vector<std::vector<unsigned char>> &iMatrix);
	void HardDrop(const std::vector<std::vector<unsigned char>> &iMatrix);
	
};

#pragma once
#include "GameState.h"
#include <vector>
#include "Tetrisbox.h"
#include "TetromioShapes.h"

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

	~Tetromino(); 

	// Accessors
	unsigned char GetShape();
	void UpdateMatrix(std::vector<std::vector<unsigned char>>& iMatrix, Tetrisbox tetrisbox);

	// Functions
	void FlipTetromino(); 
		// move the tetromio 
			// down 
	bool MoveDown(const std::vector<std::vector<unsigned char>> &iMatrix, Tetrisbox tetrisbox);
	void MoveLeft(const std::vector<std::vector<unsigned char>>& iMatrix, Tetrisbox tetrisbox);
	void MoveRight(const std::vector<std::vector<unsigned char>> &iMatrix, Tetrisbox tetrisbox);
	void Rotate(const std::vector<std::vector<unsigned char>> &iMatrix, Tetrisbox tetrisbox);




};

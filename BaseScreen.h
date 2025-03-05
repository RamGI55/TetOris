
#pragma once
#include "TetorisMatrix.h"
class BaseScreen
{
private: 
	static unsigned int ScreenWidth; 
	static unsigned int ScreenHeight; 
	// Those sizes must be relevent to the screen size. 
	float CellSize = 7.5f;
	float Columns = 10.0f;
	float Rows = 20.0f;
	float Multiplier = 4.0f;
	
public: 
	BaseScreen();
	~BaseScreen(); 
	unsigned int SetWidth(unsigned int screenwidth);
	unsigned int SetHeight(unsigned int screenheight);
	void ScreenPop();

};


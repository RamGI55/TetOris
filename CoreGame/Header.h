

// -------------------------------------------	//
//	Project : TetOris							//
//	Name : Header.h								//
//	Written by : Ram (Hyunsoo Park)				//
//	Generated Date : Feb 05, 2025				//
//	Latest Modify : 							//
// -------------------------------------------  //

// DESC : Core minimum headers to run the game. 

#pragma once 
#include <Windows.h>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <math.h>
#include <iostream>

//delta time in the Header.h? if I'd like to use the animation on the menu. 

constexpr unsigned char SOFT_DROP_SPEED = 1;
constexpr unsigned char MOVE_SPEED = 2;
struct Position
{
	char x;
	char y; 
};
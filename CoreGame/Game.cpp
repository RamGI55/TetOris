
// -------------------------------------------	//
//	Project : TetOris							//
//	Name : Game.cpp					            //
//	Written by : Ram (Hyunsoo Park)				//
//	Generated Date : Feb 05, 2025				//
//	Latest Modify : Mar 10, 2025				//
// -------------------------------------------  //

// DESC : This is for the whole game loops


#include "Game.h"
#include <SFML/System.hpp>

Game::Game()
    :event(event),tetrisbox (tetrisbox),
    tetromino(static_cast<unsigned char> (ShapeDistribution(RandomEngine)), tetrisbox.matrix),
    controller(input),
    falltimer(0),
    movetimer(0),
    softdroptimer(0),
    gameover(false),
    harddroppressed(false),
    rotatepressed(false)
    
{   // need the constructor list here 
    // Make the game loop in here.
    timer.Reset(); 
}

void Game::Run()
{
    while (windowscreen.bRunning())
    {
        windowscreen.pollEvents(); 
        windowscreen.update();
        windowscreen.render(); 
    }
}

void Game::ResetGame()
{
        gameover = false;
    // this is for the status when reseting the game.
}

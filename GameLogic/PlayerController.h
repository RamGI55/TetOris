
// -------------------------------------------	//
//	Project : TetOris							//
//	Name : PlayerController.h					//
//	Written by : Ram (Hyunsoo Park)				//
//	Generated Date : Mar 09, 2025				//
//	Latest Modify : Mar 10, 2025				//
// -------------------------------------------  //

// DESC : Handles player input, movement, and actions. Sends input to the server in multiplayer.

#pragma once
#include "Tetromino.h"
#include "../CoreGame/Header.h"
#include "../GameLogic/Tetromino.h"
#include "../GameLogic/Tetrisbox.h"
#include "../InputHandling/BaseInput.h"
class PlayerController
{
public:
    PlayerController(BaseInput& input);
    void update(Tetromino& tetromino, Tetrisbox& tetrisbox);
    void HandleKeyRelase(sf::Keyboard::Key key);

    
private:
    BaseInput& input;
    bool rotatepressed;
    bool harddroppressed;
    unsigned char movetimer;
    unsigned char softdroptimer;

    // Move to the header if those have the problem. 
   
    
};



// -------------------------------------------	//
//	Project : TetOris							//
//	Name : PlayerControl.h						//
//	Written by : Ram (Hyunsoo Park)				//
//	Generated Date : Mar 09, 2025				//
//	Latest Modify : Mar 09, 2025				//
// -------------------------------------------  //

// DESC : Handles player input, movement, and actions. Sends input to the server in multiplayer.

#pragma once
#include "Tetromino.h"
#include "../CoreGame/Header.h"
#include "../InputHandling/BaseInput.h"
class PlayerControl
{
public:

    // handling the player input, here is the tetromino, all movements must be sent to the server. 
        // down
    void InputDown();
        // left
    void InputLeft();
        // right
    void InputRight();
        // flip
    void Inputflip();
        // hard drop
    void InputHarddrop();
    
protected:

private:

public:
    BaseInput* BaseInput;
    Tetromino* Tetromino;
protected:
    
private: 
};




// -------------------------------------------	//
//	Project : TetOris							//
//	Name : PlayerController.cpp					//
//	Written by : Ram (Hyunsoo Park)				//
//	Generated Date : Mar 09, 2025				//
//	Latest Modify : Mar 10, 2025				//
// -------------------------------------------  //

// DESC : Handles player input, movement, and actions. Sends input to the server in multiplayer.


#include "PlayerController.h"


PlayerController::PlayerController(BaseInput& input)
    :input(input), rotatepressed(false), harddroppressed(false), movetimer(0), softdroptimer(0)
{
}

void PlayerController::update(Tetromino& tetromino, Tetrisbox& tetrisbox)
{
    int verticalmovemnt = input.getVerticalMovement();
    int horizontalmovemnt = input.getHorizontalMovement();

    if (verticalmovemnt == 1)
    {
        
    }
    else if (verticalmovemnt == -1)
    {
        if (softdroptimer == 0)
        {
            if (tetromino.MoveDown(tetrisbox.matrix))
            {
                softdroptimer = 1;
            }
        }
        else
        {
            softdroptimer = (1+ softdroptimer) % SOFT_DROP_SPEED;
        }
    }

    if (horizontalmovemnt == 1)
    {
        if (movetimer == 0)
        {
            tetromino.MoveRight(tetrisbox.matrix);
            movetimer = 1; 
        }
        else
        {
            movetimer = (1 + movetimer) % MOVE_SPEED;
        }
    }
    else if (horizontalmovemnt == -1)
    {
        if (movetimer == 0)
        {
            tetromino.MoveLeft(tetrisbox.matrix);
            movetimer = 1; 
        }
        else
        {
            movetimer = (1 + movetimer) % MOVE_SPEED;
        }
    }
    if (input.bPressSpacebar() && !harddroppressed)
    {
        harddroppressed = true;
        tetromino.HardDrop(tetrisbox.matrix);
    }
    if (input.bRightSwitch())
    {
        // implant the logic for the right rotation 
    }
    if (input.bLeftSwitch())
    {
        // implant the logic for the left rotation. 
    }
}

void PlayerController::HandleKeyRelase(sf::Keyboard::Key key)
{
    if (key == sf::Keyboard::Key::C || key == sf::Keyboard::Key::Z)
    {
        rotatepressed = false;
    }
    else if (key == sf::Keyboard::Key::Down)
    {
        softdroptimer = 0;
    }
    else if (key == sf::Keyboard::Key::Left || key == sf::Keyboard::Key::Right)
    {
        movetimer = 0; 
    }
    else if (key == sf::Keyboard::Key::Space)
    {
        harddroppressed = false;
    }
}


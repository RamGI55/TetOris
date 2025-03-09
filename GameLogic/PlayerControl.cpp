#include "PlayerControl.h"


void PlayerControl::InputDown()
{
    if (!BaseInput)
    {
        std::cout << "Controller input hasn't been loaded!" << std::endl;
    }
    if (BaseInput->MoveUp()  == -1)
    {
        if (Tetromino)
        {
             
        }
        // move the tetromino left 
    }
}

void PlayerControl::InputLeft()
{
    if (!BaseInput)
    {
        std::cout << "Controller input hasn't been loaded!" << std::endl;
    }
    if (BaseInput->MoveRight() == -1)
    {
       // move the tetromino left 
    }
}

void PlayerControl::InputRight()
{
    if (!BaseInput)
    {
        std::cout << "Controller input hasn't been loaded!" << std::endl;
    }
    if (BaseInput->MoveRight() == 1)
    {
        // move the tetromino right .
    }
}

void PlayerControl::Inputflip()
{
    if (!BaseInput)
    {
        std::cout << "Controller input hasn't been loaded!" << std::endl;
    }
    if (BaseInput->bPressSwitch() == true)
    {
        // flip the tetrnomino 
    }
}

void PlayerControl::InputHarddrop()
{
    if (!BaseInput)
    {
        std::cout << "Controller input hasn't been loaded!" << std::endl;
    }
    if (BaseInput->bPressSpacebar() == true)
    {
        // Hard drop for the spacebar 
    }
}






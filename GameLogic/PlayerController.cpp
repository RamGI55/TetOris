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
            if (tetromino.MoveDown(tetrisbox))
            {
                softdroptimer = 1;
            }
        }
        else
        {
           
         }
    }
}


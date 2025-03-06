
// -------------------------------------------	//
//	Project : TetOris							//
//	Name : WallKick.h							//
//	Written by : Ram (Hyunsoo Park)				//
//	Generated Date : Mar 06, 2025				//
//	Latest Modify : Mar 06, 2025				//
// -------------------------------------------  //

// DESC : Even the writer cannot understand how to make the wall kick.
//        Sit back, relax, and mark the red dot, see what exactly works in the debug once it is done. 

#include "WallKick.h"

std::vector<Position> WallKick::GetWallKick(bool IShape, unsigned char ICurrentRotation, unsigned char INewRoatation)
{
    // when it is the i shape
    if (IShape == 0)
    {
        switch (ICurrentRotation)
        {
        case 0:
        case 2:
            {
                switch (INewRoatation)
                {
                case 1:
                    {
                        // change the block if you can make a wall kick.
                        return {{0, 0}, {-1, 0}, {-1, -1}, {0, 2}, {-1, 2}};
                    }
                case 3:
                    {
                        return {{0, 0}, {1, 0}, {1, -1}, {0, 2}, {1, 2}};
                    }
                }
                // why he makes the double depth of the switch?? 
            }
        case 1:
            {
                return {{0, 0}, {1, 0}, {1, 1}, {0, -2}, {1, -2}};
            }
        case 3:
            {
                return {{0, 0}, {-1, 0}, {-1, 1}, {0, -2}, {-1, -2}};
            }
        }
        return{ {0,0}} ; // cannot be kicked back. 
    }
    else
    {
        switch (INewRoatation)
        {
            case 0:
                {
                    switch (INewRoatation)
                    {
                        case 1:
                            {
                                return {{0, 0}, {-2, 0}, {1, 0}, {-2, 1}, {1, -2}};
                            }
                        case 3:
                            {
                                return {{0, 0}, {-1, 0}, {2, 0}, {-1, -2}, {2, -1}};
                            }
                    }
                }
            case 1:
                {
                    switch (INewRoatation)
                    {
                        case 0:
                            {
                                return {{0, 0}, {2, 0}, {-1, 0}, {2, -1}, {-1, 2}};
                            }
                        case 2:
                            {
                                return {{0, 0}, {-1, 0}, {2, 0}, {-1, -2}, {2, 1}};
                            }
                    }
                }
            case 2:
                {
                    switch (INewRoatation)
                    {
                    case 1:
                        {
                            return {{0, 0}, {1, 0}, {-2, 0}, {1, 2}, {-2, -1}};
                        }
                    case 3:
                        {
                            return {{0, 0}, {2, 0}, {-1, 0}, {2, -1}, {-1, 2}};
                        }
                    }
                } 
            case 3:
                {
                    switch (INewRoatation)
                    {
                    case 0:
                        {
                            return {{0, 0}, {1, 0}, {-2, 0}, {1, 2}, {-2, -1}};
                        }
                    case 2:
                        {
                            return {{0, 0}, {-2, 0}, {1, 0}, {-2, 1}, {1, -2}};
                        }
                    }
                }
            }
            return { {0,0} } ; 
        }
    }

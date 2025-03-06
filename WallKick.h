
// -------------------------------------------	//
//	Project : TetOris							//
//	Name : WallKick.h							//
//	Written by : Ram (Hyunsoo Park)				//
//	Generated Date : Mar 06, 2025				//
//	Latest Modify : Mar 06, 2025				//
// -------------------------------------------  //

// DESC : 

#pragma once
#include "Header.h"
#include <vector> 

class WallKick
{
public:
    std::vector<Position> GetWallKick(bool IShape, unsigned char ICurrentRotation, unsigned char INewRoatation); 
    
};

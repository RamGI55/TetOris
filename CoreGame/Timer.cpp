
// -------------------------------------------	//
//	Project : TetOris							//
//	Name : Timer.cpp					        //
//	Written by : Ram (Hyunsoo Park)				//
//	Generated Date : Feb 05, 2025				//
//	Latest Modify : Mar 10, 2025				//
// -------------------------------------------  //

// DESC : 


#include "Timer.h"

Timer::Timer()
{
    Reset();   
}
// using the CPU ticks.

Timer::~Timer()
{
}

void Timer::Reset()
{
    Starttime = std::chrono::steady_clock::now();
    Previoustime = Starttime; 
}

unsigned Timer::GetElapsedTime() const
{
    return std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now() - Starttime).count();
}

unsigned Timer::GetDeltaTime()
{
    // is that swaping mechanism??
    auto CurrentTime = std::chrono::steady_clock::now();
    unsigned DeltaTime = std::chrono::duration_cast<std::chrono::milliseconds>(CurrentTime - Previoustime).count();
    Previoustime = CurrentTime;
    return DeltaTime;
}

bool Timer::HasElapsed(unsigned duration) const
{
     return GetElapsedTime() >= duration;
}





// -------------------------------------------	//
//	Project : TetOris							//
//	Name : Timer.cpp					        //
//	Written by : Ram (Hyunsoo Park)				//
//	Generated Date : Feb 05, 2025				//
//	Latest Modify : 							//
// -------------------------------------------  //

// DESC : 


#include "Timer.h"

Timer::Timer()
    : PeriodFrequency(0), LastTime(0), TimeScale(0), CurrentTime(0), DeltaTime(0)
{
    QueryPerformanceFrequency((LARGE_INTEGER*)&PeriodFrequency);
    QueryPerformanceCounter((LARGE_INTEGER*)&LastTime); 
    TimeScale = 1.0 / PeriodFrequency; 
}
// using the CPU ticks.

Timer::~Timer()
{
}

void Timer::Update()
{
    QueryPerformanceCounter((LARGE_INTEGER*)&CurrentTime);

    DeltaTime = (CurrentTime - LastTime) * TimeScale; 

    LastTime = CurrentTime; 
}

double Timer::GetDeltaTime()
{
    return DeltaTime;
}


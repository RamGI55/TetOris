#pragma once
#include"Header.h"
#include<profileapi.h>
class Timer
{
private: 
	const double PeriodFrequency; 
	double LastTime; 
	double TimeScale;
	double CurrentTime; 
	double DeltaTime;

public: 
	Timer();
	~Timer();
	void Update(); 
	double GetDeltaTime(); 
};


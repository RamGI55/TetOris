
// -------------------------------------------	//
//	Project : TetOris							//
//	Name : Timer.h								//
//	Written by : Ram (Hyunsoo Park)				//
//	Generated Date : Feb 05, 2025				//
//	Latest Modify : Mar 10, 2025				//
// -------------------------------------------  //

// DESC : This is for the timer function seperate from the main function to encapsulate.
//		 it is for the anything and everything need delicated function, like animation, spinning teto
//		 dropping the teto, your shitty movement, your mom chats... everything!

#pragma once
#include"Header.h"
#include<profileapi.h>
class Timer
{
public: 
	Timer();
	~Timer();
	void Update(); 
	void Reset();
	unsigned GetElapsedTime() const;
	unsigned GetDeltaTime();
	bool HasElapsed(unsigned duration) const;
	

	
private: 
	std::chrono::time_point<std::chrono::steady_clock> Starttime;
	std::chrono::time_point<std::chrono::steady_clock> Previoustime;
	


	
};


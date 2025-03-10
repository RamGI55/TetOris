
// -------------------------------------------	//
//	Project : TetOris							//
//	Name : Game.h					            //
//	Written by : Ram (Hyunsoo Park)				//
//	Generated Date : Feb 05, 2025				//
//	Latest Modify : Mar 10, 2025				//
// -------------------------------------------  //

// DESC : 

#pragma once
#include <chrono>
#include <random>
#include <SFML/Window/Event.hpp>
#include "../GameLogic/Tetromino.h"
#include "../GameLogic/Tetrisbox.h"
#include "../CoreGame/Timer.h"

class Game
{
public:
    Game();
    void Run();
    void ProcessEvents();
    void Update();
    void Render();
    void spawnTetromino(); 
    void ResetGame();

private:
    sf::RenderWindow window; 
    sf::Event event;
    std:: default_random_engine RandomEngine;
    std::uniform_int_distribution<unsigned short> ShapeDistribution;

    Tetromino tetromino;
    Tetrisbox tetrisbox;
    WindowScreen windowscreen;
    static sf::Clock clock; 
    Timer timer; 

    // gamestate variables, is that transfer to the gamestate after? 
    unsigned char NextShape;
    static sf::Time lag;
    unsigned linescleared;
    unsigned char cleareffecttimer;
    unsigned char currentfallspeed;
    unsigned char falltimer;
    unsigned char movetimer;
    unsigned char softdroptimer;
    
    bool gameover;
    bool harddroppressed;
    bool rotatepressed; 

    
    
    
};

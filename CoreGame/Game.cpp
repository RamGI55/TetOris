
// -------------------------------------------	//
//	Project : TetOris							//
//	Name : Game.cpp					            //
//	Written by : Ram (Hyunsoo Park)				//
//	Generated Date : Feb 05, 2025				//
//	Latest Modify : Mar 10, 2025				//
// -------------------------------------------  //

// DESC : This is for the whole game loops 

#include "Game.h"
#include <SFML/System.hpp>

Game::Game()
    
{   // need the constructor list here 
    // Make the game loop in here.
    
}

void Game::Run()
{
    while (window.isOpen())
    {
        ProcessEvents();
        Update();
        Render(); 
    }
}

void Game::ProcessEvents()
{
    while (const std::optional event = window.pollEvent())
    {
        if (event->is<sf::Event::Closed>())
        {
            this->window.close();
        }
        else if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>())
        {
            if (keyPressed->scancode == sf::Keyboard::Scancode::Escape)
                this->window.close();
        }
    }
}

void Game::Update()
{
    static const sf::Time FRAME_DURATION = sf::seconds(1.f /60.f); // 60 frame per second.
    // sfml 3.0 doesn't have any frameduration but need to set the frame rate manually.
    // Set the timer (it is very important)
    sf::Time deltatime = clock.restart();
    lag += deltatime;
    
    while (FRAME_DURATION <= lag)
    {
        lag -= FRAME_DURATION;

        
    }
    // if the 
}

void Game::ResetGame()
{
    // this is for the status when I resting the game.
}

#pragma once
#include <chrono>
#include <SFML/Window/Event.hpp>

class Game
{
public:
    Game();
    void Run();
    void ProcessEvents();
    void Update();
    void Render();
    void ResetGame();

private:
    sf::Event events;
    
    
};

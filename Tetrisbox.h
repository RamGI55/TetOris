#pragma once 
#include "GameState.h"
class Tetrisbox
{
private:
    // Variables for the tetris box 
    float BoxParameter = 8.0f;
    float Multiplier = 5.0f; 
    float Columns = 10.0f;
    float Rows = 20.0f;
    sf::RectangleShape* tetrisboxes; 
    sf::RenderWindow *window;

    // initiate tetris box 
    void InitVariables(); 
    void InitTetrisbox();

public: 
    // constructors/deconstructors 

    Tetrisbox(sf::RenderWindow* window);
    virtual ~Tetrisbox(); 

    // Accessors 
    const bool bTetrisBoxOpen() const; 
    float GetColumns() const;
    float GetRows() const; 

    // Functions
    void GetTetrisBox();
};

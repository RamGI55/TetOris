
// -------------------------------------------	//
//	Project : TetOris							//
//	Name : Tetrisbox.h							//
//	Written by : Ram (Hyunsoo Park)				//
//	Generated Date : Feb 05, 2025				//
//	Latest Modify : Mar 10, 2025				//
// -------------------------------------------  //

// DESC : what the fuck is any difference between tetobox and matrix??
//      

#pragma once

#include "../CoreGame/WindowScreen.h"
class Tetrisbox
{
private:
  
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
    // I trust you, chatGPT. 
    unsigned char GetCell(unsigned char x, unsigned char y);
    void SetCell(unsigned char x, unsigned char y, unsigned char value);
    bool isClearLine(unsigned y) const;
    void SetClearLine(unsigned y, bool value);
    void ClearLines();
    void Clear(); 
    std::vector<std::vector<unsigned char>> matrix; // must be accessible for the input mechanism.

    // Functions
    void GetTetrisBox();

private:
    // Variables for the tetris box 
    float BoxParameter = 8.0f;
    float Multiplier = 5.0f; 
    float Columns = 10.0f;
    float Rows = 20.0f;
    sf::RectangleShape* tetrisboxes; 
    sf::RenderWindow *window;
   
    std::vector<bool> clearline;
};


// -------------------------------------------	//
//	Project : TetOris							//
//	Name : Tetrisbox.h							//
//	Written by : Ram (Hyunsoo Park)				//
//	Generated Date : Feb 05, 2025				//
//	Latest Modify : Mar 16, 2025				//
// -------------------------------------------  //

// DESC : what the fuck is any difference between tetobox and matrix??
//      

#pragma once

#include "../CoreGame/Header.h"
#include "../CoreGame/WindowScreen.h"

/*
const unsigned int DEFAULT_COLUMNS = 10;
const unsigned int DEFAULT_ROWS = 20;
*/

class Tetrisbox
{
private:
  
    // initiate tetris box 
    void InitTetrisbox();
    sf::RectangleShape* tetrisboxes; 
    sf::RenderWindow* window;
    std::vector<bool> clearline;
    std::vector<sf::Color> CellColors; 

public: 
    // constructors/deconstructors 

    Tetrisbox(sf::RenderWindow* window);
    virtual ~Tetrisbox(); 

    // Accessors 
    const bool bTetrisBoxOpen() const; 
    // Getters
    float GetColumns() const;
    float GetRows() const;
    // Setters 
    void SetColums(unsigned int iColumns);
    void SetRows(unsigned int iRows);
    // I trust you, chatGPT. 
    unsigned char GetCell(unsigned char x, unsigned char y);
    void SetCell(unsigned char x, unsigned char y, unsigned char value);
    bool isClearLine(unsigned y) const;
    void SetClearLine(unsigned y, bool value);

    void ClearLines();
    void Clear(); // ???
    
    std::vector<std::vector<unsigned char>> matrix; // must be accessible for the input mechanism.
    const std::vector<sf::Color>& GetCellColours();

private:
    // Variables for the tetris box 
    float BoxParameter = 8.0f;
    float Multiplier = 5.0f; 
    float Columns; 
    float Rows;

public:
    void GetTetrisBox();
    
};

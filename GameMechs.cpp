#include "GameMechs.h"
#include "MACUILib.h"
#include <iostream>

using namespace std;

GameMechs::GameMechs()
{
    input = 0;
    exitFlag = false;
    loseFlag = false;
    score = 0;
    boardWidth = 30;
    boardHeight = 15; 

    snakeFood = new Food();
}

GameMechs::GameMechs(int boardX, int boardY)
{
    input = 0;
    exitFlag = false;
    loseFlag = false;
    score = 0;
    boardWidth = boardX;
    boardHeight = boardY;

    snakeFood = new Food();    
}

// Clean up allocated memory
GameMechs::~GameMechs()
{
    delete snakeFood;
}

bool GameMechs::getExitFlagStatus() const
{
    return exitFlag;
}

bool GameMechs::getLoseFlagStatus() const
{
    return loseFlag;
}
    
char GameMechs::getInput() 
{
    //getting the exit flag 
    return input;
}

int GameMechs::getScore() const
{
    return score;
}

void GameMechs::incrementScore()
{
    score++;
}

void GameMechs::incrmntScore10()
{
    score+=10;
}

void GameMechs::incrmntScore50()
{
    score+=50;
}
// Get board's width
int GameMechs::getBoardSizeX() const
{
    return boardWidth;
}
// Get board's height
int GameMechs::getBoardSizeY() const
{
    return boardHeight;
}

void GameMechs::setExitTrue()
{
    exitFlag = true;
}

void GameMechs::setLoseFlag()
{
    loseFlag = true;
}
// Set input character
void GameMechs::setInput(char this_input)
{
    input = this_input;
}
// Clear input
void GameMechs::clearInput()
{
    input = '\0';
}

void GameMechs::cllctAsyncInput() 
{
    if(MacUILib_hasChar() != '\0') 
    {
        input = MacUILib_getChar();
    }
}

// Returns a pointer to the snakeFood member field
Food* GameMechs::getFood() 
{
    return snakeFood;
}
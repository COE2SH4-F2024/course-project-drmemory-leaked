#include "Player.h"
#include <iostream>
using namespace std;


Player::Player(GameMechs* thisGMRef)
{
    mainGameMechsRef = thisGMRef;
    myDir = STOP;

    // more actions to be included
    playerPosList = new objPosArrayList();
    //creating starting position
    objPos headPos(mainGameMechsRef->getBoardSizeX() / 2, (mainGameMechsRef->getBoardSizeY() / 2),'@');
    playerPosList->insertHead(headPos);
}


Player::~Player()
{
    // delete any heap members here
    delete playerPosList;
}

objPosArrayList* Player::getPlayerPos() const
{
    // return the reference to the playerPos arrray list
    return playerPosList;
}

void Player::updatePlayerDir()
{
    //getting our input
    char input = mainGameMechsRef->getInput();
    mainGameMechsRef->clearInput();
    // PPA3 input processing logic
    switch(input)
    {
        //upwards movement
        case 'w':
            if(myDir != UP && myDir != DOWN)
            {
                myDir = UP;
            }
            break;  
            //leftwards movement
        case 'a':
            if(myDir != LEFT && myDir != RIGHT)
            {
                myDir = LEFT;
            }
            break;   
            //downwards movement
        case 's':           
            if(myDir != UP && myDir != DOWN)
            {
                myDir = DOWN;
            }
            break;   
            //rightwards movement
        case 'd':
            if(myDir != LEFT && myDir != RIGHT)
            {
                myDir = RIGHT;  
            }
            break;
        case 27: // esc stop the snake
            myDir = STOP;
            break;
            
        case '-': //Ends game
            mainGameMechsRef->setExitTrue();
            break;
    }
              
}

void Player::movePlayer()
{
    //objPos newHead;
    objPos tempPos = playerPosList -> getHeadElement();
    // PPA3 Finite State Machine logic
    switch (myDir)
    {
        // The below cases change either the x or y position depending on direction
        case UP:
            tempPos.pos->y--;
            break;
        case DOWN:
            tempPos.pos->y++;
            break;
        case LEFT:
            tempPos.pos->x--;
            break;
        case RIGHT:
            tempPos.pos->x++;
            break;
        default:
            break;
    }

    // Border wraparound logic
    if(tempPos.pos->x <= 0) {
        tempPos.pos->x = mainGameMechsRef->getBoardSizeX()-2;
    } else if(tempPos.pos->x >= mainGameMechsRef->getBoardSizeX()-1) {
        tempPos.pos->x = 1;
    }

    if(tempPos.pos->y <= 0) {
        tempPos.pos->y = mainGameMechsRef->getBoardSizeY()-2;
    } else if (tempPos.pos->y >= mainGameMechsRef->getBoardSizeY()-1) {
        tempPos.pos->y = 1;
    }

    // Insert the new snake head with the updated position
    playerPosList->insertHead(tempPos);
    
    if(checkFoodConsumption() == 1) {
            mainGameMechsRef->incrementScore();
            mainGameMechsRef->getFood()->generateFood(playerPosList, mainGameMechsRef->getBoardSizeX(), mainGameMechsRef->getBoardSizeY());
        }
    else if(checkFoodConsumption() == 2) {
            mainGameMechsRef->incrmntScore10();
            mainGameMechsRef->getFood()->generateFood(playerPosList, mainGameMechsRef->getBoardSizeX(), mainGameMechsRef->getBoardSizeY());
        }
    else if(checkFoodConsumption() == 3) {
            mainGameMechsRef->incrmntScore50();
            mainGameMechsRef->getFood()->generateFood(playerPosList, mainGameMechsRef->getBoardSizeX(), mainGameMechsRef->getBoardSizeY());
            for (int i = 0; i<9; i++) {
                objPos tempTail = playerPosList->getTailElement();
                playerPosList->insertTail(tempTail);
            }
        } 
        else {
            playerPosList->removeTail();
        }
    
    if(checkSelfCollision()) {
        mainGameMechsRef->setExitTrue();
        mainGameMechsRef->setLoseFlag();
    }
}
 

// More methods to be added
int Player::getDirection() {
    return myDir;
}

//this method allows us to define the conditions on which a snake has consumed food on the board.
int Player::checkFoodConsumption() {
    for(int i=0; i<mainGameMechsRef->getFood()->getFoodPos()->getSize(); i++) {
        //if the head of the snake is at an equivalent position to a food object.
        if(playerPosList->getHeadElement().pos->x == mainGameMechsRef->getFood()->getFoodPos()->getElement(i).pos->x && playerPosList->getHeadElement().pos->y == mainGameMechsRef->getFood()->getFoodPos()->getElement(i).pos->y) {
            //What type of food object are we colliding with? We change our return values depending on this, as it will allow us to adjust our
            //score increments and other snake properties inside movePlayer().
            if (mainGameMechsRef->getFood()->getFoodPos()->getElement(i).getSymbol() == 'o') {
                return 1;
            }
            else if (mainGameMechsRef->getFood()->getFoodPos()->getElement(i).getSymbol() == 'c') {
                return 2;
            }
            else if (mainGameMechsRef->getFood()->getFoodPos()->getElement(i).getSymbol() == '0') {
                return 3;
            }
        }
    }

    return 0;
}

bool Player::checkSelfCollision() {
    //Begin incrementing at i = 1 to avoid comparing the head element with index i = 0, which in other words are the same object.
    for (int i = 1; i < playerPosList->getSize(); i++)
    {
        //If the head of the snake is at an equivalent position to another snake block in the list, then we have ran into ourself.
        if(playerPosList->getHeadElement().pos->x == playerPosList->getElement(i).pos->x && playerPosList->getHeadElement().pos->y == playerPosList->getElement(i).pos->y) {
            return true;
        }
    }

    return false;
}
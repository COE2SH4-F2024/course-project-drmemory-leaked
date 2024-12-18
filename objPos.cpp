#include "objPos.h"

objPos::objPos()
{
    pos = new Pos;
    pos->x = 0;
    pos->y = 0;
    symbol = 0; //NULL
}

objPos::objPos(int xPos, int yPos, char sym)
{
    pos = new Pos;
    pos->x = xPos;
    pos->y = yPos;
    symbol = sym;
}

// Respect the rule of six / minimum four
objPos::~objPos()
{
    delete pos;
}

objPos::objPos(const objPos &obj)
{
    pos = new Pos;
    pos->x = obj.pos->x;
    pos->y = obj.pos->y;
    symbol = obj.getSymbol();
}

objPos &objPos::operator=(const objPos &obj)
{
    if(this != nullptr) {
        if(pos != nullptr){
            delete pos;
        }
        
        pos = new Pos;
        pos->x = obj.pos->x;
        pos->y = obj.pos->y;
        symbol = obj.getSymbol();
    }

    return *this;
}

void objPos::setObjPos(objPos o)
{
    pos->x = o.pos->x;
    pos->y = o.pos->y;
    symbol = o.symbol;
}

void objPos::setObjPos(int xPos, int yPos, char sym)
{
    pos->x = xPos;
    pos->y = yPos;
    symbol = sym;
}

objPos objPos::getObjPos() const
{
    objPos returnPos;
    returnPos.pos->x = pos->x;
    returnPos.pos->y = pos->y;
    returnPos.symbol = symbol;
    
    return returnPos;
}

char objPos::getSymbol() const
{
    return symbol;
}
// Checls if postion is equal to reference position
bool objPos::isPosEqual(const objPos* refPos) const
{
    return (refPos->pos->x == pos->x && refPos->pos->y == pos->y);
}
// Return symbol if position maches reference position
char objPos::getSymbolIfPosEqual(const objPos* refPos) const
{
    if(isPosEqual(refPos))
        return symbol;
    else
        return 0;
}

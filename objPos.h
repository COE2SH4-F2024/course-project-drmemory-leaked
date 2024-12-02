#ifndef OBJPOS_H
#define OBJPOS_H

// Not really a C++ thing
typedef struct
{
    int x;
    int y;
} Pos;

class objPos
{
    public:
        Pos* pos;
        char symbol;

        objPos();
        objPos(int xPos, int yPos, char sym);

        ~objPos();
        objPos(const objPos &obj);
        objPos& operator=(const objPos &obj);

        void setObjPos(objPos o);        
        void setObjPos(int xPos, int yPos, char sym);  
        objPos getObjPos() const;
        char getSymbol() const;

        bool isPosEqual(const objPos* refPos) const;
        
        char getSymbolIfPosEqual(const objPos* refPos) const;
};

#endif
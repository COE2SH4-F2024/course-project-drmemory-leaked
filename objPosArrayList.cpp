#include "objPosArrayList.h"

objPosArrayList::objPosArrayList()
{
    aList = new objPos[ARRAY_MAX_CAP]; 
    currSize = 0; // no valid element in the list upon startup
    arrayCapacity = ARRAY_MAX_CAP; //array capacity should be max
}

objPosArrayList::objPosArrayList(int size)
{
    currSize = 0;
    arrayCapacity = size;
    aList = new objPos[ARRAY_MAX_CAP];
}

objPosArrayList::~objPosArrayList()
{
    delete[] aList; //remember to use delete[] to call the destructor of all instances in the array
}                   

int objPosArrayList::getSize() const
{
    return currSize;
}
// Inserts new element at the head of array list
void objPosArrayList::insertHead(objPos thisPos)
{
    if(currSize == arrayCapacity)
    {
        //the snake cannot extend any farther because it's at its max size
        return;
    }

    // shift the elements back by one slot to make room for the inclusion of the head
    for(int i=currSize; i>0; i--)
    {
        aList[i] = aList[i-1]; 
    }

    //set the new head at the provided object position and increase the size of the snake
    aList[0] = thisPos;
    currSize++; 

}

void objPosArrayList::insertTail(objPos thisPos)
{
    if(currSize == arrayCapacity)
    {
        return;
    }

    // Place the new element at the end of the array
    aList[currSize] = thisPos;
    currSize++; 
}

void objPosArrayList::removeHead()
{
    if (currSize == 0){
        return;
    }

    //shift all the elements one position towards the tail
    for(int i = 0; i<currSize-1; i++){
        aList[i] = aList[i+1];
    }
    //decrease the size of snake
    currSize--;
}

void objPosArrayList::removeTail()
{
    if (currSize == 0){
        return;
    }
    // Simply decrease the size as the last element is "removed"
    currSize--;
}

objPos objPosArrayList::getHeadElement() const
{
    return aList[0];
}

objPos objPosArrayList::getTailElement() const
{
    return aList[currSize-1]; // Return last element
}

objPos objPosArrayList::getElement(int index) const
{
    if (index < 0 || index >= currSize)
    {
        return objPos();// Return a default objPos object if index is out of bounds
    }

    return aList[index];
}
#ifndef FOOD_H
#define FOOD_H
#include "objPosArrayList.h"

#define MAX_FOOD_ITEMS 5

class Food {
private:
    objPosArrayList* foodList;
public:
    Food();
    ~Food();

    void generateFood(objPosArrayList* blockOff, int xLim, int yLim); //Generates food items at random positions within specified limits,
    objPosArrayList* getFoodPos() const;
};

#endif
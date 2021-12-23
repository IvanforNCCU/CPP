//
// Created by 劉子御 on 2021/12/20.
//

#ifndef _WORLD_H
#define _WORLD_H
#include <iostream>
//#include "Creature.h"
//#include "Goat.h"
//#include "Grass.h"
#include "RandomNum.h"

using namespace std;

class Creature;



class World {
    public:
    World(int numPasses, int seed);//seed, pass, first grass, goat
    void mainLoop(int displayInterval);//scan and act. Use pass to determine how many times
    bool notEdge(int raw, int col);//determine coordinate is on the edge or not, return true if is ok
    void vanish(int raw, int col);
    void kill(int raw, int col);//delete the cell and point to NULL,
    void putCreature(int raw, int col,Creature* A);//point to the new creature
    Creature* getCreature(int raw, int col);//pick up the creature and do action
    bool isEmpty(int raw, int col);//check the cell is empty or not
    int getRandom(int low, int high);
    private:
    Creature* board[20][35];
    char ZaWorld[20][35];
    RandomNum random;
    int pass;
    int day;
};


#endif //_WORLD_H

//
// Created by 劉子御 on 2021/12/20.
//

#ifndef _GRASS_H
#define _GRASS_H
#include "Creature.h"

class Grass: public Creature {
public:
    Grass(int a, int b, World &w);
    virtual ~Grass(){};
    virtual void act();
    void born(int a, int b);
};


#endif //_GRASS_H

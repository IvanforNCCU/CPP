//
// Created by 劉子御 on 2021/12/20.
//

#ifndef _GOAT_H
#define _GOAT_H
#include "Creature.h"

class Goat: public Creature{
public:
    Goat(int a, int b, World &w);//also change the symbol to X
//    virtual void aging();
    virtual ~Goat(){};
    virtual void act();
    void born(int a, int b);
    void eat(int a, int b);
    void move(int next_x, int next_y);//

private:
    int foodPoint;
};


#endif //GOAT_H

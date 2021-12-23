//
// Created by 劉子御 on 2021/12/20.
//

#ifndef _CREATURE_H
#define _CREATURE_H
#include "World.h"

class World;

class Creature {
    public:
     Creature(int a, int b, World &world);
//     virtual void aging()=0;//control death
     virtual ~Creature(){};
     virtual void act()=0;//two creatures have different movement
//     void setPosition(int a, int b);
     int getx();
     int gety();
     char getSymbol();
     bool getDone();
//     void yetDone();
     void setDone(bool s);


    protected:
     int x;
     int y;
     int age;
     bool done;
     char symbol;
     World& reality;
};


#endif //_CREATURE_H

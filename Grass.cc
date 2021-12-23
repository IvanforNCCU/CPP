//
// Created by 劉子御 on 2021/12/20.
//

#include "Grass.h"


Grass::Grass(int a, int b, World &w):Creature(a,b,w) {
    symbol = 'I';
    done = true;
    age = 0;
}

void Grass::act() {
    int way = reality.getRandom(1,4);// 1=x+1, 2=y+1, 3=x-1,4=y-1
    bool legality;
    bool iamEmpty;
    int next_x, next_y;

    if(way == 1){
        next_x = x+1;
    }else if(way == 2){
        next_y = y+1;
    }else if(way == 3){
        next_x = x-1;
    }else if(way == 4){
        next_y = y-1;
    }//Determine where to go first
    legality = reality.notEdge(next_x,next_y);
    iamEmpty = reality.isEmpty(next_x,next_y);

    if(age>=3 || age<=5){
        //Check if it is legal and born the kid
        if(legality && iamEmpty){
            born(next_x,next_y);
        }
    }
    age++;
    setDone(true);
    if(age>=6){
        reality.kill(x,y);
    }
}

void Grass::born(int a, int b) {
    Creature* baby = new Grass(a,b,reality);
    reality.putCreature(a,b,baby);
}

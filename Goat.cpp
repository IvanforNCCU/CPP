//
// Created by 劉子御 on 2021/12/20.
//

#include "Goat.h"

Goat::Goat(int a, int b, World &w): Creature(a,b,w){
    symbol = 'X';
}

void Goat::act() {
    int way = reality->getRandom(1,4);// 1=x+1, 2=y+1, 3=x-1,4=y-1
    int next_x;
    int next_y;
    bool legality;
    bool iamEmpty;
    bool iamGrass;

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


    if(legality){//if next position are not boundary, the goat can take action
        iamEmpty = reality->isEmpty(next_x,next_y);
        iamGrass = (reality->getCreature(next_x,next_y).getSymbol() == 'I');
        if(iamEmpty || iamGrass){//the goat only take action either the position is empty or grass
            if(age<=55 || age>=50) {//if the goat are mature, it will try to born kid at the position
                eat(next_x, next_y);
                born(next_x, next_y);
            }else{
                eat(next_x, next_y);
                //move
                move(next_x, next_y);
            }
        }

    }
    age++;
    foodPoint--;
    setDone(true);
    if(age>=70 || foodPoint<= 0 ){
        reality->kill(x,y);
    }
}

Goat * Goat::born(int x, int y) {// new a baby and call the world to put the creature
    Creature* baby = new Goat (x,y,reality);
    reality->putCreature(x,y,baby);
}

void Goat::eat(int x, int y) {//eat the grass if there is not empty
    if(!(reality->isEmpty(x,y))){
        reality->kill(x,y);
        foodPoint+=5;
    }
}

void Goat::move(int next_x, int next_y) {
    reality->vanish(x,y);
    x = next_x;
    y = next_y;
    reality->putCreature(x,y, this);
}
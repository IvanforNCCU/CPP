//
// Created by 劉子御 on 2021/12/20.
//

#include "World.h"

World::World(int numPasses, int seed):random(seed) {
    pass = numPasses;
    int count_goat = 0;
    int count_grass = 0;
    //這裡要新增生物: 5goat 10grass
    while(count_goat<5){
        int x1, y1;
        x1 = getRandom(0,19);
        y1 = getRandom(0,34);
        if(isEmpty(x1,y1)){
            Creature* baby = new Goat(x1,y1,this);
            putCreature(x1,y1,baby);
            count_goat++;
        }
    }//add goats when the chosen cell is empty, until the counter of goat are > 5
    while(count_grass<10){
        int x1, y1;
        x1 = getRandom(0,19);
        y1 = getRandom(0,34);
        if(isEmpty(x1,y1)){
            Creature* baby = new Grass(x1,y1,this);
            putCreature(x1,y1,baby);
            count_grass++;
        }
    }
}

void World::mainloop(int displayInterval) {
    while(day<pass){
        // scan the board and make everyone move
        for(int d =0;d <20;d++){
            for(int k=0;k<35;k++){
                if(isEmpty(d,k) == false){
                    if(board[d][k]->getDone() == false){
                        board[d][k]->act();
                    }
                }
            }
        }
        for(int a=0;a<20;a++){//turn the symbol back to not done & copy to char array
            for(int b=0;b<35;b++){
                if(isEmpty(a,b) == false){
                    board[a][b]->setDone(false);
                    ZaWorld[a][b] = (board[a][b]->getSymbol());
                }else if(isEmpty(a,b)){
                    ZaWorld[a][b] = ' ';
                }
            }
        }
        if((pass%displayInterval) == 0){
            //print the char array if the displayInterval are legal
            for(int raw =0;raw<20;raw++){
                for(int col =0;col<35;col++){
                    cout << ZaWorld[raw][col];
                }
                cout << endl;
            }
            cout <<"------------------------------------------------------------------------ "<<endl;
        }
        day++;
    }
}

bool World::notEdge(int raw, int col) {
    if(raw>=20 || col>=35 || raw<0 || col<0){
        return false;
    }else{
        return true;
    }
}

void World::vanish(int raw, int col) {
    board[raw][col] = NULL;
}

void World::kill(int raw, int col) {
    delete board[raw][col];
    vanish(raw,col);
}

void World::putCreature(int raw, int col, Creature *A) {
    board[raw][col] = A;
}

Creature * World::getCreature(int raw, int col) {
    return board[raw][col];
}

bool World::isEmpty(int raw, int col) {
    if(board[raw][col] == NULL){
        return true;
    }else{
        return false;
    }
}

int World::getRandom(int low, int high) {
    int tmp;
    tmp = random.getRandomNum(low,high);
    return tmp;
}





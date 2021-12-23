//
// Created by 劉子御 on 2021/12/20.
//

#include "Creature.h"
using namespace std;

Creature::Creature(int a, int b, World &w): reality(w){
    x = a;
    y = b;
}

//void Creature::setPosition(int a, int b) {
//    x = a;
//    y = b;
//}

int Creature::getx() {
    return x;
}

int Creature::gety() {
    return y;
}

char Creature::getSymbol() {
    return symbol;
}

bool Creature::getDone() {
    return done;
}

void Creature::setDone(bool s) {
    done = s;
}
//void Creature::yetDone() {
//    done = true;
//}
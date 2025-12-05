#pragma once
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

const int MAX_MONSTRUOS = 100;

class Monster {
private:
    int id;
    string name;
    int hp;
    int hpMax;
    int atk;
    int def;
    int probabilidad;

public:
    // Constructor por defecto
    Monster() : id(0), name(""), hp(0), hpMax(0), atk(0), def(0), probabilidad(0.0) {}
    Monster(int i, string n, int h, int hMx, int a, int df, int prob)
        : id(i), name(n), hp(h), hpMax(hMx), atk(a), def(df), probabilidad(prob) {}

    ~Monster() = default;
    
int   getId() const { 
    return id; 
}
string   getName() const {
    return name;
 }
int   getHp() const { 
    return hp;
 }
int   getHpMax() const {
    return hpMax; 
}
int  getAtk() const {
    return atk; 
}
int   getDef() const {
    return def; 
}
double    getProb() const {
    return probabilidad;
}

void   setHp(int v) { 
    hp = v; 
}   

    
};



#pragma once
#include <iostream>
using namespace std;
#include "Exploracion.h"
#include "Monster.h"
#include "Casilla.h"
#include "Grafo.h"

template <typename T>
class Game {
    private:
        
    public:
        void gameInit();
        int createMap();


};

#include "game.tpp"
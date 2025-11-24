#pragma once
#include <cstdlib>
#include <ctime>
#include "Casilla.h"

#include <iostream>
using namespace std;

template <typename T>
Casilla<T> :: Casilla(int id, const T& nombre, int probmounstro)
    : idCasilla(id), nombreCasilla(nombre), probmounstro(probmounstro) {}

template <typename T>
int Casilla<T> :: hasMonster() {
    srand(time(nullptr));
    int random = rand() % 100;
    int probabilidad = probmounstro ;
    if (random < probabilidad) {
        return 1; // Aparece un monstruo
    } else {
        return 0; // No aparece un monstruo
    }
}

template <typename T>
int Casilla<T> :: getId() const{
    return idCasilla;
}
template <typename T>
T Casilla<T> :: getNombre() const{
    return nombreCasilla;
}
template <typename T>
int Casilla<T> :: getProbMonstruo() const{
    return probmounstro;
}



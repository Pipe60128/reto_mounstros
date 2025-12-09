#pragma once
#include <cstdlib> 
#include <ctime> //Librerías para manejar el tiempo y poder hacer probabilidades
#include "Box.h"

#include <iostream>
using namespace std;

// Implementación de los métodos de la clase Box o Casilla
template <typename T>
Box<T> :: Box(int id, const T& name, int probmonster) // Constructor con parámetros
    : idBox(id), nameBox(name), probmounstro(probmonster) {}

template <typename T>
int Box<T> :: hasMonster() {
    int random = rand() % 100;
    int prob = probmounstro;

    if (random < prob) { // Si el número aleatorio es menor que la probabilidad
        return 1;// Aparece un monstruo
    } else {
        return 0; // No aparece un monstruo
    }
}

template <typename T>
int Box<T> :: getId() const{ // Getter para el ID de la casilla
    return idBox;
}
template <typename T>
T Box<T> :: getName() const{ // Getter para el nombre o tipo de la casilla
    return nameBox;
}
template <typename T>
int Box<T> :: getProbMonstruo() const{ // Getter para la probabilidad de monstruo
    return probmounstro;
}

template <typename T>
void Box<T> :: setProb(int p) { // Setter para la probabilidad de monstruo
    probmounstro = p;
}


#pragma once
#include "Edge.h"

template <typename T> 
T Edge<T> :: getDestino() const {
     return destino; 
    }

template <typename T> 
int Edge<T> :: getPeso() const { 
    return peso;
 }

template <typename T> 
void Edge<T> :: setPeso(int w) { 
    peso = w;
 }


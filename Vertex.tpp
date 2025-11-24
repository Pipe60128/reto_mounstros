#pragma once
#include "Vertex.h"

template <typename T>
Casilla<T> Vertex<T> :: getCasilla() const { //este es mi getData de un grafo normal  
    return casilla; 
}
template <typename T>
bool Vertex<T> :: isVisitado() const { 
    return visitado; 
}
template <typename T>
void Vertex<T> :: setVisitado(bool v) { 
    visitado = v;
 }
template <typename T>
Exploracion<Casilla<T>>& Vertex<T> :: getAdj() { 
    return adj;
 }
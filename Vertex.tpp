#pragma once
#include "Vertex.h"
// Implementación de los métodos de la clase Vertex
template <typename T>
Box<T> Vertex<T> :: getBox() const { //este es mi getData de un grafo normal  
    return casilla; 
}
template <typename T>
bool Vertex<T> :: isVisitado() const { // Marca si el vertice fue visited o no
    return visited; 
}
template <typename T>
void Vertex<T> :: setVisitado(bool v) { // Cambia el estado de visited
    visited = v;
 }
template <typename T>
Exploration<Edge<Box<T>>>& Vertex<T> :: getAdj() {  // Retorna la lista de adyacencia
    return adj;
 }

template <typename T>
int Vertex<T> ::getId() { // Retorna el id de la casilla
    return casilla.getId();
 }

template <typename T>
int Vertex<T>::getDistance() const { // Retorna la distancia desde el nodo inicial
    return distance;
}

template <typename T>
void Vertex<T>::setDistance(int d) { // Establece la distancia desde el nodo inicial
    distance = d;
}
 template <typename T>
Box<T> Vertex<T>::getParent() const { // Retorna el padre del nodo actual
    return parent;
}

template <typename T>
void Vertex<T>::setParent(const Box<T>& p) { // Establece el padre del nodo actual
    parent = p;
}
 
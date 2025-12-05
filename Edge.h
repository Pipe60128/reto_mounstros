#pragma once
#include <iostream>
#include "Box.h"
using namespace std;

// Definición de la clase Edge
template <typename T>
class Edge {
private:
    T destino; // Nodo destino
    int peso; // Peso del edge
    
public:
    Edge(const T& dest, int w) : destino(dest), peso(w) {}
    
    T getDestino() const; // Getter para el destino
    int getPeso() const; // Getter para el peso
    void setPeso(int w); // Setter para el peso
    
    bool operator==(const Edge<T>& other) const { // Sobrecarga del operador de igualdad para comparar edges
        return destino == other.destino;
    }
    
    friend ostream& operator<<(ostream& out, const Edge<T>& e) { // Sobrecarga del operador de cout para imprimir el edge
        cout << e.destino << "\n|      El costo de xp para pasar al siguiente lugar es: (" << e.peso << ")";
        return out;
    }
};
#include "Edge.tpp"
#pragma once
#include <iostream>
#include "Casilla.h"
using namespace std;

template <typename T>
class Edge {
private:
    T destino;
    int peso;
    
public:
    Edge(const T& dest, int w) : destino(dest), peso(w) {}
    
    T getDestino() const;
    int getPeso() const;
    void setPeso(int w);
    
    bool operator==(const Edge<T>& other) const {
        return destino == other.destino;
    }
    
    friend ostream& operator<<(ostream& out, const Edge<T>& e) {
        out << e.destino << "(" << e.peso << ")";
        return out;
    }
};
#include "Edge.tpp"
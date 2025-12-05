#ifndef VERTEX_H
#define VERTEX_H
#include "Box.h"
#include "Exploration.h"
#include "Edge.h"
#include <limits>

// Definición de la clase Vertex
template<typename T>
class Vertex {
private:
    Box<T> casilla;                    // Datos de la casilla simulando T data;
    Exploration<Edge<Box<T>>> adj;    // Lista de casillas adyacentes
    bool visited;
    int distance;
    Box<T> parent;
    
public:
    // Sobrecarga del operador de igualdad para comparar vertices
    bool operator==(const Vertex<T>& c)  const{ 
            return casilla == c.getBox();
        }

    // Sobrecarga del operador de salida para imprimir vertices
    friend ostream& operator<<(ostream& out, const Vertex& c) { 
        out<<c.getBox();
        return out;
    }

    Vertex(const Box<T>& c) : casilla(c) {
        visited = false;
        distance = std::numeric_limits<int>::max();
    }

    // Box methods
    Box<T> getBox() const;
    bool isVisitado() const;
    void setVisitado(bool v);
    int getId();

    // Adjacency methods
    Exploration<Edge<Box<T>>>& getAdj();
    int getDistance() const;
    void setDistance(int d);
    
    // Parent methods
    Box<T> getParent() const;
    void setParent(const Box<T>& p);
    
};

#include "Vertex.tpp"
#endif

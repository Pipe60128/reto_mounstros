#ifndef VERTEX_H
#define VERTEX_H
#include "Casilla.h"
#include "Exploracion.h"
#include "Edge.h"

template<typename T>
class Vertex {
private:
    Casilla<T> casilla;                    // Datos de la casilla simulando T data;
    Exploracion<Casilla<T>> adj;    // Lista de casillas adyacentes
    bool visitado;
    
public:
//sobre craga de operadores
     bool operator==(const Vertex<T>& c)  const{
            return casilla== c.getCasilla();
        }

    
    friend ostream& operator<<(ostream& out, const Vertex& c) {
        out<<c.getCasilla();
        return out;
    }

    Vertex(const Casilla<T>& c) : casilla(c), visitado(false) {}

    Casilla<T> getCasilla() const;
    bool isVisitado() const;
    void setVisitado(bool v);

    Exploracion<Casilla<T>>& getAdj();
    
};

#include "Vertex.tpp"
#endif

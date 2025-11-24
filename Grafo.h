#ifndef GRAFO_H
#define GRAFO_H
#include "Vertex.h"
#include "Casilla.h"
#include "Exploracion.h"

template <typename T>
class Grafo {
    private:
        Exploracion<Vertex<T>> vertices; //lista de vertices     
        Node<Vertex<T>>* findVertexNode(const Casilla<T>& c); //retorna el nodo del vertice con el valor dado
    public:
        Grafo() = default;
        bool addVertex(const Casilla<T>& c); //agrega un vertice al grafo
        bool addEdge(const Casilla<T>& from, const Casilla<T>& to, const bool directed = false); //agrega una arista entre dos vertices
        //bool addEdge(const Casilla<T>& from, const Casilla<T>& to, int weight, const bool directed = false);
        void print() const; //imprime el grafo
        void resetVisited();
        void DFS(const Casilla<T>& start);
        void BFS(const Casilla<T>& start);
        

};

#include "Grafo.tpp"
#endif //GRAFO_H
#pragma once
#include "Vertex.h"
#include "Box.h"
#include "Exploration.h"
#include "Hero.h"
#include "Monster.h"
#include <fstream>  
#include <sstream> 

template <typename T>
class Grafo {
    private:
        Exploration<Vertex<T>> vertices; //lista de vertices     
        Node<Vertex<T>>* findVertexNode(const Box<T>& c) const ; //retorna el nodo del vertice con el valor dado
        
        
    public:
        Grafo() = default;
        bool addVertex(const Box<T>& c); //agrega un vertice al grafo
        bool addEdge(const Box<T>& from, const Box<T>& to, const bool directed = false); //agrega una arista entre dos vertices
        bool addEdge(const Box<T>& from, const Box<T>& to, int weight, const bool directed = false);

        // Métodos de impresión 
        void printOpciones(Box<T>& actual, Hero& h);
        void print(int id) const; //imprime el grafo

        // Métodos de recorrido y búsqueda
        void resetVisited();
        Box<T>* elegirCasilla(Box<T>& actual, Hero& h);
        bool isVisited(Box<T>& actual);
        bool setVisited(Box<T>& actual);
        void Dijstrak(const Box<T>& start,const Box<T>& end);
        
        // Métodos del juego
        void IinitGame();
        bool game(Hero& h, Monster& m);
        Hero chooseHero();
        Monster chooseMonster(const Box<string>& actual);

        //leer desde archivos
        bool cargarCasillasDesdeArchivo(const string& archivo, Box<T>* casillas, int& numCasillas);
        bool cargarConexionesDesdeArchivo(const string& archivo, Box<T>* casillas, int numCasillas);
        bool cargarHeroesDesdeArchivo(const string& archivo, Hero* heroes , int& numHeroes);
        bool cargarMounstruosDesdeArchivo(const string& archivo, Monster* Mounstruo, int& numMonstruos);

        

};

#include "Grafo.tpp"
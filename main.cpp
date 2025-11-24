#include <iostream>
using namespace std;
#include "Exploracion.h"
#include "Monster.h"
#include "Casilla.h"
#include "Grafo.h"


int main() {
    // Crear casillas
    Casilla<string> pasillo(1, "Pasillo principal", 10);
    Casilla<string> sala1(2, "Cueva Misteriosa", 20);
    Casilla<string> sala2(3, "Pueblo Seguro", 40);
    Casilla<string> sala3(4, "Castillo Abandonado", 60);
    Casilla<string> sala4(5, "Castillo Abandonado", 90);
    
    // Crear grafo
    Grafo<string> mapa;
    
    // Agregar casillas al mapa
    mapa.addVertex(pasillo);
    mapa.addVertex(sala1);
    mapa.addVertex(sala2);
    mapa.addVertex(sala3);
    mapa.addVertex(sala4);
    
    // Agregar conexiones (caminos entre casillas)
    mapa.addEdge(pasillo, sala1);      
    mapa.addEdge(sala1, sala2);      
    mapa.addEdge(sala2, sala3);     
    mapa.addEdge(sala3, sala4);
    mapa.addEdge(sala4, sala2);

    // Imprimir el mapa
    mapa.print();
    
    return 0;
}

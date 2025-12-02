#include <iostream>
using namespace std;
#include "Exploracion.h"
#include "Monster.h"
#include "Casilla.h"
#include "Grafo.h"
#include "game.h"


template <typename T>
int Game<T> :: createMap() {
    // Crear casillas
    Casilla<string> pasillo(1, "Pasillo principal", 10);
    Casilla<string> sala1(2, "Pasillo Misterioso", 20);
    Casilla<string> sala2(3, "Sala misteriosa", 40);
    Casilla<string> sala3(4, "Sala Abandonado", 60);
    Casilla<string> sala4(5, "Sala de descanso", 90);
    Casilla<string> final(6, "Sala final", 100);

    // ⭐ Grafo de Casilla<string>
    Grafo<string> mapa;
    
    // Agregar casillas
    mapa.addVertex(pasillo);
    mapa.addVertex(sala1);
    mapa.addVertex(sala2);
    mapa.addVertex(sala3);
    mapa.addVertex(sala4);
    mapa.addVertex(final);
    
    // Agregar conexiones con distancias
    mapa.addEdge(pasillo, sala1, 5);
    mapa.addEdge(sala1, sala2, 8);
    mapa.addEdge(sala2, sala3, 12);
    mapa.addEdge(sala3, sala4, 15);
    mapa.addEdge(sala4, sala2, 10);
    mapa.addEdge(sala4, final, 20);

    // Imprimir mapa
    
    
    return 0;
}
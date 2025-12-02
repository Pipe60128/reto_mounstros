#include <iostream>
using namespace std;
#include "Exploracion.h"
#include "Monster.h"
#include "Casilla.h"
#include "Grafo.h"
#include "Vertex.h"
#include "game.h"


int main() {
    int vidaPersona = 10;
    /*
    //Crear casillas
    Casilla<string> pasillo(1, "Pasillo principal", 0);
    Casilla<string> sala1(2, "Pasillo Misterioso", 5);
    Casilla<string> sala2(3, "Sala misteriosa", 40);
    Casilla<string> sala3(4, "Sala Abandonado", 60);
    Casilla<string> sala4(5, "Sala de descanso", 90);
    Casilla<string> final(6, "Sala final", 100);

    // Crear grafo
    Grafo<string> mapa;
    
    // Agregar casillas al mapa
    mapa.addVertex(pasillo);
    mapa.addVertex(sala1);
    mapa.addVertex(sala2);
    mapa.addVertex(sala3);
    mapa.addVertex(sala4);
    mapa.addVertex(final);
    
    // Agregar conexiones (caminos entre casillas)
    mapa.addEdge(pasillo, sala1);      
    mapa.addEdge(sala1, sala2,1);      
    mapa.addEdge(sala2, sala3,2);     
    mapa.addEdge(sala3, sala4,3);
    mapa.addEdge(sala4, sala2,1);
    mapa.addEdge(sala4, final,10);

    // Imprimir el mapa
    mapa.print(1); 
    while (vidaPersona > 2){  
        mapa.elegirCasilla(pasillo);
        vidaPersona = vidaPersona -1;

    }

    return 0;*/
    int numCasillas = 6;
    Casilla<string> casillas[6] = {
        Casilla<string>(0, "Pasillo principal", 0),
        Casilla<string>(1, "Pasillo Misterioso", 5),
        Casilla<string>(2, "Sala misteriosa", 40),
        Casilla<string>(3, "Sala Abandonada", 60),
        Casilla<string>(4, "Sala de descanso", 90),
        Casilla<string>(5, "Sala final", 100)
    };
    

    // Crear grafo
    Grafo<string> mapa;
    
    // Agregar todas las casillas al mapa
    for (int i = 0; i < numCasillas; i++) {
        mapa.addVertex(casillas[i]);
    }
    
    // Agregar conexiones usando índices
    mapa.addEdge(casillas[0], casillas[1]);  // pasillo -> sala1
    mapa.addEdge(casillas[1], casillas[2], 1);  // sala1 -> sala2
    mapa.addEdge(casillas[2], casillas[3], 2);  // sala2 -> sala3
    mapa.addEdge(casillas[3], casillas[4], 3);  // sala3 -> sala4
    mapa.addEdge(casillas[4], casillas[2], 1);  // sala4 -> sala2
    mapa.addEdge(casillas[4], casillas[5], 10); // sala4 -> final

    mapa.print(0); 
    int num = 0;
    int xp = 0;
    while (vidaPersona > 2 && num < numCasillas){  
        cout << "vida del Heroe: "<< vidaPersona<<endl;
        Casilla<string> siguiente = casillas[num];
        if (siguiente.hasMonster() == 1){
            cout<<"Entramos al combate "<<endl;
            
            cout<<"derrotaste el mounstruo?: "<<endl;
            string mounsterdead;
            cin>>mounsterdead;
            if (mounsterdead != "no") {
                Casilla<string>* sig = mapa.elegirCasilla(siguiente);
                if (sig == nullptr) {
                    cout << "¡Juego terminado!ln" << endl;
                    break;
                }
                
                // Buscar el índice de la siguiente casilla
                for (int i = 0; i < numCasillas; i++) {
                    if (casillas[i] == *sig) {
                        num = i;
                        break;
                    }
                }
                vidaPersona = vidaPersona - 1;
            } else {
                cout<<"Perdiste"<<endl;
                break;
            }

            
        } else {
            cout<<"Que suerte sala vacia +10xp"<<endl;
             Casilla<string>* siguiente = mapa.elegirCasilla(casillas[num]);
            if (siguiente == nullptr) {
                cout << "¡Juego terminado!" << endl;
                break;
            }
            
            // Buscar el índice de la siguiente casilla
            for (int i = 0; i < numCasillas; i++) {
                if (casillas[i] == *siguiente) {
                    num = i;
                    break;
                }
            }
                }
    }
    return 0;
    
};

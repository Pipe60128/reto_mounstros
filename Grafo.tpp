#pragma once
#include "Grafo.h"
#include <iostream>
#include <limits>
using namespace std;

// Cargar casillas desde archivo
template <typename T>
bool Grafo<T>::cargarCasillasDesdeArchivo(const string& archivo, Box<T>* casillas, int& numCasillas) {
    ifstream file(archivo);
    if (!file.is_open()) {
        // No se pudo abrir el archivo 
        return false;
    }
    
    // Leer número de casillas
    file >> numCasillas;
    if (numCasillas <= 0 || numCasillas > 100) {
        //Número de casillas inválido
        file.close();
        return false;
    }
    
    //Cargando  casillas
    // Leer cada casilla
    for (int i = 0; i < numCasillas; i++) {
        int id, prob;
        string nombre;
        file >> id >> nombre >> prob;

        // Reemplazar guiones bajos por espacios
        for (char& c : nombre) {
            if (c == '_') c = ' ';
        }
        casillas[i] = Box<T>(id, nombre, prob);
        // Agregar al grafo
        addVertex(casillas[i]);
    }
    file.close();
    //cargadas exitosamente
    return true;
    
}

// Cargar conexiones desde archivo
template <typename T>
bool Grafo<T>::cargarConexionesDesdeArchivo(const string& archivo, Box<T>* casillas, int numCasillas) {
    ifstream file(archivo);
    if (!file.is_open()) {
        // No se pudo abrir el archivo 
        return false;
    }
    int numConexiones;
    file >> numConexiones;
    if (numConexiones <= 0) {
        //conexiones inválido
        file.close();
        return false;
    }
    for (int i = 0; i < numConexiones; i++) {
        int origen, destino, peso;
        file >> origen >> destino >> peso;
        
        // Agregar arista
        addEdge(casillas[origen], casillas[destino], peso);
    }
    file.close();
    return true;
    
}

// Cargar Mounstruos desde archivo
template <typename T>
bool Grafo<T>::cargarMounstruosDesdeArchivo(const string& archivo, Monster* Mounstruo, int& numMonstruos) {
    ifstream file(archivo);
    if (!file.is_open()) {
        //No se pudo abrir el archivo 
        return false;
    }
    // Leer número de Mounstruos
    file >> numMonstruos;
    if (numMonstruos <= 0 || numMonstruos > 100) {
        //MOnstruos inválido
        file.close();
        return false;
    }
    // Leer cada Mounstruos
    for (int i = 0; i < numMonstruos; i++) {
        int id,hp,hpMax,atk,def,probabilidad;
        string nombre;
        file >> id >> nombre >> hp >> hpMax >> atk >> def >> probabilidad;
        // Reemplazar guiones bajos por espacios
        for (char& c : nombre) {
            if (c == '_') c = ' ';
        }
        Mounstruo[i] = Monster(id, nombre, hp, hpMax, atk, def, probabilidad);
    }
    file.close();
    return true;
}

// Cargar Heroe desde archivo
template <typename T>
bool Grafo<T>::cargarHeroesDesdeArchivo(const string& archivo, Hero* heroes, int& numHeroes) {
    ifstream file(archivo);
    if (!file.is_open()) {
        //No se pudo abrir el archivo
        return false;
    }
    // Leer número de Heroe
    file >> numHeroes;
    if (numHeroes <= 0 || numHeroes > 100) {
        //Heores inválido
        file.close();
        return false;
    }
    // Leer cada Heroe
    for (int i = 0; i < numHeroes; i++) {
        int id,hp,hpMax,atk,def,potions;
        string nombre;
        file >> id >> nombre >> hp >> hpMax >> atk >> def >> potions; 
        // Reemplazar guiones bajos por espacios
        for (char& c : nombre) {
            if (c == '_') c = ' ';
        }
            heroes[i] = Hero(id, nombre, hp, hpMax, atk, def, potions);
    }
    file.close();
    return true;
}

template <typename T>
Monster Grafo<T>::chooseMonster(const Box<string>& actual) {
    Monster monstruos[100]; //Maixmo de mounstruos 
    int numMonstruos = 0; 
    cargarMounstruosDesdeArchivo("Mounstruos.txt", monstruos, numMonstruos);
    for (int i = 0; i < numMonstruos; i++) {
        if (monstruos[i].getProb() >= actual.getProbMonstruo() ) {
            return monstruos[i];
        } else{
            continue;
        }
    }
    return monstruos[0];
}

// Elegir héroe
template <typename T>
Hero Grafo<T>::chooseHero() {
    Hero heroes[100];
    int numHeroes = 0;
    cargarHeroesDesdeArchivo("heroes.txt", heroes, numHeroes);
        cout << "== Aqui esta el almanaque de heroes esocje el que mas te guste: =="<<endl;
        for (int i = 0; i < numHeroes; ++i) {
            cout<<i+1<< ". " <<heroes[i].getName()<< " (HP: " << heroes[i].getHp()<< ", ATK: " << heroes[i].getAtk()<< ", DEF: " << heroes[i].getDef()<< ", Pociones: " << heroes[i].getPotions() << ")"<<endl;
        }
        int choice = 1;
        cout << "Elige tu héroe:"<<endl;
        cin >> choice;
        if (choice >= 1 && choice <= numHeroes) return heroes[choice-1];
        cout << "Elección inválida, se asignará el primero por defecto.\n";
        return heroes[0];
}

//agrega un vertice al grafo que son las casillas
template <typename T> 
bool Grafo<T>::addVertex(const Box<T>& c){ 
    if (findVertexNode(c) != nullptr) {
        return false; 
    }
    Vertex<T> newVertex(c);
    vertices.pushBack(newVertex);
    return true;
} 

//funcion para encontrar el nodo del vertice con el valor dado
template <typename T>
Node<Vertex<T>>* Grafo<T>::findVertexNode(const Box<T>& c) const { //retorna el nodo del vertice con el valor dado
    Node<Vertex<T>>* current = vertices.getHead();
    while(current) {
        if (current->data.getBox() == c) {
            return current;
        } else {
            current = current->next;
        }
    }
    return nullptr;
}

//agrega una arista entre dos vertices sin peso
template <typename T>
bool Grafo<T>::addEdge(const Box<T>& from, const Box<T>& to, const bool directed) { 
    return addEdge(from, to, 0, false);
} 

//agrega una arista entre dos vertices con peso
template <typename T>
bool Grafo<T>:: addEdge(const Box<T>& from, const Box<T>& to, int weight, const bool directed ){
    Node<Vertex<T>>* originNode = findVertexNode(from);
    Node<Vertex<T>>* toNode = findVertexNode(to);
    if (!originNode || !toNode) {
        return false; 
    }
    Edge<Box<T>> edge(to, weight);
    // Buscar si ya existe la arista
    Node<Edge<Box<T>>>* existingEdge = originNode->data.getAdj().search(edge);
    if (!existingEdge) {
        originNode->data.getAdj().pushBack(edge);
    } else {
        // Si existe, actualizar el peso
        existingEdge->data.setPeso(weight);
    }
    // Si no es dirigido, agregar arista inversa
    if (!directed) {
        Edge<Box<T>> reverseEdge(from, weight);
        Node<Edge<Box<T>>>* existingReverseEdge = toNode->data.getAdj().search(reverseEdge);
        if (!existingReverseEdge) {
            toNode->data.getAdj().pushBack(reverseEdge);
        } else {
            existingReverseEdge->data.setPeso(weight);
        }
    }
    return true;
}
 //imprime el grafo
template <typename T>
void Grafo<T>::print(int id) const{ 
    Node<Vertex<T>>* current = vertices.getHead();
     int opcion = 0;
    while (current != nullptr && current->data.getId() != id) {
        current = current->next;
    }
    if (!current) {
        cout << "Box no encontrada.\n";
        return;
    }
    cout<<"__________________________________________________________"<<endl;
    cout<<"|^▽‸‸‸▽▾‸▽‸‸‸▽▾‸▽‸‸†⌈⁗⁗⁗⁗DUNGEON‷‷‷‷⌉†‸‸▽‸▾▽‸‸‸▽‸▾▽‸ ‸‸▽^|"<<endl;
    cout<<"|--------------------------------------------------------|"<<endl;
    cout <<"|            " <<current->data.getBox() <<endl;
    cout<<"|--------------------------------------------------------|"<<endl;
    cout<<"|                ‸‸^‸‡ Salas a donde ir‸‸‸‸      "<<endl;
    current->data.getAdj().print();
    cout<<"\n========================================================="<<endl;
    
}

template <typename T>
void Grafo<T>::printOpciones(Box<T>& actual, Hero& h) {
    Node<Vertex<T>>* current = vertices.getHead();
    int opcion = 0;
    while (current != nullptr  && current->data.getBox().getId() != actual.getId()) {
        current = current->next;
    }
    //cout<<"|ataque:"<<h.getAtk()<<endl;
    cout<<"|--------------------------------------------------------|"<<endl;
    cout<<"|                ‸‸^‸‡ Salas a donde ir‸‸‸‸      "<<endl;
    current->data.getAdj().print();
    cout<<"\n========================================================="<<endl;
}
template <typename T>
void Grafo<T>:: resetVisited() {
    Node<Vertex<T>>* current = vertices.getHead();
    while (current != nullptr) {
        current->data.setVisitado(false); 
        current = current->next;
    }
}

template <typename T>
Box<T>* Grafo<T>::elegirCasilla(Box<T>& actual, Hero& h) {
    Node<Vertex<T>>* vertexNode = findVertexNode(actual);
    
    // Verificar que el vértice existe
    if (vertexNode == nullptr) {
        cout << "Error: Box no encontrada en el grafo" << endl;
        return nullptr;
    }
    Exploration<Edge<Box<T>>>& adj = vertexNode->data.getAdj();
    
    // Verificar que tiene adyacencias
    if (adj.empty()) {
        cout << "¡Has llegado al final! No hay más caminos." << endl;
        return nullptr;
    }
    
    while (true) {  
        cout << "\n¿A qué casilla quieres ir?: ";
        int opcion;
        cin >> opcion;
        
        // Validar rango
        if (opcion < 1 || opcion > adj.size()) {
            cout << "Opción inválida. Intenta de nuevo." << endl;
            continue;  // Volver a pedir
        }
        
        // Buscar la casilla seleccionada
        Node<Edge<Box<T>>>* adjNode = adj.getHead();
        int contador = 1;
        bool encontrado = false;

        //bucle para verificar si tiene xp suficiente 
        while (adjNode != nullptr) {
            if (contador == opcion) {
                encontrado = true;
                
                // Verificar XP
                int costoXP = adjNode->data.getPeso();
                if (h.getXp() < costoXP) {
                    cout << "No tienes suficiente XP." << endl;
                    cout << "Necesitas: " << costoXP << " XP" << endl;
                    cout << "Tienes: " << h.getXp() << " XP" << endl;
                    cout << "Vuelve a escoger.\n" << endl;
                    break; 
                }
                
                //h.setXp(h.getXp() - costoXP);
                
                cout << "\nMoviendo de casilla" << endl;
                print(adjNode->data.getDestino().getId());
                return new Box<T>(adjNode->data.getDestino());
            }
            contador++;
            adjNode = adjNode->next;
        }
        // Si no encontró la opción, continuar el bucle
        if (!encontrado) {
            cout << "Opción inválida. Intenta de nuevo." << endl;
        }
    }
    cout << "Opción inválida" << endl;
    return nullptr;
}


template <typename T>
bool Grafo<T>:: isVisited(Box<T>& actual){
    Node<Vertex<T>>* current = findVertexNode(actual);
    if (current == nullptr) return false; 
    return current->data.isVisitado();   
}

template <typename T>
bool Grafo<T>:: setVisited(Box<T>& actual){
    Node<Vertex<T>>* current = findVertexNode(actual);
    if (current == nullptr) return false;
    current->data.setVisitado(true);
    return true;
}

//cheat 
template<typename T> 
void Grafo<T>::Dijstrak(const Box<T>& start, const Box<T>& end)  {
        // Verificar que ambas casillas existen
        Node<Vertex<T>>* startNode = findVertexNode(start);
        Node<Vertex<T>>* endNode = findVertexNode(end);
        if (!startNode || !endNode) {
            cout << "Box inicial no encontrada" << endl;
            return;
        }
        // Si son la misma casilla
        if (start == end) {
            cout << "Ruta: " << start.getName() << endl;
            return;
        }
        const int MAX_INT = std::numeric_limits<int>::max();
        // INICIALIZAR TODOS LOS VÉRTICES
        Node<Vertex<T>>* current = vertices.getHead();
        while (current) {
            current->data.setDistance(MAX_INT);
            current->data.setVisitado(false);
            current->data.setParent(Box<T>()); // Padre vacío
            current = current->next;
        }
        // DISTANCIA INICIAL = 0
        startNode->data.setDistance(0);
        // ALGORITMO DIJKSTRA
        int totalVertices = vertices.size();
        for (int i = 0; i < totalVertices; i++) {
            // Buscar el vértice no visited con menor distancia
            int u = -1;
            int best = MAX_INT;
            Node<Vertex<T>>* bestNode = nullptr;
            Node<Vertex<T>>* temp = vertices.getHead();
            while (temp) {
                if (!temp->data.isVisitado() && temp->data.getDistance() < best) {
                    best = temp->data.getDistance();
                    bestNode = temp;
                    u = temp->data.getId();
                }
                temp = temp->next;
            }
            // Si no hay más nodos alcanzables, terminar
            if (u == -1) break;
            // Si llegamos al destino, terminar
            if (bestNode->data.getBox() == end) break;
            // Marcar como visited
            bestNode->data.setVisitado(true);
            // RELAJACIÓN: revisar vecinos
            Node<Edge<Box<T>>>* edgeNode = bestNode->data.getAdj().getHead();
            while (edgeNode) {
                Box<T> vecino = edgeNode->data.getDestino();
                int peso = edgeNode->data.getPeso(); // Peso = XP necesario
                Node<Vertex<T>>* vecinoNode = findVertexNode(vecino);
                if (vecinoNode && !vecinoNode->data.isVisitado()) {
                    int distanciaActual = bestNode->data.getDistance();
                    // Evitar overflow
                    if (distanciaActual != MAX_INT) {
                        int candidato = distanciaActual + peso;
                        if (candidato < vecinoNode->data.getDistance()) {
                            vecinoNode->data.setDistance(candidato);
                            vecinoNode->data.setParent(bestNode->data.getBox());
                        }
                    }
                }
                edgeNode = edgeNode->next;
            }
        }
        if (endNode->data.getDistance() == MAX_INT) {
            cout << "No hay ruta desde " << start.getName() 
                << " hasta " << end.getName() << " F :(" << endl;
            return;
        }
        // Guardar camino en un temporal
        const int MAX_PATH = 100;
        Box<T> path[MAX_PATH];
        int pathSize = 0;
        Box<T> actual = end;
        while (actual.getId() != -1 && pathSize < MAX_PATH) {
            path[pathSize++] = actual;
            Node<Vertex<T>>* node = findVertexNode(actual);
            if (!node) break;
            Box<T> padre = node->data.getParent();
            // Si llegamos al inicio o no hay más padres
            if (padre.getId() == -1 || padre == actual) break;
            actual = padre;
        }
        // IMPRIMIR RUTA Y COSTO
        cout << "\n================================" << endl;
        cout << "|== Mejor Camino Por tomar... ==" << endl;
        cout << "|================================" << endl;
        cout << "|Costo total: " << endNode->data.getDistance() << " XP" << endl;
        cout << "|================================" << endl;
        cout << "|Ruta: ";
        
        for (int i = pathSize - 1; i >= 0; i--) {
            if (i == pathSize - 1) {
                cout <<""<< path[i].getName()<< "\n|           ↓\n";
            }else{ 
            cout <<"|      "<< path[i].getName();
            if (i > 0) cout << "\n|           ↓\n";
            }
        }
        cout << endl;
        cout << "=================================" << endl;

}

// Implementación de la inicialización del juego
template <typename T>
void Grafo<T>::IinitGame() {
    srand(time(nullptr)); // Inicializa la semilla para números aleatorios
    Hero h = chooseHero();
    int vida = h.getHp();
    Grafo<string> mapa;

    // Cargar casillas y conexiones
    Box<string>* casillas = new Box<string>[100]; // Máximo 100 casillas
    int numCasillas = 0;
    mapa.cargarCasillasDesdeArchivo("casillas.txt", casillas, numCasillas);
    mapa.cargarConexionesDesdeArchivo("conexiones.txt", casillas, numCasillas);

    //index de casilla
    int num = 0;

    //cheat code
    string key = "estructuradeatos2025";
    string inputKey;
    cout<<"Ingresa tu numbre : ";
    cin>>inputKey;
    if (key == inputKey){
        cout<<"Clave correcta!. Mostrando mejor camino."<<endl;
        string optiongame = "";
        cout<<"¿Deseas jugar de todos modos? (si/no): ";
        cin>>optiongame;

        if (optiongame == "si" || optiongame == "Si"){

            cout << "\n=== Ejecutando Dijkstra ===" << endl;
            mapa.Dijstrak(casillas[0], casillas[numCasillas - 1]);
            cout<<"AUN ASI QUIERES JUGAR?"<<endl;
            cin>>optiongame;

            if (optiongame == "no" || optiongame == "No"){
                cout<<"Felicidades ganaste sin juagr"<<endl;
                return;
            }
        } else if (optiongame == "no" || optiongame == "No"){
            cout<<"Felicidades gaanste sin juagr"<<endl;
            return;
        }
    } else {
        cout<<"Clave incorrecta Iniciando juego..."<<endl;
    }

    // Inicio del juego
    mapa.print(0);
    // Estado inicial del héroe
    cout << "| * vida del Heroe: "<< vida<<endl;
    cout<< "| * XP del heroe: "<<h.getXp()<<endl;

    // Marcar la casilla inicial como visitada
    Box<string> casilla0 = casillas[0];
    mapa.setVisited(casilla0);

    // Bucle principal del juego
    while (vida > 2 && num < numCasillas){ 
        Box<string> siguiente = casillas[num];
        mapa.setVisited(siguiente);
        
        if (siguiente.hasMonster() == 1){
            Monster m = chooseMonster(siguiente);
            bool mounsterdead = mapa.game(h,m);

            if (mounsterdead != false) {
                if (siguiente == casillas[numCasillas - 1]) {
                    cout<<"\n.\n..\n...\n....Felicidades ganaste\n terminaste el juego\n....\n...\n..\n. "<<endl;
                    break;
                }
                if (siguiente.getId() == 7) {
                    cout<<"¡Has encontrado el tesoro legendario! +50 XP"<<endl;
                    h.addXp(50);
                }
                if (siguiente.getId() == 13) {
                    cout<<"\n¡Has llegado a la sala de armeria ten un upgrade\n"<<endl;
                    h.setAtk(h.getAtk() + 5);
                    h.heal(20);
                    cout<<"\n +5 de ataque"<<endl;
                    cout<<"\n +20 de vida"<<endl;
                }
                
                mapa.printOpciones(siguiente, h);  
                Box<string>* sig = mapa.elegirCasilla(siguiente, h);
                
                if (sig == nullptr) {
                    Monster M = chooseMonster(siguiente);
                    bool mounsterdead = mapa.game(h,M);
                    cout << "¡Juego terminado!ln" << endl;
                    break;
                }
                // Buscar el índice de la siguiente casilla
                for (int i = 0; i < numCasillas; i++) {
                    if (casillas[i] == *sig) {
                        num = i;
                        if(!mapa.isVisited(casillas[i])){
                            // Marcar como visitada y dar XP
                            mapa.setVisited(casillas[i]);
                            h.addXp(2);
                            cout<<"| +2xp"<<endl;
                        }
                        break;
                    }
                }
                // Mostrar estado del héroe
                cout << "| * HP: "<< vida<<endl;
                cout<< "| * XP del heroe: "<<h.getXp()<<endl;
            } else {
                cout<<"Perdiste"<<endl;
                break;
            }
        } else {
            // No hay monstruo, elegir siguiente casilla
            Box<string>* sig = mapa.elegirCasilla(casillas[num], h);
            for (int i = 0; i < numCasillas; i++){
                if (casillas[i] == *sig){
                if(!mapa.isVisited(casillas[i])){
                        mapa.setVisited(casillas[i]);
                        h.addXp(2);
                        cout<<"| +2xp"<<endl;
                    }
                }
            }
            // Mostrar estado del héroe
            cout << "|  * HP: "<< vida<<endl;
            cout<< "|   * XP del heroe: "<<h.getXp()<<endl; 
            if (sig == nullptr) {
                cout << "¡Juego terminado!" << endl;
                break;
            }
            
            //Buscar el índice de la siguiente casilla
            for (int i = 0; i < numCasillas; i++) {
                if (casillas[i] == *sig) {
                    num = i;
                    break;
                }
            }
        }
    }

    return;
    
}

// Implementación del combate
template <typename T>
bool Grafo<T>:: game(Hero& h, Monster& m) {
    cout<<"\n=== COMBATE INICIADO ===\n"<<endl;
    cout << "Has encontrado un " << m.getName() << "!" << endl;
    cout << "Estado " << m.getName()<< ": [HP: " << m.getHp() << "/" << m.getHpMax()<< " | ATK: " << m.getAtk() << "]" << endl;
    int turno = 1;

    while (h.getHp() > 0 && m.getHp() > 0) {
        cout << "\n--- Turno " << turno << " ---" << endl;

        cout << "Estado " << m.getName() 
             << ": [HP: " << m.getHp() << " | ATK: " << m.getAtk() << "]" << endl;

        cout << "Estado " << h.getName() 
             << ": [HP: " << h.getHp() << "/" << h.getHpMax() 
             << " | ATK: " << h.getAtk()
             << " | Pociones: " << h.getPotions() << "]" << endl;

        // turno del héroe
        cout << "\n¿Qué harás?\n1. Atacar\n2. Usar poción (+20 HP)\n> ";
        int opcion;
        cin >> opcion;

        if (opcion == 1) {
            int danio = h.getAtk() - m.getDef();
            m.setHp(m.getHp() - danio);

            cout << ">> Atacas a " << m.getName()<< " y le haces " << danio << " de daño." << endl;
        } 
        else if (opcion == 2) {
            if (h.getPotions() > 0) {
                if (h.getHp() + 20 > h.getHpMax()){
                    h.setHp(h.getHpMax());
                } else {
                h.setHp( h.getHp() + 20); 
                }
                h.setPotions(h.getPotions() - 1);

                cout << ">> Bebes una poción. Recuperas HP." << endl;
            } else {
                cout << ">> ¡No te quedan pociones! Pierdes el turno." << endl;
            }
        } 
        else {
            cout << ">> Opción inválida, pierdes el turno." << endl;
        }

        // Si el monstruo muere antes de contraatacar
        if (m.getHp() <= 0) break;

        // turno del enemigo
        cout << "\n[Turno enemigo]" << endl;

        int danioM = max(1, m.getAtk() - h.getDef());
        h.setHp(h.getHp() - danioM);

        cout << ">> " << m.getName() 
             << " te ataca furiosamente y te hace " << danioM << " de daño." << endl;

        turno++;
    }

    cout << "\n==========================================" << endl;

    if (h.getHp() > 0) {
        cout << "   ¡VICTORIA! Has derrotado a " << m.getName() << endl;

        cout << "   ¡Tus stats suben! (+5 xp, +1 ATK)" << endl;

        h.setXp(h.getXp() + 5);
        h.setAtk(h.getAtk() + 1);
        h.setHp(h.getHpMax()); // cura total tras ganar

        return true;
    } 
    else {
        cout << "   HAS MUERTO... GAME OVER." << endl;
        return false;
    }
}

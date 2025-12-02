#pragma once
#include "Grafo.h"
//#include "Stack.h"
//#include "Queue.h"
#include <iostream>
using namespace std;

template <typename T>
bool Grafo<T>::addVertex(const Casilla<T>& c){ //agrega un vertice al grafo
    if (findVertexNode(c) != nullptr) {
        return false; 
    }
    Vertex<T> newVertex(c);
    vertices.pushBack(newVertex);
    return true;

} 
template <typename T>
Node<Vertex<T>>* Grafo<T>::findVertexNode(const Casilla<T>& c) { //retorna el nodo del vertice con el valor dado
    Node<Vertex<T>>* current = vertices.getHead();
    while(current) {
        if (current->data == c) {
            return current;
        } else {
            current = current->next;
        }
    }
    return nullptr;
}

template <typename T>
bool Grafo<T>::addEdge(const Casilla<T>& from, const Casilla<T>& to, const bool directed) { //agrega una arista entre dos vertices
    return addEdge(from, to, 0, false);
} 
template <typename T>
bool Grafo<T>:: addEdge(const Casilla<T>& from, const Casilla<T>& to, int weight, const bool directed ){
    Node<Vertex<T>>* originNode = findVertexNode(from);
    Node<Vertex<T>>* toNode = findVertexNode(to);
    if (!originNode || !toNode) {
        return false; 
    }
    /*if (!originNode->data.getAdj().search(to)) {
        originNode->data.getAdj().pushBack(to);
    }
    if (!directed) {
        if (!toNode->data.getAdj().search(from)) {
            toNode->data.getAdj().pushBack(from);
        }
    }
    return true;*/
    Edge<Casilla<T>> edge(to, weight);
    
    // Buscar si ya existe la arista
    Node<Edge<Casilla<T>>>* existingEdge = originNode->data.getAdj().search(edge);
    
    if (!existingEdge) {
        originNode->data.getAdj().pushBack(edge);
    } else {
        // Si existe, actualizar el peso
        existingEdge->data.setPeso(weight);
    }
    
    // Si no es dirigido, agregar arista inversa
    if (!directed) {
        Edge<Casilla<T>> reverseEdge(from, weight);
        Node<Edge<Casilla<T>>>* existingReverseEdge = toNode->data.getAdj().search(reverseEdge);
        
        if (!existingReverseEdge) {
            toNode->data.getAdj().pushBack(reverseEdge);
        } else {
            existingReverseEdge->data.setPeso(weight);
        }
    }
    
    return true;

}

template <typename T>
void Grafo<T>::print(int id) const{  //imprime el grafo
    Node<Vertex<T>>* current = vertices.getHead();
     int opcion = 0;
    while (current != nullptr && current->data.getId() != id) {
        current = current->next;
    }
    if (!current) {
        cout << "Casilla no encontrada.\n";
        return;
    }

    cout<<"___________________________________"<<endl;
    cout<<"|‸▽▾‸▽‸‸†⌈⁗⁗⁗⁗DUNGEON‷‷‷‷⌉†‸‸▽‸▾▽‸|"<<endl;
    cout<<"|---------------------------------|"<<endl;
    cout <<"| " <<current->data.getCasilla() <<endl;
    cout<<"|---------------------------------|\n|"<<endl;
        if (current->data.getCasilla().hasMonster() == 1) {
        cout << "|  ‡Ha aparecido un mounstruo MONSTRUO: "<<endl;
    } else {
        cout << "|   ‸‸‡ Sala vacia‸"<<endl;
    }
    cout<<"|---------------------------------|"<<endl;
    cout<<"|      ‸‸‸‸Salas a donde ir‸‸‸‸      "<<endl;
    current->data.getAdj().print();
    cout<<"\n==================================="<<endl;
    
}
template <typename T>
void Grafo<T>:: resetVisited() {
    Node<Vertex<T>>* current = vertices.getHead();
    while (current != nullptr) {
        current->data.setVisited(false); 
        current = current->next;
    }
}

template <typename T>
Casilla<T>* Grafo<T>::elegirCasilla(Casilla<T>& actual) {
    Node<Vertex<T>>* vertexNode = findVertexNode(actual);
    
    // Verificar que el vértice existe
    if (vertexNode == nullptr) {
        cout << "Error: Casilla no encontrada en el grafo" << endl;
        return nullptr;
    }
    
    Exploracion<Edge<Casilla<T>>>& adj = vertexNode->data.getAdj();
    
    // Verificar que tiene adyacencias
    if (adj.empty()) {
        cout << "¡Has llegado al final! No hay más caminos." << endl;
        return nullptr;
    }
    
    // Pedir al usuario que elija
    cout << "\n¿A qué casilla quieres ir? (número): ";
    int opcion;
    cin >> opcion;
    
    // Buscar la casilla según la opción
    Node<Edge<Casilla<T>>>* adjNode = adj.getHead();
    int contador = 1;
    
    while (adjNode != nullptr) {
        if (contador == opcion) {
            // Retornar una copia de la casilla destino
            cout<<"\nMovinedo de casilla\n"<<endl;
            print(adjNode->data.getDestino().getId());
            
            return new Casilla<T>(adjNode->data.getDestino());
        } 
        contador++;
        adjNode = adjNode->next;
    }
    
    cout << "Opción inválida. Intenta de nuevo." << endl;
    return nullptr;
}
/*
template <typename T>
void Grafo<T>:: BFS(const Casilla<T>& start) {
    resetVisited();
    Node<Vertex<T>>* startNode = findVertexNode(start);
    if (startNode == nullptr) {
        cout << "Vértice de inicio no encontrado" << endl;
        return;
    }
    cout << "BFS desde " << start << ": ";
    Queue<Node<Vertex<T>>*> q;
    startNode->data.setVisited(true);
    q.enQueue(startNode);

    while(!q.isEmpty()) {
        Node<Vertex<T>>* current = q.deQueue();
        cout << current->data.getData() << "-> ";
        Node<Vertex<T>>* adj = current->data.getAdj().getHead();

        while(adj != nullptr) {
            // Buscar el nodo completo del grafo
            Node<Vertex<T>>* fullAdjNode = findVertexNode(adj->data.getData());

            if (fullAdjNode != nullptr && !fullAdjNode->data.isVisited()) {
                fullAdjNode->data.setVisited(true);
                q.enQueue(fullAdjNode);
            }

            adj = adj->next; 
        }
    }
    cout << endl;
}

template <typename T>
void Grafo<T>:: DFS(const Casilla<T>& start) {
    resetVisited();
    Node<Vertex<T>>* startNode = findVertexNode(start);
    if (startNode == nullptr) {
        cout << "Vértice de inicio no encontrado" << endl;
        return;
    }
    cout << "DFS desde " << start << ": ";
    Stack<Node<Vertex<T>>*> s;
    startNode->data.setVisited(true);
    s.push(startNode);

    while (!s.isEmpty()) {
        Node<Vertex<T>>* current = s.pop();
        cout << current->data.getData() << "-> ";
        Node<Vertex<T>>* adj = current->data.getAdj().getHead();

        while (adj != nullptr) {
            // Buscar el nodo completo del grafo
            Node<Vertex<T>>* fullAdjNode = findVertexNode(adj->data.getData());

            if (fullAdjNode != nullptr && !fullAdjNode->data.isVisited()) {
                fullAdjNode->data.setVisited(true);
                s.push(fullAdjNode);
            }

            adj = adj->next; 
        }
    }

    cout << endl;

}*/
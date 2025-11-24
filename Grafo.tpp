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
    Node<Vertex<T>>* originNode = findVertexNode(from);
    Node<Vertex<T>>* toNode = findVertexNode(to);
    if (!originNode || !toNode) {
        return false; 
    }
    if (!originNode->data.getAdj().search(to)) {
        originNode->data.getAdj().pushBack(to);
    }
    if (!directed) {
        if (!toNode->data.getAdj().search(from)) {
            toNode->data.getAdj().pushBack(from);
        }
    }
    return true;


} 
template <typename T>
void Grafo<T>::print() const{  //imprime el grafo
    Node<Vertex<T>>* current = vertices.getHead();
    while(current) {
        cout<<"___________________________________"<<endl;
        cout<<"|‸▽▾‸▽‸‸†⌈⁗⁗⁗⁗DUNGEON‷‷‷‷⌉†‸‸▽‸▾▽‸|"<<endl;
        cout <<"|" <<current->data.getCasilla() << " \n|--------------------------\n| Salas a donde ir:\n";
        current->data.getAdj().print();
        if (current->data.getCasilla().hasMonster() == 1) {
            cout << "\n|  ‡Ha aparecido un mounstruo MONSTRUO: ";
        } else {
            cout << "\n|   ‸‸‡ Sala vacia‸";
        }
        current = current->next;
        cout<<"\n==================================="<<endl;
        
    }
    
}
template <typename T>
void Grafo<T>:: resetVisited() {
    Node<Vertex<T>>* current = vertices.getHead();
    while (current != nullptr) {
        current->data.setVisited(false); 
        current = current->next;
    }
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
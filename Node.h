#ifndef NODE_H
#define NODE_H

// Definición de la clase Node (Nodo) para una Linked List
template<typename T>
class Node{
    public:
        T data; // Valor almacenado en el nodo
        Node<T>* next; 
        Node(const T& v);

};

#include "node.tpp"
#endif //NODE_H
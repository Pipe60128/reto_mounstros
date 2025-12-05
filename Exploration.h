#ifndef EXPLORATION_H
#define EXPLORATION_H
#include "Node.h"

// Definición de la clase Exploration que es nuestra Linked List
template<typename T>
class Exploration{
    private:
        Node<T>* head; // Puntero al primer nodo
        unsigned int n; // Tamaño de la lista
    public:
        Exploration();
        ~Exploration();

        unsigned int size() const; // Retorna el tamaño de la lista
        bool empty() const; // Retorna true si la lista está vacía
        void clear(); // Limpia la lista

        void pushFront(const T& value); // Inserta un elemento al inicio de la lista
        void pushBack(const T& value); // Inserta un elemento al final de la lista
        bool insert(unsigned int index,const T& value); // Inserta un elemento en una posición específica
        T* elementAt(unsigned int index); // Retorna el elemento en una posición específica

        void print() const; // Imprime la lista

        Node<T>* getHead() const; // Retorna el puntero al primer nodo
        Node<T>* search(const T& value); // Busca un elemento en la lista y retorna su nodo


};

#include "Exploration.tpp"
#endif //EXPLORACION_H
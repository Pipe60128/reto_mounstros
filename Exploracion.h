#ifndef EXPLORACION_H
#define EXPLORACION_H
#include "Node.h"


template<typename T>
class Exploracion{
    private:
        Node<T>* head;
        unsigned int n;
    public:
        Exploracion();
        ~Exploracion();
        unsigned int size() const;
        bool empty() const; 
        void clear();
        void pushFront(const T& value);
        void pushBack(const T& value);
        bool insert(unsigned int index,const T& value);
        T* elementAt(unsigned int index);
        void print() const;
        Node<T>* getHead() const;
        Node<T>* search(const T& value);


};

#include "Exploracion.tpp"
#endif //EXPLORACION_H
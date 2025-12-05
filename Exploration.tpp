#pragma once 
using namespace std;
#include "Exploration.h"

// Constructor
template <typename T>
Exploration<T> :: Exploration(): head(nullptr), n(0){}

// Destructor
template <typename T>
Exploration<T> :: ~Exploration(){
    clear();
}

// Checa si la lista esta vacia
template <typename T>
bool Exploration<T> :: empty() const {
    return n==0 || !head;
}

// Imprime la Linked List
template <typename T>
void Exploration<T> :: print() const {
        if (empty()) {
            cout << "[]";
            return;
        }
        Node<T>* current = head;
        cout<<"|--------------------------------------------------------|"<<endl;
        cout << "|";
        int opcion = 1;
        while (current) {
            cout<< "  " <<opcion <<")"<< current->data;
            if (current->next) cout << "\n|";
            current = current->next;
            opcion++;
        }
        cout << " ";
}



// Metodo pushBack
template <typename T>
void Exploration<T> :: pushBack(const T& value){
    Node<T>* newNode = new Node<T>(value);
    if (!head) {
        head = newNode;
    } else {
        Node<T>* current = head;
        while (current->next) {
            current = current-> next;
        }
        current->next = newNode;
    }
    ++n;

        
    
}

// Metodo pushFront
template <typename T>
void Exploration<T> :: pushFront(const T& value){
    Node<T>* newNode = new Node<T>(value);
    if (!head) {
        head = newNode;
    } else {
        newNode->next = head;
        head = newNode;
    }
    ++n;

}
 // Metodo insert
template <typename T>
bool Exploration<T> :: insert(unsigned int index, const T& value){
    if (index > n) return false;
    if (index == 0) {
        pushFront(value);
        return true;
    }
    Node<T>* current = head;
    for (unsigned int i = 0; i < index-1 && current; ++i){
        current = current->next;
    }
    if (!current) return false;
    Node<T>* newNode = new Node<T>(value);
    newNode->next = current->next;
    current->next = newNode;
    ++n;
    return true;

}


// Metodo clear
template <typename T>
void Exploration<T> :: clear(){
    Node<T>* current = head;
    while (current){
        Node<T>* next = current->next;
        delete current;
        current = next;
        --n;
    }
    head = nullptr;
}

// Metodo size
template <typename T> 
unsigned int Exploration<T> :: size() const{
    return n;
}


// Metodo getHead
template <typename T>
Node<T>* Exploration<T> :: getHead() const{
    return head;
}

// Metodo search
template <typename T>
Node<T>* Exploration<T> :: search(const T& value) {
    Node<T>* current = head;
    while(current) {
        if (current->data == value){
            return current;
        } else {
            current = current->next;
        } 
    }
    return nullptr;
}
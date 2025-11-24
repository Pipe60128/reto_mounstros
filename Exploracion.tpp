#pragma once 
using namespace std;
#include "Exploracion.h"

//constructor
template <typename T>
Exploracion<T> :: Exploracion(): head(nullptr), n(0){}

//destructor
template <typename T>
Exploracion<T> :: ~Exploracion(){
    clear();
}

//check if list is empty
template <typename T>
bool Exploracion<T> :: empty() const {
    return n==0 || !head;
}

//print method
template <typename T>
void Exploracion<T> :: print() const {
        if (empty()) {
            cout << "[]";
            return;
        }
        Node<T>* current = head;
        cout<<"|--------------------------"<<endl;
        cout << "|";
        while (current) {
            cout << " " << current->data;
            if (current->next) cout << "\n|";
            current = current->next;
        }
        cout << " ";
}



//pushFront
template <typename T>
void Exploracion<T> :: pushBack(const T& value){
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

//pushBack method
template <typename T>
void Exploracion<T> :: pushFront(const T& value){
    Node<T>* newNode = new Node<T>(value);
    if (!head) {
        head = newNode;
    } else {
        newNode->next = head;
        head = newNode;
    }
    ++n;

}
 //inset method
template <typename T>
bool Exploracion<T> :: insert(unsigned int index, const T& value){
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


//clear method
template <typename T>
void Exploracion<T> :: clear(){
    Node<T>* current = head;
    while (current){
        Node<T>* next = current->next;
        delete current;
        current = next;
        --n;
    }
    head = nullptr;
}

//size method
template <typename T> 
unsigned int Exploracion<T> :: size() const{
    /*unsigned int nSize = 0;
    Node<T>* current = head;
    while (current) {
        ++nSize;
        current = current -> next;
    }*/
    return n;

}


//gethead method
template <typename T>
Node<T>* Exploracion<T> :: getHead() const{
    return head;
}

//search method
template <typename T>
Node<T>* Exploracion<T> :: search(const T& value) {
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
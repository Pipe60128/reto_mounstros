#pragma once
#include <iostream>
using namespace std;

// Definición de la clase Box o Casilla
template<typename T>
class Box{

    private:
        int probmounstro; // Probabilidad (0-100) de que aparezca un monstruo en la casilla
        T nameBox; // Nombre o tipo de la casilla
        int idBox; // ID de la casilla

    public:
        // Sobrecarga del operador de igual para comparar dos casillas por su ID
        bool operator==(const Box<T>& other) const { 
            return idBox == other.idBox;
        }
        // Sobrecarga del operador de salida para imprimir la casilla
        friend ostream& operator<<(ostream& out, const Box<T>& c) { 
            out << "      ‸‸" << c.nameBox << "‸";
        return out;
        }
        Box(): idBox(-1), nameBox(""), probmounstro(0) {} 
        Box(int id, const T& name, int probmounstro); 
        int getId() const; // Getter para el ID de la casilla
        T getName() const; // Getter para el nombre de la casilla
        int getProbMonstruo() const; // Getter para la probabilidad de monstruo
        int hasMonster(); // Método para determinar si hay un monstruo en la casilla
        void setProb(int p); // Setter para la probabilidad de monstruo
    };
#include "Box.tpp"
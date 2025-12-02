#ifndef CASILLA_H
#define CASILLA_H
#include <iostream>
using namespace std;

template<typename T>
class Casilla{
    private:
        int probmounstro; // probabilidad (0-100) de que aparezca un monstruo
        T nombreCasilla;
        int idCasilla;
    public:
        bool operator==(const Casilla<T>& other) const {
            return idCasilla == other.idCasilla;
        }
        friend ostream& operator<<(ostream& out, const Casilla<T>& c) {
            out << "      ‸‸" << c.nombreCasilla << "‸";
        return out;
        }
        Casilla(int id, const T& nombre, int probmounstro); 
        int getId() const;
        T getNombre() const;
        int getProbMonstruo() const;
        int hasMonster();

};

#include "Casilla.tpp"
#endif //CASILLA_H
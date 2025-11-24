#pragma once 
#include "Monster.h"

bool Monstruo::cargarDesdeArchivo(ifstream& file) {
    if (!(file >> id))
        return false;

    file.ignore();                 // Quitar salto de línea anterior
    getline(file, nombre);         // Lee nombre con espacios

    if (!(file >> vida)) return false;
    if (!(file >> ataque)) return false;
    if (!(file >> defensa)) return false;
    if (!(file >> probabilidad)) return false;

    file.ignore(); // limpiar salto final

    return true;
}

// Carga TODOS los monstruos desde un archivo
int Monstruo::cargarTodos(const string& archivo, Monstruo monstruos[], int& total) {
    ifstream file(archivo);

    if (!file.is_open()) {
        cout << "Error: no se pudo abrir el archivo " << archivo << endl;
        return -1;
    }

    total = 0;
    while (total < MAX_MONSTRUOS && monstruos[total].cargarDesdeArchivo(file)) {
        total++;
    }

    file.close();
    return total;
}

int Monstruo :: getId() const {
    return id;
}
string Monstruo :: getNombre() const{
    return nombre;
}
int Monstruo :: getVida() const {
    return vida;
}
int  Monstruo :: getAtaque() const {
    return ataque;
}
int Monstruo :: getDefensa() const {
    return defensa;
}
double Monstruo :: getProbabilidad() const {
    return probabilidad;
}
//

 bool Monstruo :: cargarDesdeArchivo(ifstream& file) {
        if (!(file >> id)) return false;
        file.ignore();
        getline(file, nombre);

        if (!(file >> vida)) return false;
        if (!(file >> ataque)) return false;
        if (!(file >> defensa)) return false;
        if (!(file >> probabilidad)) return false;
        file.ignore();
        
        return true;
    }

// Mostrar atributos completos
void Monstruo :: mostrar() const {
     cout << "ID: " << id << endl;
        cout << "Nombre: " << nombre << endl;
        cout << "Vida: " << vida << endl;
        cout << "Ataque: " << ataque << endl;
        cout << "Defensa: " << defensa << endl;
        cout << "Probabilidad: " << probabilidad << endl;
        cout << "------------------------" << endl;
}
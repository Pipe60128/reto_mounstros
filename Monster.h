#pragma once
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
const int MAX_MONSTRUOS = 100;

class Monstruo {
private:
    int id;
    string nombre;
    int vida;
    int ataque;
    int defensa;
    double probabilidad;
    //lista y maximo de mounstruos
   
    
public:
    // Constructor por defecto
    Monstruo() : id(0), vida(0), ataque(0), defensa(0), probabilidad(0.0) {
        nombre = "";
    }
    
    // Cargar un monstruo desde el archivo
   bool cargarDesdeArchivo(ifstream& file);
    
    // Funciones globales de carga
    static int cargarTodos(const string& archivo, Monstruo monstruos[], int& total);

    
    // Getters
    int getId() const;
    string getNombre() const;
    int getVida() const;
    int getAtaque() const;
    int getDefensa() const;
    double getProbabilidad() const;

    // Mostrar atributos completos
    void mostrar() const;
    void mostrarTodos() const;
    int cargarDesdeArchivo(const string& archivo);

    
    };
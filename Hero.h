
#pragma once
#include <iostream>
#include <fstream> //Librerias para cargar y guardar Heroes.txt
#include <string>
using namespace std;

// Definición de la clase Hero
class Hero {
    private:
        int id;
        string name;
        int hp;
        int hpMax;
        int atk;
        int def;
        int potions;
        int xp; // Experiencia del héroe que usamos para moverse por el grafo
    public:

        Hero() : id(0), name(""), hp(0), hpMax(0), atk(0), def(0), potions(0) { // Constructor por defecto
        }

        Hero(int i, string n, int h, int hMx, int a, int df, int pt): // Constructor con parámetros
        id(i),name(n), hp(h), hpMax(hMx), atk(a), def(df), potions(pt), xp() {}

        ~Hero()= default; // Destructor por defecto

        // Se implemntaron los getters y setters directos en el .h porque no leía los cpp

        int getId() const{  // Getter para el ID del héroe
            return id;
        }

        int getXp() const{ // Getter para la experiencia del héroe
            return xp;
        }

        void setXp(int v){ // Setter para la experiencia del héroe
            xp = v;
        }

        string getName() const{ // Getter para el nombre del héroe
            return name;
        }

        // Getter para la vida actual del héroe
        int getHp() const{ 
            return hp;
        }

        // Getter para el número de pociones del héroe
        int getPotions() const{ 
            return potions;
        }

        // Getter para el ataque del héroe
        int getAtk() const{ 
            return atk;
        }

        // Getter para la defensa del héroe
        int getDef() const{ 
            return def;
        }

        // Getter para la vida máxima del héroe
        int getHpMax() const{ 
            return hpMax;
        }

        void setPotions(int v){ // Setter para el número de pociones del héroe
            potions = v;
        }
        void setHp(int v){ // Setter para la vida actual del héroe
            hp = v;
        }
        void setHpMax(int v){ // Setter para la vida máxima del héroe
            hpMax = v;
        }
        void setAtk(int v){ // Setter para el ataque del héroe
            atk = v;
        }

        void heal(int amount){ // Método para curar al héroe
            hp += amount;
            if (hp > hpMax) {
                hp = hpMax;
            }
        }

        void addXp(int amount){ // Método para añadir experiencia al héroe
            xp += amount;
        }

        };

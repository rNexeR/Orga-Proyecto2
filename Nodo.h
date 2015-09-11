#ifndef NODO
#define NODO

#include <iostream>
using namespace std;

class Nodo{
public:
    string valor;
    Nodo *hijos[4];
    int cont;
    int orden;
    Nodo(){

    }

    Nodo(int orden, string val){
        valor = val;
        cont = 0;
        this->orden = orden;/*
        for(int x = 0; x < orden; x++)
            hijos[x] = new Nodo()*/
    }

    void addHijo(Nodo* hijo){
        if(cont >= orden)
            return;
        hijos[cont++] = hijo;
    }
};

#endif // NODO


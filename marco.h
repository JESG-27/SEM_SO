#ifndef MARCO_H
#define MARCO_H

#include <iostream>
#include "Proceso.h"

using namespace std;

class Marco
{
    int id;
    int bloques;
    string estado;          

public:
    Marco()
    {
        this->id = 0;
        this-> bloques = 0;
        this-> estado = "Libre";
    }

    void setID(int dato)
    {
        id = dato;
    }

    int getID()
    {
        return id;
    }

    void setBloques(int dato)
    {
        bloques = dato;
    }

    int getBloques()
    {
        return bloques;
    }

    void setEstado(const string &dato)
    {
        estado = dato;
    }

    string getEstado()
    {
        return estado;
    }
};

#endif
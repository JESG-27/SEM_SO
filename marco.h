#ifndef MARCO_H
#define MARCO_H

#include <iostream>

using namespace std;

class Marco
{
    int id;
    int bloques;           

public:
    Marco()
    {
        this->id = 0;
        this-> bloques = 0;
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
};

#endif
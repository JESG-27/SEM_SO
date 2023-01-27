#ifndef LOTE_H
#define LOTE_H

#include "proceso.h"

using namespace std;

class Lote{
    Proceso arreglo[4];
    size_t cont;
public:
    Lote();
    void agregarProceso(const Proceso &p);
    int size();

    friend Lote& operator<<(Lote &l, const Proceso &p)
    {
        l.agregarProceso(p);
        return l;
    }
};

#endif
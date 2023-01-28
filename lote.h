#ifndef LOTE_H
#define LOTE_H

#include "proceso.h"

using namespace std;

class Lote{
    list<Proceso> lista_procesos;
    size_t cont;
public:
    Lote();
    void agregarProceso(const Proceso &p);
    int size();
    void print();
    Proceso front();
    void pop_front();
    void print_ejecucion();

    friend Lote& operator<<(Lote &l, const Proceso &p)
    {
        l.agregarProceso(p);
        return l;
    }
};

#endif
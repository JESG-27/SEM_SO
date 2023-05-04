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
    void agregarProcesoListos(const Proceso &p, int llegada);
    void agregarProcesoEjecucion(const Proceso &p, int llegada);
    int size();
    void print();
    Proceso front();
    void pop_front();

    void print_listos();
    void print_ejecucion();
    void print_bloqueados();

    void BCP_nuevos();
    void BCP_listos_ejecucion_bloqueados(int cont);

    friend Lote& operator<<(Lote &l, const Proceso &p)
    {
        l.agregarProceso(p);
        return l;
    }
};

#endif
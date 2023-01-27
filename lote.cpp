#include "lote.h"

Lote::Lote()
{
    cont = 0;
}

void Lote::agregarProceso(const Proceso &p)
{
    if (cont<4)
    {
        arreglo[cont] = p;
        cont++;
    }
}

int Lote::size()
{
    return cont;
}
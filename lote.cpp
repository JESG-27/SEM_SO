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

Proceso Lote::acceder(int pos)
{
    if (pos<4)
    {
        return arreglo[pos];
    }
    else 
    {
        cout << "posicion no valida" << endl;
    }
}

int Lote::size()
{
    return cont;
}
#include "lote.h"

Lote::Lote()
{
    cont = 0;
}

void Lote::agregarProceso(const Proceso &p)
{
    if (cont<4)
    {
        lista_procesos.push_back(p);
        cont++;
    }
}

int Lote::size()
{
    return cont;
}

void Lote::print()
{
    for (auto it = lista_procesos.begin(); it != lista_procesos.end(); it++)
    {
        Proceso pro = *it;
        cout << "   ID: " << pro.getId() << endl;
        cout << "   Operacion: " << pro.getOperando_1() << pro.getOperacion() << pro.getOperando_2() << endl;
        cout << "   Tiempo: " << pro.getTiempo() << endl;
    }
}

Proceso Lote::front()
{
    return lista_procesos.front();
}

void Lote::pop_front()
{
    lista_procesos.pop_front();
    cont--;
}

void Lote::print_ejecucion()
{
    for (auto it = lista_procesos.begin(); it != lista_procesos.end(); it++)
    {
        Proceso pro = *it;
        cout << "   ID: " << pro.getId();
        cout << "   Estado: " << pro.getEstado();
        cout << "   Tiempo estimado: " << pro.getTiempo();
        cout << "   Tiempo transcurrido: " << pro.getTiempo()-pro.getTiempoRes() << endl;
    }
}
#include "lote.h"

Lote::Lote()
{
    cont = 0;
}

void Lote::agregarProceso(const Proceso &p)
{
    lista_procesos.push_back(p);
    cont++;
}

void Lote::agregarProcesoListos(const Proceso &p, int llegada)
{
    Proceso proceso = p;
    if (proceso.getTiempoLLegada() == -1)
    {
        proceso.setTiempoLLegada(llegada);    
    }
    proceso.setEstado("listo");
    lista_procesos.push_back(proceso);
    cont++;
}

void Lote::agregarProcesoEjecucion(const Proceso &p, int llegada)
{
    Proceso proceso = p;
    if (proceso.getTiempoRespuesta() == -1)
    {
        proceso.setTiempoRespuesta(llegada);    
    }
    proceso.setEstado("ejecucion");
    lista_procesos.push_back(proceso);
    cont++;
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

void Lote::print_listos()
{
    for (auto it = lista_procesos.begin(); it != lista_procesos.end(); it++)
    {
        Proceso pro = *it;
        cout << "   ID: " << pro.getId();
        cout << "   Tiempo estimado: " << pro.getTiempo();
        cout << "   Tiempo transcurrido: " << pro.getTiempo()-pro.getTiempoRes() << endl;
    }
}

void Lote::print_ejecucion()
{
    for (auto it = lista_procesos.begin(); it != lista_procesos.end(); it++)
    {
        Proceso pro = *it;
        cout << "   ID: " << pro.getId();
        cout << "   Operacion: " << pro.getOperando_1() << pro.getOperacion() << pro.getOperando_2();
        cout << "   Tiempo estimado: " << pro.getTiempo();
        cout << "   Tiempo transcurrido: " << pro.getTiempo()-pro.getTiempoRes();
        cout << "   Tiempo restante: " << pro.getTiempoRes() << endl;
    }
}

void Lote::print_bloqueados()
{
    for (auto it = lista_procesos.begin(); it != lista_procesos.end(); it++)
    {
        Proceso pro = *it;
        cout << "   ID: " << pro.getId();
        cout << "   Tiempo bloqueado (restante): " << pro.getTiempoBlo() << endl;
    }
}

void Lote::BCP_nuevos()
{
    for (auto it = lista_procesos.begin(); it != lista_procesos.end(); it++)
    {
        Proceso pro = *it;
        cout << "   ID: " << pro.getId() << endl;
        cout << "       Estado: " << pro.getEstado() << endl;
        cout << "       Operacion: " << pro.getOperando_1() << pro.getOperacion() << pro.getOperando_2() << endl << endl;
    }
}

void Lote::BCP_listos_ejecucion_bloqueados(int cont)
{
    for (auto it = lista_procesos.begin(); it != lista_procesos.end(); it++)
    {
        Proceso pro = *it;
        cout << "   ID: " << pro.getId() << endl;
        cout << "       Estado: " << pro.getEstado() << endl;
        cout << "       Operacion: " << pro.getOperando_1() << pro.getOperacion() << pro.getOperando_2() << endl;
        cout << "       Tiempo de llegada: " << pro.getTiempoLLegada() << endl;
        cout << "       Tiempo espera: " << (cont-pro.getTiempoLLegada())-(pro.getTiempo()-pro.getTiempoRes()) << endl;
        cout << "       Tiempo de servicio: " << pro.getTiempo()-pro.getTiempoRes()  << endl;
        cout << "       Tiempo restante: " << pro.getTiempoRes()  << endl;
        if (pro.getTiempoRespuesta() != -1)
        {
            cout << "       Tiempo respuesta: " << pro.getTiempoRespuesta()-pro.getTiempoLLegada() << endl;
        }
        if (pro.getEstado() == "bloqueado")
        {
            cout << "       Tiempo bloqueado (restante): " << pro.getTiempoBlo() << endl;
        }
        cout << endl;
    }
}
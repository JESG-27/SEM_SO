#include <iostream>
#include <queue>
#include <list>
#include "proceso.h"
#include "lote.h"
#include "funciones.h"

using namespace std;

int main(){

    int num_pro=0; // Número de procesos
    float num_lotes; // Número de lotes
    size_t i=0;
    queue<Lote> cola_lotes;
    list<Proceso> procesos_terminados;
    list<int> ids;

    do
    {
        cout << "Procesos a agregar: ";
        cin >> num_pro; cin.ignore();
        if (num_pro <= 0)
        {
            cout << "Cantidad no valida" << endl;
            system("pause");
        }
        system("cls");
    }
    while (num_pro < 0);

    num_lotes = num_pro/4;
    
    if (num_pro%4 != 0)
    {
        num_lotes = num_lotes+1;
    }

    cout << "Cantidad de lotes: " << num_lotes << endl;
    while (i<num_pro)
    {
        Lote nuevo_lote;
        size_t j=0;
        while (i<num_pro && j<4)
        {
            cout << "Proceso " << i+1 << endl;
            Proceso nuevo_proceso = capturarProceso(nuevo_lote, ids);
            nuevo_lote << nuevo_proceso;
            i++;
            j++;
            system("cls");
        }
        cola_lotes.push(nuevo_lote);
    }

    while (cola_lotes.size() != 0)
    {
        Lote lote_actual = cola_lotes.front();
        cola_lotes.pop();

        while (lote_actual.size() != 0)
        {
            Proceso proceso_actual = lote_actual.front();
            lote_actual.pop_front();
            
            cout << "Lotes Pendientes: " << cola_lotes.size() << endl;
            
            cout << "Tiempo transcurrido: " << endl; // Contador global

            cout << "Lote en ejecucion:" << endl;
            lote_actual.print_ejecucion();

            cout << "Proceso en ejecucion:" << endl;
            proceso_actual.print_ejecucion();
            //ejecutar_proceso(proceso_actual);
            // delay contador global, tiempo transcurrido y tiempo restante

            cout << "Procesos terminados:" << endl;
            if (lote_actual.size() == 0)
            {
                procesos_terminados.push_back(proceso_actual);
                for (auto it = procesos_terminados.begin(); it != procesos_terminados.end(); it++)
                {
                    Proceso pro = *it;
                    pro.print_terminado();
                }
            }
            else
            {
                for (auto it = procesos_terminados.begin(); it != procesos_terminados.end(); it++)
                {
                    Proceso pro = *it;
                    pro.print_terminado();
                }
                procesos_terminados.push_back(proceso_actual);
            }
        }    
    }
    return 0;
}

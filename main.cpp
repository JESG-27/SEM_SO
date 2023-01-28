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
    queue<Lote> lotes_terminados;
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
        // for (size_t pos=0; pos<num_lotes; pos++)
        // {
        //     cout << "Lote actual: " << pos+1 << endl;
        //     cola_lotes.front().print();
        //     lotes_terminados.push(cola_lotes.front());
        //     cola_lotes.pop();
        // }

        // cout << endl << "Terminados" << endl;
        // for (size_t pos=0; pos<num_lotes; pos++)
        // {
        //     lotes_terminados.front().print();
        //     lotes_terminados.pop();
        // }
        
        if (cola_lotes.size() != 1)
        {
            cout << "Lotes Pendientes: " << cola_lotes.size()-1 << endl;
        }
        cout << "Tiempo transcurrido: " << endl;
        
        cout << "Lote en ejecucion:" << endl;
        Lote lote_actual = cola_lotes.front();
        Proceso proceso_actual = lote_actual.front();
        lote_actual.pop_front();
        lote_actual.print();
        cout << endl;
        
        cout << "Proceso en ejecucion:" << endl;

        cout << "Procesos terminados:" << endl;
        for (size_t pos=0; pos<num_lotes; pos++)
        {
            lotes_terminados.front().print();
            lotes_terminados.pop();
        }
    }

    return 0;
}

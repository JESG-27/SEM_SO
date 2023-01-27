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
        cin >> num_pro;
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
            agregarProceso(nuevo_lote, ids);
            //nuevo_lote.agregarProceso(nuevo);
            i++;
            j++;
        }
        //cola_lotes.push(nuevo_lote);
        j=0;
    }


    //cout << "Lotes en cola: " << cola_lotes.size() << endl;
    //cout << cola_lotes.front().acceder(0).getId() << endl;
    
    return 0;
}

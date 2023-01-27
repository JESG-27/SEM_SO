#include <iostream>
#include "proceso.h"
#include "lote.h"
#include "funciones.h"
#include <queue>

using namespace std;

int main(){

    int num_pro=0; // Número de procesos
    float num_lotes; // Número de lotes
    size_t i=0;
    queue<Lote> cola_lotes;
    queue<Lote> lotes_terminados;


    // Lote lote1;
    // Proceso pro = Proceso(123, "Emmanuel", "12+10", 10);
    // lote1.agregarProceso(pro);
    // cout << "ID: " << lote1.acceder(6).getId() << endl;

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
        for (size_t j=0; j<4; j++)
        {
            Proceso nuevo = agregarProceso();    
            nuevo_lote.agregarProceso(nuevo);
            i++;
        }
        cola_lotes.push(nuevo_lote);
    }

    cout << "Lotes en cola: " << cola_lotes.size() << endl;
    cout << cola_lotes.front().acceder(0).getId() << endl;
    
    return 0;
}

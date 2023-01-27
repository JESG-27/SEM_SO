#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <iostream>
#include <vector>
#include "proceso.h"

using namespace std;

 vector<int> ids;

bool idExiste(int id){
    if (ids.size() == 0)
    {
        return false;
    }
    else
    {
        for (size_t i=0; i<ids.size(); i++)
        {
            if (ids[i] == id)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
    }
}

Proceso agregarProceso(){
    system("cls");

    int id, tiempo;
    string programador, operacion;

    cout << "ID: ";
    cin >> id;
    bool validacion = idExiste(id);

    while (validacion == true)
    {
        cout << "ID no valido" << endl;
        cout << "Ingreselo de nuevo" << endl;
        cout << "ID: ";
        cin >> id;
        validacion = idExiste(id);
    }

    if (validacion == false)
    {
        ids.push_back(id);
    }

    cout << "Programador: ";
    cin >> programador;

    cout << "Operacion: ";
    cin >> operacion;

    cout << "Tiempo: ";
    cin >> tiempo; 

    Proceso nuevo = Proceso(id, programador, operacion, tiempo);

    return nuevo;
}


#endif
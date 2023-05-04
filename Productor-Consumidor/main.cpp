#include <iostream>
#include <conio.h>
#include <windows.h>
#include "lista.h"
#include "productor.h"
#include "consumidor.h"

using namespace std;

int main()
{
    lista sala_espera;
    productor prod;
    consumidor cons;

    int num;

    while (true)
    {
        num = rand()%2;

        if (num == 0)                                   // Productor
        {
            cout << "Turno: Productor" << endl;
            cons.setEstado("Inactivo");

            if (sala_espera.size() < 22)
            {
                prod.setEstado("Activo");
                prod.producir(sala_espera);
            }

            else
            {
                prod.setEstado("Inactivo");
            }
        }

        else if (num == 1)                              // Consumidor
        {
            cout << "Turno: Consumidor" << endl;
            prod.setEstado("Inactivo");

            if (sala_espera.size() != 0)
            {
                cons.setEstado("Activo");
                cons.consumir(sala_espera);
            }

            else
            {
                cons.setEstado("Inactivo");
            }
        }

        cout << "Productor: " << prod.getEstado() << endl;
        cout << "Consumidor: " << cons.getEstado() << endl;

        sala_espera.imprimir();                         // Impresión de sala

        if (kbhit())                                    // Salir de la ejecución
        {
            char ch = getch();
            fflush(stdin);
            if (ch == 27)
            {
                break;
            }
        }

        Sleep(1000);
        system("cls");
    }

    return 0;
}
#include <iostream>
#include <queue>
#include <list>
#include <windows.h>
#include <conio.h>
#include <time.h>
#include "proceso.h"
#include "lote.h"
#include "funciones.h"

using namespace std;

int main(){

    int num_pro = 0, tiempo_res, global = 0, memoria = 0;        // Número de procesos
    size_t i=0, cont=0;
    list<int> ids;
    char ch;

    // Lotes de estados
    Lote nuevos, listos, bloqueados, ejecucion;
    list<Proceso> terminados;

    // Captura de número de procesos 
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

    // Captura de los procesos
    while (i<num_pro)
    {
        Proceso nuevo_proceso = capturarProceso(nuevos, ids);
        nuevos.agregarProceso(nuevo_proceso);
        i++;
        system("cls");
    }

    // Ejecucción de los procesos
    while (terminados.size() != num_pro)
    {
        memoria = listos.size() + ejecucion.size() + bloqueados.size();

        if (memoria < 4)
        {
            if (nuevos.size() > 0)
            {
                int faltantes = 4 - memoria;
                while (nuevos.size() > 0 && faltantes > 0)
                {
                    Proceso p = nuevos.front();
                    nuevos.pop_front();
                    listos.agregarProceso(p);
                    faltantes--; 
                    memoria = listos.size() + ejecucion.size() + bloqueados.size();
                }
            }
        }

        if (listos.size() != 0)
        {
            Proceso proceso_actual = listos.front();
            listos.pop_front();
            ejecucion.agregarProceso(proceso_actual);
        }

        while (true)
        {   
            cout << "Tiempo total: " << cont << endl;

            if (listos.size() != 0 || ejecucion.size() != 0)
            {
                if (ejecucion.size() == 0)
                {
                    Proceso proceso_actual = listos.front();
                    listos.pop_front();
                    ejecucion.agregarProceso(proceso_actual);
                }
                
                Proceso proceso_actual = ejecucion.front();

                if (proceso_actual.getTiempoRes() != 0)
                {
                    cout << "Ejecucion" << endl;
                    proceso_actual.print_ejecucion();
                    cout << "   Tiempo restante: "<< proceso_actual.getTiempoRes() << endl;
                    proceso_actual.setTiempoRes(proceso_actual.getTiempoRes()-1);
                    ejecucion.pop_front();
                    ejecucion.agregarProceso(proceso_actual);
                }

                else if (proceso_actual.getTiempoRes() == 0)
                {
                    ejecucion.pop_front();
                    ejecutar_proceso(proceso_actual);
                    terminados.push_back(proceso_actual);
                    system("cls");
                    break;
                }
            }
            

            // Actualización de bloqueados
            if (bloqueados.size() != 0)
            {
                cout << endl << "Bloqueados" << endl;
                tiempoBloqueo(bloqueados, listos);
                bloqueados.print_ejecucion();
            }

            if (bloqueados.size() == 0 && listos.size() != 0 && ejecucion.size() == 0)
            {
                system("cls");
                break;
            }

            cout << "Nuevos: " << nuevos.size() << endl;
            cout << "Memoria: " << memoria << endl;
            cout << "   Listos: " << listos.size() << endl;
            cout << "   Ejecucion: " << ejecucion.size() << endl;
            cout << "   Bloqueados: " << bloqueados.size() << endl;
            cout << "Terminados: " << terminados.size() << endl << endl;

            Sleep(1000);
            cont++;

            // Pulsaciones de teclas
            if (kbhit())
            {
                ch = getch();
                ch = tolower(ch);
                fflush(stdin);

                if(ch =='i')                                    // Bloqueo
                {
                    if (ejecucion.size() != 0)
                    {
                        Proceso proceso_actual = ejecucion.front();
                        ejecucion.pop_front();
                        proceso_actual.setTiempoBlo(5);
                        bloqueados.agregarProceso(proceso_actual);
                        system("cls");
                        break;    
                    }
                }

                
                else if (ch =='e')                              // Error
                {
                    if (ejecucion.size() != 0)
                    {
                        Proceso proceso_actual = ejecucion.front();
                        proceso_actual.setEstado("error"); 
                        ejecucion.pop_front();
                        terminados.push_back(proceso_actual);
                        system("cls");
                        break;
                    }
                }

                else if (ch == 'p')
                {
                    while (true)
                    {
                        ch = getch();
                        ch = tolower(ch);
                        if (ch == 'c')
                        {
                            break;
                        }
                    }
                }

            }
            
            system("cls");
        }
   
    }

    cout << "Termino" << endl;

    return 0;
}

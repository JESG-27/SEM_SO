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

    int num_pro=0, tiempo_res, global = 0, TTE=0, TRE=0;        // Número de procesos
    float num_lotes;                                        // Número de lotes
    char ch;
    size_t i=0;
    queue<Lote> cola_lotes;
    list<Proceso> procesos_terminados;
    list<int> ids;

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

    num_lotes = num_pro/4;
    
    if (num_pro%4 != 0)
    {
        num_lotes = num_lotes+1;
    }

    // Captura de los procesos
    cout << "Cantidad de lotes: " << num_lotes << endl;
    while (i<num_pro)
    {
        Lote nuevo_lote;
        size_t j=0;
        int num_lote;
        while (i<num_pro && j<4)
        {
            cout << "Proceso " << i+1 << endl;
            Proceso nuevo_proceso = capturarProceso(nuevo_lote, ids, cola_lotes.size()+1);
            nuevo_lote << nuevo_proceso;
            i++;
            j++;
            system("cls");
        }
        cola_lotes.push(nuevo_lote);
    }

    // Ejecucción de los procesos
    while (cola_lotes.size() != 0)
    {
        Lote lote_actual = cola_lotes.front();
        cola_lotes.pop();

        while (lote_actual.size() != 0)
        {
            Proceso proceso_actual = lote_actual.front();
            lote_actual.pop_front();
            tiempo_res = proceso_actual.getTiempoRes();
            TTE=0;

            while (tiempo_res >= 0)
            {
                if (kbhit())
                {
                    ch = getch();
                    fflush(stdin);
                    //cout << "Capturo " << ch << endl;

                    if(ch =='i')                                    // Interrupción
                    {
                        cout << "Interrupcion" << endl;
                        proceso_actual.setEstado("Interrumpido");
                        lote_actual.agregarProceso(proceso_actual);
                        break;
                    }

                    else if (ch =='e')                              // Error
                    {
                        cout << "Error" << endl;
                        proceso_actual.setEstado("Error");
                        procesos_terminados.push_back(proceso_actual);
                        break;
                    }

                    else if (ch =='p')
                    {
                        proceso_actual.setEstado("Pausa");
                        fflush( stdin );

                        system("cls");
                        cout << "Proceso en ejecucion:" << endl;
                        proceso_actual.print_ejecucion();
                        cout << "   Tiempo transcurrido: " << TTE;
                        cout << "   Tiempo restante: " << proceso_actual.getTiempoRes() << endl; 
                        cout << "Presiona c para continuar: ";

                        while (true)
                        {
                            ch = getch();
                            if (ch == 'c')
                            {
                                cout << "Continua" << endl;
                                proceso_actual.setEstado("Ejecutando");
                                break;
                            }
                        }
                    }
                }


                cout << "Lotes Pendientes: " << cola_lotes.size() << endl;
                
                cout << "Tiempo total transcurrido: " << global <<endl; // Contador global

                cout << "Lote en ejecucion:" << endl;
                lote_actual.print_ejecucion();

                cout << "Proceso en ejecucion:" << endl;
                proceso_actual.print_ejecucion();
                cout << "   Tiempo transcurrido: " << proceso_actual.getTiempo()-proceso_actual.getTiempoRes();
                cout << "   Tiempo restante: " << proceso_actual.getTiempoRes() << endl;                           

                
                cout << "Procesos terminados:" << endl;
                for (auto it = procesos_terminados.begin(); it != procesos_terminados.end(); it++)
                {
                    Proceso pro = *it;
                    pro.print_terminado();
                }
                
                Sleep(1000);        //Detener por un segundo 
                global++;           //Aumenta el contador global 
                proceso_actual.setTiempoRes(tiempo_res--);
                TTE++;              //Tiempo transcurrido

                system("cls");
            }

            if (proceso_actual.getTiempoRes() == 0)
            {
                ejecutar_proceso(proceso_actual);       //Valor de la operacion 
                proceso_actual.setEstado("Terminado");
                procesos_terminados.push_back(proceso_actual);
            }
            
            if (cola_lotes.size() == 0 && lote_actual.size() == 0)
            {
                cout << "Tiempo total:" << global << endl;
                cout << "Procesos terminados:" << endl;
                for (auto it = procesos_terminados.begin(); it != procesos_terminados.end(); it++)
                {
                    Proceso pro = *it;
                    pro.print_terminado();
                }
            }

        }    
    }
    return 0;
}

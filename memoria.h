#ifndef MEMORIA_H
#define MEMORIA_H

#include <iostream>
#include "marco.h"
#include "proceso.h"

using namespace std;

class Memoria
{
    Marco arreglo[40];
    int cont;

public:
    
    Memoria()
    {
        cont = 0;
        size_t i = 0;
        while(i != 40)
        {
            Marco a = Marco();
            arreglo[i] = a;
            
            if (i == 38 || i == 39)
            {
                arreglo[i].setID(-1);
                arreglo[i].setBloques(5);
                cont++;
            }

            i++;
        }
    }

    int size()
    {
        return cont;
    }

    void cargarMemoria(Proceso &p)
    {
        bool fragmentacion = false;
        int marcos = p.getTamanio()/5;
        int fragmentos = p.getTamanio()%5;
        
        if (p.getTamanio()%5 != 0)
        {
            marcos++;
            fragmentacion = true;
        }
        
        for (size_t i=0; i<40; i++)
        {
            if (arreglo[i].getID() == 0)
            {
                if (marcos != 0)
                {
                    arreglo[i].setID(p.getId());
                    
                    if (fragmentacion == false)
                    {
                        arreglo[i].setBloques(5);
                        marcos--;
                        cont++;
                    }
                    
                    else if (fragmentacion == true)
                    {
                        if (marcos != 1)
                        {
                            arreglo[i].setBloques(5);
                            marcos--;
                            cont++;
                        }
                        else if (marcos == 1)
                        {
                            arreglo[i].setBloques(fragmentos);
                            marcos--;
                            cont++;
                        }
                    }
                }

                else
                {
                    break;
                }
            }
        }
    }
};

#endif
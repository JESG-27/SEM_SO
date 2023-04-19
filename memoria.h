#ifndef MEMORIA_H
#define MEMORIA_H

#include <iostream>
#include "marco.h"
#include "proceso.h"

#define SIZE 40

using namespace std;

class Memoria
{
    Marco arreglo[SIZE];
    int cont;

public:
    
    Memoria()
    {
        cont = 0;
        size_t i = 0;
        while(i != SIZE)
        {
            Marco a = Marco();
            arreglo[i] = a;
            
            if (i == SIZE-2 || i == SIZE-1)
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

    void agregar(Proceso &p)
    {
        bool fragmentacion = false;
        int marcos = p.getTamanio()/5;
        int fragmentos = p.getTamanio()%5;
        
        if (p.getTamanio()%5 != 0)
        {
            marcos++;
            fragmentacion = true;
        }
        
        for (size_t i=0; i<SIZE; i++)
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


    void eliminar(Proceso &p)
    {
        int id_eliminar = p.getId();
        for (size_t i=0; i<SIZE; i++)
        {
            if (arreglo[i].getID() == id_eliminar)
            {
                arreglo[i].setID(0);
                arreglo[i].setBloques(0);
                cont--;
            }
        }
    }

    void imprimir()
    {
        for (size_t i=0; i<SIZE; i++)
        {
            if (i < 10)
            {
                if (arreglo[i].getID() == 0)
                {
                    cout << "   Marco:  " << i << "    ID: Libre" << "    Bloques en uso: " << arreglo[i].getBloques() << "/5" << endl;
                }
                else
                {
                    if (arreglo[i].getID() < 10)
                        cout << "   Marco:  " << i << "    ID:     " << arreglo[i].getID() << "    Bloques en uso: " << arreglo[i].getBloques() << "/5" << endl;
                    else
                        cout << "   Marco:  " << i << "    ID:   " << arreglo[i].getID() << "     Bloques en uso: " << arreglo[i].getBloques() << "/5" << endl;
                }
            }

            else
            {
                if (arreglo[i].getID() == 0)
                {
                    cout << "   Marco:  " << i << "   ID: Libre" << "    Bloques en uso: " << arreglo[i].getBloques() << "/5" << endl;
                }

                else if (arreglo[i].getID() == -1)
                {
                    cout << "   Marco:  " << i << "   ID: SO   " << "    Bloques en uso: " << arreglo[i].getBloques() << "/5" << endl;
                }

                else
                {
                    if (arreglo[i].getID() < 10)
                        cout << "   Marco:  " << i << "   ID:     " << arreglo[i].getID() << "    Bloques en uso: " << arreglo[i].getBloques() << "/5" << endl;
                    else
                        cout << "   Marco:  " << i << "   ID:   " << arreglo[i].getID() << "     Bloques en uso: " << arreglo[i].getBloques() << "/5" << endl;
                }
            }
        }
        cout << endl;
    }
};

#endif
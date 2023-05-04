#ifndef PRODUCTOR_H
#define PRODUCTOR_H

#include <iostream>
#include "lista.h"

using namespace std;

class productor
{
    private:
        int posicion;
        string estado;
    
    public:
        productor()
        {
            posicion = 0;
            estado = "Inactivo";
        }

        void setEstado(const string &dato)
        {
            estado = dato;
        }

        string getEstado()
        {
            return estado;
        }

        void producir(lista &sala)
        {
            int inicial = posicion;
            int prod = rand()%7;

            if (prod<3)
            {
                prod = prod+3;
            }

            cout << "Producir: " << prod << endl;

            while (prod != 0)
            {
                if (sala.dato(posicion) == ' ')
                {
                    sala.agregar(posicion);
                    posicion++;
                    prod--;
                }

                else if (sala.dato(posicion+1) == ' ')
                {
                    sala.agregar(posicion+1);
                    posicion++;
                    prod--;
                }

                else if (posicion == 22)
                {
                    posicion = 0;
                }

                else 
                {
                    break;
                }
            }
        }
};

#endif
#ifndef CONSUMIDOR_H
#define CONSUMIDOR_H

#include <iostream>

using namespace std;

class consumidor
{
    private:
        int posicion;
        string estado;

    public:
        consumidor()
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

        void consumir(lista &sala)
        {
            int inicial = posicion;
            int cons = rand()%7;

            if (cons<3)
            {
                cons = cons+3;
            }

            cout << "Consumir: " << cons << endl;

            while (cons != 0)
            {
                if (sala.dato(posicion) == '*')
                {
                    sala.eliminar(posicion);
                    posicion++;
                    cons--;
                }

                else if (sala.dato(posicion+1) == '*')
                {
                    sala.eliminar(posicion+1);
                    posicion++;
                    cons--;
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
#ifndef LISTA_H
#define LISTA_H
#define SIZE 22

#include <iostream>

using namespace std;

class lista
{
    private:
        char arreglo[SIZE];
        int cont;
    
    public:
        lista()
        {
            cont = 0;
            for (size_t i=0; i<SIZE; i++)
            {
                arreglo[i] = ' ';
            }
        }

        int size()
        {
            return cont;
        }

        void agregar(int pos)
        {
            arreglo[pos] = '*';
            cont++;
        }

        void eliminar(int pos)
        {
            arreglo[pos] = ' ';
            cont--;
        }

        char dato(int pos)
        {
            return arreglo[pos];
        }

        void imprimir()
        {
            int i = 1;
            while (i <= SIZE)
            {
                if (i<10)
                {
                    cout << " " << i << "  ";
                }
                else
                {
                    cout << i << "  ";
                }
                i++;
            }
            cout << endl;

            i = 0;
            while (i != SIZE)
            {
                cout << " " << arreglo[i] << "  ";
                i++;
            }
            cout << endl;
        }
};

#endif
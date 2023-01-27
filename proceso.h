#ifndef PROCESO_H
#define PROCESO_H

#include <iostream>

using namespace std;

class Proceso{
    int id;
    string programador;
    string operacion;
    int tiempo;

public:
    Proceso();
    Proceso(int id, const string &programador, const string &operacion, int tiempo);
    void setId(int dato);
    int getId();
    void setProgramador(const string &dato);
    string getProgramador();
    void setOperacion(const string &dato);
    string getOperacion();
    void setTiempo(int dato);
    int getTiempo();
};

#endif
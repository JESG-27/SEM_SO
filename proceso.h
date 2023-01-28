#ifndef PROCESO_H
#define PROCESO_H

#include <iostream>
#include <list>

using namespace std;

class Proceso{
    int id;
    string programador;
    float operando_1;
    string operacion;
    float operando_2;
    int tiempo;
    float resultado;

public:
    Proceso();
    Proceso(int id, const string &programador, float operando_1, const string &operacion, float operando_2, int tiempo);
    
    void setId(int dato);
    int getId();
    
    void setProgramador(const string &dato);
    string getProgramador();
    
    void setOperando_1(float dato);
    float getOperando_1();
    
    void setOperacion(const string &dato);
    string getOperacion();

    void setOperando_2(float dato);
    float getOperando_2();
    
    void setTiempo(int dato);
    int getTiempo();

    void setResultado(float dato);
    float getResultado();

    void print_ejecucion();
    void print_terminado();
};

#endif
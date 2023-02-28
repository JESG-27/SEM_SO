#ifndef PROCESO_H
#define PROCESO_H

#include <iostream>
#include <list>

using namespace std;

class Proceso{
    int id;
    float operando_1;
    string operacion;
    float operando_2;
    int tiempo;
    int tiempo_res;
    int tiempo_blo;
    float resultado;
    string estado;

public:
    Proceso();
    Proceso(int id, float operando_1, const string &operacion, float operando_2, int tiempo, const string &estado);
    
    void setId(int dato);
    int getId();
    
    void setOperando_1(float dato);
    float getOperando_1();
    
    void setOperacion(const string &dato);
    string getOperacion();
    

    void setOperando_2(float dato);
    float getOperando_2();
    
    void setTiempo(int dato);
    int getTiempo();

    void setTiempoRes(int dato);
    int getTiempoRes();

    void setTiempoBlo(int dato);
    int getTiempoBlo();

    void setResultado(float dato);
    float getResultado();

    void setEstado(const string &dato);
    string getEstado();

    void print_ejecucion();
    void print_terminado();

};

#endif
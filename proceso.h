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
    float resultado;
    int num_lote;
    string estado;

public:
    Proceso();
    Proceso(int id, float operando_1, const string &operacion, float operando_2, int tiempo, int numero_lote,const string &estado);
    
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

    void setResultado(float dato);
    float getResultado();

    void setEstado(const string &dato);
    string getEstado();

    void setNum_lote(int dato);
    int getNum_lote();

    void print_ejecucion();
    void print_terminado();
};

#endif
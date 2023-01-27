#ifndef PROCESO_H
#define PROCESO_H

#include <iostream>

using namespace std;

class Proceso{
    int id;
    string programador;
    float operando_1;
    char operacion;
    float operando_2;
    int tiempo;

public:
    Proceso();
    Proceso(int id, const string &programador, float operando_1, const char &operacion, float operando_2, int tiempo);
    
    void setId(int dato);
    int getId();
    
    void setProgramador(const string &dato);
    string getProgramador();
    
    void setOperando_1(float dato);
    float getOperando_1();
    
    void setOperacion(const char &dato);
    char getOperacion();

    void setOperando_2(float dato);
    float getOperando_2();
    
    void setTiempo(int dato);
    int getTiempo();
};

#endif
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

    int tiempo;                     // Tiempo estimado
    int tiempo_res;                 // Tiempo restante
    int tiempo_blo;                 // Tiempo bloqueado
    int tiempo_llegada;             // Tiempo llegada
    int tiempo_respuesta;           // Tiempo respuesta
    int tiempo_finalizacion;        // Tiempo finalización

    int quantum;
    
    float resultado;
    string estado;
    int tamanio;

public:
    Proceso();
    Proceso(int id, float operando_1, const string &operacion, float operando_2, int tiempo, const string &estado, int tamanio);
    
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

    void setTiempoLLegada(int dato);
    int getTiempoLLegada();

    void setTiempoRespuesta(int dato);
    int getTiempoRespuesta();

    void setTiempoFinalizacion(int dato);
    int getTiempoFinalizacion();

    void setQuantum(int dato);
    int getQuantum();

    void setResultado(float dato);
    float getResultado();

    void setEstado(const string &dato);
    string getEstado();

    void setTamanio(int dato);
    int getTamanio();

    void print_ejecucion();
    void print_terminado();

};

#endif
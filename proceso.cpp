#include "proceso.h"

Proceso::Proceso()
{

}

Proceso::Proceso(int id, float operando_1, const string &operacion, float operando_2, int tiempo, const string &estado, int tamanio)
{
    this->id = id;
    this->operando_1 = operando_1;
    this->operacion = operacion;
    this->operando_2 = operando_2;
    this->tiempo = tiempo;
    this->tiempo_res = tiempo;
    this->tiempo_blo = 0;
    this->tiempo_llegada = -1;
    this->tiempo_respuesta = -1;
    this->estado = estado;
    this->tamanio = tamanio;
}

void Proceso::setId(int dato)
{
    id = dato;
}

int Proceso::getId()
{
    return id;
}

void Proceso::setOperando_1(float dato)
{
    operando_1 = dato;
}

float Proceso::getOperando_1()
{
    return operando_1;
}

void Proceso::setOperacion(const string &dato)
{
    operacion = dato;
}

string Proceso::getOperacion()
{
    return operacion;
}

void Proceso::setOperando_2(float dato)
{
    operando_2 = dato;
}

float Proceso::getOperando_2()
{
    return operando_2;
}

void Proceso::setTiempoRes(int dato)
{
    tiempo_res = dato;
}

int Proceso::getTiempoRes()
{
    return tiempo_res;
}

void Proceso::setTiempo(int dato)
{
    tiempo = dato;
}

int Proceso::getTiempo()
{
    return tiempo;
}

void Proceso::setTiempoBlo(int dato)
{
    tiempo_blo = dato;
}

int Proceso::getTiempoBlo()
{
    return tiempo_blo;
}

void Proceso::setTiempoLLegada(int dato)
{
    tiempo_llegada = dato;
}

int Proceso::getTiempoLLegada()
{
    return tiempo_llegada;
}

void Proceso::setTiempoRespuesta(int dato)
{
    tiempo_respuesta = dato;
}

int Proceso::getTiempoRespuesta()
{
    return tiempo_respuesta;
}

void Proceso::setTiempoFinalizacion(int dato)
{
    tiempo_finalizacion = dato;
}

int Proceso::getTiempoFinalizacion()
{
    return tiempo_finalizacion;
}

void Proceso::setResultado(float dato)
{
    resultado = dato;
}

float Proceso::getResultado()
{
    return resultado;
}

void Proceso::setEstado(const string &dato)//Agregue el estado del proceos
{
    estado = dato;
}

string Proceso::getEstado()
{
    return estado;
}

void Proceso::setTamanio(int dato)
{
    tamanio = dato;
}

int Proceso::getTamanio()
{
    return tamanio;
}

void Proceso::print_ejecucion()
{
    cout << "   ID: " << id;
    cout << "   Operacion: " << operando_1 << operacion << operando_2;
    cout << "   Tiempo estimado: " << tiempo;
}

void Proceso::print_terminado()
{
    cout << "   ID: " << id;
    cout << "   Operacion: " << operando_1 << operacion << operando_2;
    if(estado!="Error"){
        cout << "   Resultado: " << resultado;
    }
    cout << "   Estado: " << estado;
}
#include "proceso.h"

Proceso::Proceso()
{

}

Proceso::Proceso(int id, float operando_1, const string &operacion, float operando_2, int tiempo, int numero_lote,const string &estado)
{
    this->id = id;
    this->operando_1 = operando_1;
    this->operacion = operacion;
    this->operando_2 = operando_2;
    this->tiempo = tiempo;
    this->tiempo_res = tiempo;
    this->num_lote = numero_lote;
    this->estado = estado;
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

void Proceso::setNum_lote(int dato)
{
    num_lote = dato;
}

int Proceso::getNum_lote()
{
    return num_lote;
}

void Proceso::print_ejecucion()
{
    cout << "   ID: " << id;
    cout << "   Operacion: " << operando_1 << operacion << operando_2;
    cout << "   Estado: " << estado;
    cout << "   Tiempo estimado: " << tiempo;
}

void Proceso::print_terminado()
{
    cout << "   ID: " << id;
    cout << "   Operacion: " << operando_1 << operacion << operando_2;
    cout << "   Resultado: " << resultado;
    cout << "   Estado: " << estado;
    cout << "   Lote: " << num_lote << endl;
}
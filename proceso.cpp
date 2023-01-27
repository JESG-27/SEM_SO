#include "proceso.h"

Proceso::Proceso()
{

}

Proceso::Proceso(int id, const string &programador, float operando_1, const char &operacion, float operando_2, int tiempo)
{
    this->id = id;
    this->programador = programador;
    this->operando_1 = operando_1;
    this->operacion = operacion;
    this->operando_2 = operando_2;
    this->tiempo = tiempo;
}

void Proceso::setId(int dato)
{
    id = dato;
}

int Proceso::getId()
{
    return id;
}

void Proceso::setProgramador(const string &dato)
{
    programador = dato;
}

string Proceso::getProgramador()
{
    return programador;
}

void Proceso::setOperando_1(float dato)
{
    operando_1 = dato;
}

float Proceso::getOperando_1()
{
    return operando_1;
}

void Proceso::setOperacion(const char &dato)
{
    operacion = dato;
}

char Proceso::getOperacion()
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

void Proceso::setTiempo(int dato)
{
    tiempo = dato;
}

int Proceso::getTiempo()
{
    return tiempo;
}
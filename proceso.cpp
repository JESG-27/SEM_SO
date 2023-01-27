#include "proceso.h"

Proceso::Proceso()
{

}

Proceso::Proceso(int id, const string &programador, const string &operacion, int tiempo)
{
    this->id = id;
    this->programador = programador;
    this->operacion = operacion;
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

void Proceso::setOperacion(const string &dato)
{
    operacion = dato;
}

string Proceso::getOperacion()
{
    return operacion;
}

void Proceso::setTiempo(int dato)
{
    tiempo = dato;
}

int Proceso::getTiempo()
{
    return tiempo;
}
#include "Cliente.h"

Cliente::Cliente(int idCliente, string nombre, string apellido)
{
    this->idCliente = idCliente;
    this->nombre = nombre;
    this->apellido = apellido;
}

Cliente::~Cliente()
{
    //dtor
}

int Cliente::getIdCliente() {
    return this->idCliente;
}

string Cliente::getNombre() {
    return this->nombre;
}

string Cliente::getApellido() {
    return this->apellido;
}

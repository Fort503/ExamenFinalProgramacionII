#include "Fecha.h"

Fecha::Fecha(int dia, int mes, int anio)
{
    this->dia = dia;
    this->mes = mes;
    this->anio = anio;
}

Fecha::~Fecha()
{
    //dtor
}

string Fecha::mostrarFecha() {
    return to_string(dia) + "/" + to_string(mes) + "/" + to_string(anio);
}

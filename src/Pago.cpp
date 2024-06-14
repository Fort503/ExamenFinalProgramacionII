#include "Pago.h"

Pago::Pago(Fecha* fechaPago, float montoPago)
{
    this->fechaPago = fechaPago;
    this->montoPago = montoPago;
}

Pago::~Pago()
{
    //dtor
}

Fecha* Pago::getFechaPago() {
    return this->fechaPago;
}

float Pago::getMontoPago() {
    return montoPago;
}

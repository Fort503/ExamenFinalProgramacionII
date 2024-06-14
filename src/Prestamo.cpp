#include "Prestamo.h"

Prestamo::Prestamo()
{
    this->numeroPrestamo = 0;
    this->cliente = nullptr;
    this->fechaAprobacion = nullptr;
    this->montoAprobado = 0;
    this->saldoPendiente = 0;
    this->contadorDePagos = 0;
}

Prestamo::Prestamo(int numeroPrestamo, Cliente* cliente, Fecha* fechaAprobacion, float montoAprobado) {
    this->numeroPrestamo = numeroPrestamo;
    this->cliente = cliente;
    this->fechaAprobacion = fechaAprobacion;
    this->montoAprobado = montoAprobado;
    this->saldoPendiente = montoAprobado;
    this->contadorDePagos = 0;
}

Prestamo::~Prestamo()
{
    //dtor
}

int Prestamo::getNumeroPrestamo() {
    return this->numeroPrestamo;
}

Cliente* Prestamo::getCliente() {
    return this->cliente;
}

Fecha* Prestamo::getFechaAprobacion() {
    return this->fechaAprobacion;
}

float Prestamo::getMontoAprobado() {
    return this->montoAprobado;
}

bool Prestamo::hacerPago(Pago* pago) {
    bool pagoRealizado = false;
    if(this->saldoPendiente >= pago->getMontoPago()) {
        this->saldoPendiente -= pago->getMontoPago();
        this->lstPagos[this->contadorDePagos] = pago;
        this->contadorDePagos++;
        pagoRealizado = true;
    }

    return pagoRealizado;
}

Pago** Prestamo::getLstPagos() {
    return this->lstPagos;
}

float Prestamo::getSaldoPendiente() {
    return this->saldoPendiente;
}

int Prestamo::getContadorPagos() {
    return this->contadorDePagos;
}




#include "Modelo.h"

Cliente* Modelo::clientes[MAX_CLIENTES];
int Modelo::contadorClientes = 0;
int Modelo::ultimoIdCliente = 0;

Prestamo* Modelo::prestamos[MAX_PRESTAMOS];
int Modelo::contadorPrestamos = 0;
int Modelo::ultimoIdPrestamo = 0;

void Modelo::agregarCliente(Cliente* cliente) {
    if (contadorClientes < MAX_CLIENTES) {
        clientes[contadorClientes] = cliente;
        contadorClientes++;
    } else {
        wxMessageBox("No se pueden agregar más clientes. Límite alcanzado.");
    }
}

Cliente** Modelo::getClientes() {
    return clientes;
}

int Modelo::getContadorClientes() {
    return contadorClientes;
}

int Modelo::generarIdCliente() {
    return ++ultimoIdCliente;
}

void Modelo::agregarPrestamo(Prestamo* prestamo) {
    if (contadorPrestamos < MAX_PRESTAMOS) {
        prestamos[contadorPrestamos] = prestamo;
        contadorPrestamos++;
    } else {
        wxMessageBox("No se pueden agregar más préstamos. Límite alcanzado.");
    }
}

Prestamo** Modelo::getPrestamos() {
    return prestamos;
}

int Modelo::getContadorPrestamos() {
    return contadorPrestamos;
}

int Modelo::generarIdPrestamo() {
    return ++ultimoIdPrestamo;
}

#ifndef MODELO_H
#define MODELO_H

#include "Cliente.h"
#include "Prestamo.h"
#include "wx/msgdlg.h"

const int MAX_CLIENTES = 100;
const int MAX_PRESTAMOS = 100;

class Modelo
{
public:
    static void agregarCliente(Cliente* cliente);
    static Cliente** getClientes();
    static int getContadorClientes();
    static int generarIdCliente();

    static void agregarPrestamo(Prestamo* prestamo);
    static Prestamo** getPrestamos();
    static int getContadorPrestamos();
    static int generarIdPrestamo();

private:
    static Cliente* clientes[MAX_CLIENTES];
    static int contadorClientes;
    static int ultimoIdCliente;

    static Prestamo* prestamos[MAX_PRESTAMOS];
    static int contadorPrestamos;
    static int ultimoIdPrestamo;
};

#endif // MODELO_H

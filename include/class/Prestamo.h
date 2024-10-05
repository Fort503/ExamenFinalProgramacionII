#ifndef PRESTAMO_H
#define PRESTAMO_H
#include "Cliente.h"
#include "Pago.h"
#include "Fecha.h"
#define TAM 5


class Prestamo
{
    public:
        Prestamo();
        Prestamo(int, Cliente*, Fecha*, float);
        virtual ~Prestamo();
        int getNumeroPrestamo();
        void setNumeroPrestamo();
        Cliente* getCliente();
        void setCliente(Cliente*);
        Fecha* getFechaAprobacion();
        void setFechaAprobacion(Fecha*);
        float getMontoAprobado();
        bool hacerPago(Pago*);
        Pago** getLstPagos();
        float getSaldoPendiente();
        int getContadorPagos();


    protected:

    private:
        int numeroPrestamo;
        Cliente* cliente;
        Fecha* fechaAprobacion;
        float montoAprobado;
        Pago* lstPagos[TAM];
        float saldoPendiente;
        int contadorDePagos;

};

#endif // PRESTAMO_H

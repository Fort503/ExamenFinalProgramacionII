#ifndef PAGO_H
#define PAGO_H
#include "Fecha.h"

class Pago
{
    public:
        Pago(Fecha*, float);
        virtual ~Pago();
        Fecha* getFechaPago();
        float getMontoPago();

    protected:

    private:
        Fecha* fechaPago;
        float montoPago;
};

#endif // PAGO_H

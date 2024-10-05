#ifndef DETALLESPRESTAMOFRAME_H
#define DETALLESPRESTAMOFRAME_H

#include <wx/wx.h>
#include <wx/listbox.h>
#include "Prestamo.h"
#include "HacerPagoFrame.h"

class DetallesPrestamoFrame : public wxFrame
{
public:
    DetallesPrestamoFrame(wxWindow* parent, Prestamo* prestamo);
    void actualizarListaPagos();

private:
    void OnHacerPago(wxCommandEvent& event);
    void OnSalir(wxCommandEvent& event);

    Prestamo* prestamo;

    wxPanel* panel;
    wxBoxSizer* mainSizer;
    wxBoxSizer* buttonSizer;

    wxTextCtrl* numeroPrestamoCtrl;
    wxTextCtrl* clienteCtrl;
    wxTextCtrl* fechaAprobacionCtrl;
    wxTextCtrl* montoAprobadoCtrl;
    wxTextCtrl* saldoPendienteCtrl;
    wxListBox* pagosListBox;

    wxButton* hacerPagoButton;
    wxButton* salirButton;

    wxDECLARE_EVENT_TABLE();
};

enum
{
    ID_HacerPago = 1,
    ID_Salir
};

#endif // DETALLESPRESTAMOFRAME_H

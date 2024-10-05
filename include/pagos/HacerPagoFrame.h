#ifndef HACERPAGOFRAME_H
#define HACERPAGOFRAME_H

#include <wx/wx.h>
#include <wx/datectrl.h>
#include <wx/dateevt.h>
#include "Modelo.h"
#include "Prestamo.h"
#include "fonts.h"
#include "colors.h"
#include "PrestamosFrame.h"

class HacerPagoFrame : public wxFrame
{
public:
    HacerPagoFrame(wxWindow* parent, Prestamo* prestamo);

private:
    void OnGuardar(wxCommandEvent& event);
    void OnCancelar(wxCommandEvent& event);

    Prestamo* prestamo;

    wxPanel* panel;
    wxTextCtrl* montoCtrl;
    wxDatePickerCtrl* fechaCtrl;
    wxButton* guardarButton;
    wxButton* cancelarButton;

    wxDECLARE_EVENT_TABLE();
};

enum
{
    ID_GuardarPago = 1,
    ID_CancelarPago
};

#endif // HACERPAGOFRAME_H

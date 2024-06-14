#ifndef AGREGAR_PRESTAMO_FRAME_H
#define AGREGAR_PRESTAMO_FRAME_H

#include <wx/wx.h>
#include <wx/datectrl.h>
#include <wx/dateevt.h>
#include "Modelo.h"
#include "Prestamo.h"
#include "fonts.h"
#include "colors.h"
#include "PrestamosFrame.h"

class AgregarPrestamoFrame : public wxFrame
{
public:
    AgregarPrestamoFrame(wxWindow* parent, const wxString& title);
    ~AgregarPrestamoFrame();

private:
    wxPanel* panel;
    wxComboBox* clienteCtrl;
    wxDatePickerCtrl* fechaCtrl;
    wxTextCtrl* montoCtrl;
    wxButton* guardarButton;
    wxButton* cancelarButton;

    void OnGuardar(wxCommandEvent& event);
    void OnCancelar(wxCommandEvent& event);

    wxDECLARE_EVENT_TABLE();
};

#endif // AGREGAR_PRESTAMO_FRAME_H

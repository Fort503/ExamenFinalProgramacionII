#ifndef AGREGARCLIENTEFRAME_H
#define AGREGARCLIENTEFRAME_H

#include <wx/wx.h>
#include "Modelo.h"
#include "Cliente.h"

class AgregarClienteFrame : public wxFrame
{
public:
    AgregarClienteFrame(wxWindow* parent, const wxString& title);

private:
    void OnGuardar(wxCommandEvent& event);
    void OnCancelar(wxCommandEvent& event);

    wxPanel* panel;
    wxBoxSizer* mainSizer;
    wxBoxSizer* inputSizer;
    wxBoxSizer* buttonSizer;
    wxButton* guardarButton;
    wxButton* cancelarButton;
    wxTextCtrl* nombreCtrl;
    wxTextCtrl* apellidoCtrl;
    wxTextCtrl* idCtrl;

    wxDECLARE_EVENT_TABLE();
};

#endif // AGREGARCLIENTEFRAME_H

#ifndef CLIENTESFRAME_H
#define CLIENTESFRAME_H

#include <wx/wx.h>
#include <wx/listctrl.h>
#include <Cliente.h>

class ClientesFrame : public wxFrame
{
public:
    ClientesFrame(wxWindow* parent, const wxString& title);
    Cliente** getClientes();
    void actualizarListaClientes();

private:
    void OnSalir(wxCommandEvent& event);
    void OnAgregarCliente(wxCommandEvent& event);

    wxPanel* panel;
    wxBoxSizer* mainSizer;
    wxBoxSizer* buttonSizer;
    wxListCtrl* listCtrl;
    wxButton* agregarClienteButton;
    wxButton* salirButton;

    wxDECLARE_EVENT_TABLE();
};

enum
{
    idAgregarCliente = 1,
    idSalirClientes
};

#endif // CLIENTESFRAME_H

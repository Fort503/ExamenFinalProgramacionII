#ifdef WX_PRECOMP
#include "wx_pch.h"
#endif

#ifdef __BORLANDC__
#pragma hdrstop
#endif //__BORLANDC__

#include "ClientesFrame.h"
#include "AgregarClienteFrame.h"
#include "fonts.h"
#include "colors.h"
#include "Modelo.h"
#include "wx/msgdlg.h"

wxBEGIN_EVENT_TABLE(ClientesFrame, wxFrame)
    EVT_BUTTON(idAgregarCliente, ClientesFrame::OnAgregarCliente)
    EVT_BUTTON(idSalirClientes, ClientesFrame::OnSalir)
wxEND_EVENT_TABLE()

ClientesFrame::ClientesFrame(wxWindow* parent, const wxString& title) : wxFrame(parent, wxID_ANY, title, wxDefaultPosition, wxSize(500, 500)) {
    panel = new wxPanel(this, wxID_ANY);

    mainSizer = new wxBoxSizer(wxVERTICAL);
    buttonSizer = new wxBoxSizer(wxHORIZONTAL);

    wxStaticText* titulo = new wxStaticText(panel, wxID_ANY, "Gestion de Clientes");
    titulo->SetFont(TITLE_FONT);

    listCtrl = new wxListCtrl(panel, wxID_ANY, wxDefaultPosition, wxSize(480, 300), wxLC_REPORT | wxBORDER_SUNKEN);
    listCtrl->InsertColumn(0, "ID", wxLIST_FORMAT_LEFT, 100);
    listCtrl->InsertColumn(1, "Nombre", wxLIST_FORMAT_LEFT, 200);
    listCtrl->InsertColumn(2, "Apellido", wxLIST_FORMAT_LEFT, 180);
    listCtrl->SetFont(NORMAL_FONT);

    agregarClienteButton = new wxButton(panel, idAgregarCliente, "Agregar Cliente");
    salirButton = new wxButton(panel, idSalirClientes, "Salir");

    salirButton->SetBackgroundColour(BACKGROUND_COLOR_SALIR);
    salirButton->SetFont(NORMAL_FONT);
    salirButton->SetForegroundColour(FONT_COLOR_BLANCO);

    agregarClienteButton->SetBackgroundColour(BACKGROUND_COLOR_CONFIRMAR);
    agregarClienteButton->SetFont(NORMAL_FONT);
    agregarClienteButton->SetForegroundColour(FONT_COLOR_BLANCO);

    buttonSizer->Add(agregarClienteButton, 1, wxALL | wxEXPAND, 5);
    buttonSizer->Add(salirButton, 1, wxALL | wxEXPAND, 5);

    mainSizer->Add(titulo, 0, wxALL | wxALIGN_CENTER, 20);
    mainSizer->Add(listCtrl, 1, wxALL | wxEXPAND, 10);
    mainSizer->Add(buttonSizer, 0, wxALIGN_CENTER | wxALL | wxEXPAND, 10);

    panel->SetSizer(mainSizer);
    panel->Layout();
    this->SetMinSize(wxSize(500, 500));
    this->SetSize(wxSize(500, 500));

    listCtrl->DeleteAllItems();

    Cliente** clientes = Modelo::getClientes();
    int contadorClientes = Modelo::getContadorClientes();

    for (int i = 0; i < contadorClientes; ++i) {
        wxListItem item;
        item.SetId(i);
        item.SetText(wxString::Format("%d", clientes[i]->getIdCliente()));
        listCtrl->InsertItem(item);

        listCtrl->SetItem(i, 1, clientes[i]->getNombre());
        listCtrl->SetItem(i, 2, clientes[i]->getApellido());
    }

}

void ClientesFrame::OnAgregarCliente(wxCommandEvent& event) {
    AgregarClienteFrame* agregarClienteFrame = new AgregarClienteFrame(this, "Agregrar cliente");
    agregarClienteFrame->Show();
}

void ClientesFrame::OnSalir(wxCommandEvent& event) {
    Close();
}

void ClientesFrame::actualizarListaClientes() {
    listCtrl->DeleteAllItems();

    Cliente** clientes = Modelo::getClientes();
    int contadorClientes = Modelo::getContadorClientes();

    for (int i = 0; i < contadorClientes; ++i) {
        wxListItem item;
        item.SetId(i);
        item.SetText(wxString::Format("%d", clientes[i]->getIdCliente()));
        listCtrl->InsertItem(item);

        listCtrl->SetItem(i, 1, clientes[i]->getNombre());
        listCtrl->SetItem(i, 2, clientes[i]->getApellido());
    }
}



#include "AgregarClienteFrame.h"
#include "ClientesFrame.h"
#include "fonts.h"
#include "colors.h"

wxBEGIN_EVENT_TABLE(AgregarClienteFrame, wxFrame)
    EVT_BUTTON(wxID_SAVE, AgregarClienteFrame::OnGuardar)
    EVT_BUTTON(wxID_CANCEL, AgregarClienteFrame::OnCancelar)
wxEND_EVENT_TABLE()

AgregarClienteFrame::AgregarClienteFrame(wxWindow* parent, const wxString& title)
    : wxFrame(parent, wxID_ANY, title, wxDefaultPosition, wxSize(500, 500))
{
    panel = new wxPanel(this, wxID_ANY);

    wxBoxSizer* mainSizer = new wxBoxSizer(wxVERTICAL);
    wxBoxSizer* inputSizer = new wxBoxSizer(wxVERTICAL);
    wxBoxSizer* buttonSizer = new wxBoxSizer(wxHORIZONTAL);

    wxStaticText* tituloLabel = new wxStaticText(panel, wxID_ANY, "Agregar Cliente");
    tituloLabel->SetFont(TITLE_FONT);

    wxStaticText* nombreLabel = new wxStaticText(panel, wxID_ANY, "Nombre:");
    nombreCtrl = new wxTextCtrl(panel, wxID_ANY, "", wxDefaultPosition, wxSize(200, 40), 0);

    wxStaticText* apellidoLabel = new wxStaticText(panel, wxID_ANY, "Apellido:");
    apellidoCtrl = new wxTextCtrl(panel, wxID_ANY, "", wxDefaultPosition, wxSize(200, 40), 0);

    guardarButton = new wxButton(panel, wxID_SAVE, "Guardar");
    cancelarButton = new wxButton(panel, wxID_CANCEL, "Cancelar");

    guardarButton->SetBackgroundColour(BACKGROUND_COLOR_CONFIRMAR);
    guardarButton->SetForegroundColour(FONT_COLOR_BLANCO);
    cancelarButton->SetBackgroundColour(BACKGROUND_COLOR_SALIR);
    cancelarButton->SetForegroundColour(FONT_COLOR_BLANCO);

    nombreLabel->SetFont(NORMAL_FONT);
    apellidoLabel->SetFont(NORMAL_FONT);
    nombreCtrl->SetFont(NORMAL_FONT);
    apellidoCtrl->SetFont(NORMAL_FONT);
    guardarButton->SetFont(NORMAL_FONT);
    cancelarButton->SetFont(NORMAL_FONT);

    inputSizer->Add(nombreLabel, 0, wxALIGN_LEFT | wxALL, 5);
    inputSizer->Add(nombreCtrl, 0, wxEXPAND | wxALL, 5);
    inputSizer->Add(apellidoLabel, 0, wxALIGN_LEFT | wxALL, 5);
    inputSizer->Add(apellidoCtrl, 0, wxEXPAND | wxALL, 5);

    buttonSizer->Add(guardarButton, 1, wxEXPAND | wxALL, 5);
    buttonSizer->Add(cancelarButton, 1, wxEXPAND | wxALL, 5);

    mainSizer->Add(tituloLabel, 0, wxALIGN_CENTER | wxALL, 10);
    mainSizer->Add(inputSizer, 1, wxEXPAND | wxLEFT | wxRIGHT | wxTOP, 10);
    mainSizer->Add(buttonSizer, 0, wxEXPAND | wxALL, 10);

    panel->SetSizer(mainSizer);
    panel->Layout();

    this->SetMinSize(wxSize(500, 300));
    this->SetSize(wxSize(500, 300));
}


void AgregarClienteFrame::OnGuardar(wxCommandEvent& event) {
    wxString nombre = nombreCtrl->GetValue();
    wxString apellido = apellidoCtrl->GetValue();

    if (nombre.IsEmpty() || apellido.IsEmpty()) {
        wxMessageBox("Por favor, ingrese un nombre y un apellido.", "Error", wxOK | wxICON_ERROR);
        return;
    }

    Cliente* cliente = new Cliente(Modelo::generarIdCliente(), nombre.ToStdString(), apellido.ToStdString());
    Modelo::agregarCliente(cliente);
    wxMessageBox("Cliente agregado correctamente.", "Éxito", wxOK | wxICON_INFORMATION);

    Close();

    ClientesFrame* parentFrame = dynamic_cast<ClientesFrame*>(GetParent());
    if (parentFrame) {
        parentFrame->actualizarListaClientes();
    }
}


void AgregarClienteFrame::OnCancelar(wxCommandEvent& event) {
    Close();
}

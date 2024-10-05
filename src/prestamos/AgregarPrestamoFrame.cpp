#include "AgregarPrestamoFrame.h"

wxBEGIN_EVENT_TABLE(AgregarPrestamoFrame, wxFrame)
    EVT_BUTTON(wxID_SAVE, AgregarPrestamoFrame::OnGuardar)
    EVT_BUTTON(wxID_CANCEL, AgregarPrestamoFrame::OnCancelar)
wxEND_EVENT_TABLE()

AgregarPrestamoFrame::AgregarPrestamoFrame(wxWindow* parent, const wxString& title) : wxFrame(parent, wxID_ANY, title, wxDefaultPosition, wxSize(500, 500)) {
    panel = new wxPanel(this, wxID_ANY);

    wxBoxSizer* mainSizer = new wxBoxSizer(wxVERTICAL);
    wxBoxSizer* inputSizer = new wxBoxSizer(wxVERTICAL);
    wxBoxSizer* buttonSizer = new wxBoxSizer(wxHORIZONTAL);

    wxStaticText* tituloLabel = new wxStaticText(panel, wxID_ANY, "Agregar Prestamo");
    tituloLabel->SetFont(TITLE_FONT);

    wxStaticText* clienteLabel = new wxStaticText(panel, wxID_ANY, "Cliente:");
    clienteCtrl = new wxComboBox(panel, wxID_ANY, "", wxDefaultPosition, wxSize(200, -1), 0, nullptr, wxCB_DROPDOWN | wxCB_READONLY);

    Cliente** clientes = Modelo::getClientes();
    int contadorClientes = Modelo::getContadorClientes();
    for (int i = 0; i < contadorClientes; ++i) {
        clienteCtrl->Append(clientes[i]->getNombre());
    }

    wxStaticText* montoLabel = new wxStaticText(panel, wxID_ANY, "Monto Aprobado:");
    montoCtrl = new wxTextCtrl(panel, wxID_ANY, "", wxDefaultPosition, wxSize(200, -1), 0);

    guardarButton = new wxButton(panel, wxID_SAVE, "Guardar");
    cancelarButton = new wxButton(panel, wxID_CANCEL, "Cancelar");

    guardarButton->SetBackgroundColour(BACKGROUND_COLOR_CONFIRMAR);
    guardarButton->SetForegroundColour(FONT_COLOR_BLANCO);
    cancelarButton->SetBackgroundColour(BACKGROUND_COLOR_SALIR);
    cancelarButton->SetForegroundColour(FONT_COLOR_BLANCO);

    clienteLabel->SetFont(NORMAL_FONT);
    montoLabel->SetFont(NORMAL_FONT);
    clienteCtrl->SetFont(NORMAL_FONT);
    montoCtrl->SetFont(NORMAL_FONT);
    guardarButton->SetFont(NORMAL_FONT);
    cancelarButton->SetFont(NORMAL_FONT);

    inputSizer->Add(clienteLabel, 0, wxALIGN_LEFT | wxALL, 5);
    inputSizer->Add(clienteCtrl, 0, wxEXPAND | wxALL, 5);
    inputSizer->Add(montoLabel, 0, wxALIGN_LEFT | wxALL, 5);
    inputSizer->Add(montoCtrl, 0, wxEXPAND | wxALL, 5);

    buttonSizer->Add(guardarButton, 1, wxEXPAND | wxALL, 5);
    buttonSizer->Add(cancelarButton, 1, wxEXPAND | wxALL, 5);

    mainSizer->Add(tituloLabel, 0, wxALIGN_CENTER | wxALL, 10);
    mainSizer->Add(inputSizer, 1, wxEXPAND | wxLEFT | wxRIGHT | wxTOP, 10);
    mainSizer->Add(buttonSizer, 0, wxEXPAND | wxALL, 10);

    panel->SetSizer(mainSizer);
    panel->Layout();

    this->SetMinSize(wxSize(500, 350));
    this->SetSize(wxSize(500, 350));
}

AgregarPrestamoFrame::~AgregarPrestamoFrame()
{
}

void AgregarPrestamoFrame::OnGuardar(wxCommandEvent& event) {
    wxString clienteSeleccionado = clienteCtrl->GetValue();
    wxString monto = montoCtrl->GetValue();

    if (clienteSeleccionado.IsEmpty() || monto.IsEmpty()) {
        wxMessageBox("Por favor, complete todos los campos.", "Error", wxOK | wxICON_ERROR);
        return;
    }

    int clienteIndex = clienteCtrl->GetSelection();
    Cliente** clientes = Modelo::getClientes();
    Cliente* cliente = clientes[clienteIndex];

    // Eliminamos la lógica de fecha ya que no se necesita
    // wxDateTime fecha = fechaCtrl->GetValue();
    // Fecha* fechaAprobacion = new Fecha(fecha.GetDay(), fecha.GetMonth(), fecha.GetYear());

    Prestamo* prestamo = new Prestamo(Modelo::generarIdPrestamo(), cliente, nullptr, wxAtof(monto)); // Aquí se ajusta para no usar fecha
    Modelo::agregarPrestamo(prestamo);

    wxMessageBox("Prestamo agregado correctamente.", "Éxito", wxOK | wxICON_INFORMATION);

    Close();

    PrestamosFrame* parentFrame = dynamic_cast<PrestamosFrame*>(GetParent());
    if (parentFrame) {
        parentFrame->actualizarListaPrestamos();
    }
}

void AgregarPrestamoFrame::OnCancelar(wxCommandEvent& event) {
    Close();
}

#include "HacerPagoFrame.h"
#include "Modelo.h"

wxBEGIN_EVENT_TABLE(HacerPagoFrame, wxFrame)
    EVT_BUTTON(ID_GuardarPago, HacerPagoFrame::OnGuardar)
    EVT_BUTTON(ID_CancelarPago, HacerPagoFrame::OnCancelar)
wxEND_EVENT_TABLE()

HacerPagoFrame::HacerPagoFrame(wxWindow* parent, Prestamo* prestamo) : wxFrame(parent, wxID_ANY, "Hacer Pago", wxDefaultPosition, wxSize(400, 300)), prestamo(prestamo) {
    panel = new wxPanel(this, wxID_ANY);

    wxBoxSizer* mainSizer = new wxBoxSizer(wxVERTICAL);
    wxBoxSizer* inputSizer = new wxBoxSizer(wxVERTICAL);
    wxBoxSizer* buttonSizer = new wxBoxSizer(wxHORIZONTAL);

    wxStaticText* tituloLabel = new wxStaticText(panel, wxID_ANY, "Hacer Pago");
    tituloLabel->SetFont(TITLE_FONT);

    wxStaticText* montoLabel = new wxStaticText(panel, wxID_ANY, "Monto del Pago:");
    montoCtrl = new wxTextCtrl(panel, wxID_ANY, "", wxDefaultPosition, wxSize(200, -1), 0);

    wxStaticText* fechaLabel = new wxStaticText(panel, wxID_ANY, "Fecha del Pago:");
    fechaCtrl = new wxDatePickerCtrl(panel, wxID_ANY, wxDefaultDateTime, wxDefaultPosition, wxSize(200, -1), wxDP_DROPDOWN);

    guardarButton = new wxButton(panel, ID_GuardarPago, "Guardar");
    cancelarButton = new wxButton(panel, ID_CancelarPago, "Cancelar");

    guardarButton->SetBackgroundColour(BACKGROUND_COLOR_CONFIRMAR);
    guardarButton->SetForegroundColour(FONT_COLOR_BLANCO);
    cancelarButton->SetBackgroundColour(BACKGROUND_COLOR_SALIR);
    cancelarButton->SetForegroundColour(FONT_COLOR_BLANCO);

    montoLabel->SetFont(NORMAL_FONT);
    fechaLabel->SetFont(NORMAL_FONT);
    montoCtrl->SetFont(NORMAL_FONT);
    fechaCtrl->SetFont(NORMAL_FONT);
    guardarButton->SetFont(NORMAL_FONT);
    cancelarButton->SetFont(NORMAL_FONT);

    inputSizer->Add(montoLabel, 0, wxALIGN_LEFT | wxALL, 5);
    inputSizer->Add(montoCtrl, 0, wxEXPAND | wxALL, 5);
    inputSizer->Add(fechaLabel, 0, wxALIGN_LEFT | wxALL, 5);
    inputSizer->Add(fechaCtrl, 0, wxEXPAND | wxALL, 5);

    buttonSizer->Add(guardarButton, 1, wxEXPAND | wxALL, 5);
    buttonSizer->Add(cancelarButton, 1, wxEXPAND | wxALL, 5);

    mainSizer->Add(tituloLabel, 0, wxALIGN_CENTER | wxALL, 10);
    mainSizer->Add(inputSizer, 1, wxEXPAND | wxLEFT | wxRIGHT | wxTOP, 10);
    mainSizer->Add(buttonSizer, 0, wxEXPAND | wxALL, 10);

    panel->SetSizer(mainSizer);
    panel->Layout();

    this->SetMinSize(wxSize(400, 300));
    this->SetSize(wxSize(400, 300));
}

void HacerPagoFrame::OnGuardar(wxCommandEvent& event)
{
    wxString montoStr = montoCtrl->GetValue();
    wxDateTime fecha = fechaCtrl->GetValue();

    if (montoStr.IsEmpty() || !fecha.IsValid()) {
        wxMessageBox("Por favor, ingrese el monto y la fecha del pago.", "Error", wxOK | wxICON_ERROR);
        return;
    }

    float monto = wxAtof(montoStr);
    Fecha* fechaPago = new Fecha(fecha.GetDay(), fecha.GetMonth() + 1, fecha.GetYear());

    Pago* pago = new Pago(fechaPago, monto);
    if (prestamo->hacerPago(pago)) {
        wxMessageBox("Pago realizado correctamente.", "Éxito", wxOK | wxICON_INFORMATION);
    } else {
        wxMessageBox("El monto del pago excede el saldo pendiente.", "Error", wxOK | wxICON_ERROR);
        delete pago;
    }

    Close();

    DetallesPrestamoFrame* parentFrame = dynamic_cast<DetallesPrestamoFrame*>(GetParent());
    if (parentFrame) {
        parentFrame->actualizarListaPagos();
    }
}

void HacerPagoFrame::OnCancelar(wxCommandEvent& event)
{
    Close();
}

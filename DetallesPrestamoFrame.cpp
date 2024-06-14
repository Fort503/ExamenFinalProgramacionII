#include "DetallesPrestamoFrame.h"
#include "Pago.h"
#include "HacerPagoFrame.h"
#include "fonts.h"
#include "colors.h"
#include "Modelo.h"
#include "PrestamosFrame.h"

wxBEGIN_EVENT_TABLE(DetallesPrestamoFrame, wxFrame)
    EVT_BUTTON(ID_HacerPago, DetallesPrestamoFrame::OnHacerPago)
    EVT_BUTTON(ID_Salir, DetallesPrestamoFrame::OnSalir)
wxEND_EVENT_TABLE()

DetallesPrestamoFrame::DetallesPrestamoFrame(wxWindow* parent, Prestamo* prestamo) : wxFrame(parent, wxID_ANY, "Detalles del Prestamo", wxDefaultPosition, wxSize(400, 600)), prestamo(prestamo) {
    panel = new wxPanel(this, wxID_ANY);

    mainSizer = new wxBoxSizer(wxVERTICAL);
    buttonSizer = new wxBoxSizer(wxHORIZONTAL);

    wxStaticText* titulo = new wxStaticText(panel, wxID_ANY, "Ver Detalles");
    titulo->SetFont(TITLE_FONT);

    wxStaticText* numeroPrestamoLabel = new wxStaticText(panel, wxID_ANY, "Numero de Prestamo:");
    numeroPrestamoLabel->SetFont(NORMAL_FONT);
    numeroPrestamoCtrl = new wxTextCtrl(panel, wxID_ANY, wxString::Format("%d", prestamo->getNumeroPrestamo()), wxDefaultPosition, wxDefaultSize, wxTE_READONLY);

    wxStaticText* clienteLabel = new wxStaticText(panel, wxID_ANY, "Cliente:");
    clienteLabel->SetFont(NORMAL_FONT);
    clienteCtrl = new wxTextCtrl(panel, wxID_ANY, wxString(prestamo->getCliente()->getNombre()), wxDefaultPosition, wxDefaultSize, wxTE_READONLY);

    wxStaticText* fechaAprobacionLabel = new wxStaticText(panel, wxID_ANY, "Fecha de Aprobacion:");
    fechaAprobacionLabel->SetFont(NORMAL_FONT);
    fechaAprobacionCtrl = new wxTextCtrl(panel, wxID_ANY, wxString(prestamo->getFechaAprobacion()->mostrarFecha()), wxDefaultPosition, wxDefaultSize, wxTE_READONLY);

    wxStaticText* montoAprobadoLabel = new wxStaticText(panel, wxID_ANY, "Monto Aprobado:");
    montoAprobadoLabel->SetFont(NORMAL_FONT);
    montoAprobadoCtrl = new wxTextCtrl(panel, wxID_ANY, wxString::Format("$%.2f", prestamo->getMontoAprobado()), wxDefaultPosition, wxDefaultSize, wxTE_READONLY);

    wxStaticText* saldoPendienteLabel = new wxStaticText(panel, wxID_ANY, "Saldo Pendiente:");
    saldoPendienteLabel->SetFont(NORMAL_FONT);
    saldoPendienteCtrl = new wxTextCtrl(panel, wxID_ANY, wxString::Format("$%.2f", prestamo->getSaldoPendiente()), wxDefaultPosition, wxDefaultSize, wxTE_READONLY);

    wxStaticText* pagosLabel = new wxStaticText(panel, wxID_ANY, "Pagos:");
    pagosLabel->SetFont(NORMAL_FONT);
    pagosListBox = new wxListBox(panel, wxID_ANY, wxDefaultPosition, wxDefaultSize);

    for (int i = 0; i < prestamo->getContadorPagos(); ++i) {
        Pago* pago = prestamo->getLstPagos()[i];
        wxString item = wxString::Format("%s - $%.2f", pago->getFechaPago()->mostrarFecha(), pago->getMontoPago());
        pagosListBox->Append(item);
    }

    hacerPagoButton = new wxButton(panel, ID_HacerPago, "Hacer Pago");
    hacerPagoButton->SetBackgroundColour(BACKGROUND_COLOR_CONFIRMAR);
    hacerPagoButton->SetFont(NORMAL_FONT);
    hacerPagoButton->SetForegroundColour(FONT_COLOR_BLANCO);

    salirButton = new wxButton(panel, ID_Salir, "Salir");
    salirButton->SetBackgroundColour(BACKGROUND_COLOR_SALIR);
    salirButton->SetFont(NORMAL_FONT);
    salirButton->SetForegroundColour(FONT_COLOR_BLANCO);

    buttonSizer->Add(hacerPagoButton, 1, wxALL | wxEXPAND, 5);
    buttonSizer->Add(salirButton, 1, wxALL | wxEXPAND, 5);

    mainSizer->Add(titulo, 0, wxALL | wxALIGN_CENTER, 20);
    mainSizer->Add(numeroPrestamoLabel, 0, wxALL, 5);
    mainSizer->Add(numeroPrestamoCtrl, 0, wxALL | wxEXPAND, 5);
    mainSizer->Add(clienteLabel, 0, wxALL, 5);
    mainSizer->Add(clienteCtrl, 0, wxALL | wxEXPAND, 5);
    mainSizer->Add(fechaAprobacionLabel, 0, wxALL, 5);
    mainSizer->Add(fechaAprobacionCtrl, 0, wxALL | wxEXPAND, 5);
    mainSizer->Add(montoAprobadoLabel, 0, wxALL, 5);
    mainSizer->Add(montoAprobadoCtrl, 0, wxALL | wxEXPAND, 5);
    mainSizer->Add(saldoPendienteLabel, 0, wxALL, 5);
    mainSizer->Add(saldoPendienteCtrl, 0, wxALL | wxEXPAND, 5);
    mainSizer->Add(pagosLabel, 0, wxALL, 5);
    mainSizer->Add(pagosListBox, 1, wxALL | wxEXPAND, 5);
    mainSizer->Add(buttonSizer, 0, wxALIGN_CENTER | wxALL | wxEXPAND, 10);

    panel->SetSizer(mainSizer);
    panel->Layout();

    this->SetMinSize(wxSize(300, 650));
    this->SetSize(wxSize(500, 650));
}

void DetallesPrestamoFrame::OnHacerPago(wxCommandEvent& event) {
    HacerPagoFrame* frame = new HacerPagoFrame(this, prestamo);
    frame->Show(true);
}

void DetallesPrestamoFrame::OnSalir(wxCommandEvent& event) {
    this->Close();

    PrestamosFrame* parentFrame = dynamic_cast<PrestamosFrame*>(GetParent());
    if (parentFrame) {
        parentFrame->actualizarListaPrestamos();
    }
}

void DetallesPrestamoFrame::actualizarListaPagos() {
    pagosListBox->Clear();
    int contadorPrestamos = Modelo::getContadorPrestamos();
    saldoPendienteCtrl->SetValue(wxString::Format("$%.2f", prestamo->getSaldoPendiente()));

    for (int i = 0; i < prestamo->getContadorPagos(); ++i) {
        Pago* pago = prestamo->getLstPagos()[i];
        wxString item = wxString::Format("%s - $%.2f", pago->getFechaPago()->mostrarFecha(), pago->getMontoPago());
        pagosListBox->Append(item);
    }
}

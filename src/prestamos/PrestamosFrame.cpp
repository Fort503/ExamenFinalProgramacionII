#ifdef WX_PRECOMP
#include "wx_pch.h"
#endif

#ifdef __BORLANDC__
#pragma hdrstop
#endif //__BORLANDC__

#include "PrestamosFrame.h"
#include "fonts.h"
#include "colors.h"

wxBEGIN_EVENT_TABLE(PrestamosFrame, wxFrame)
    EVT_BUTTON(idAgregarPrestamo, PrestamosFrame::OnAgregarPrestamo)
    EVT_BUTTON(idVerdetalles, PrestamosFrame::OnVerDetalles)
wxEND_EVENT_TABLE()

PrestamosFrame::PrestamosFrame(wxWindow* parent, const wxString& title) : wxFrame(parent, wxID_ANY, title, wxDefaultPosition, wxSize(500, 500)) {
    panel = new wxPanel(this, wxID_ANY);

    mainSizer = new wxBoxSizer(wxVERTICAL);
    buttonSizer = new wxBoxSizer(wxHORIZONTAL);

    wxStaticText* titulo = new wxStaticText(panel, wxID_ANY, "Gestion de Prestamos");
    titulo->SetFont(TITLE_FONT);

    listCtrl = new wxListCtrl(panel, wxID_ANY, wxDefaultPosition, wxSize(480, 300), wxLC_REPORT | wxBORDER_SUNKEN);
    listCtrl->InsertColumn(0, "No.", wxLIST_FORMAT_LEFT, 50);
    listCtrl->InsertColumn(1, "Fecha de Aprobacion", wxLIST_FORMAT_LEFT, 200);
    listCtrl->InsertColumn(2, "Saldo Pendiente", wxLIST_FORMAT_LEFT, 230);
    listCtrl->SetFont(NORMAL_FONT);

    agregarPrestamoButton = new wxButton(panel, idAgregarPrestamo, "Agregar Prestamo");
    verDetallesButton = new wxButton(panel, idVerdetalles, "Ver Detalles");

    verDetallesButton->SetBackgroundColour(BACKGROUND_COLOR_DETALLES);
    verDetallesButton->SetFont(NORMAL_FONT);
    verDetallesButton->SetForegroundColour(FONT_COLOR_BLANCO);

    agregarPrestamoButton->SetBackgroundColour(BACKGROUND_COLOR_CONFIRMAR);
    agregarPrestamoButton->SetFont(NORMAL_FONT);
    agregarPrestamoButton->SetForegroundColour(FONT_COLOR_BLANCO);

    buttonSizer->Add(agregarPrestamoButton, 1, wxALL | wxEXPAND, 5);
    buttonSizer->Add(verDetallesButton, 1, wxALL | wxEXPAND, 5);

    mainSizer->Add(titulo, 0, wxALL | wxALIGN_CENTER, 20);
    mainSizer->Add(listCtrl, 1, wxALL | wxEXPAND, 10);
    mainSizer->Add(buttonSizer, 0, wxALIGN_CENTER | wxALL | wxEXPAND, 10);

    panel->SetSizer(mainSizer);
    panel->Layout();
    this->SetMinSize(wxSize(500, 500));
    this->SetSize(wxSize(500, 500));

    actualizarListaPrestamos();
}

PrestamosFrame::~PrestamosFrame() {
    // Implementación del destructor (si es necesario)
}


void PrestamosFrame::OnAgregarPrestamo(wxCommandEvent& event) {
    AgregarPrestamoFrame* Frame = new AgregarPrestamoFrame(this, "Agregar Prestamo");
    Frame->Show(true);
}

void PrestamosFrame::OnVerDetalles(wxCommandEvent& event) {
    int itemIndex = listCtrl->GetNextItem(-1, wxLIST_NEXT_ALL, wxLIST_STATE_SELECTED);
    if (itemIndex != wxNOT_FOUND) {
        Prestamo** prestamos = Modelo::getPrestamos();
        Prestamo* prestamoSeleccionado = prestamos[itemIndex];
        DetallesPrestamoFrame* frame = new DetallesPrestamoFrame(this, prestamoSeleccionado);
        frame->Show(true);
    }
}

void PrestamosFrame::actualizarListaPrestamos() {
    listCtrl->DeleteAllItems();

    Prestamo** prestamos = Modelo::getPrestamos();
    int contadorPrestamos = Modelo::getContadorPrestamos();

    for (int i = 0; i < contadorPrestamos; ++i) {
        wxListItem item;
        item.SetId(i);
        item.SetText(wxString::Format("%d", prestamos[i]->getNumeroPrestamo()));
        listCtrl->InsertItem(item);

        listCtrl->SetItem(i, 0, wxString::Format("%d", prestamos[i]->getNumeroPrestamo()));

        wxString fecha = prestamos[i]->getFechaAprobacion()->mostrarFecha();
        listCtrl->SetItem(i, 1, fecha);

        listCtrl->SetItem(i, 2, wxString::Format("$%.2f", prestamos[i]->getSaldoPendiente()));
    }
}

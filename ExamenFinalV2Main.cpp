#ifdef WX_PRECOMP
#include "wx_pch.h"
#endif

#ifdef __BORLANDC__
#pragma hdrstop
#endif //__BORLANDC__

#include "ExamenFinalV2Main.h"

// helper functions
enum wxbuildinfoformat {
    short_f, long_f
};

wxString wxbuildinfo(wxbuildinfoformat format)
{
    wxString wxbuild(wxVERSION_STRING);

    if (format == long_f)
    {
#if defined(__WXMSW__)
        wxbuild << _T("-Windows");
#elif defined(__WXMAC__)
        wxbuild << _T("-Mac");
#elif defined(__UNIX__)
        wxbuild << _T("-Linux");
#endif

#if wxUSE_UNICODE
        wxbuild << _T("-Unicode build");
#else
        wxbuild << _T("-ANSI build");
#endif // wxUSE_UNICODE
    }

    return wxbuild;
}

wxBEGIN_EVENT_TABLE(ExamenFinalV2Frame, wxFrame)
    EVT_BUTTON(idGestionarCliente, ExamenFinalV2Frame::gestionarClientes)
    EVT_BUTTON(idGestionarPrestamos, ExamenFinalV2Frame::gestionarPrestamos)
    EVT_BUTTON(idGestionarSalir, ExamenFinalV2Frame::Salir)
wxEND_EVENT_TABLE()

ExamenFinalV2Frame::ExamenFinalV2Frame(wxWindow* parent, const wxString& title) : wxFrame(parent, wxID_ANY, title, wxDefaultPosition, wxSize(500, 500)) {
    panel = new wxPanel(this, wxID_ANY);

    wxBoxSizer* mainSizer = new wxBoxSizer(wxVERTICAL);
    wxBoxSizer* buttonSizer = new wxBoxSizer(wxVERTICAL);

    wxStaticText* titulo = new wxStaticText(panel, wxID_ANY, "Gestion de prestamos");
    titulo->SetFont(TITLE_FONT);

    int buttonHeight = 40;

    wxButton* gestionarClienteButton = new wxButton(panel, idGestionarCliente, "Gestionar Clientes", wxDefaultPosition, wxSize(-1, buttonHeight));
    wxButton* gestionarPrestamosButton = new wxButton(panel, idGestionarPrestamos, "Gestionar Prestamos", wxDefaultPosition, wxSize(-1, buttonHeight));
    wxButton* salirButton = new wxButton(panel, idGestionarSalir, "Salir", wxDefaultPosition, wxSize(-1, buttonHeight));

    salirButton->SetBackgroundColour(BACKGROUND_COLOR_SALIR);
    salirButton->SetForegroundColour(FONT_COLOR_BLANCO);
    gestionarClienteButton->SetFont(NORMAL_FONT);
    gestionarPrestamosButton->SetFont(NORMAL_FONT);
    salirButton->SetFont(NORMAL_FONT);

    buttonSizer->AddStretchSpacer();
    buttonSizer->Add(titulo, 0, wxALL | wxALIGN_CENTER, 20);
    buttonSizer->Add(gestionarClienteButton, 0, wxALL | wxEXPAND, 10);
    buttonSizer->Add(gestionarPrestamosButton, 0, wxALL | wxEXPAND, 10);
    buttonSizer->Add(salirButton, 0, wxALL | wxEXPAND, 10);
    buttonSizer->AddStretchSpacer();
    buttonSizer->AddStretchSpacer();

    mainSizer->Add(buttonSizer, 1, wxALIGN_CENTER | wxALL | wxEXPAND, 40);

    panel->SetSizer(mainSizer);
    panel->Layout();
    this->SetMinSize(wxSize(500, 500));
    this->SetSize(wxSize(500, 500));
}

ExamenFinalV2Frame::~ExamenFinalV2Frame()
{
}

void ExamenFinalV2Frame::gestionarClientes(wxCommandEvent& event) {
    ClientesFrame* clientesFrame = new ClientesFrame(this, "Gestion de Clientes");
    clientesFrame->Show();
}

void ExamenFinalV2Frame::gestionarPrestamos(wxCommandEvent& event) {
    PrestamosFrame* prestamosFrame = new PrestamosFrame(this, "Gestion de Prestamos");
    prestamosFrame->Show();
}

void ExamenFinalV2Frame::Salir(wxCommandEvent& event) {
    Close(true);
}

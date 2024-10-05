#ifndef EXAMENFINALV2MAIN_H
#define EXAMENFINALV2MAIN_H

#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif

#include "ExamenFinalV2App.h"
#include <wx/vector.h>
#include "Cliente.h"
#include "ClientesFrame.h"
#include "PrestamosFrame.h"
#include "Cliente.h"
#include "colors.h"
#include "fonts.h"
#include "Modelo.h"

class ExamenFinalV2Frame: public wxFrame
{
    public:
        ExamenFinalV2Frame(wxWindow* parent, const wxString& title);
        ~ExamenFinalV2Frame();
        void agregarCliente(Cliente* cliente);

    private:
        void OnClose(wxCommandEvent& event);
        void gestionarClientes(wxCommandEvent& event);
        void gestionarPrestamos(wxCommandEvent& event);
        void Salir(wxCommandEvent& event);

        wxPanel* panel;
        wxBoxSizer* sizer;

        wxDECLARE_EVENT_TABLE();

        enum {
            idGestionarCliente = 1,
            idGestionarPrestamos = 2,
            idGestionarSalir = 3,
        };
};

#endif // EXAMENFINALV2MAIN_H

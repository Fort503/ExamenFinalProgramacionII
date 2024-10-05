#ifndef PRESTAMOS_FRAME_H
#define PRESTAMOS_FRAME_H

#include <wx/wx.h>
#include <wx/listctrl.h>
#include "AgregarPrestamoFrame.h"
#include "Modelo.h"
#include "DetallesPrestamoFrame.h"

class PrestamosFrame : public wxFrame
{
public:
    PrestamosFrame(wxWindow* parent, const wxString& title);
     ~PrestamosFrame();
    void actualizarListaPrestamos();

private:
    wxPanel* panel;
    wxBoxSizer* mainSizer;
    wxBoxSizer* buttonSizer;
    wxListCtrl* listCtrl;
    wxButton* agregarPrestamoButton;
    wxButton* verDetallesButton;

    void OnAgregarPrestamo(wxCommandEvent& event);
    void OnVerDetalles(wxCommandEvent& event);

    enum
    {
        idAgregarPrestamo = 1,
        idVerdetalles
    };

    wxDECLARE_EVENT_TABLE();
};

#endif // PRESTAMOS_FRAME_H

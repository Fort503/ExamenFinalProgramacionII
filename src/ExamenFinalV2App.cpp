/***************************************************************
 * Name:      ExamenFinalV2App.cpp
 * Purpose:   Code for Application Class
 * Author:    Christopher Alvarez ()
 * Created:   2024-06-06
 * Copyright: Christopher Alvarez ()
 * License:
 **************************************************************/

#ifdef WX_PRECOMP
#include "wx_pch.h"
#endif

#ifdef __BORLANDC__
#pragma hdrstop
#endif //__BORLANDC__

#include "ExamenFinalV2App.h"
#include "ExamenFinalV2Main.h"

IMPLEMENT_APP(ExamenFinalV2App);

bool ExamenFinalV2App::OnInit()
{
    ExamenFinalV2Frame* frame = new ExamenFinalV2Frame(0L, _("wxWidgets Application Template"));
    frame->Show();
    return true;
}

//
// Created by sebastian on 9/20/19.
//

#include <wx/wx.h>

#include "EditorTab.h"

wxBEGIN_EVENT_TABLE(views::EditorTab, wxControl)
//    wxEVT_PAINT(views::EditorTab::OnPaint)
wxEND_EVENT_TABLE()

views::EditorTab::EditorTab() : m_editor(new wxTextCtrl()),
                                m_activeTab(true) {

}

views::EditorTab::EditorTab(wxWindow *parent, wxWindowID winid, const wxPoint &point, const wxSize &size, long style,
                            unsigned int base, unsigned int mindigits, int min, int max, int initial,
                            const wxString &name) :
                            wxControl(parent, winid, point, size, style),
                            m_editor(new wxTextCtrl(parent, wxID_ANY, "", wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE)),
                            m_activeTab(true) {


    wxSize sizez = GetSize();

    m_editor->SetSize(sizez.x, sizez.y, this->m_width, this->m_height);

    Bind(wxEVT_PAINT, &EditorTab::OnPaint, this, wxID_ANY);
}

bool views::EditorTab::Create(wxWindow *parent, wxWindowID winid, const wxPoint &point, const wxSize &size, long style,
                              unsigned int base, unsigned int mindigits, int min, int max, int initial,
                              const wxString &name) {

    return wxControl::Create(parent, winid, point, size, style, wxDefaultValidator, name);

    //this->SetSizeHints(wxDefaultSize, wxDefaultSize);

}

void views::EditorTab::OnPaint(wxPaintEvent &event) {
    wxPaintDC dc(this);

    dc.DrawText(wxT("Hello There"), 40, 60);
}

bool views::EditorTab::IsActiveTab() const {
    return m_activeTab;
}

void views::EditorTab::SetActiveTab(bool isActive) {
    m_activeTab = isActive;
}

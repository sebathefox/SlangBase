//
// Created by sebastian on 9/20/19.
//

#include <wx/wx.h>
#include "EditorTab.h"

wxBEGIN_EVENT_TABLE(views::EditorTab, wxControl)
//    wxEVT_PAINT(views::EditorTab::OnPaint)
wxEND_EVENT_TABLE()

views::EditorTab::EditorTab() : m_editor(new wxTextCtrl()),
                                m_activeTab(true),
                                m_boxSizer() {

}

views::EditorTab::EditorTab(wxWindow *parent, wxWindowID winid, const wxPoint &point, const wxSize &size, long style,
                            unsigned int base, unsigned int mindigits, int min, int max, int initial,
                            const wxString &name) :
                            wxControl(parent, winid, point, size, style),
                            m_editor(new wxTextCtrl(parent, wxID_ANY, "", wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE | wxTE_AUTO_URL)),
                            m_activeTab(true),
                            m_boxSizer() {


    //wxSize sizez = GetSize();

    //m_editor->SetSize(sizez.x, sizez.y, this->m_parent->m_width - sizez.x, this->m_parent->m_width - sizez.y);

    m_editor->SetScrollbar(wxSB_VERTICAL, 16, 50, 15);

    m_editor->SetBackgroundColour(wxColour(0x0082827B));

    Bind(wxEVT_PAINT, &EditorTab::OnPaint, this, wxID_ANY);
    Bind(wxEVT_SIZE, &EditorTab::OnSize, this);
}

bool views::EditorTab::Create(wxWindow *parent, wxWindowID winid, const wxPoint &point, const wxSize &size, long style,
                              unsigned int base, unsigned int mindigits, int min, int max, int initial,
                              const wxString &name) {

    return wxControl::Create(parent, winid, point, size, style, wxDefaultValidator, name);

}

void views::EditorTab::OnPaint(wxPaintEvent &event) {

    //TODO: FIX and make line below work.
    std::cout << "PAINTING" << std::endl;

    wxPaintDC dc(this);

    dc.DrawText(wxT("Hello There"), 40, 60);
}

bool views::EditorTab::IsActiveTab() const {
    return m_activeTab;
}

void views::EditorTab::SetActiveTab(bool isActive) {
    m_activeTab = isActive;
}

void views::EditorTab::OpenFile(const std::string& filename) {
    //TODO: Implement the logic to open a file.
    //m_file = std::make_unique<FILE>(fopen(filename.c_str(), "a+"));

    ParseFilePathName(filename);
}

void views::EditorTab::ParseFilePathName(const std::string& filePathName) {
    m_filepath = filePathName.substr(0, filePathName.find_last_of('/'));
    m_filename = filePathName.substr(filePathName.find_last_of('/') + 1, filePathName.size());

}

std::string views::EditorTab::GetText() {
    return m_editor->GetValue().ToStdString();
}

void views::EditorTab::SetText(const std::string& text) {
    m_editor->SetValue(text);
}

void views::EditorTab::OnSize(wxSizeEvent &event) {
    m_editor->SetSize(200, 200, this->m_width, this->m_height - 15);
}

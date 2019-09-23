//
// Created by sebastian on 9/12/19.
//

#ifndef SLANGBASE_EDITOR_H
#define SLANGBASE_EDITOR_H

#include <wx/wxprec.h>

#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif

#include <wx/treectrl.h>

enum {
    ID_HELLO = 1,
    ID_SAVE = 2
};

namespace views {
    class EditorTab;
}

class App : public wxApp {
public:
virtual bool OnInit();
};

class Editor : public wxFrame {
public:
    Editor();

private:
    wxTextCtrl* textEditor;

//    wxTreeCtrl* m_fileTree;

    views::EditorTab* m_tab;

    std::string m_openFile;

    void OnHello(wxCommandEvent& event);
    void OnExit(wxCommandEvent& event);
    void OnAbout(wxCommandEvent& event);

    void OnSave(wxCommandEvent& event);

};


#endif //SLANGBASE_EDITOR_H

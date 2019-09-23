/**
 * The file containing the main window and the application entry point.
 * @file Editor.cpp
 * @author Sebastian Davaris
 * @date 23-09-2019
 */

#include <fstream>
#include "Editor.h"
#include "FileData.h"
#include "views/EditorTab.h"
#include "controllers/TabController.h"

wxIMPLEMENT_APP(App);

bool App::OnInit() {
    m_frame = std::make_unique<Editor>();
    m_frame->Show(true);
    return true;
}

Editor::Editor() : wxFrame(nullptr, wxID_ANY, "SlangBase Editor"),
                textEditor(new wxTextCtrl(this, ID_SAVE, "", wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE)),
                m_fileTree(new wxTreeCtrl(this)),
                m_tabController(std::make_unique<controllers::TabController>()) {
    wxMenu * menufile = new wxMenu;
    menufile->Append(ID_HELLO, "&Hello...\tCTRL-H",
                     "Help string shown in status bar for this menu item");

    menufile->Append(wxID_OPEN, "&Open\tCTRL-O",
                    "Opens a file for editing.");

    menufile->Append(ID_SAVE, "&Save\tCTRL-S",
                     "Saves the open file to disk.");

    menufile->AppendSeparator();
    menufile->Append(wxID_EXIT);

    wxMenu* menuHelp = new wxMenu;
    menuHelp->Append(wxID_ABOUT);

    wxMenuBar* menuBar = new wxMenuBar;
    menuBar->Append(menufile, "&File");
    menuBar->Append(menuHelp, "&Help");

    SetMenuBar(menuBar);

    CreateStatusBar();
    SetStatusText("Welcome to wxWidgets");

    wxTreeItemId rootId = m_fileTree->AddRoot("Root");

    DIR* dir;
    struct dirent* ent;
    if((dir = opendir("./")) != nullptr) {
        while ((ent = readdir(dir)) != nullptr) {
            m_fileTree->AppendItem(rootId, ent->d_name, -1, -1, new FileData(ent->d_name));
        }
        closedir(dir);
    }

    m_fileTree->SetSize(0, 0, 300, 400, wxSIZE_AUTO_HEIGHT);

    wxColour col(0X0082827B);

    wxColour foreground(0xFF5500);

    textEditor->SetSize(300, 0, 128, 128, wxSIZE_AUTO);

    textEditor->SetBackgroundColour(col);

    textEditor->SetForegroundColour(foreground);

    m_tabController->AddTab(this);

    // Bind events.
    Bind(wxEVT_MENU, &Editor::OnHello, this, ID_HELLO);
    Bind(wxEVT_MENU, &Editor::OnSave, this, ID_SAVE);
    Bind(wxEVT_MENU, &Editor::OnAbout, this, wxID_ABOUT);
    Bind(wxEVT_MENU, &Editor::OnExit, this, wxID_EXIT);
}

void Editor::OnExit(wxCommandEvent &event) {
    Close(true);
}

void Editor::OnAbout(wxCommandEvent &event) {
    wxMessageBox("This is a Simple text editor made by Sebathefox.",
                 "About SlangBase", wxOK | wxICON_INFORMATION);
}

//TODO: Remove because of test only method.
void Editor::OnHello(wxCommandEvent &event) {
    wxLogMessage("Hello There");
}

void Editor::OnSave(wxCommandEvent &event) {
    wxString content = textEditor->GetValue();

    m_openFile = ((FileData*)m_fileTree->GetItemData(m_fileTree->GetFocusedItem()))->GetData();

    if(m_openFile.empty())
        //TODO: Implement a user warning containing that no file have been opened, or create the new file
        return;

    std::ofstream file;
    file.open(m_openFile);
    file << content.ToStdString();
    file.close();
}

void Editor::OnOpen(wxCommandEvent &event) {
    //TODO: Implement opening of file and ui logic.
}
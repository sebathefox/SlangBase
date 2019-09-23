/**
 * The file containing the main window and the application entry point.
 * @file Editor.h
 * @author Sebastian Davaris
 * @date 23-09-2019
 */

#ifndef SLANGBASE_EDITOR_H
#define SLANGBASE_EDITOR_H

#include <wx/wxprec.h>

#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif

#include <wx/treectrl.h>
#include <bits/unique_ptr.h>

/**
 * The different event ID's.
 * @author Sebastian Davaris
 * @date 23-09-2019
 */
enum {
    ID_HELLO = 1,
    ID_SAVE = 2,
    ID_OPEN = 3
};

namespace controllers {
    class TabController;
}

class Editor;

/**
 * The main application entry point.
 * @author Sebastian Davaris
 * @date 23-09-2019
 */
class App : public wxApp {
public:
bool OnInit() override;

private:
    std::unique_ptr<Editor> m_frame;
};

/**
 * The main window.
 * @author Sebastian Davaris
 * @date 23-09-2019
 */
class Editor : public wxFrame {
public:
    Editor();

private:
    wxTextCtrl* textEditor;

    wxTreeCtrl* m_fileTree;

    std::unique_ptr<controllers::TabController> m_tabController;

    std::string m_openFile;

    void OnHello(wxCommandEvent& event);

    /**
     * Called when the exit button is pressed.
     * @author Sebastian Davaris
     * @date 23-09-2019
     * @param event The event arguments.
     */
    void OnExit(wxCommandEvent& event);

    /**
     * Called when the about button is clicked.
     * @author Sebastian Davaris
     * @date 23-09-2019
     * @param event The event arguments.
     */
    void OnAbout(wxCommandEvent& event);

    /**
     * The save callback for saving a file.
     * @author Sebastian Davaris
     * @date 23-09-2019
     * @param event The event arguments.
     */
    void OnSave(wxCommandEvent& event);

    /**
     * Callback for the file open event.
     * @author Sebastian Davaris
     * @date 23-09-2019
     * @param event The event arguments.
     */
    void OnOpen(wxCommandEvent& event);

};

#endif //SLANGBASE_EDITOR_H
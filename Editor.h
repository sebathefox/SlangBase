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

/**
 * No one knows what it's like
 * To be the badman
 * To be the sad man
 * Behind blue eyes
 * And no one knows what it's like
 * To be hated
 * To be faded to telling only lies
 *
 * But my dreams they aren't as empty
 * As my conscience seems to be
 * I have hours, only lonely
 * My love is vengeance
 * That's never free
 *
 * No one knows what its like
 * To feel these feelings
 * Like i do
 * And i blame you
 * No one bites back as hard
 * On their anger
 * None of my pain and woe
 * Can show through
 *
 * But my dreams they aren't as empty
 * As my conscience seems to be
 * I have hours, only lonely
 * My love is vengeance
 * That's never free
 *
 * No one knows what it's like
 * To be mistreated, to be defeated
 * Behind blue eyes
 * An no one know how to say
 * That they're sorry and don't worry
 * I'm not telling lies
 *
 * But my dreams they aren't as empty
 * As my conscience seems to be
 * I have hours, only lonely
 * My love is vengeance
 * That's never free
 *
 * No one knows what its like
 * To be the bad man
 * To be the sad man
 * Behind blue eyes
 */
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

    /**
     * The resize event callback.
     * @author Sebastian Davaris
     * @date 24-09-2019
     * @param event The event arguments.
     */
    void OnSize(wxSizeEvent& event);
};

#endif //SLANGBASE_EDITOR_H
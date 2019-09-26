/**
 * The file containing the base editor tab.
 * @file EditorTab.h
 * @author Sebastian Davaris
 * @date 20-09-2019
 */

#ifndef SLANGBASE_EDITORTAB_H
#define SLANGBASE_EDITORTAB_H

#include <wx/wx.h>
#include <bits/unique_ptr.h>

namespace views {

    /**
     * The Theme ID's for the program.
     * @author Sebastian Davaris
     * @date 24-09-2019
     */
    enum {
        EDITOR_SHOW_BUTTON = 1,
        EDITOR_DARK_THEME = 2,
        EDITOR_LIGHT_THEME = 3,

        EDITOR_DEFAULT_STYLE = (EDITOR_SHOW_BUTTON | EDITOR_DARK_THEME)
    };

    /**
     * The EditorTab class.
     * @author Sebastian Davaris
     * @date 20-09-2019
     */
    class EditorTab : public wxControl {
    public:
        /**
         * The explicit empty constructor.
         * @author Sebastian Davaris
         * @date 23-09-2019
         */
        explicit EditorTab();

        /**
         * Creates a new EditorTab.
         * @author Sebastian Davaris
         * @date 23-09-2019
         * @param parent The parent element this element is a child of.
         * @param winid The window ID.
         * @param point The position of the element.
         * @param size The size of the element.
         * @param style The layout style of the element.
         * @param base ?
         * @param mindigits ?
         * @param min ?
         * @param max ?
         * @param initial ?
         * @param name ?
         */
        EditorTab(wxWindow *parent, wxWindowID winid = wxID_ANY, const wxPoint& point = wxDefaultPosition, const wxSize& size = wxDefaultSize,
                  long style = 0L, unsigned int base = 10, unsigned int mindigits = 0, int min = 0, int max = 0x100, int initial = 0, const wxString& name = "EditorTab");

        /**
         * Creates a new EditorTab.
         * @author Sebastian Davaris
         * @date 23-09-2019
         * @param parent The parent element this element is a child of.
         * @param winid the window ID.
         * @param point The position of the element.
         * @param size The size of the element.
         * @param style The layout style of the element.
         * @param base ?
         * @param mindigits ?
         * @param min ?
         * @param max ?
         * @param initial ?
         * @param name ?
         * @return True if succeeded otherwise false.
         */
        bool Create(wxWindow *parent, wxWindowID winid = wxID_ANY, const wxPoint& point = wxDefaultPosition, const wxSize& size = wxDefaultSize,
                    long style = 0L, unsigned int base = 10, unsigned int mindigits = 0, int min = 0, int max = 0x100, int initial = 0, const wxString& name = "EditorTab");

        /**
         * checks if tab is currently active.
         * @author Sebastian Davaris
         * @date 23-09-2019
         * @return Returns true if active tab otherwise false.
         */
        bool IsActiveTab() const;

        /**
         * Sets the tab to active or inactive.
         * @author Sebastian Davaris
         * @date 23-09-2019
         */
        void SetActiveTab(bool isActive = true);

        /**
         * Opens a file in the current tab.
         * @author Sebastian Davaris
         * @date 23-09-2019
         * @param filename The name and path of the file.
         */
        void OpenFile(const std::string& filename);

        std::string GetText();

        void SetText(const std::string& text);

    protected:
        /**
         * The paint event callback.
         * @author Sebastian Davaris
         * @date 23-09-2019
         * @param event The event Arguments.
         */
        void OnPaint(wxPaintEvent& event);

        /**
         * The resize event callback.
         * @author Sebastian Davaris
         * @date 24-09-2019
         * @param event The event arguments.
         */
        void OnSize(wxSizeEvent& event);

        /**
         * Parses a file path and name and splits them into the private variables.
         * @author Sebastian Davaris
         * @date 23-09-2019
         * @param filePathName The file path and name of the file.
         */
        void ParseFilePathName(const std::string& filePathName);

    private:
        wxBoxSizer* m_boxSizer;

        wxTextCtrl* m_editor;

        std::unique_ptr<FILE> m_file;

        std::string m_filepath;
        std::string m_filename;

        bool m_activeTab;

        wxDECLARE_EVENT_TABLE();
    };
}

#endif //SLANGBASE_EDITORTAB_H

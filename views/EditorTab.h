/**
 * The file containing the base editor tab.
 * @file EditorTab.h
 * @author Sebastian Davaris
 * @date 20-09-2019
 */

#ifndef SLANGBASE_EDITORTAB_H
#define SLANGBASE_EDITORTAB_H

#include <wx/wx.h>

namespace views {

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
        explicit EditorTab();

        EditorTab(wxWindow *parent, wxWindowID winid = wxID_ANY, const wxPoint& point = wxDefaultPosition, const wxSize& size = wxDefaultSize,
                  long style = 0L, unsigned int base = 10, unsigned int mindigits = 0, int min = 0, int max = 0x100, int initial = 0, const wxString& name = "EditorTab");

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

    protected:
        void OnPaint(wxPaintEvent& event);

    private:
        wxTextCtrl* m_editor;

        std::string m_filepath;
        std::string m_filename;

        bool m_activeTab;

        wxDECLARE_EVENT_TABLE();
    };
}

#endif //SLANGBASE_EDITORTAB_H

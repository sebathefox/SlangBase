/**
 * The file containing the tab controller implementation.
 * @file TabController.cpp
 * @author Sebastian Davaris
 * @date 23-09-2019
 */

#include "TabController.h"
#include "../views/EditorTab.h"
#include <wx/wx.h>

controllers::TabController::TabController() : m_tabs() {

}

bool controllers::TabController::AddTab(wxWindow* parent) {

    //DEMO TEST.
    if(this->m_tabs.size() >= 8) {
        return false;
    }

    this->m_tabs.push_back(std::make_unique<views::EditorTab>(parent, wxID_ANY, wxPoint(200, 200), wxSize(200, 200), views::EDITOR_DEFAULT_STYLE, NULL, NULL, NULL, NULL, NULL, "EditorTab"));

    return true;
}

views::EditorTab &controllers::TabController::GetTab(unsigned int index) {
    return *(this->m_tabs.at(index));
}

void controllers::TabController::SetDefaultPosition(wxPoint point) {
    m_point = point;
}

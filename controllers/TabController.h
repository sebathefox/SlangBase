/**
 * The file containing the tab controller declaration.
 * @file TabController.h
 * @author Sebastian Davaris
 * @date 23-09-2019
 */

#ifndef SLANGBASE_TABCONTROLLER_H
#define SLANGBASE_TABCONTROLLER_H

#include <vector>
#include <bits/unique_ptr.h>

// Forward declarations.
namespace views {
    class EditorTab;
}

class wxWindow;

namespace controllers {
    /**
     * The TabController class.
     * @author Sebastian Davaris
     * @date 23-09-2019
     */
    class TabController {
    public:
        /**
         * Creates a new TabController.
         * @author Sebastian Davaris
         * @date 23-09-2019
         */
        TabController();

        /**
         * Adds a tab to the collection.
         * @author Sebastian Davaris
         * @date 23-09-2019
         * @param tab The tab to add.
         * @return Whether the operation succeeded or not.
         */
        bool AddTab(wxWindow* parent);

        /**
         * Gets the tab with the specified index.
         * @author Sebastian Davaris
         * @date 23-09-2019
         * @param index The integer index of the tab.
         * @return A unique pointer to the Tab.
         */
        views::EditorTab& GetTab(unsigned int index);

    protected:

    private:
        std::vector<std::unique_ptr<views::EditorTab>> m_tabs;
    };
}

#endif //SLANGBASE_TABCONTROLLER_H

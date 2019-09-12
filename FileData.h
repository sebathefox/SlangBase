//
// Created by sebastian on 9/12/19.
//

#ifndef SLANGBASE_FILEDATA_H
#define SLANGBASE_FILEDATA_H


#include <wx/treebase.h>

class FileData : public wxTreeItemData {
public:
    explicit FileData(wxString file);

    wxString GetData() const;

    void SetData(wxString file);

private:
    wxString m_file;
};


#endif //SLANGBASE_FILEDATA_H

//
// Created by sebastian on 9/12/19.
//

#include "FileData.h"

FileData::FileData(wxString file) {
    m_file = file;
}

wxString FileData::GetData() const {
    return m_file;
}

void FileData::SetData(wxString file) {
    m_file = file;
}

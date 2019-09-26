#include "File.h"

io::File::File(std::string fileName) {
    m_file.open(fileName);
}

io::File::~File() {
    m_file.close();
}

void io::File::SetText(std::string text) {

}

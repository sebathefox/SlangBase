cmake_minimum_required(VERSION 3.14)
project(SlangBase)

set(CMAKE_CXX_STANDARD 14)

# Finds the UI/UX Package library
find_package(wxWidgets REQUIRED COMPONENTS net core base)
include(${wxWidgets_USE_FILE})

add_executable(SlangBase Editor.cpp Editor.h FileData.cpp FileData.h views/EditorTab.h views/EditorTab.cpp controllers/TabController.cpp controllers/TabController.h io/File.h io/File.cpp)
target_link_libraries(SlangBase ${wxWidgets_LIBRARIES})
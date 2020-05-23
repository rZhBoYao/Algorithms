include_directories(..)
add_library(Selection Selection.cpp)
add_executable(SelectionTest SelectionTest.cpp)
target_link_libraries(SelectionTest PRIVATE Selection)

add_library(LCS LCS.cpp)
add_executable(LCSTest LCSTest.cpp)
target_link_libraries(LCSTest PRIVATE LCS)

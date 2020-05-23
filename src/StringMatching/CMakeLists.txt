add_library(KMP KMP.cpp)
add_executable(KMPTest KMPTest.cpp)
target_link_libraries(KMPTest PRIVATE KMP)

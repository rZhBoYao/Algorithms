![build](https://github.com/rZhBoYao/Algorithms-Playground/workflows/build/badge.svg) ![clang-format](https://github.com/rZhBoYao/Algorithms-Playground/workflows/clang-format/badge.svg)
# Algorithms-Playground
This repository houses implementation of some algorithms I find interesting in **Introduction to Algoritms (CLRS)** and **Algorithms Unlocked** for pedagogical purpose and for fun. Only those with hyperlinks are done.
## Configure and Build 
Using [CMake](https://cmake.org/) and [Ninja](https://ninja-build.org/)
```SHELL
mkdir buildRelease && cd buildRelease
cmake .. -GNinja -DCMAKE_EXPORT_COMPILE_COMMANDS=YES -DCMAKE_BUILD_TYPE=Release
cmake --build .    # Ninja defaults to running commands in parallel
```
## Debugging & Having Fun
* Build a debug build
```SHELL
mkdir build && cd build
cmake .. -GNinja -DCMAKE_EXPORT_COMPILE_COMMANDS=YES -DCMAKE_BUILD_TYPE=Debug
cmake --build .    # or "cmake --build . -- -j12" just to make sure
```
* Source code indexing with [clangd](https://clangd.llvm.org/)
```SHELL
# For clang-based tools (e.g. clangd) to find the compilation database
cd ..
ln -s build/compile_commands.json
```
* Play with a debugger  
You might need to type in your user passwaord on macOS Catilina
```SHELL
# Fire up a debugger for fun. 
# For example:
lldb -- build/src/StringMatching/KMPTest
```
## String Matching
[The Knuth-Morris-Pratt Algorithm (KMP)](src/StringMatching/KMP.cpp#L23-L45)  
## Searching
[Linear Search](src/Searching/Searching.hpp#L4-L19)  
[Binary Search](src/Searching/Searching.hpp#L21-L44)  
## Dynamic Programming
[Longest Common Subsequence](src/DynamicProgramming/LCS.cpp#L11-L27)  
Matrix-Chain Multiplication  
Rod-Cutting  
## Selection
[Minimum and Maximum](src/Selection/Selection.cpp#L9-L55)  
[Selection in Expected Linear Time](src/Selection/Selection.cpp#L57-L83)  
Selection in Worst-Case Linear Time  
## Sorting
Merge Sort  
Heap Sort  
Quick Sort  
Insertion Sort  
Bubble Sort  
Selection Sort  
Counting Sort  
Radix Sort  
## Graph
Breadth-First Search  
Depth-First-Search  
Topological Sort  
Strongly Connected Components  
Shortest Path  
Prim's Algorithm  
Kruskal's Algorithm  
Maximum Flow  
## References
[A Tour of C++](http://www.stroustrup.com/tour2.html)  
[libcxx implementation](https://github.com/llvm/llvm-project/blob/master/libcxx/include/algorithm)  
[cppreference.com](https://en.cppreference.com/w/cpp)  
[Introduction to Algorithms, Third Edition](https://mitpress.mit.edu/books/introduction-algorithms-third-edition)  
[Algorithms Unlocked](https://mitpress.mit.edu/books/algorithms-unlocked)  

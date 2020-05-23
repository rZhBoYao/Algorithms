#ifndef SELECTION_SELECTION_HPP
#define SELECTION_SELECTION_HPP

#include "Common/Utils.hpp"

#include <vector>

//
// CLRS 9.1 Minimum and Maximum
// page 214 ~ 215
//
// requires a vector
// returns a std::pair<int, int>(min, max) for the min and max of the entire
// vector
//
auto findMinMax(const std::vector<int>& v) -> std::pair<int, int>;

//
// CLRS 9.2 Selection in Expected Linear Time
// page 215
//
int randomizedSelect(std::vector<int>& a, int p, int r, int i);

#endif // SELECTION_SELECTION_HPP

#ifndef DYNAMICPROGRAMMING_LCS_HPP
#define DYNAMICPROGRAMMING_LCS_HPP

#include <string>
#include <vector>

// Sol for Solution
using Sol = std::vector<std::vector<size_t>>;

Sol getLCSLength(const std::string& x, const std::string& y);

void printLCS(const Sol& sol, const std::string& x, size_t i, size_t j);

#endif // DYNAMICPROGRAMMING_LCS_HPP

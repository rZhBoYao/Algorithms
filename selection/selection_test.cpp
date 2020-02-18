#include "selection.hpp"
#include <iostream>

int main() {
  std::vector<int> v = {7, 23, 11, 13, 29, 19, 21, 5, 43, 9, 37, 15, 25, 31};
  std::cout << v << '\n';
  sort(v);
  std::cout << v << '\n';
  sort(v, std::greater<int>());
  std::cout << v << '\n';
}

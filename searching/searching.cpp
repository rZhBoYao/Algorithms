#include "searching.hpp"
#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

int main() {
  std::cout << "Testing linear search: \n";
  int n1 = 0;
  int n2 = -5;

  std::vector<int> v = {0, 1, 2, 3, 4};
  auto result1 = linear_search(std::begin(v), std::end(v), n1);
  auto result2 = linear_search(std::begin(v), std::end(v), n2);

  if (result1 != std::end(v))
    std::cout << "v contains: " << n1 << '\n'
              << "dereference: " << *result1 << '\n'
              << "at index: " << std::distance(std::begin(v), result1) << '\n';
  else
    std::cout << "v does not contain: " << n1 << '\n';

  if (result2 != std::end(v))
    std::cout << "v contains: " << n2 << '\n'
              << "dereference: " << *result2 << '\n'
              << "at index: " << std::distance(std::begin(v), result2) << '\n';
  else
    std::cout << "v does not contain: " << n2 << '\n';

  std::cout << '\n'
            << "Testing binary search: \n";
  n1 = 19;
  n2 = 70;
  v = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 13, 13, 14, 15, 16, 16, 17, 17, 17, 17, 17, 17, 18, 19};
  result1 = binary_find(std::begin(v), std::end(v), n1);
  result2 = binary_find(std::begin(v), std::end(v), n2);

  if (result1 != std::end(v))
    std::cout << "v contains: " << n1 << '\n'
              << "dereference: " << *result1 << '\n'
              << "at index: " << std::distance(std::begin(v), result1) << '\n';
  else
    std::cout << "v does not contain: " << n1 << '\n';

  if (result2 != std::end(v))
    std::cout << "v contains: " << n2 << '\n'
              << "dereference: " << *result2 << '\n'
              << "at index: " << std::distance(std::begin(v), result2) << '\n';
  else
    std::cout << "v does not contain: " << n2 << '\n';
}

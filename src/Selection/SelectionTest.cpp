#include "Selection.hpp"

#include <iostream>

int main() {
  std::vector<int> v =
      {7, 23, 11, 13, 29, 19, 21, 5, 43, 9, 37, 15, 25, 31, 87};

  auto [min, max] = findMinMax(v);

  std::cout << "min: " << min << '\n' << "max: " << max << std::endl;

  // start from 0
  for (size_t i = 0; i < v.size(); ++i) {
    std::cout << i << "th: "
              << randomizedSelect(v, 0, static_cast<int>(v.size()) - 1, i)
              << '\n';
  }

  sort(v);
  std::cout << "sorted:\n" << v << '\n';
  sort(v, std::greater<>());
  std::cout << "sorted:\n" << v << '\n';
}

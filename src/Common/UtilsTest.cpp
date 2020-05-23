#include "Utils.hpp"

#include <iostream>

int main() {
  //
  // test for
  // class Rand_int
  //
  constexpr int max = 30;
  RandInt       rnd{0, max};

  std::vector<int> histogram(max + 1);
  for (size_t i = 0; i != histogram.size() * 10; ++i) {
    ++histogram[rnd()];
  }

  for (size_t i = 0; i != histogram.size(); ++i) {
    std::cout << i << '\t';
    for (int j = 0; j != histogram[i]; ++j) {
      std::cout << '*';
    }
    std::cout << '\n';
  }

  //
  // test for
  // inline std::ostream& operator<<(std::ostream& out, const std::vector<int>&
  // v) inline void sort(std::vector<int>& v) template<typename Compare> inline
  // void sort(std::vector<int>& v, Compare comp)
  //
  std::vector<int> v = {7, 23, 11, 13, 29, 19, 21, 5, 43, 9, 37, 15, 25, 31};
  std::cout << v << '\n';
  sort(v);
  std::cout << v << '\n';
  sort(v, std::greater<>());
  std::cout << v << '\n';
}

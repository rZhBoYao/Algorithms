#include "Selection.hpp"

#include "Common/Utils.hpp"

#include <algorithm>
#include <iostream>
#include <vector>

//
// CLRS 9.1 Minimum and Maximum
// page 214 ~ 215
//
// requires a vector
// returns a std::pair<int, int>(min, max) for the min and max of the entire
// vector
//
auto findMinMax(const std::vector<int>& v) -> std::pair<int, int> {
  const auto len = std::distance(v.begin(), v.end());
  auto       it  = v.begin();
  int        min = 0;
  int        max = 0;
  if (len % 2) { // odd length
    ++it;
    max = v[0];
    min = v[0];
  } else { // even length
    it += 2;
    if (v[0] > v[1]) {
      max = v[0];
      min = v[1];
    } else {
      max = v[1];
      min = v[0];
    }
  }

  for (; it != v.end(); it += 2) {
    if (*it > *(it + 1)) {
      if (*it > max) {
        max = *it;
      }
      if (*(it + 1) < min) {
        min = *(it + 1);
      }
    } else {
      if (*it < min) {
        min = *it;
      }
      if (*(it + 1) > max) {
        max = *(it + 1);
      }
    }
  }
  return std::make_pair(min, max);
}

//
// CLRS 9.2 Selection in Expected Linear Time
// page 215
//
int randomizedSelect(std::vector<int>& a, int p, int r, int i) {
  if (p == r) {
    return a[p];
  }

  RandInt rnd{p, r};
  auto    pivot = a[rnd()];

  std::partition(a.begin() + p, a.begin() + r + 1,
                 [=](int a) { return a <= pivot; });
  int q = std::partition(a.begin() + p, a.begin() + r + 1,
                         [=](int a) { return a < pivot; }) -
          a.begin();

  auto k = q - p;
  if (i == k) {
    return a[q];
  } else if (i < k) {
    return randomizedSelect(a, p, q - 1, i);
  } else {
    return randomizedSelect(a, q + 1, r, i - k - 1);
  }
}

#include "../utilities/utilities.hpp"
#include <algorithm>
#include <iostream>
#include <vector>

//
// CLRS 9.1 Minimum and Maximum
// page 214 ~ 215
//
// requires a vector
// returns a std::pair<int, int>(min, max) for the min and max of the entire vector
//
inline auto find_min_max(const std::vector<int>& v) {
  const auto len = std::distance(v.begin(), v.end());
  auto it = v.begin();
  int min, max;
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
      if (*it > max)
        max = *it;
      if (*(it + 1) < min)
        min = *(it + 1);
    } else {
      if (*it < min)
        min = *it;
      if (*(it + 1) > max)
        max = *(it + 1);
    }
  }
  return std::make_pair(min, max);
}

//
// CLRS 9.2 Selection in Expected Linear Time
// page 215
//
inline int randomized_select(std::vector<int>& A, int p, int r, int i) {
  if (p == r)
    return A[p];

  Rand_int rnd{p, r};
  auto pivot = A[rnd()];

  std::partition(A.begin() + p, A.begin() + r + 1, [=](int a) { return a <= pivot; });
  auto q = std::partition(A.begin() + p, A.begin() + r + 1, [=](int a) { return a < pivot; }) - A.begin();

  auto k = q - p;
  if (i == k)
    return A[q];
  else if (i < k)
    return randomized_select(A, p, q - 1, i);
  else
    return randomized_select(A, q + 1, r, i - k - 1);
}

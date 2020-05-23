// This file implements longest common sunsequence from CLRS (15.4) page 390 ~
// 396

#include "LCS.hpp"

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

Sol getLCSLength(const std::string& x, const std::string& y) {
  const auto m = x.length();
  const auto n = y.length();

  Sol sol(m + 1, std::vector<size_t>(n + 1, 0));

  for (size_t i = 1; i <= m; ++i) {
    for (size_t j = 1; j <= n; ++j) {
      if (x[i - 1] == y[j - 1]) { // decrement the index for string subscripting
        sol[i][j] = sol[i - 1][j - 1] + 1;
      } else {
        sol[i][j] = std::max(sol[i][j - 1], sol[i - 1][j]);
      }
    }
  }
  return sol;
}

namespace {
void doPrintLCS(const Sol& sol, const std::string& x, size_t i, size_t j) {
  if (i == 0 || j == 0) {
    return;
  }
  if (sol[i - 1][j - 1] == sol[i][j] - 1 &&
      sol[i - 1][j - 1] >= sol[i - 1][j] &&
      sol[i - 1][j - 1] >= sol[i][j - 1]) {
    doPrintLCS(sol, x, i - 1, j - 1);
    std::cout << x[i - 1]; // decrement the index for string subscripting
  } else if (sol[i - 1][j] >= sol[i][j - 1]) {
    doPrintLCS(sol, x, i - 1, j);
  } else {
    doPrintLCS(sol, x, i, j - 1);
  }
}
} // namespace

void printLCS(const Sol& sol, const std::string& x, size_t i, size_t j) {
  doPrintLCS(sol, x, i, j);
  std::cout << "\n";
}

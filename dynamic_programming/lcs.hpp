// This file implements longest common sunsequence from CLRS (15.4) page 390 ~ 396

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

// Sol for Solution
using Sol = std::vector<std::vector<size_t>>;

inline Sol lcs_length(const std::string& X, const std::string& Y) {
  const auto m = X.length();
  const auto n = Y.length();
  Sol sol(m + 1, std::vector<size_t>(n + 1, 0));
  for (size_t i = 1; i <= m; ++i) {
    for (size_t j = 1; j <= n; ++j) {
      if (X[i - 1] == Y[j - 1]) // decrement the index for string subscripting
        sol[i][j] = sol[i - 1][j - 1] + 1;
      else
        sol[i][j] = std::max(sol[i][j - 1], sol[i - 1][j]);
    }
  }
  return sol;
}

inline void print_lcs_(const Sol& sol, const std::string& X, size_t i, size_t j) {
  if (i == 0 || j == 0)
    return;
  if (sol[i - 1][j - 1] == sol[i][j] - 1 &&
      sol[i - 1][j - 1] >= sol[i - 1][j] &&
      sol[i - 1][j - 1] >= sol[i][j - 1]) {
    print_lcs_(sol, X, i - 1, j - 1);
    std::cout << X[i - 1]; // decrement the index for string subscripting
  } else if (sol[i - 1][j] >= sol[i][j - 1]) {
    print_lcs_(sol, X, i - 1, j);
  } else {
    print_lcs_(sol, X, i, j - 1);
  }
}

inline void print_lcs(const Sol& sol, const std::string& X, size_t i, size_t j) {
  print_lcs_(sol, X, i, j);
  std::cout << "\n";
}

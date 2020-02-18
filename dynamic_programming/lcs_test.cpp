#include "lcs.hpp"
#include <iostream>
#include <string>

int main() {
  std::string X = "ABCBDAB";
  std::string Y = "BDCABA";
  auto sol = lcs_length(X, Y);
  std::cout << sol.back().back() << '\n';
  print_lcs(sol, X, X.length(), Y.length());
  for (auto row : sol) {
    for (auto a : row)
      std::cout << a;
    std::cout << '\n';
  }

  X = "DFADBDCEBEAGCF";
  Y = "EFBEGECAEBDABD";
  sol = lcs_length(X, Y);
  std::cout << sol.back().back() << '\n';
  print_lcs(sol, X, X.length(), Y.length());
  for (auto row : sol) {
    for (auto a : row)
      std::cout << a;
    std::cout << '\n';
  }

  X = "GTCA";
  Y = "GTACG";
  sol = lcs_length(X, Y);
  std::cout << sol.back().back() << '\n';
  print_lcs(sol, X, X.length(), Y.length());
  for (auto row : sol) {
    for (auto a : row)
      std::cout << a;
    std::cout << '\n';
  }
}

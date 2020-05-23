#include "LCS.hpp"

#include <iostream>
#include <string>

int main() {
  std::string x   = "ABCBDAB";
  std::string y   = "BDCABA";
  auto        sol = getLCSLength(x, y);
  std::cout << sol.back().back() << '\n';
  printLCS(sol, x, x.length(), y.length());
  for (const auto& row : sol) {
    for (auto a : row) {
      std::cout << a;
    }
    std::cout << '\n';
  }

  x   = "DFADBDCEBEAGCF";
  y   = "EFBEGECAEBDABD";
  sol = getLCSLength(x, y);
  std::cout << sol.back().back() << '\n';
  printLCS(sol, x, x.length(), y.length());
  for (const auto& row : sol) {
    for (auto a : row) {
      std::cout << a;
    }
    std::cout << '\n';
  }

  x   = "GTCA";
  y   = "GTACG";
  sol = getLCSLength(x, y);
  std::cout << sol.back().back() << '\n';
  printLCS(sol, x, x.length(), y.length());
  for (const auto& row : sol) {
    for (auto a : row) {
      std::cout << a;
    }
    std::cout << '\n';
  }
}

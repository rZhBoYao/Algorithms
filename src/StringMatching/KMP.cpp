#include "KMP.hpp"

#include <iostream>

// more like a failure function
std::vector<int> computePrefixFunction(const std::string& p) {
  const auto       m = p.length();
  std::vector<int> 𝛑(m);
  𝛑[0]   = -1;
  auto k = -1;
  for (size_t q = 1; q < m; ++q) {
    while (k > -1 && p[k + 1] != p[q]) {
      k = 𝛑[k];
    }
    if (p[k + 1] == p[q]) {
      ++k;
    }
    𝛑[q] = k;
  }
  return 𝛑;
}

std::vector<size_t> kmpMatcher(const std::string& t, const std::string& p) {
  const auto          n = t.length();
  const auto          m = p.length();
  auto                𝛑 = computePrefixFunction(p);
  auto                q = -1; // match to what position in pattern
  std::vector<size_t> matched;

  for (size_t i = 0; i < n; ++i) {
    while (q > -1 && p[q + 1] != t[i]) {
      q = 𝛑[q];
    }

    if (p[q + 1] == t[i]) {
      ++q;
    }

    if (q == static_cast<int>(m) - 1) {
      matched.push_back(i - q);
      q = 𝛑[q];
    }
  }
  return matched;
}

void printOccurrence(const std::string& t, const std::string& p,
                     const std::vector<size_t>& positions) {
  if (positions.empty()) {
    std::cout << "Pattern not found.\n\n";
    return;
  }

  std::cout << "Text:\n" << t << '\n';
  for (const auto& index : positions) {
    std::cout << "Pattern matched starting from index " << index << '\n'
              << std::string(index, ' ') << p << '\n';
  }

  std::cout << '\n';
}

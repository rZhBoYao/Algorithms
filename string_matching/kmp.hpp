#include <iostream>
#include <string>
#include <vector>

// more like a failure function
inline std::vector<int> compute_prefix_function(const std::string& P) {
  const auto m = P.length();
  std::vector<int> 𝛑(m);
  𝛑[0] = -1;
  auto k = -1;
  for (size_t q = 1; q < m; ++q) {
    while (k > -1 && P[k + 1] != P[q])
      k = 𝛑[k];
    if (P[k + 1] == P[q])
      ++k;
    𝛑[q] = k;
  }
  return 𝛑;
}

inline std::vector<size_t> KMP_matcher(const std::string& T, const std::string& P) {
  const auto n = T.length();
  const auto m = P.length();
  auto 𝛑 = compute_prefix_function(P);
  auto q = -1; // match to what position in pattern
  std::vector<size_t> matched;

  for (size_t i = 0; i < n; ++i) {
    while (q > -1 && P[q + 1] != T[i])
      q = 𝛑[q];

    if (P[q + 1] == T[i])
      ++q;

    if (q == (int)m - 1) {
      matched.push_back(i - q);
      q = 𝛑[q];
    }
  }
  return matched;
}

inline void print_occurrence(const std::string& T, const std::string& P, const std::vector<size_t>& positions) {
  if (!positions.size()) {
    std::cout << "Pattern not found.\n\n";
    return;
  }

  std::cout << "Text:\n"
            << T << '\n';
  for (const auto& index : positions)
    std::cout << "Pattern matched starting from index " << index << '\n'
              << std::string(index, ' ') << P << '\n';

  std::cout << '\n';
}

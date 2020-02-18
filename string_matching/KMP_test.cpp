#include "kmp.hpp"
#include <iostream>
#include <string>
#include <vector>

int main() {
  std::string text = "bacbababaabcbab";
  std::string pattern = "ababaca";
  print_occurrence(text, pattern, KMP_matcher(text, pattern));

  text = "bacbababaabcbab";
  pattern = "aab";
  print_occurrence(text, pattern, KMP_matcher(text, pattern));

  text = "aababbababbbababbaaabb";
  pattern = "ababbaaa";
  print_occurrence(text, pattern, KMP_matcher(text, pattern));

  text = "aababbababbbababbaaabb";
  pattern = "aba";
  print_occurrence(text, pattern, KMP_matcher(text, pattern));

  auto f = compute_prefix_function("aabaabaaab");
  for (auto i : f)
    std::cout << i << '\t';
  std::cout << '\n';
}

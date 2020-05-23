#include "KMP.hpp"

#include <iostream>

int main() {
  std::string text    = "bacbababaabcbab";
  std::string pattern = "ababaca";
  printOccurrence(text, pattern, kmpMatcher(text, pattern));

  text    = "bacbababaabcbab";
  pattern = "aab";
  printOccurrence(text, pattern, kmpMatcher(text, pattern));

  text    = "aababbababbbababbaaabb";
  pattern = "ababbaaa";
  printOccurrence(text, pattern, kmpMatcher(text, pattern));

  text    = "aababbababbbababbaaabb";
  pattern = "aba";
  printOccurrence(text, pattern, kmpMatcher(text, pattern));

  auto f = computePrefixFunction("aabaabaaab");
  for (auto i : f) {
    std::cout << i << '\t';
  }
  std::cout << '\n';
}

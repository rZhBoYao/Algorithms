#ifndef STRINGMATCHING_KMP_HPP
#define STRINGMATCHING_KMP_HPP

#include <string>
#include <vector>

// more like a failure function
std::vector<int> computePrefixFunction(const std::string& p);

std::vector<size_t> kmpMatcher(const std::string& t, const std::string& p);

void printOccurrence(const std::string&         t,
                     const std::string&         p,
                     const std::vector<size_t>& positions);

#endif // STRINGMATCHING_KMP_HPP

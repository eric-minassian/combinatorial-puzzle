#include "puzzleSolver.hpp"
#include <cmath>
#include <string>
#include <unordered_map>
#include <unordered_set>

bool verifySolution(std::string s1, std::string s2, std::string s3,
                    const std::unordered_map<char, unsigned> &mapping) {

  // Create an unsigned int for each string
  unsigned int s1Num = 0, s2Num = 0, s3Num = 0;

  // Loop through each string and add the value to its respective unsigned int
  // The value is multiplied by 10 to the power of the length of the string
  // minus the current index minus 1 to get the correct place value of each
  // value
  for (int i = 0; i < s1.length(); i++) {
    s1Num += mapping.at(s1[i]) * pow(10, s1.length() - i - 1);
  }

  for (int i = 0; i < s2.length(); i++) {
    s2Num += mapping.at(s2[i]) * pow(10, s2.length() - i - 1);
  }

  for (int i = 0; i < s3.length(); i++) {
    s3Num += mapping.at(s3[i]) * pow(10, s3.length() - i - 1);
  }

  // If the sum of s1Num and s2Num is equal to s3Num, return true
  // Else return false
  if ((s1Num + s2Num) == s3Num) {
    return true;
  } else {
    return false;
  }
}

bool backtrack(const std::string s1, const std::string s2, const std::string s3,
               std::unordered_map<char, unsigned> &mapping,
               std::unordered_set<unsigned> &numbers,
               std::unordered_set<char> &letters) {

  if (mapping.size() == letters.size()) {
    return verifySolution(s1, s2, s3, mapping);
  }

  for (auto &v : letters) {
    if (mapping.find(v) == mapping.end()) {
      unsigned int num = *numbers.begin();
      numbers.erase(numbers.begin());
      mapping[v] = num;

      if (backtrack(s1, s2, s3, mapping, numbers, letters)) {
        return true;
      } else {
        mapping.erase(v);
        numbers.insert(num);
      }
    }
  }
  return false;
}

bool puzzleSolver(const std::string &s1, const std::string &s2,
                  const std::string &s3,
                  std::unordered_map<char, unsigned> &mapping) {
  std::unordered_set<unsigned int> numbers = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  std::unordered_set<char> letters;
  for (unsigned short i = 0; i < s1.length(); i++) {
    letters.insert(s1[i]);
  }
  for (unsigned short i = 0; i < s2.length(); i++) {
    letters.insert(s2[i]);
  }

  for (unsigned short i = 0; i < s3.length(); i++) {
    letters.insert(s3[i]);
  }

  return backtrack(s1, s2, s3, mapping, numbers, letters);
}

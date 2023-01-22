#include "puzzleSolver.hpp"
#include <string>
#include <unordered_map>
#include <unordered_set>

bool backtrack(const std::string s1, const std::string s2, const std::string s3,
               std::unordered_map<char, unsigned> &mapping,
               std::unordered_set<unsigned> &numbers,
               std::unordered_set<char> &letters, unsigned int remainder) {

  if (letters.size() == mapping.size()) {
    return true;
  }

  unsigned int s1Value, s2Value, s3Value;
  if (!s1.empty()) {
    if (mapping.find(s1[s1.length() - 1]) != mapping.end()) {
      s1Value = mapping[s1[s1.length() - 1]];
    } else {
      for (auto value : numbers) {
        mapping[s1[s1.length() - 1]] = value;
        numbers.erase(value);
        if (backtrack(s1, s2, s3, mapping, numbers, letters, remainder)) {
          return true;
        }
        numbers.insert(value);
        mapping.erase(s1[s1.length() - 1]);
      }
    }
  } else {
    s1Value = 0;
  }

  if (!s2.empty()) {
    if (mapping.find(s2[s2.length() - 1]) != mapping.end()) {
      s2Value = mapping[s2[s2.length() - 1]];
    } else {
      for (auto value : numbers) {
        mapping[s2[s2.length() - 1]] = value;
        numbers.erase(value);
        if (backtrack(s1, s2, s3, mapping, numbers, letters, remainder)) {
          return true;
        }
        numbers.insert(value);
        mapping.erase(s2[s2.length() - 1]);
      }
    }
  } else {
    s2Value = 0;
  }

  if (!s3.empty()) {
    if (mapping.find(s3[s3.length() - 1]) != mapping.end()) {
      s3Value = mapping[s3[s3.length() - 1]];
    } else {
      for (auto value : numbers) {
        mapping[s3[s3.length() - 1]] = value;
        numbers.erase(value);
        if (backtrack(s1, s2, s3, mapping, numbers, letters, remainder)) {
          return true;
        }
        numbers.insert(value);
        mapping.erase(s3[s3.length() - 1]);
      }
    }
  } else {
    s3Value = 0;
  }

  if ((remainder + s1Value + s2Value) % 10 == s3Value) {

    if (backtrack(s1.substr(0, s1.length() - 1), s2.substr(0, s2.length() - 1),
                  s3.substr(0, s3.length() - 1), mapping, numbers, letters,
                  ((remainder + s1Value + s2Value) / 10))) {
      return true;
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

  return backtrack(s1, s2, s3, mapping, numbers, letters, 0);
}

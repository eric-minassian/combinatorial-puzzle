#include <set>
#include <string>
#include <unordered_map>

// Recursive helper function to solve the puzzle
bool backtrack(const std::string &s1, const std::string &s2,
               const std::string &s3,
               std::unordered_map<char, unsigned> &mapping,
               std::set<unsigned> &numbers, unsigned remainder,
               unsigned offset) {

  // Get the index of the current letter in each word
  int s1Index = s1.size() - 1 - offset, s2Index = s2.size() - 1 - offset,
      s3Index = s3.size() - 1 - offset;

  // Base Case
  // If all the letters have been assigned a value and the remainder is 0
  // then the puzzle has been solved
  if (s1Index < 0 && s2Index < 0 && s3Index < 0 && remainder == 0) {
    return true;
  }

  // Recursive Case
  // Set variables to hold the value of the current letter in each word
  unsigned s1Num = 0, s2Num = 0, s3Num = 0;

  // If the index is valid, check if the letter has been assigned a value
  // If not, leave the value as 0
  if (s1Index >= 0) {

    // If the letter hasn't been assigned a value, try assigning it a value
    // from the set of numbers
    if (mapping.find(s1[s1Index]) == mapping.end()) {
      // Create a copy of the set of numbers
      std::set<unsigned> numbersCopy = numbers;
      // Try assigning the letter a value from the set of numbers
      for (const auto &v : numbersCopy) {
        mapping[s1[s1Index]] = v;
        numbers.erase(v);

        // If the letter can be assigned a value, call the function again
        if (backtrack(s1, s2, s3, mapping, numbers, remainder, offset)) {
          return true;
        }
        numbers.insert(v);
        mapping.erase(s1[s1Index]);
      }
      // If the letter can't be assigned a value, return false
      return false;
    } else {
      s1Num = mapping[s1[s1Index]];
    }
  }

  // If the index is valid, check if the letter has been assigned a value
  // If not, leave the value as 0
  if (s2Index >= 0) {

    // If the letter hasn't been assigned a value, try assigning it a value
    // from the set of numbers
    if (mapping.find(s2[s2Index]) == mapping.end()) {
      // Create a copy of the set of numbers
      std::set<unsigned> numbersCopy = numbers;
      // Try assigning the letter a value from the set of numbers
      for (const auto &v : numbersCopy) {
        mapping[s2[s2Index]] = v;
        numbers.erase(v);

        // If the letter can be assigned a value, call the function again
        if (backtrack(s1, s2, s3, mapping, numbers, remainder, offset)) {
          return true;
        }
        numbers.insert(v);
        mapping.erase(s2[s2Index]);
      }

      // If the letter can't be assigned a value, return false
      return false;
    } else {
      s2Num = mapping[s2[s2Index]];
    }
  }

  // If the index is valid, check if the letter has been assigned a value
  // If not, leave the value as 0
  if (s3Index >= 0) {
    // If the letter hasn't been assigned a value, try assigning it a value
    // from the set of numbers
    if (mapping.find(s3[s3Index]) == mapping.end()) {
      // Create a copy of the set of numbers
      std::set<unsigned> numbersCopy = numbers;
      // Try assigning the letter a value from the set of numbers
      for (const auto &v : numbersCopy) {
        mapping[s3[s3Index]] = v;
        numbers.erase(v);

        // If the letter can be assigned a value, call the function again
        if (backtrack(s1, s2, s3, mapping, numbers, remainder, offset)) {
          return true;
        }
        numbers.insert(v);
        mapping.erase(s3[s3Index]);
      }
      return false;
    } else {
      s3Num = mapping[s3[s3Index]];
    }
  }

  // If the sum of the s1Num and s2Num and remainder is equal to the s3Num, call
  // the function again with the new remainder and offset + 1
  if ((s1Num + s2Num + remainder) % 10 == s3Num) {
    // If the function returns true, return true
    if (backtrack(s1, s2, s3, mapping, numbers,
                  (s1Num + s2Num + remainder) / 10, offset + 1)) {
      return true;
    }
  }

  return false;
}

// Function to solve the puzzle problem
bool puzzleSolver(const std::string &word1, const std::string &word2,
                  const std::string &word3,
                  std::unordered_map<char, unsigned> &mapping) {

  // Create a set of all the number possibilities
  std::set<unsigned> numbers = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

  // Call the recursive helper function and return result
  return backtrack(word1, word2, word3, mapping, numbers, 0, 0);
}

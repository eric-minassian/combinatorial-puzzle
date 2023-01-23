#include <set>
#include <string>
#include <unordered_map>

// Helper function to check if the mapping is correct
bool isCorrect(const std::string &word1, const std::string &word2,
               const std::string &word3,
               const std::unordered_map<char, unsigned> &dct) {
  int num1 = 0, num2 = 0, num3 = 0;

  for (const auto &v : word1) {
    num1 = num1 * 10 + dct.at(v);
  }

  for (const auto &v : word2) {
    num2 = num2 * 10 + dct.at(v);
  }

  for (const auto &v : word3) {
    num3 = num3 * 10 + dct.at(v);
  }

  return num1 + num2 == num3;
}

// Recursive helper function to solve the puzzle
bool backtrack(const std::string &s1, const std::string &s2,
               const std::string &s3,
               std::unordered_map<char, unsigned> &mapping,
               std::set<unsigned> &numbers, std::set<char> &letters) {

  // Base Case
  // If all the letters are mapped to a number then run the isCorrect function
  // and return the result
  if (letters.empty()) {
    return isCorrect(s1, s2, s3, mapping);
  }

  // Recursive Case
  // For each letter in the set of letters, try to map it to each number in the
  // set of available numbers

  // Remove the letter from the set of letters
  auto letter = *letters.begin();
  letters.erase(letters.begin());

  // Try to map the letter to each number in the set of available numbers
  for (const auto &num : numbers) {
    auto remaining_numbers = numbers;
    remaining_numbers.erase(num);
    mapping[letter] = num;

    // Recursively call the function with the updated mapping and sets
    // If the recursive call returns true, then return true
    if (backtrack(s1, s2, s3, mapping, remaining_numbers, letters)) {
      return true;
    }
  }

  // If the letter cannot be mapped to any available numbers, then add it back
  // to the set
  letters.insert(letter);
  return false;
}

// Function to solve the puzzle problem
bool puzzleSolver(const std::string &word1, const std::string &word2,
                  const std::string &word3,
                  std::unordered_map<char, unsigned> &mapping) {

  // Create a set of all the number possibilities
  // Create a set of all the different letters to be assigned a value
  std::set<char> letters;
  std::set<unsigned> numbers = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

  // Add the letters to the set
  for (const auto &l : word1) {
    letters.insert(l);
  }
  for (const auto &l : word2) {
    letters.insert(l);
  }
  for (const auto &l : word3) {
    letters.insert(l);
  }

  // Call the recursive helper function and return result
  return backtrack(word1, word2, word3, mapping, numbers, letters);
}

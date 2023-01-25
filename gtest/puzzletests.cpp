#include "puzzleSolver.hpp"
#include "ver.hpp"
#include "gtest/gtest.h"
#include <string>
#include <unordered_map>

/*

Note that this IS NOT a comprehensive set of test cases.
You should still write additional test cases.

This is to get you started and serve as a sanity check.


Note that "gradeYesAnswer" is provided for use in your test cases, but
you may NOT use it in any code you write otherwise for this project.

 */

namespace {

TEST(Required, PotPanBib) {

  std::unordered_map<char, unsigned> puzzle;

  bool p1 = puzzleSolver("POT", "PAN", "BIB", puzzle);
  EXPECT_TRUE(p1 and gradeYesAnswer("POT", "PAN", "BIB", puzzle));
}

TEST(Required, NeatFind) {

  std::unordered_map<char, unsigned> puzzle;

  bool p1 = puzzleSolver("UCI", "ALEX", "MIKE", puzzle);
  EXPECT_TRUE(p1 and gradeYesAnswer("UCI", "ALEX", "MIKE", puzzle));
} // end test two, "NeatFind"

TEST(Required, FirstNo) {

  std::unordered_map<char, unsigned> puzzle;

  bool p1 = puzzleSolver("LARRY", "CAREER", "LEGEND", puzzle);
  EXPECT_FALSE(p1);
}

// Additional Test Cases

TEST(puzzleSolver, Additional1) {

  std::unordered_map<char, unsigned> puzzle;

  bool p1 = puzzleSolver("INVMPBDWU", "IEVMUEWBP", "BEINVUWIV", puzzle);
  EXPECT_FALSE(p1);
}

TEST(puzzleSolver, Additional2) {

  std::unordered_map<char, unsigned> puzzle;

  bool p1 = puzzleSolver("JFKFJE", "EKFNF", "EJFNG", puzzle);
  EXPECT_FALSE(p1);
}

TEST(puzzleSolver, Additional3) {

  std::unordered_map<char, unsigned> puzzle;

  bool p1 = puzzleSolver("CENTER", "CENTRAL", "CENTRIC", puzzle);
  EXPECT_FALSE(p1);
}

TEST(puzzleSolver, Additional4) {

  std::unordered_map<char, unsigned> puzzle;

  bool p1 = puzzleSolver("LARRY", "CARTER", "LEGEND", puzzle);
  EXPECT_TRUE(p1 and gradeYesAnswer("LARRY", "CARTER", "LEGEND", puzzle));
}

TEST(puzzleSolver, Additional5) {

  std::unordered_map<char, unsigned> puzzle;

  bool p1 = puzzleSolver("A", "A", "A", puzzle);
  EXPECT_TRUE(p1 and gradeYesAnswer("A", "A", "A", puzzle));
}

TEST(puzzleSolver, Additional6) {

  std::unordered_map<char, unsigned> puzzle;

  bool p1 = puzzleSolver("RTYWTTROPT", "OTRYERTQW", "TEPTPUIEPY", puzzle);
  EXPECT_TRUE(p1 and
              gradeYesAnswer("RTYWTTROPT", "OTRYERTQW", "TEPTPUIEPY", puzzle));
}

TEST(puzzleSolver, Additional7) {

  std::unordered_map<char, unsigned> puzzle;

  bool p1 = puzzleSolver("QYRYERTQW", "ITYWQOROQT", "TERQPUEIYP", puzzle);
  EXPECT_FALSE(p1);
}

TEST(puzzleSolver, Additional8) {

  std::unordered_map<char, unsigned> puzzle;

  bool p1 = puzzleSolver("ABCDE", "FGHIJ", "MHJBCE", puzzle);
  EXPECT_FALSE(p1);
}

} // end namespace

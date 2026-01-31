#include <gtest/gtest.h>
#include <set>
#include <string>
#include "wordle.h"

TEST(Wordle, Basic) {
  std::set<std::string> dict = {"apple","apply","amply","angle","amble"};
  // pattern: a _ _ l e
  auto res = wordle("a--le", "p", dict);
  EXPECT_TRUE(res.count("apple") > 0);
  EXPECT_TRUE(res.count("amble") == 0);
}

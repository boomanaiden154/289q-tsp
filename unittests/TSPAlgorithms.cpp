#include <gtest/gtest.h>

#include "TSPAlgorithms.h"

// Demonstrate some basic assertions.
TEST(TSPAlgorithmsTest, GreatestNodeDegree1) {
  std::vector<std::tuple<int, int, float>> Edges;
  Edges.push_back(std::make_tuple(1,2,1.0f));
  EXPECT_EQ(getGreatestNodeDegree(Edges), 1);
}

TEST(TSPAlgorithmsTest, GreatestNodeDegree2) {
  std::vector<std::tuple<int, int, float>> Edges;
  Edges.push_back(std::make_tuple(1,2,1.0f));
  Edges.push_back(std::make_tuple(2,3,1.0f));
  EXPECT_EQ(getGreatestNodeDegree(Edges), 2);
}

TEST(TSPAlgorithmsTest, GreatestNodeDegree3) {
  std::vector<std::tuple<int, int, float>> Edges;
  Edges.push_back(std::make_tuple(1,2,1.0f));
  Edges.push_back(std::make_tuple(2,3,1.0f));
  Edges.push_back(std::make_tuple(2,4,1.0f));
  EXPECT_EQ(getGreatestNodeDegree(Edges), 3);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    int ret{RUN_ALL_TESTS()};
    if (!ret)
      return 0;
    else
      return 1;
}

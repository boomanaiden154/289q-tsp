#include <iostream>
#include <vector>

#include "DataLoader.h"
#include "TSPUtils.h"

int main() {
  std::map<std::pair<int, int>, float> TSPInstance =
      loadDataFromFile("./data/1000_euclidianDistance.txt");
  std::vector<int> BasicPath;
  for (int i = 1; i <= 1000; ++i) {
    BasicPath.push_back(i);
  }
  float TotalCost = computeCost(TSPInstance, BasicPath);
  std::cout << TotalCost << "\n";
}

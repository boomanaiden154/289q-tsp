#include <iostream>
#include <vector>
#include <fstream>

#include "DataLoader.h"
#include "TSPAlgorithms.h"
#include "TSPUtils.h"

int main() {
  std::map<std::pair<int, int>, float> TSPInstance =
      loadDataFromFile("./data/1000_euclidianDistance.txt");
  std::vector<int> BasicPath;
  for (int i = 1; i <= 1000; ++i) {
    BasicPath.push_back(i);
  }
  BasicPath.push_back(1);
  float TotalCost = computeCost(TSPInstance, BasicPath);
  std::cout << TotalCost << "\n";
  std::vector<int> GreedyPath = solveTSPNearestNeighbor(TSPInstance, 1000);
  float GreedyCost = computeCost(TSPInstance, GreedyPath);
  std::cout << GreedyCost << "\n";
  std::cout << "size:" << GreedyPath.size() << "\n";
  std::cout << validatePath(GreedyPath, 1000) << "\n";

  std::ofstream blah("/test.txt");
  for (int Test : GreedyPath) {
    blah << Test << "\n";
  }
}

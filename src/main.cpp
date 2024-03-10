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
  //float TotalCost = computeCost(TSPInstance, BasicPath);
  //std::cout << TotalCost << "\n";
  //std::vector<int> NNPath = solveTSPNearestNeighbor(TSPInstance);
  //float NNCost = computeCost(TSPInstance, NNPath);
  //std::cout << NNCost << "\n";
  //std::cout << validatePath(NNPath, 1000) << "\n";
  std::vector<int> GreedyPath = solveTSPGreedy(TSPInstance);
  std::ofstream test("/test.txt");
  for (int Node : GreedyPath) {
    test << Node << "\n";
  }
  std::cout << validatePath(GreedyPath, 1000) << "\n";
}

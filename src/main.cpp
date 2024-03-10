#include <iostream>
#include <vector>
#include <fstream>

#include "DataLoader.h"
#include "TSPAlgorithms.h"
#include "TSPUtils.h"

int main() {
  std::map<std::pair<int, int>, float> TSPInstance =
      loadDataFromFile("./data/1000_euclidianDistance.txt");
  const int ProblemSize = 1000;
  std::vector<int> NNPath = solveTSPNearestNeighbor(TSPInstance, ProblemSize);
  float NNCost = computeCost(TSPInstance, NNPath);
  std::cout << "nearest neighbor cost:" << NNCost << "\n";
  std::cout << "nearest neighbor valid:" << validatePath(NNPath, ProblemSize) << "\n";

  std::vector<int> OptimizedPath = ImproveTour(TSPInstance, NNPath, ProblemSize);
  std::cout << "optimized path cost: " << computeCost(TSPInstance, OptimizedPath) << "\n";
  std::cout << "optimized path valid: " << validatePath(OptimizedPath, ProblemSize) << "\n";

  std::ofstream OutputHandle("/tour_output.txt");
  for (int Test : OptimizedPath) {
    OutputHandle << Test << "\n";
  }
}

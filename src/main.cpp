#include <iostream>
#include <vector>
#include <fstream>

#include "DataLoader.h"
#include "TSPAlgorithms.h"
#include "TSPUtils.h"

int main() {
  std::map<std::pair<int, int>, float> TSPInstance =
      loadDataFromFile("./data/1000_randomDistance.txt");
  const int ProblemSize = 1000;
  std::vector<int> BasicPath;
  for (int i = 1; i <= ProblemSize; ++i) {
    BasicPath.push_back(i);
  }
  BasicPath.push_back(1);
  float TotalCost = computeCost(TSPInstance, BasicPath);
  std::cout << TotalCost << "\n";
  std::vector<int> GreedyPath = solveTSPNearestNeighbor(TSPInstance, ProblemSize);
  float GreedyCost = computeCost(TSPInstance, GreedyPath);
  std::cout << "greedy path cost:" << GreedyCost << "\n";
  std::cout << "size:" << GreedyPath.size() << "\n";
  std::cout << validatePath(GreedyPath, ProblemSize) << "\n";

  /*std::cout << "Printing path\n";
  for (int Node : GreedyPath) {
    std::cout << Node << "\n";
  }
  std::cout << "Done printing path\n";*/

  std::vector<int> OptimizedPath = ImproveTour(TSPInstance, GreedyPath, ProblemSize);
  std::cout << "path size: " << OptimizedPath.size() << "\n";
  std::cout << "is path valid: " << validatePath(OptimizedPath, ProblemSize) << "\n";

  /*std::cout << "printing path\n";
  for (int Node : OptimizedPath) {
    std::cout << Node << "\n";
  }
  std::cout << "done printing path\n";*/

  std::cout << "optimized path cost: " << computeCost(TSPInstance, OptimizedPath) << "\n";

  std::ofstream blah("/test.txt");
  for (int Test : GreedyPath) {
    blah << Test << "\n";
  }
}

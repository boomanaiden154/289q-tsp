#include "TSPAlgorithms.h"

#include <limits>
#include <unordered_map>

std::vector<int> solveTSPNearestNeighbor(
    const std::map<std::pair<int, int>, float> &TSPInstance,
    int ProblemSize) {
  std::unordered_map<int, bool> VisitedNodes;
  for (int I = 1; I <= ProblemSize; ++I) {
    VisitedNodes[I] = false;
  }
  // Start off at the first node just because.
  int CurrentNode = 1;
  std::vector<int> ResultingPath = {CurrentNode};
  VisitedNodes[CurrentNode] = true;
  for (int I = 1; I < ProblemSize; ++I) {
    // Find the nearest node that has not been visited yet and select that
    // one.
    int NearestUnvisitedNode = 1;
    float NearestUnvisitedNodeDistance = std::numeric_limits<float>::max();
    for (int I = 1; I <= ProblemSize; ++I) {
      if (TSPInstance.at(std::make_pair(I, NearestUnvisitedNode)) <
              NearestUnvisitedNodeDistance &&
          !VisitedNodes[I]) {
        NearestUnvisitedNode = I;
        NearestUnvisitedNodeDistance =
            TSPInstance.at(std::make_pair(CurrentNode, I));
      }
    }

    ResultingPath.push_back(NearestUnvisitedNode);
    VisitedNodes[NearestUnvisitedNode] = true;
    CurrentNode = NearestUnvisitedNode;
  }
  // Make sure to go back to the original node.
  ResultingPath.push_back(1);
  return ResultingPath;
}

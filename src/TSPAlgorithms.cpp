#include "TSPAlgorithms.h"

#include <limits>
#include <unordered_map>
#include <iostream>
#include <algorithm>

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

void twoSwap(std::vector<int> &CurrentRoute, int X, int Y) {
  std::reverse(CurrentRoute.begin()+X, CurrentRoute.begin()+Y);
}

std::vector<int> ImproveTour(const std::map<std::pair<int,int>, float> &TSPInstance,
    const std::vector<int> PreviousSolution, int ProblemSize) {
  std::vector<int> ToReturn(PreviousSolution);
  for (int X = 1; X < PreviousSolution.size() - 1; ++X) {
    for (int Y = 1; Y < PreviousSolution.size() - 1; ++Y) {
      if (X - Y >= -1 && X - Y <= 1) continue;
      const int EdgeXNodeA = ToReturn[X-1];
      const int EdgeXNodeB = ToReturn[X];
      const int EdgeYNodeA = ToReturn[Y-1];
      const int EdgeYNodeB = ToReturn[Y];
      const float EdgeXDistance = TSPInstance.at(std::make_pair(EdgeXNodeA, EdgeXNodeB));
      const float EdgeYDistance = TSPInstance.at(std::make_pair(EdgeYNodeA, EdgeYNodeB));
      const float Edge1NewDistance = TSPInstance.at(std::make_pair(EdgeXNodeA, EdgeYNodeA));
      const float Edge2NewDistance = TSPInstance.at(std::make_pair(EdgeXNodeB, EdgeYNodeB));
      if (EdgeXDistance + EdgeYDistance > Edge1NewDistance + Edge2NewDistance) {
        twoSwap(ToReturn, X, Y);
      }
    }
  }
  return ToReturn;
}

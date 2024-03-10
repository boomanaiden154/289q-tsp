#include "TSPAlgorithms.h"

#include <limits>
#include <unordered_map>
#include <algorithm>
#include <iostream>

std::vector<int> solveTSPNearestNeighbor(
    const std::map<std::pair<int, int>, float> &TSPInstance) {
  std::unordered_map<int, bool> VisitedNodes;
  // TODO(boomanaiden154): Make this work regardless of problem size by
  // parameterizing the node count.
  for (int I = 1; I <= 1000; ++I) {
    VisitedNodes[I] = false;
  }
  // Start off at the first node just because.
  int CurrentNode = 1;
  std::vector<int> ResultingPath = {CurrentNode};
  VisitedNodes[CurrentNode] = true;
  for (int I = 1; I < 1000; ++I) {
    // Find the nearest node that has not been visited yet and select that
    // one.
    int NearestUnvisitedNode = 1;
    float NearestUnvisitedNodeDistance = std::numeric_limits<float>::max();
    for (int I = 1; I <= 1000; ++I) {
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

int getGreatestNodeDegree(std::vector<std::tuple<int, int, float>> Edges) {
  std::unordered_map<int, int> NodeDegrees;
  // Parameterize this at some point.
  for (int I = 1; I <= 1000; ++I) {
    NodeDegrees[I] = 0;
  }
  for (const auto Edge : Edges) {
    const int NodeA = std::get<0>(Edge);
    const int NodeB = std::get<1>(Edge);
    NodeDegrees[NodeA]++;
    NodeDegrees[NodeB]++;
  }
  int MaxDegree = 0;
  for (const auto [NodeIndex, NodeDegree] : NodeDegrees) {
    if (NodeDegree > MaxDegree)
      MaxDegree = NodeDegree;
  }
  return MaxDegree;
}

std::vector<int> solveTSPGreedy(
    const std::map<std::pair<int, int>, float> &TSPInstance) {
  std::vector<std::tuple<int, int, float>> SortedEdges;
  SortedEdges.reserve(TSPInstance.size());
  for (const auto [EdgeVertices, EdgeWeight] : TSPInstance) {
    SortedEdges.push_back(std::make_tuple(
        std::get<0>(EdgeVertices), std::get<1>(EdgeVertices), EdgeWeight));
  }
  std::sort(SortedEdges.begin(), SortedEdges.end(), [](const auto LHS, const auto RHS) {
    return std::get<2>(LHS) < std::get<2>(RHS);
  });
  std::vector<std::tuple<int, int, float>> FinalPath;
  FinalPath.reserve(1001);
  size_t CurrentEdgeIndex = 0;
  while (FinalPath.size() < 1000) {
    const int NodeA = std::get<0>(SortedEdges[CurrentEdgeIndex]);
    const int NodeB = std::get<1>(SortedEdges[CurrentEdgeIndex]);
    if (NodeA == NodeB) {
      SortedEdges.erase(SortedEdges.begin()+CurrentEdgeIndex);
      continue;
    }
    FinalPath.push_back(SortedEdges[CurrentEdgeIndex]);
    if (getGreatestNodeDegree(FinalPath) > 2) {
      FinalPath.pop_back();
      CurrentEdgeIndex++;
      continue;
    }
    SortedEdges.erase(SortedEdges.begin()+CurrentEdgeIndex);
    CurrentEdgeIndex = 0;
    std::cout << std::get<0>(FinalPath.back()) << ":" << std::get<1>(FinalPath.back()) << "\n";
    std::cout << FinalPath.size() << "\n";
  }
  std::vector<int> RawPath;
  RawPath.reserve(1001);
  std::unordered_map<int, std::pair<int,int>> EdgesMap;
  for (const auto PathPiece : FinalPath) {
    const int NodeA = std::get<0>(PathPiece);
    const int NodeB = std::get<1>(PathPiece);
    if (EdgesMap.count(NodeA) != 0) {
      EdgesMap[NodeA].second = NodeB;
    }
    else {
      EdgesMap[NodeA] = std::make_pair(NodeB, 0);
    }
    
    if (EdgesMap.count(NodeB) != 0) {
      EdgesMap[NodeB].second = NodeA;
    }
    else {
      EdgesMap[NodeB] = std::make_pair(NodeA, 0);
    }
  }
  const int StartingNode = std::get<0>(FinalPath[0]);
  RawPath.push_back(StartingNode);
  for (int I = 1; I < 1000; ++I) {
    const int PreviousNode = RawPath[I - 1];
    const std::pair<int,int> NextNodePair = EdgesMap[PreviousNode];
    if (NextNodePair.first != PreviousNode)
      RawPath.push_back(NextNodePair.first);
    else
      RawPath.push_back(NextNodePair.second);
  }
  RawPath.push_back(RawPath[0]);
  return RawPath;
}

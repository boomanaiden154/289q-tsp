#include "TSPUtils.h"

#include <unordered_map>
#include <iostream>

float computeCost(const std::map<std::pair<int, int>, float> &TSPInstance,
                  const std::vector<int> &ProposedPath) {
  float TotalCost = 0;
  for (int I = 1; I < ProposedPath.size(); ++I) {
    TotalCost +=
        TSPInstance.at(std::make_pair(ProposedPath[I - 1], ProposedPath[I]));
  }
  return TotalCost;
}

bool validatePath(const std::vector<int> &ProposedPath, int NodeCount) {
  if (ProposedPath.size() != NodeCount + 1) {
    return false;
  }
  std::unordered_map<int, bool> VisitedCities;
  for (int I = 1; I <= NodeCount; ++I) VisitedCities[I] = false;
  for (const int VisitedCity : ProposedPath) VisitedCities[VisitedCity] = true;
  for (int I = 1; I <= NodeCount; ++I) {
    if (!VisitedCities[I]) {
      return false;
    }
  }
  return true;
}

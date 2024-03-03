#include "TSPUtils.h"

float computeCost(const std::map<std::pair<int, int>, float> &TSPInstance,
                  const std::vector<int> &ProposedPath) {
  float TotalCost = 0;
  for (int I = 1; I < ProposedPath.size(); ++I) {
    TotalCost +=
        TSPInstance.at(std::make_pair(ProposedPath[I - 1], ProposedPath[I]));
  }
  return TotalCost;
}

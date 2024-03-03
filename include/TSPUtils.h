// The header file containing misc code that is useful for heuristically
// solving TSP problems.

#include <map>
#include <utility>
#include <vector>

float computeCost(const std::map<std::pair<int, int>, float> &TSPInstance,
                  const std::vector<int> &ProposedPath);

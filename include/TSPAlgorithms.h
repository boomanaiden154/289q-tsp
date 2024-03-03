// The header file containing functions that solve the TSP heuristically.

#include <map>
#include <utility>
#include <vector>

std::vector<int> solveTSPNearestNeighbor(
    const std::map<std::pair<int, int>, float> &TSPInstance);

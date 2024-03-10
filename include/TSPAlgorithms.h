// The header file containing functions that solve the TSP heuristically.

#include <map>
#include <utility>
#include <vector>
#include <optional>

std::vector<int> solveTSPNearestNeighbor(
    const std::map<std::pair<int, int>, float> &TSPInstance);

// Greedy algorithm/helper functions.
int getGreatestNodeDegree(std::vector<std::tuple<int, int, float>> Edges);

std::vector<int> solveTSPGreedy(
    const std::map<std::pair<int, int>, float> &TSPInstance);


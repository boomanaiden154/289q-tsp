// The header file containing functions that solve the TSP heuristically.

#include <map>
#include <utility>
#include <vector>

std::vector<int> solveTSPNearestNeighbor(
    const std::map<std::pair<int, int>, float> &TSPInstance,
    int ProblemSize);

std::vector<int> ImproveTour(
    const std::map<std::pair<int, int>, float> &TSPInstance,
    const std::vector<int> PreviousSolution,
    int ProblemSize);

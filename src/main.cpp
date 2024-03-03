#include <iostream>

#include "DataLoader.h"

int main() {
  std::map<std::pair<int, int>, float> TSPInstance =
      loadDataFromFile("./data/1000_euclidianDistance.txt");
  for (int i = 1; i < 50; ++i) {
    std::cout << TSPInstance[std::make_pair(i, 2)] << "\n";
  }
}

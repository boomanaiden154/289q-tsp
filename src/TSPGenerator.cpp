#include <iostream>
#include <random>

int main(int argc, char** argv) {
  if (argc != 2) {
    std::cout << "Incorrect usage\n";
  }
  size_t ProblemSize = std::stoi(argv[1]);
  std::cout << ProblemSize << "\n";
  std::cout << "Node1 Node2 Distance\n";

  std::random_device RandomDevice;
  std::mt19937 RandomNumberGenerator(RandomDevice());
  std::uniform_real_distribution<float> Distribution(1.0,50.0);
  for (int X = 1; X <= ProblemSize; ++X) {
    for (int Y = X + 1; Y <= ProblemSize; ++Y) {
      std::cout << X << " " << Y << " " << Distribution(RandomNumberGenerator) << "\n";
    }
  }
}
